#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC target ("avx2", "bmi", "bmi2", "lzcnt", "popcnt")

#include <bits/stdc++.h>

using namespace std;

char s[200010];
int c[65536];
unsigned a[32][200010], b[32][200010];

inline int cnt (unsigned x)
{
  return c[x >> 16] + c[x & 65535];
}

signed main ()
{
  ios_base::sync_with_stdio (false);
  cin.tie (nullptr);

  cin >> s;

  for (int j = 0; j < 32; j++)
    for (int i = 0; s[j + i]; i++) a[j][i >> 5] |= s[j + i] == '1' ? 1 << (i & 31) : 0;

  cin >> s;

  for (int j = 0; j < 32; j++)
    for (int i = 0; s[j + i]; i++) b[j][i >> 5] |= s[j + i] == '1' ? 1 << (i & 31) : 0;

  for (int i = 0; i < 65536; i++) c[i] = c[i >> 1] + (i & 1);

  int q;
  cin >> q;

  while (q--)
    {
      int x, y, l;
      cin >> x >> y >> l;

      int r = 0;

      int i, j;
      for (i = x >> 5, j = y >> 5; l > 31; i++, j++, l -= 32) r += cnt (a[x & 31][i] ^ b[y & 31][j]);

      r += cnt ((a[x & 31][i] ^ b[y & 31][j]) & ((1 << l) - 1));

      cout << r << '\n';
    }

  return 0;
}
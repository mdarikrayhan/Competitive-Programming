#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 15;

int maxi[N];
int orgSeg[N];
int zeroSeg[N];

int a[N];

int res[N];

void solve2()
{
  int n;
  scanf("%d ", &n);

  for (int i = 1; i <= n; ++i)
  {
    scanf("%d ", &a[i]);
  }
  maxi[n + 1] = 0;
  orgSeg[n + 1] = 0;
  zeroSeg[n + 1] = 0;

  maxi[n] = 1;
  orgSeg[n] = -1;
  zeroSeg[n] = 1;

  int maxOrgSeg = 0;

  for (int i = n - 1; i; --i)
  {

    if (a[i] == orgSeg[i + 1])
    {
      res[i] = 0;
    }
    else
    {
      if (maxi[i + 1] >= a[i] || orgSeg[i + 1] != -1)
      {
        res[i] = 1;
      }
      else
      {
        res[i] = 2;
      }
    }
    zeroSeg[i] = max(zeroSeg[i + 1], 1 + maxOrgSeg);
    orgSeg[i] = i + a[i] + 1 <= n + 1 && orgSeg[i + a[i] + 1] != -1 ? 1 + orgSeg[i + a[i] + 1] : -1;
    maxi[i] = 0;
    if (i + a[i] + 1 <= n + 1)
    {
      maxi[i] = 1 + maxi[i + a[i] + 1];
    }
    maxi[i] = max(maxi[i], max(zeroSeg[i], orgSeg[i]));

    maxOrgSeg = max(maxOrgSeg, orgSeg[i]);
  }

  for (int i = 1; i < n; ++i)
  {
    printf("%d ", res[i]);
  }
  putchar('\n');
}

void solve()
{
  // init();
  int t;
  scanf("%d", &t);
  while (t--)
    solve2();
}

int main()
{
  solve();
  return 0;
}

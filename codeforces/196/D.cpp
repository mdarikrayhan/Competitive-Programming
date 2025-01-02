//
#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define int128 __int128_t

const int N = 4e5 + 5;
const ull P = 131;
int n, d, id;
char ch[N], ans[N];
ull hash1[N], hash2[N], f[N];
bool is;
inline void init()
{
	f[0] = 1; for (register int i = 1; i < N; i++) f[i] = f[i - 1] * P;
}
inline bool check(int l, int r)
{
	return (hash1[r] - hash1[l - 1] * f[r - l + 1]) * f[l - 1] == hash2[r] - hash2[l - 1];
}
inline void ___()
{
	init();
	scanf("%lld", &d);
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	id = n;
	for (register int i = 1; i <= n; i++)
	{
		hash1[i] = hash1[i - 1] * P + ch[i];
		hash2[i] = hash2[i - 1] + ch[i] * f[i - 1];
		if (i >= d && check(i - d + 1, i)) { id = i; break; }
		if (i > d && check(i - d, i)) { id = i; break; }
		ans[i] = ch[i];
	}
	for (register int i = id; i >= 1; i--)
	{
		is = false;
		for (register char j = ch[i] + 1; j <= 'z'; j++)
		{
			hash1[i] = hash1[i - 1] * P + j;
			hash2[i] = hash2[i - 1] + j * f[i - 1];
			if (i >= d && check(i - d + 1, i)) continue;
			if (i > d && check(i - d, i)) continue;
			ans[i] = j;
			id = i;
			is = true;
			break;
		}
		if (is) break;
	}
	if (!is) return void(printf("Impossible\n"));
	for (register int i = id + 1; i <= n; i++)
	{
		is = false;
		for (register char j = 'a'; j <= 'z'; j++)
		{
			hash1[i] = hash1[i - 1] * P + j;
			hash2[i] = hash2[i - 1] + j * f[i - 1];
			if (i >= d && check(i - d + 1, i)) continue;
			if (i > d && check(i - d, i)) continue;
			ans[i] = j;
			is = true;
			break;
		}
		if (!is) return void(printf("Impossible\n"));
	}
	printf("%s\n", ans + 1);
}
signed main()
{
	register int t = 1;
	// scanf("%lld", &t);
	while (t--) ___();
}
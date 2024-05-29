// LUOGU_RID: 157420169
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll inf = 1e18;
ll a[400005], p[400005], lp[400005], rp[400005], wow[400005], owo[400005];

int main()
{
	int t, m, i, c, q, o;
	ll n, k, l, r, mid, L, R, sum, d, ans;
	scanf("%d", &t);
	while(t--)
	{
		ans = inf;
		scanf("%lld%d%lld", &n, &m, &k);
		for(i = 1; i <= m; i++)
			scanf("%lld", p + i);
		p[m + 1] = n;
		for(i = 0; i <= m; i++)
			a[i] = p[i + 1] - p[i];
		k += m + 1;
		l = 1;
		r = n;
		while(l <= r)
		{
			sum = 0;
			mid = (l + r) >> 1;
			for(i = 0; i <= m; i++)
				sum += a[i] / mid;
			if(k <= sum)
				l = mid + 1;
			else
				r = mid - 1;
		}
		L = r;
		l = 1;
		r = n;
		while(l <= r)
		{
			sum = 0;
			mid = (l + r) >> 1;
			for(i = 0; i <= m; i++)
				sum += (a[i] + mid - 1) / mid;
			if(k >= sum)
				r = mid - 1;
			else
				l = mid + 1;
		}
		R = l;
		c = 0;
		q = 0;
//		printf("!!%lld %lld\n", L, R);
		for(i = 0; i <= m; i++)
			if((a[i] - 1) / R == a[i] / L)
			{
				++c;
				d = a[i] / L;
				if(d)
					rp[c] = (a[i] + d - 1) / d;
				else
					rp[c] = inf;
				lp[c] = a[i] / (d + 1);
				wow[++q] = lp[c];
			}
		wow[++q] = L;
		sort(wow + 1, wow + q + 1);
		q = unique(wow + 1, wow + q + 1) - wow - 1;
		for(i = 1; i <= q; i++)
			owo[i] = 0;
		for(i = 1; i <= c; i++)
		{
			o = lower_bound(wow + 1, wow + q + 1, lp[i]) - wow;
			owo[o] = max(owo[o], rp[i]);
		}
		for(i = 1; i <= q; i++)
		{
			ans = min(ans, R - wow[i]);
			R = max(R, owo[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
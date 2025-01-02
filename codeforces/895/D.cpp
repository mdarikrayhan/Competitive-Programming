#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

const int maxn = 1000010, mod = 1e9 + 7;
ll f[maxn][2][2], len, a[maxn], b[maxn], num[maxn], jie[maxn];
char s1[maxn], s2[maxn];

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll solve(ll cur, bool up, bool down)
{
    ll ans = 0;
    if (f[cur][up][down] != -1)
        return f[cur][up][down];
    if (up && down && a[cur] == b[cur] && num[a[cur]] > 0)
    {
        num[a[cur]]--;
        ll temp = solve(cur + 1, up, down);
        num[a[cur]]++;
        return f[cur][up][down] = temp;
    }
    if (up && num[b[cur]])
    {
        num[b[cur]]--;
        ans += solve(cur + 1, 1, 0);
        ans %= mod;
        num[b[cur]]++;
    }
    if (down && num[a[cur]])
    {
        num[a[cur]]--;
        ans += solve(cur + 1, 0, 1);
        ans %= mod;
        num[a[cur]]++;
    }
    ll temp = 1;
    for (ll i = 1; i <= 26; i++)
        temp = (temp * jie[num[i]]) % mod;
    temp = qpow(temp, mod - 2);
    int upx = (up ? b[cur] - 1 : 26), downx = (down ? a[cur] + 1 : 1);
    ll left = len - cur;
    for (ll i = downx; i <= upx; i++)
    {
        if (num[i] > 0)
            ans += jie[left] * temp % mod * num[i] % mod;  //因为num[i]的数量要-1，所以分母的阶乘要减少num[i]
        ans %= mod;
    }
    return f[cur][up][down] = ans;
}

int main()
{
    jie[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
        jie[i] = (jie[i - 1] * i) % mod;
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    len = strlen(s1 + 1);
    for (ll i = 1; i <= len; i++)
    {
        a[i] = s1[i] - 'a' + 1;
        num[a[i]]++;
        b[i] = s2[i] - 'a' + 1;
    }
    memset(f, -1, sizeof(f));
    cout << solve(1,1,1) << endl;

    return 0;
}
		 				 		 					 	   	 	 	 	 		
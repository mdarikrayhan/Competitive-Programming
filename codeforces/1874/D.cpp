// LUOGU_RID: 160423195
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ll long long
#define lf long double
#define _mp make_pair
#define _pb push_back
#define _1 first
#define _2 second
#define inf 3423423423423423422ll
#define MAX_N 3422

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c < 33)c = getchar();return c;}

int n, m;
lf dpl[MAX_N], dp[MAX_N];

void MAIN()
{
    n = read();
    m = read();
    dp[0] = 0;
    for(int i = 1; i <= m; i++)
        dp[i] = inf;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
            dpl[j] = dp[j], dp[j] = inf;
        for(int k = 1; k <= m / (n - i + 1); k++)
            for(int j = k; j <= m; j++)
                dp[j] = min(dp[j], dpl[j - k] + (j - k) / (lf)k);
    }
    lf ans = inf;
    for(int i = 0; i <= m; i++)
        ans = min(ans, dp[i]);
    ans = 2 * ans + n;
    printf("%.15Lf\n", ans);
}

void CLEAR()
{
    ;
}

void EXP()
{
    ;
}

int main()
{
    EXP();
    int T = 1;
    while(T--)
        MAIN(), CLEAR();
    return 0;
}
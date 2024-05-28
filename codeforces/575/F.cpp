#pragma GCC optimize("O3")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")   
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

long long int dp[2][10005];
set <int> S;
int n,m,x;
int p[10005];
int l[10005][2];
map <int,int> mn;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

    cin >> n >> x;
    S.insert(x);
    for(int i=0;i<n;i++)
    {
        cin >> l[i][0] >> l[i][1];
        S.insert(l[i][0]);
        S.insert(l[i][1]);
    }

    m = 0;
    for(auto it : S)
    {
        p[m] = it;
        mn[it] = m++;
    }

    x = mn[x];
    for(int i=0;i<n;i++)
    {
        l[i][0] = mn[l[i][0]];
        l[i][1] = mn[l[i][1]];
    }

    for(int i=0;i<m;i++)
    {
        dp[1][i] = 1e18;
    }

    for(int i=0;i<m;i++)
    {
        dp[1][i] = abs(p[i] - p[x]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[0][j] = dp[1][j];
            dp[1][j] = 1e18;
        }
        long long int Min = 1e18;
        for(int j=0;j<m;j++)
        {
            Min = min(Min,dp[0][j] - p[j]);
            dp[1][j] = min(dp[1][j],Min + p[j]);
        }
        Min = 1e18;
        for(int j=m-1;j>=0;j--)
        {
            Min = min(Min,dp[0][j] + p[j]);
            dp[1][j] = min(dp[1][j],Min - p[j]);
        }
        for(int j=0;j<m;j++)
        {
            long long int D = 0;
            if(j <= l[i][0]) D = p[l[i][0]] - p[j];
            else if(j >= l[i][1]) D = p[j] - p[l[i][1]];
            dp[1][j] += D;
        }
    }

    long long int res = 1e18;
    for(int i=0;i<m;i++) res = min(res,dp[1][i]);

    cout << res << '\n';

	return 0;
}
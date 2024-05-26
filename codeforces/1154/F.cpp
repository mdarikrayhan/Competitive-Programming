//Submitted by Yousry_Essam
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl '\n'
#define ll long long
#define NO cout<<"NO\n"
#define YES cout<<"YES\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define format(n) fixed<<setprecision(n)
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define _DEBUG(x) cout<< #x <<" = "<<"\""<< (x) <<"\""<<endl
#define Yousry_Essam std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void FIO();
//==========================functions & vars & DS=======================//
int n, m, k;
vector<int>v, bestOffer;
int dp[2009][2009];
int calcCost(int idx, int x)
{
    int endPos = idx + x - 1;
    int endOff = idx + bestOffer[x] - 1;
    return v[endPos] - v[endOff];
}
int dp_solve(int idx , int rem) {
    if (idx > k)  return 0;
    int& ret = dp[idx][rem];
    if (~ret) return ret;
    ret = dp_solve(idx + 1, rem - 1) + (v[idx] - v[idx - 1]);
    for (int i = 1; i <= rem; i++) if (~bestOffer[i])ret = min(ret, dp_solve(idx + i, rem - i) + calcCost(idx, i));
    return ret;
}
//===============================solutions==============================//
void solve(int T)
{
    mem(dp, -1);
    cin >> n >> m >> k;
    v.resize(n+1);
    bestOffer.resize(k + 2, -1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(all(v));
    for (int i = 1; i <= n; i++) v[i] += v[i - 1];
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        if (x <= k) bestOffer[x] = max(bestOffer[x], y);
    }
    cout << dp_solve(1, k);
}
int main()
{
    Yousry_Essam;
    FIO();
    int t = 1;//cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}
void FIO()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
}
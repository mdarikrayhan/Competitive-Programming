/**
    Author: Kristopher Paul
    Date Created: 24-05-2023
**/
#include<bits/stdc++.h>
//#include<stdio.h>
#include<unordered_map>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int ll
#define pb push_back
#define INF 1e18
//#define MOD 1000000007
#define MOD 998244353
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define umap unordered_map
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define out(x) cout << #x << " is " << x << endl
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

//using namespace __gnu_pbds;

//typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> pbds; // set
//typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // multiset

int ModExp(int x, int y, int m){
    int res = 1;
    x = x % m;
    while (y > 0){
        if (y & 1)
            res = (res*x) % m;
        y = y>>1;
        x = (x*x) % m;
    }
    return res;
}

void solve(){
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    FOR(i,0,n){
        cin >> a[i];
    }
    int g = 0;
    FOR(i,0,m){
        cin >> b[i];
        g = gcd(g,b[i]);
    }
    int dp[n][2];
    FOR(i,0,g){
        dp[i][0] = a[i];
        dp[i][1] = -a[i];
    }
    FOR(i,g,n){
        dp[i][0] = max(dp[i-g][0]+a[i],dp[i-g][1]-a[i]);
        dp[i][1] = max(dp[i-g][0]-a[i],dp[i-g][1]+a[i]);
    }
    int a1 = 0,a2 = 0;
    FOR(i,n-g,n){
        a1 += dp[i][0];
        a2 += dp[i][1];
    }
    cout << max(a1,a2) << "\n";
}

signed main(){
    FastIO;
    int t = 1;
    cin >> t;
    WL(t){
        solve();
    }
}
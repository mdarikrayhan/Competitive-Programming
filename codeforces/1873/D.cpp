#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

typedef long long ll;
typedef unsigned long long ull;
#define int ll
#define forn(i, x, n) for (int i = x; i <= n; i++)
#define forn(i, n) for (int i = 0; i < n; i++)
#define cin(fib, n) forn(i, n) cin >> fib[i]
#define cout(fib, n) forn(i, n) cout << fib[i] << ' '
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(fib) fib.begin(), fib.end()
#define alln(fib, n) fib, fib + n
#define rall(fib) fib.rbegin(), fib.rend()
#define yes cout << "YES"
#define no cout << "NO"
#define yn(b) (b ? yes : no)
#define pb push_back
#define nl cout << "\n"
#define minPQ priority_queue<int, vector<int>, greater<int>>
#define vi vector<int>
#define vs vector<string>
const int mod = 1000000007;
const int N = 100010;
const int oo = LONG_LONG_MAX;


void solve() {

    int n,k; cin>>n>>k;
   string s; cin>>s;

   vi a;

   forn(i,s.size())
   if(s[i]=='B')
       a.pb(i);

   int ans=0;
   forn(i,a.size())
   {
       int j=i+1;
        bool flg=0;
       while(j<a.size() && a[j]-a[i]<k  )
           j++,flg=1;

       if(flg)
           i=j-1;
       ans++;
   }

   cout<<ans;

}


    signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    FastIO;
    int t = 1;
    cin>>t;

    while (t--)
    {
        solve();
        nl;
    }


    return 0;
}
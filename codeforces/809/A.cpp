#include <bits/stdc++.h>
using namespace std;
#define dbg(v)                                                                 \
	cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define viii vector<vector<vector<int>>> 
#define pi pair<int, int>
#define pb push_back                   
#define si set<int>
#define f first
#define s second
#define INF (int)(1e18)
#define rep(var, l, r) for (int var = l; var < r; var++)
int const M=1e9+7;
int const N=32000;
int const D=998244353;
int exp(int a,int b,int M)
{int p=1;
while(b>0)
{if(b&1)
{p=(p*a)%M;}
a=(a*a)%M;
b>>=1;}
return p;}

void solve()
{int n;
cin >>n;
vi a(n);
rep(i,0,n)
{cin >>a[i];}
sort(a.begin(),a.end());
int ans=0;

rep(i,0,n)
{ans=(ans+((exp(2,i,M)-exp(2,n-i-1,M))%M)*a[i]%M);
if(ans<0)
{ans+=M;}}
cout <<ans%M<<"\n";}

















int32_t main()
  {  auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
   //cin >>t;
    
   
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        solve();
    }
   auto end = std::chrono::high_resolution_clock::now();
   auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
   cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define in(n) int n ; cin>>n;
#define print(x) cout<<x<<'\n'
#define pritn(x) cout<<x<<'\n'
#define sin(str) string str ; cin>>str;
#define all(x) x.begin(), x.end()
#define sz(x)  (int)(x.size())
#define inp(v,n)  ve v(n);  for(int i=0;i<n;i++) cin>>v[i];
#define out_ve(v,n)   for(auto &e:v) {cout<<e<<' ';}
#define  lp(i,a,b) for(int i=a;i<b;i++)
#define ve vector<int>
#define mii map<int,int>
#define INF (int)1e18
#define vpi vector<pair<int,int>>
typedef pair<int,int>pi;
const int num = 1e6+10;
const int mod1 = 1e9+7;
const int mod2 = 998244353;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

void solve()
{
        in(m); in(a); in(b);
        ve f(a+b,-1);
        int ans = 0,x = 0, y = 0;
        
        while(1){
               f[x] = y;
               if(x>=b){
                    x-=b;    
               }
               else{
                   x+=a;     
               }
               y = max(y,x);
               if(f[x]!=-1) break;  
        }


        for(int i=0;i<a+b;i++){
                if(f[i]!=-1){
                        ans+=max(0LL,m-f[i]+1);
                }
        }

        if(m>=a+b){
                int g = __gcd(a,b), l = (a+b), r = m/g*g, n = (r-l)/g+1;
                ans+=((m+1)*n)-(n*(l+r))/2;
        }

        pritn(ans);
        
}             
signed main () {
        ios::sync_with_stdio(0);
        cin.tie(0);
int tt;
tt=1;
//cin>>tt;
while(tt--)
{
solve();
}
        return 0;
}
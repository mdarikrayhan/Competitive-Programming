
#include<bits/stdc++.h>

#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
#define int long long
#define vi vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define nl endl
#define Nl endl
#define f first
#define s second

#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 2e18;
using namespace std;

void solve()
{
    int l,r;cin>>l>>r;
    if (l==r)
    {
        cout<<l<<nl;return;
    }
    int abase=log10(l);
    int bbase=log10(r);
    int powb=(pow(10,bbase)+0.01);
    if (bbase!=abase)
    {
        cout<<(powb-1)<<nl;
        return;
    }
    
    
    for (int diff = 0; diff < 10; diff++)
    {
        int number=0;
        for (int st = 0; st <=9-diff; st++)
        {
            number=0;
            int a=l;int b=r;
            int base=log10(max(a,b));
            base=pow(10,base)+0.01;
            bool istrue=1;
            int end=st+diff;

            while (base!=0)
            {
                if (a/base==b/base)
                {
                    if(a/base>end or a/base<st){
                        istrue=0;
                        break;
                    }
                    number+=(a/base)*base;
                    a-=(a/base)*base;
                    b-=(b/base)*base;
                    
                    base/=10;
                    continue;
                }
                int highest=b;
                int lowest=a;
                int ad=a/base;
                int bd=b/base;
                for(int i=ad+1;i<bd;i++){
                    if(i>=st and i<=(st+diff)){
                        number+=(base*10-1)/9*i;
                        cout<<number<<nl;
                        return;
                    }
                }
                if (ad<=(st+diff) and ad>=(st))
                {
                    int temp=0;
                    temp+=(ad)*base;
                    temp+=((base-1)/9)*(st+diff);
                    if((temp)>=a){
                        cout<<number+temp<<nl;
                        return;
                    }
                }
                if (bd<=(st+diff) and bd>=(st))
                {
                    int temp=0;
                    temp+=(bd)*base;
                    temp+=((base-1)/9)*(st);
                    if((temp)<=b){
                        cout<<number+temp<<nl;
                        return;
                    }
                }
                break;
                
                
            }  
        }
        
    }
    
    
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;
}




#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,n) for(ll i=0;i<n;++i)

ll gcd(ll a,ll b){
    if(a!=0&&b!=0){
        return __gcd(a,b);
    }
    return max(a,b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vll v(n);set<pair<ll,ll>>s;
        rep(i,n){
            cin>>v[i];
        }
        if(n==1){
            cout<<0<<"\n";
        }
        else if(n==2){
            if(v[0]==v[1]&&v[0]==1){
                if(k<2){
                    cout<<1<<"\n";
                }
                else{
                    cout<<0<<"\n";
                }
            }
            else{
                cout<<0<<"\n";
            }
        }
        else{
            ll c = 0;
            for(ll i=1;i<=n-2;++i){
                if(c==k)break;
                ll left = gcd(v[i-1],v[i]);
                ll right = gcd(v[i],v[i+1]);
                if(left==1&&right==1&&v[i-1]!=1&&v[i+1]!=1){
                    v[i] = 0;
                    c++;
                }
            }
            ll start = -1; ll counter = 0;
            rep(i,n){
                if(v[i]==1){
                    counter++;
                    if(i==n-1){
                        s.insert({counter,start});
                    }
                }
                else{
                    if(counter>0){
                        s.insert({counter,start});
                    }
                    start = i;
                    counter = 0;
                }
            }
            for(auto p:s){
                if(c==k)break;
                if(p.second!=-1&&p.first+p.second!=n-1){
                    for(ll i = p.second+1;i<=p.second+p.first;++i){
                        v[i]=0;
                        c++;
                        if(c==k)break;
                    }
                }
            }
            for(auto p:s){
                if(c==k)break;
                if(p.second==-1){
                    for(ll i = p.second+p.first;i>p.second;--i){
                        v[i]=0;
                        c++;
                        if(c==k)break;
                    }
                }
                else if(p.first+p.second==n-1){
                    for(ll i=p.second+1;i<=n-1;++i){
                        v[i]=0;
                        c++;
                        if(c==k)break;
                    }
                }
            }
            rep(i,n-1){
                if(c==k)break;
                if(gcd(v[i],v[i+1])==1){
                    v[i]=0;
                    c++;
                }
                
            }
            ll ans = 0;
            rep(i,n-1){
                if(gcd(v[i],v[i+1])==1){
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }

}
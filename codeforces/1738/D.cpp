#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define fr(i,n) for(i=0;i<n;i++)
#define fa(i,v) for(auto &i:v)
#define yesno cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define vvl vector<vector<ll> > 
#define vl vector<ll> 
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll> >
#define vvpll vector<vector<pair<ll,ll> > >
#define all(v) v.begin(),v.end()
#define mp make_pair
#define eb emplace_back
#define rs resize
#define cl(v) v.clear()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define inf (ll)1e18
#define f1 first
#define f2 second
#define mod (ll)(1e9+7)
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

int main(){
    fastio
    int t=1;
    cin>>t;
    while(t--){
        ll n,i,k=0;
        cin>>n;
        ll a[n];
        vvl v(n+2);
        fr(i,n){
            cin>>a[i];
            if(a[i]>i+1) k++;
            v[a[i]].eb(i+1);
        }
        cout<<k<<endl;
        if(v[n+1].size()){
            ll vert=n+1, nv;
            while(1){
                bool sb=1;
                fa(i,v[vert]){
                    if(v[i].size()){
                        sb=0;
                        nv=i;
                        continue;
                    }
                    cout<<i<<' ';
                }
                vert=nv;
                if(sb) break;
                else cout<<vert<<' ';
            }
        }
        else{
            ll vert=0, nv;
            while(1){
                bool sb=1;
                fa(i,v[vert]){
                    if(v[i].size()){
                        sb=0;
                        nv=i;
                        continue;
                    }
                    cout<<i<<' ';
                }
                vert=nv;
                if(sb) break;
                else cout<<vert<<' ';
            }
        }
        cout<<endl;
    }
}

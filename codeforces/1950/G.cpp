#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define fl(i,a,b) for(int i=b-1;i>=a;i--)
#define go(a,x) for(auto &a:x)
#define inn(a) go(x,a)cin>>x
#define print(v) go(x,v){cout<<x<<" ";}cout<<endl;
const ll inf=9223372036854775807;
void yes(){cout <<"YES"<<endl;}
void no(){cout <<"NO"<<endl;}
void ne(){cout <<-1<<endl;}
#define yn(a) cout<<((a)?"YES\n":"NO\n")
typedef pair<ll, ll> pii;
using pq = priority_queue<ll>;
using vi = vector<ll>;
using vii = vector<pair<ll,ll>>;
using mii = map<ll,ll>;
using umii = unordered_map<ll,ll>;
using si = set<ll>;
using usi = unordered_set<ll>;
using msi = multiset<ll>;
ll ff=-1;
ll jj=0;
void solve(){
        ll n;cin>>n;
        jj++;
        vector<pii>v;
        vector<pair<string,string>>w;
        vector<string>ss;
        fr(i,0,n){
            string r,s;cin>>r>>s;
            w.pb({r,s});
            ss.pb(r);
            ss.pb(s);
            // PolyHash R1 = PolyHash(rrr(r));
            // PolyHash R2 = PolyHash(rrr(s));
            // v.pb({R1.get_hash(0,r.length()-1),R2.get_hash(0,s.length()-1)});
        }
        // if(ff==400&&jj==183){
        //     go(x,w)cout<<x.F<<" "<<x.S<<endl;
        // }
        // else if(ff==400)return;
        sort(all(ss));
        fr(i,0,n){
            v.pb({find(all(ss),w[i].F)-ss.begin(),find(all(ss),w[i].S)-ss.begin()});
        }
        // go(x,v)cout<<x.F<<" "<<x.S<<endl;
        ll mask=(1<<n);
        ll ans=0;
        bool dp[mask][n]={0};
        vector<int>g[n+1];
        for(int i=0;i<mask;i++){
            g[__builtin_popcount(i)].pb(i);
        }
        for(int i=0;i<n;i++)dp[(1<<i)][i]=1;
        for(int cnt=1;cnt<=n;cnt++){
            for(auto  i:g[cnt]){
            for(int k=0;k<n;k++){
                if(!dp[i][k])continue;
            for(int j=0;j<n;j++){
                if((1<<j)&i)continue;
                if(v[j].F==v[k].F||v[j].S==v[k].S)dp[(i|(1<<j))][j]=1;
            }
            }
            }
        }
        fr(i,0,mask){
            fr(j,0,n){
                if(dp[i][j])ans=max(ans,(ll)__builtin_popcount(i));
            }
        }
        cout<<n-ans<<endl;


}

int main(){
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
ios::sync_with_stdio(0); cin.tie(0);
  ll tt=1;

    cin>>tt;
    ff=tt;

  while(tt--){
   solve();
  }
   
return 0;
}
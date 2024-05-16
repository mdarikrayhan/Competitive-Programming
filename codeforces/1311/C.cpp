#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ccc cout<<
#define ce cout<<endl;
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define c0 cout<<0<<endl;
#define c1 cout<<1<<endl;
#define c01 cout<<-1<<endl;
#define endy <<endl;
#define inf 1000000000
int main() {
    ll T;
    cin>>T;
    while(T--){
        ll n,k,e=0,la,ra,maxl=-9000000000000000000,maxr=9000000000000000000;
        ll sum=0,a,b,c;
        map<char,ll>m,ma;
        vector<pair<ll,ll>>vp ;
        cin>>n>>k;
        string s;cin>>s;
        deque<ll>v(n+1,0),w;
        for(ll i=0;i<k;i++){
          ll x;cin>>x;
          v[x]--;v[0]++;
        }
        for(ll i=0;i<n;i++){
          sum+=v[i];
          w.push_back(sum+1);
        }
        // for(auto x:v)cout<<x<<" ";ce
        // for(auto x:w)cout<<x<<" ";ce
        for(int i=0;i<n;i++){
          m[s[i]]+=w[i];
        }
        for(char i='a';i<='z';i++){
          cout<<m[i]<<" ";
        }ce
    }
    return 0;
}

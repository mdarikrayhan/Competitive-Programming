#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define USE_FILE 0
void solve()
{
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    map<char,ll> cnt;
    for(auto i:s)
    {
        cnt[i]++;
    }
    ll ans =0;
    for(int i=0;i<26;i++)
    {
        ans+=min(cnt['a'+i],cnt['A'+i]);
    }
    for(int i=0;i<26;i++)
    {
        ll maxx= (cnt['a'+i]+cnt['A'+i])/2-min(cnt['a'+i],cnt['A'+i]);
        if(k>=maxx)
        {
            ans+=maxx;
            k-=maxx;
        }else{
            ans+=k;
            break;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #if USE_FILE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)solve();
}
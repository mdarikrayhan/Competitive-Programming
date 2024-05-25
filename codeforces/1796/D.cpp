#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,k,x;
        cin>>n>>k>>x;
        vector<ll> vec(n+1);
        for(int i=0;i<n;i++) cin>>vec[i+1];
        vector<ll> pre1(n+1),pre(n+1);
        for(int i=1;i<=n;i++) pre1[i]=pre1[i-1]+vec[i];
        for(int i=1;i<=n;i++) pre[i]=pre1[i];
        if(x<0){
            k=n-k;
            x=-x;
        }
        ll mini=0;
        for(ll i=1;i<=n;i++){
            pre[i]-=i*x;
            pre1[i]+=i*x;
        }
        ll ans=0;
        for(int i=k;i<=n;i++){
            ans=max(ans,pre[i]-mini+2*k*x);
            mini=min(mini,pre[i-k]);
        }
        deque<pair<ll,ll>> dq;
        for(int i=0;i<=n;i++){
            while(!dq.empty()&&i-dq.front().second>k) dq.pop_front();
            if(!dq.empty()) ans=max(ans,pre1[i]-dq.front().first);
            while(!dq.empty()&&dq.back().first>=pre1[i]) dq.pop_back();
            dq.push_back(make_pair(pre1[i],i));
        }
        cout<<ans<<"\n";
    }
}
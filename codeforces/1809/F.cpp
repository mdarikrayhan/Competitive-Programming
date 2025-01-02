#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
struct node{
    int l,r;
    int l_on,r_on;
    ll sum;
};
node mp[400010][20];
const int c=20;
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(2*n+1),b(2*n+1);
    vector<ll> pre(2*n+1); 
    auto merge=[&](node a,node b)->node {
        node ans;
        ans.l=a.l,ans.r=b.r;
        if(a.l_on==-1) ans.l_on=b.l_on; 
        else ans.l_on=a.l_on;
        if(b.r_on==-1)  ans.r_on=a.r_on;
        else ans.r_on=b.r_on;
        ll sum=a.sum+b.sum;
        ans.sum=sum;
        if(a.r_on==-1)    return ans;
        ll len1=(b.l_on==-1?pre[b.r]-pre[b.l-1]:pre[b.l_on-1]-pre[b.l-1]);
        ll len2=pre[a.r]-pre[a.r_on-1];
        //cout<<a.l<<' '<<a.r<<' '<<b.l<<' '<<b.r<<'\n';
        //if(a.l==2&&b.r==5)  cout<<len1<<' '<<ans.sum<<'\n';
        if(len2>=k) return ans;
        else ans.sum-=min(k-len2,len1);
        return ans;
    };


    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[n+i]=a[i];
    }
    for(int i=1;i<=2*n;i++)   pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b[n+i]=b[i];
    }
    for(int i=0;i<=c-1;i++){
        for(int j=1;j<=2*n;j++){
            if(i==0){
                if(b[j]==1) mp[j][0]={j,j,j,j,1ll*a[j]};
                else mp[j][0]={j,j,-1,-1,1ll*2*a[j]};
            }
            else{
                if(j+(1<<i)-1>2*n)  continue;
                mp[j][i]=merge(mp[j][i-1],mp[j+(1<<(i-1))][i-1]);
            }
        }
    }
    //cout<<mp[2][1].sum<<'\n';
    for(int i=1;i<=n;i++){
        int l=i+1,r=i+n-1;
        node ans;
        if(b[i]==1) ans={i,i,i,i,a[i]};
        else ans={i,i,-1,-1,2*a[i]};
        for(int i=c-1;i>=0;i--){
            if(l+(1<<i)-1>r)    continue;
            ans=merge(ans,mp[l][i]);
            l+=(1<<i);
        }
        cout<<ans.sum<<' ';
    }
    cout<<'\n';
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}

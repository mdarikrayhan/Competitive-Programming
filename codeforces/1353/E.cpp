// LUOGU_RID: 160429758
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+50,M=2e6+60;
ll T,n,k,a[N],cnt,ans,pre[N],la[N],s1;
string s;
ll get(){
    la[cnt+1]=0;
    for(int i=1;i<=cnt;++i)pre[i]=pre[i-1]+a[i];
    for(int i=cnt;i;--i)la[i]=la[i+1]+a[i];
    priority_queue< ll , vector<ll> , greater<> >q;
    q.push(0);
    ll minn=1e18,t=0,x=0,y=0;
    for(ll i=1;i<=cnt;++i){
        if(a[i]==0)x++;
        else y++;
        minn=min(minn,x+q.top()+la[i+1]);
        q.push(y-x);
    }
    return minn+s1-pre[cnt];
}
void solve(){
    s=' '+s;ans=1e18;s1=0;
    for(int i=1;i<=n;++i)s1+=s[i]-'0';
    for(int i=1;i<=k;++i){
        cnt=0;
        for(int j=i;j<=n;j+=k){
            a[++cnt]=s[j]-'0';
        }
        ans=min(ans,get());
    }
    cout<<min(ans,s1)<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k;
        cin>>s;
        solve();
    }
    return 0;
}
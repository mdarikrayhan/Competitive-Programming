// LUOGU_RID: 160425405
#include <bits/stdc++.h>
using namespace std;
namespace Le0{
#define LL long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e5+5,mx=1e5;
const int inf=0x3f3f3f3f;
int T,n,k;
LL ans;
int a[N],dp[N];
map<int,int> mp;
struct seg{
    int t[N<<2],t2[N<<2];
    void pp(int p){
        t[p]=min(t[p<<1],t[p<<1|1]);
        t2[p]=t2[p<<1]+t2[p<<1|1];
    }
    void build(int p,int l,int r){
        t[p]=inf;
        if(l==r) return;
        int mid=l+r>>1;
        build(p<<1,l,mid);build(p<<1|1,mid+1,r);
    }
    void modify(int p,int l,int r,int x,int k,int k2){
        if(l==r){
            if(k2>-1) t[p]=min(t[p],k),t2[p]++;
            else t[p]=inf,t2[p]=0;
            return;
        }int mid=l+r>>1;
        if(x<=mid) modify(p<<1,l,mid,x,k,k2);
        else modify(p<<1|1,mid+1,r,x,k,k2);
        pp(p);
    }
    LL query(int p,int l,int r,int ql,int qr){
        if(l>=ql&&r<=qr) return t2[p];
        int mid=l+r>>1;LL as=0;
        if(ql<=mid) as+=query(p<<1,l,mid,ql,qr);
        if(qr>mid) as+=query(p<<1|1,mid+1,r,ql,qr);
        return as;
    }
    int qry2(int p,int l,int r,int ql,int qr){
        if(l==r) return t[p];
        int mid=l+r>>1;
        if(t2[p<<1]) return qry2(p<<1,l,mid,ql,qr);
        if(t2[p<<1|1]) return qry2(p<<1|1,mid+1,r,ql,qr);
        return inf;
    }
    int qry(int p,int l,int r,int ql,int qr){
        if(l>=ql&&r<=qr){
            return t[p];
        }int mid=l+r>>1;
        int mx=inf;
        if(ql<=mid) mx=min(mx,qry(p<<1,l,mid,ql,qr));
        if(qr>mid) mx=min(mx,qry(p<<1|1,mid+1,r,ql,qr));
        return mx;
    }
}sg;
void clear(){
    mp.clear();
    ans=0;
}
void work(){
    for(int i=n;i>=1;i--){
        int pos=sg.qry(1,1,mx,a[i]+1,a[i]+k);
        if(pos!=inf){
            dp[i]=dp[pos]+sg.query(1,1,mx,a[i]+1,a[pos]);
        }
        ans+=dp[i];
        sg.modify(1,1,mx,a[i],i,1);
    }
    for(int i=1;i<=n;i++) sg.modify(1,1,mx,a[i],i,-1),dp[i]=0;
}
int main(){
    cin>>T;
    sg.build(1,1,mx);
    while(T--){
        cin>>n>>k;
        clear();
        for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++;
        for(auto z:mp){
            int y=z.se;
            ans+=1ll*y*(y+1)/2;
        }
        work();
        reverse(a+1,a+1+n);
        work();
        cout<<ans<<"\n";
    }
    return 0;
}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    return Le0::main();
}
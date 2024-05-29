// LUOGU_RID: 159759199
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
const ll INF=1e18+9;
ll n,k,w[N],g[N];
ll a[N],b[N],c[N],d[N];
ll sd[N<<2],sd1[N<<2],tag[N<<2];
#define ls (x<<1)
#define rs (x<<1|1)
#define MID ((l+r)>>1)
void brush(ll x,ll v){
    sd1[x]+=v; tag[x]+=v;
}
void push_down(ll x){
    if(tag[x]==0) return;
    brush(ls,tag[x]); brush(rs,tag[x]);
    tag[x]=0;
}
void push_up(ll x){
    sd[x]=max(sd[ls],sd[rs]);
    sd1[x]=max(sd1[ls],sd1[rs]);
}
void build(ll x,ll l,ll r){
    if(l==r){
        sd1[x]=-INF;
        return ;
    }
    build(ls,l,MID); build(rs,MID+1,r);
    push_up(x);
}
void upd(ll x,ll l,ll r,ll L,ll R,ll v){
    if(L<=l && r<=R){
        brush(x,v); return;
    }
    push_down(x);
    if(L<=MID) upd(ls,l,MID,L,R,v);
    if(R>MID) upd(rs,MID+1,r,L,R,v);
    push_up(x);
}
void add(ll x,ll l,ll r,ll u,ll v){
    if(l==r){
        sd[x]=sd1[x]=v;
        return;
    }
    push_down(x);
    if(u<=MID) add(ls,l,MID,u,v);
    else add(rs,MID+1,r,u,v);
    push_up(x);
}
ll find(ll x,ll l,ll r,ll L,ll R,ll lmax){
    if(l==r) return l;
    push_down(x);
    if(R<=MID) return find(ls,l,MID,L,R,lmax);
    if(L>MID) return find(rs,MID+1,r,L,R,lmax);
    if(max(lmax,sd1[ls])<=sd[rs]+k) return find(rs,MID+1,r,L,R,max(lmax,sd1[ls]));
    return find(ls,l,MID,L,R,lmax);

}
ll query(ll x,ll l,ll r,ll u){
    if(l==r) return sd1[x];
    push_down(x);
    if(u<=MID) return query(ls,l,MID,u);
    else return query(rs,MID+1,r,u);
}
ll s[N],top;
int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<n;i++) cin>>w[i];
    for(ll i=1;i<=n;i++) cin>>g[i];
    for(ll i=1;i<=n;i++) a[i]=a[i-1]+w[i];
    for(ll i=1;i<=n;i++) b[i]=b[i-1]+g[i];
    for(ll i=1;i<=n;i++) c[i]=a[i-1]-b[i-1],d[i]=b[i]-a[i-1];
    ll ans=0;
    build(1,1,n);
    //for(ll i=1;i<=n;i++) cout<<c[i]<<' '; cout<<endl;
    //for(ll i=1;i<=n;i++) cout<<d[i]<<" "; cout<<endl;
    for(ll i=n;i>=1;i--){
        while(top && c[s[top]]<=c[i]){
            if(top>1){
                upd(1,1,n,s[top-1]-1,n,-(c[s[top-1]]-c[s[top]]));
                //cout<<"cancel "<<s[top-1]-1<<" "<<c[s[top-1]]-c[s[top]]<<endl;
            }
            top--;
        }       
        s[++top]=i;
        add(1,1,n,i,d[i]);
        if(top>1){
            upd(1,1,n,s[top-1]-1,n,c[s[top-1]]-c[s[top]]);
            //cout<<"add "<<s[top-1]-1<<" "<<c[s[top-1]]-c[s[top]]<<endl;
        }
        
        //cout<<"add "<<i<<endl;
        ll l=1,r=top;
        if(i==1){
            //for(ll i=1;i<=top;i++) cout<<c[s[i]]<<" "; cout<<endl;
            //for(ll i=1;i<=n;i++) cout<<d[i]<<" "; cout<<endl;
            
        }
        //for(ll i=1;i<=n;i++) cout<<query(1,1,n,i)<<" "; cout<<endl;
        while(l!=r){
            ll mid=(l+r)>>1;
            if(c[s[mid]]-c[i]<=k) r=mid;
            else l=mid+1;
        }
        //cout<<"b r="<<r<<endl;
        if(r>1) r=s[r-1]-1;
        else r=n;
        //cout<<"range "<<i<<" - "<<r<<endl;
        //cout<<"get at "<<find(1,1,n,i,r,-INF)<<endl;
        ans=max(ans,find(1,1,n,i,r,-INF)-i+1);
    }
    cout<<ans;
    return 0;
}
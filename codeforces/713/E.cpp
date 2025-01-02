// LUOGU_RID: 157368640
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pii pair<ll,ll>
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)
using namespace std;
bool Mbe;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const ll N=1e6+9;
ll n,m,a[N],pos=1,b[N],dp[N];
ll chk(ll mid){
    dp[1]=0;
    rep(i,2,m){
        dp[i]=dp[i-1];
        if(dp[i-1]>=b[i]-1)dp[i]=max(dp[i],b[i]+mid);
        if(dp[i-1]>=b[i]-mid-1)dp[i]=max(dp[i],b[i]);
        if(i>=3&&dp[i-2]>=b[i]-mid-1)dp[i]=max(dp[i],b[i-1]+mid);
    }
    if(dp[m]>=n-mid-1)return 1;
    dp[2]=max(b[2],mid);
    rep(i,3,m){
        dp[i]=dp[i-1];
        if(dp[i-1]>=b[i]-1)dp[i]=max(dp[i],b[i]+mid);
        if(dp[i-1]>=b[i]-mid-1)dp[i]=max(dp[i],b[i]);
        if(i>=3&&dp[i-2]>=b[i]-mid-1)dp[i]=max(dp[i],b[i-1]+mid);
    }
    if(dp[m]>=min(n-1,n+b[2]-mid-1))return 1;
    return 0;
}
bool Med;
int main(){
    cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
    n=read(),m=read();
    if(m==1)return write(n-1),0;
    rep(i,1,m)a[i]=read();
    sort(a+1,a+m+1);
    rep(i,1,m)a[i+m]=a[i]+n;
    rep(i,2,m){
        if(a[i+1]-a[i]>a[pos+1]-a[pos])pos=i;
    }
    ll l=1,r=a[pos+1]-a[pos]-1;
    rep(i,1,m)b[i]=a[i+pos];
    rep(i,2,m)b[i]-=b[1];
    b[1]=0;
    ll res=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(chk(mid))res=mid,r=mid-1;
        else l=mid+1;
    }
    write(res);
    return 0;
}
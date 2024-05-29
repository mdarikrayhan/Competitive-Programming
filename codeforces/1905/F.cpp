// LUOGU_RID: 160596113
#include <bits/stdc++.h>
#define F(i,x,y) for(int i=(x);i<=(y);i++)
#define DF(i,x,y) for(int i=(x);i>=(y);i--)
#define ms(x,y) memset(x,y,sizeof(x))
#define SZ(x) (int)x.size()-1
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T> void chkmax(T &x,T y){ x=max(x,y);}
template<typename T> void chkmin(T &x,T y){ x=min(x,y);}
template<typename T> void read(T &FF){
    FF=0;int RR=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') RR=-1;
    for(;isdigit(ch);ch=getchar()) FF=(FF<<1)+(FF<<3)+ch-48;
    FF*=RR;
}
const int N=200010,inf=1e9;
int n,a[N];
int st[N],pl[N],pr[N];
map<pii,int> mp;
#define fi first
#define se second
int pre[N],suf[N],premx[N],sufmn[N];
void work(){
    mp.clear();
    read(n);
    F(i,1,n) read(a[i]);
    int mx1=0,mx2=0,pmx=0;
    F(i,1,n) if(a[i]!=i) st[i]=1;
    F(i,1,n){
        if(a[i]==i){
            if(a[i]>mx1) st[i]=0;
            else if(a[i]<mx2) st[i]=1;
            else st[i]=2,pl[i]=pmx;
        }
        if(a[i]>mx1) mx2=mx1,mx1=a[i],pmx=i;
        else chkmax(mx2,a[i]);
    }
    int mn1=inf,mn2=inf,pmn=0;
    DF(i,n,1){
        if(a[i]==i){
            if(a[i]<mn1) st[i]=0;
            else if(a[i]>mn2) st[i]=1;
            else st[i]=2,pr[i]=pmn;
        }
        if(a[i]<mn1) mn2=mn1,mn1=a[i],pmn=i;
        else chkmin(mn2,a[i]);
    }
    F(i,1,n){ pre[i]=pre[i-1];if(!st[i]) pre[i]++;}
    suf[n+1]=0;
    DF(i,n,1){ suf[i]=suf[i+1];if(!st[i]) suf[i]++;}
    F(i,1,n) premx[i]=max(premx[i-1],a[i]);
    sufmn[n+1]=inf;
    DF(i,n,1) sufmn[i]=min(sufmn[i+1],a[i]);
    int ans=pre[n]-2;
    F(i,1,n){
        int l=i,r=a[i];
        if(l==r) continue;
        if(l>r) swap(l,r);
        bool fl1=(a[r]==l&&premx[l-1]<l);
        bool fl2=(a[l]==r&&sufmn[r+1]>r);
        chkmax(ans,pre[l-1]+suf[r+1]+fl1+fl2);
    }
    F(i,1,n) if(st[i]==2) mp[{pl[i],pr[i]}]++;
    for(auto it:mp){
        int l=it.fi.fi,r=it.fi.se,cnt=it.se;
        bool fl1=(a[r]==l&&premx[l-1]<l);
        bool fl2=(a[l]==r&&sufmn[r+1]>r);
        chkmax(ans,pre[l-1]+suf[r+1]+cnt+fl1+fl2);
    }
    printf("%d\n",ans);
}
int main(){
    int T;read(T);
    while(T--) work();
    return 0;
}

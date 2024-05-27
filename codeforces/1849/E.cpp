#include<bits/stdc++.h>
#define int long long
//#define int __int128
#define ll long long
#define pa pair<int,int>
//#define int unsigned long long
//const int mod=1e9+7;
//const int mod=1e7+7;
//const int mod=1e9+9;
const int mod=998244353;
#define sg signed
#define fi first
#define se second
#define ls s[x][0]
#define rs s[x][1]
#define ld long double
#define bs basic_string
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
        s=s*10+ch-'0',ch=getchar();
    return s*w;
}
int n,p[1000005],pre[1000005],nxt[1000005];
int pr[1000005],nx[1000005];
int sta[1000005],tp;
int sum[4000005];
int lz[4000005];
void pd(int x,int l,int r){
	if(lz[x]==-1)return;
	lz[x*2]=lz[x*2+1]=lz[x];
	int mid=(l+r)>>1;
	sum[x*2]=(mid-l+1)*lz[x];
	sum[x*2+1]=(r-mid)*lz[x];
	lz[x]=-1;
}
void up(int x){
	sum[x]=sum[x*2]+sum[x*2+1];
}
void change(int x,int l,int r,int L,int R,int val){
	if(L>R)return;
	if(l>=L&&r<=R){
		lz[x]=val;
		sum[x]=(r-l+1)*val;
		return;
	}
	pd(x,l,r);
	int mid=(l+r)>>1;
	if(mid>=L)change(x*2,l,mid,L,R,val);
	if(mid+1<=R)change(x*2+1,mid+1,r,L,R,val);
	up(x);
}
signed main(){
	memset(lz,-1,sizeof(lz));
	n=read();
	for(int i=1;i<=n;i++)p[i]=read();
	int ans=0;
	for(int i=n;i>=1;i--){
		while(tp&&p[sta[tp]]>p[i])pre[sta[tp--]]=i;
		sta[++tp]=i;
	}
	tp=0;
	for(int i=1;i<=n;i++){
		while(tp&&p[sta[tp]]>p[i])nxt[sta[tp--]]=i;
		sta[++tp]=i;
	}
	tp=0;
	for(int i=1;i<=n;i++){
		while(tp&&p[sta[tp]]<p[i])nx[sta[tp--]]=i;
		sta[++tp]=i;
	}
	tp=0;
	for(int i=n;i>=1;i--){
		while(tp&&p[sta[tp]]<p[i])pr[sta[tp--]]=i;
		sta[++tp]=i;
	}
	for(int i=1;i<=n;i++){
		change(1,1,n,pr[i]+1,i-1,1);
		change(1,1,n,pre[i]+1,i-1,0);
//		cout<<i<<" "<<pre[i]<<" "<<pr[i]<<endl;
		ans+=sum[1];
	}
	cout<<ans;
    return 0;
}
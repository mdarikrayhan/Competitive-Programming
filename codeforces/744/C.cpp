// LUOGU_RID: 160258848
//From: ifffer_2137
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7fffffff
#define eb emplace_back
#define pii pair<int,int>
#define mkpr make_pair
#define fir first
#define sec second
mt19937 rnd(time(NULL));
inline int read(){
    char ch=getchar();int x=0,w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48,ch=getchar();return w==1?x:-x;
}
const int maxn=20;
int n,ans;
struct node{
	int op;
	int r,b;
}a[maxn],t[maxn];
int calc(){
	int cr=0,cb=0,sr=0,sb=0,tot=0;
	for(int i=1;i<=n;i++){
		int k=max(max(0ll,a[i].r-sr-cr),max(0ll,a[i].b-sb-cb));
		cr+=k-max(0ll,a[i].r-sr);cb+=k-max(0ll,a[i].b-sb);tot+=k;
		if(a[i].op==1) sr++;
		else sb++;
	}
	return tot+n;
}
void SA(){
	for(double T=1000.0;T>1e-3;T*=0.9999){
		int res=calc(),swp=n*T/1000.0+1;
		memcpy(t,a,sizeof(t));
		while(swp--) swap(a[rnd()%n+1],a[rnd()%n+1]);
		int nw=calc(),dlt=res-nw; ans=min(ans,min(res,nw));
		if(dlt>0||rnd()%RAND_MAX+1<exp(1.0*dlt/T)*RAND_MAX) continue;
		memcpy(a,t,sizeof(a));
	}
}
signed main(){
	cin.tie(0),cout.tie(0);
	n=read();
	for(int i=n;i>=1;i--){
		char c;cin>>c;
		if(c=='R') a[i].op=1;
		else a[i].op=2;
		a[i].r=read(),a[i].b=read();
	}
	ans=inf;
	for(int i=1;i<=5;i++) SA();
	cout<<ans<<endl;
	return 0;
}
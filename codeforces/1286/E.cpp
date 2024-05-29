// LUOGU_RID: 160542385
#include<iostream>
#include<map>
#include<cstring>
#define Int __int128
// #define Int long long
using namespace std;
const int N=6e5+5,C=26,INF=0x3f3f3f3f;
int n,nxt[N],a[N],s[N],to[N][C];
Int ans,Now;
map<int,int>S;
inline void write(Int x){
	int st[35],top=0;
	do{st[++top]=x%10,x/=10;}while(x);
	while(top) putchar(st[top--]+'0');
	putchar('\n');
}
namespace ST{
	#define k1 (k<<1)
	#define k2 (k<<1|1)
	#define mid ((l+r)>>1)
	int mn[N<<2];
	inline void change(int x,int v,int k=1,int l=1,int r=n){
		if(l==r) return mn[k]=v,void();
		if(x<=mid) change(x,v,k1,l,mid);
		else change(x,v,k2,mid+1,r);
		mn[k]=min(mn[k1],mn[k2]);
	}
	inline int ask(int L,int R,int k=1,int l=1,int r=n){
		if(L<=l&&R>=r) return mn[k];
		if(R<=mid) return ask(L,R,k1,l,mid);
		if(L>mid) return ask(L,R,k2,mid+1,r);
		return min(ask(L,R,k1,l,mid),ask(L,R,k2,mid+1,r));
	}
}using namespace ST;
char c;
#define fi first
#define se second
inline void ins(int val,int cnt){S[val]+=cnt,Now+=1ll*val*cnt;}
inline void calc(int x){
	int cnt=0;
	for(auto it=S.upper_bound(x);it!=S.end();it=S.erase(it)) 
		cnt+=it->se,Now-=1ll*it->fi*it->se;
	ins(x,cnt);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1,j=0,w;i<=n;++i){
		cin>>c>>w,s[i]=(c-'a'+ans)%26,a[i]=w^(ans%(1<<30));
		change(i,a[i]),ans+=ask(1,i);
		if(i==1){write(ans);continue;}
		while(j&&s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1]) ++j;
		nxt[i]=j;
		memcpy(to[i],to[nxt[i]],sizeof to[i]),to[i][s[nxt[i]+1]]=nxt[i];
		if(s[i]==s[1]) ins(a[i],1);
		for(int v=0;v<C;++v)
			if(v!=s[i]) for(int x=to[i-1][v];x;x=to[x][v]) ins(ask((i-1)-x+1,i-1),-1);
		calc(a[i]),write(ans+=Now);
	}
}
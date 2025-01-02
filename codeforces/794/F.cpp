// LUOGU_RID: 158159934
//From: ifffer_2137
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7fffffff
#define pii pair<int,int>
#define mkpr make_pair
#define fir first
#define sec second
inline int read(){
    char ch=getchar();int x=0,w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48,ch=getchar();return w==1?x:-x;
}
const int maxn=1e5+5;
int n,q;
int a[maxn];
struct Segment_Tree{
	int sumv[maxn*4][10],tag[maxn*4][10];
	int ss[2][10],st[2][10];
	void pushup(int o){
		for(int i=0;i<=9;i++){
			sumv[o][i]=sumv[o*2][i]+sumv[o*2+1][i];
		}
	}
	void pushdown(int o){
		for(int i=0;i<=9;i++){
			ss[0][i]=sumv[o*2][i];
			ss[1][i]=sumv[o*2+1][i];
			st[0][i]=tag[o*2][i];
			st[1][i]=tag[o*2+1][i];
		}
		for(int i=0;i<=9;i++){
			if(tag[o][i]==i) continue;
			sumv[o*2][tag[o][i]]+=ss[0][i],sumv[o*2][i]-=ss[0][i];
			for(int j=0;j<=9;j++) if(st[0][j]==i) tag[o*2][j]=tag[o][i];
			sumv[o*2+1][tag[o][i]]+=ss[1][i],sumv[o*2+1][i]-=ss[1][i];
			for(int j=0;j<=9;j++) if(st[1][j]==i) tag[o*2+1][j]=tag[o][i];
			tag[o][i]=i;
		}
	}
	void build(int o,int l,int r){
		for(int i=0;i<=9;i++){
			tag[o][i]=i;
		}
		if(l==r){
			int v=a[l],b=1;
			while(v){
				sumv[o][v%10]+=b;
				v/=10;b*=10;
			}
			return;
		}
		int m=(l+r)/2;
		build(o*2,l,m);
		build(o*2+1,m+1,r);
		pushup(o);
	}
	void update(int o,int l,int r,int x,int y,int k,int t){
		if(x<=l&&r<=y){
			sumv[o][t]+=sumv[o][k];
			sumv[o][k]=0;
			for(int i=0;i<=9;i++) if(tag[o][i]==k) tag[o][i]=t;
			return;
		}
		pushdown(o);
		int m=(l+r)/2;
		if(x<=m) update(o*2,l,m,x,y,k,t);
		if(y>m) update(o*2+1,m+1,r,x,y,k,t);
		pushup(o);
	}
	int query(int o,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			int res=0;
			for(int i=0;i<=9;i++){
				res+=sumv[o][i]*i;
			}
			return res;
		}
		pushdown(o);
		int m=(l+r)/2,res=0;
		if(x<=m) res+=query(o*2,l,m,x,y);
		if(y>m) res+=query(o*2+1,m+1,r,x,y);
		return res;
	}
}seg;
signed main(){
	cin.tie(0),cout.tie(0);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	seg.build(1,1,n);
	while(q--){
		int op=read();
		if(op==1){
			int l=read(),r=read(),x=read(),y=read();
			if(x==y) continue;
			seg.update(1,1,n,l,r,x,y);
		}else{
			int l=read(),r=read();
			cout<<seg.query(1,1,n,l,r)<<endl;
		}
	}
	return 0;
}
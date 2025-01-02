// LUOGU_RID: 159813165
#include<bits/stdc++.h>
#define MAXN 100005
#define ls ch[x][0]
#define rs ch[x][1]
using namespace std;

inline int read(){
    int x=0;
    char c=getchar();
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}

int n,m;
int fa[MAXN],ch[MAXN][3],rv[MAXN],id[MAXN];
long long val[MAXN],mx[MAXN];
stack<int> st;
struct node{
	int u,v;
	long long w1,w2;
}E[MAXN];
long long g,s;
multiset<long long> mw;

bool cmp(node aa,node bb){
	if(aa.w2==bb.w2) return aa.w1<bb.w1;
	return aa.w2<bb.w2;
}

bool notrt(int x){
	return ch[fa[x]][0]==x || ch[fa[x]][1]==x;
}

void pushup(int x){
	mx[x]=val[x];
	id[x]=x;
	if(mx[ls]>mx[x]){
		mx[x]=mx[ls];
		id[x]=id[ls];
	}
	if(mx[rs]>mx[x]){
		mx[x]=mx[rs];
		id[x]=id[rs];
	}
//	printf("%d %d %d %d %d %d %d %d\n",x,ls,rs,mx[x],id[x],val[x],mx[ls],mx[rs]);
}

void makerv(int x){
	rv[x]^=1;
	swap(ls,rs);
}

void pushdown(int x){
	if(rv[x]){
		if(ls) makerv(ls);
		if(rs) makerv(rs);
		rv[x]=0;
	}
} 

void pushdn(int x){
	while(!st.empty()) st.pop();
	st.push(x);
	while(notrt(x)){
		x=fa[x];
		st.push(x);
	}
	while(!st.empty()){
		pushdown(st.top());
		st.pop();
	}
}

void rotate(int x){
	int y=fa[x],z=fa[y];
	int k=(ch[y][1]==x);
	int w=ch[x][k^1];
	if(notrt(y)) ch[z][ch[z][1]==y]=x;
	fa[x]=z;
	fa[fa[ch[ch[x][k^1]=y][k]=w]=y]=x;
	pushup(y);
	pushup(x);
}

void splay(int x){
	pushdn(x);
	while(notrt(x)){
		int y=fa[x],z=fa[y];
		if(notrt(y)){
			if((ch[y][1]==x) == (ch[z][1]==y)) rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
}

void access(int x){
	for(int y=0;x;y=x,x=fa[x]){
		splay(x);
		ch[x][1]=y;
		pushup(x);
	}
}

void makeroot(int x){
	access(x);
	splay(x);
	makerv(x);
}

int findroot(int x){
	access(x);
	splay(x);
	while(ls){
		pushdown(x);
		x=ls;
	}
	splay(x);
	return x;
}

void split(int x,int y){
	makeroot(x);
	access(y);
	splay(y);
}

void link(int x,int y){
	makeroot(x);
	if(findroot(y)!=x) fa[x]=y;
	pushup(y);
}

void cut(int x,int y){
	split(x,y);
	if(ch[y][0]!=x || ch[y][1]) return;
	ch[y][0]=fa[x]=0;
	pushup(y);
}

bool check(int x,int y){
	makeroot(x);
	if(findroot(y)==x) return true;
	else return false;
}

int main(){
	n=read();m=read();
	g=read();s=read();
	for(int i=1;i<=m;i++){
		E[i].u=read();E[i].v=read();
		E[i].w1=read();E[i].w2=read();
	}
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=m;i++){
		val[n+i]=E[i].w1;
	} 
	int cnt=0,p=0;
	long long ans=2e18;
	for(int i=1;i<=m;i++){
		int u=E[i].u;
		int v=E[i].v;
		long long w=E[i].w1;
		if(u==v) continue;
		if(!check(u,v)){
			link(u,n+i);
			link(n+i,v);
			mw.insert(w);
			cnt++;
		}else{
			split(u,v);
			int x=id[v];
			long long mxx=mx[v];
			if(mxx<=w) continue;
			splay(x);
			fa[ls]=fa[rs]=0;
			mw.erase(mw.find(mxx));
			link(u,n+i);
			link(n+i,v);
			mw.insert(w);
		}
		if(cnt==n-1){
			auto it=mw.end();
			it--;
			ans=min(ans,*it*g+E[i].w2*s);
		}
	}
	if(cnt<n-1) ans=-1;
	printf("%lld",ans);
	return 0;
}
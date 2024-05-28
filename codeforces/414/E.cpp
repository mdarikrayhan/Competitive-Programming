// LUOGU_RID: 156701093
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
int n,q;
int ord[200005],in[100005],out[100005],dep[100005];
namespace sp{
	int nd,root;
#define getson(x) (x==a[a[x].f].so[1])
	struct node{
		int so[2],f,s,d,mi,ma,sz;
		int tg;
	}a[200005];
	void pushdown(int c){
		if(!a[c].tg||!c)return;
		if(a[c].so[0])a[a[c].so[0]].tg+=a[c].tg,a[a[c].so[0]].d+=a[c].tg,a[a[c].so[0]].mi+=a[c].tg,a[a[c].so[0]].ma+=a[c].tg;
		if(a[c].so[1])a[a[c].so[1]].tg+=a[c].tg,a[a[c].so[1]].d+=a[c].tg,a[a[c].so[1]].mi+=a[c].tg,a[a[c].so[1]].ma+=a[c].tg;
		a[c].tg=0;
	}
	void pushup(int c){
		a[c].sz=a[a[c].so[0]].sz+a[a[c].so[1]].sz+1;
		a[c].ma=max({a[a[c].so[0]].ma,a[a[c].so[1]].ma,a[c].d});
		a[c].mi=min({a[a[c].so[0]].mi,a[a[c].so[1]].mi,a[c].d});
	}
	void work(int c){
		if(!c)return;
		pushdown(c);
		work(a[c].so[0]);
		work(a[c].so[1]);
		pushup(c);
	}
	void inorder(int c){
		if(!c)return;
		inorder(a[c].so[0]);
		cout<<"("<<c<<":"<<a[c].d<<","<<a[c].s<<","<<a[c].tg<<","<<a[c].sz<<')';
		inorder(a[c].so[1]);
	}
	int newnode(int f,int s){
		++nd,a[nd].f=f,a[nd].s=s,a[nd].sz=1;
		a[nd].d=a[nd].mi=a[nd].ma=dep[s];
		return nd;
	}
	void rotate(int c){
		int f=a[c].f,g=a[f].f;
		pushdown(g),pushdown(f),pushdown(c);
		bool p=getson(c);
		if(g)a[g].so[getson(f)]=c;
		a[f].so[p]=a[c].so[p^1];
		if(a[c].so[p^1])a[a[c].so[p^1]].f=f;
		a[c].so[p^1]=f,a[f].f=c,a[c].f=g;
		pushup(f),pushup(c);
	}
	void splay(int c,int tar=0){
		for(int f=a[c].f;f!=tar;rotate(c),f=a[c].f)
			if(a[f].f!=tar)rotate(getson(c)==getson(f)?f:c);
		if(!tar)root=c;
	}
	int ne(int c){
		splay(c);
		c=a[c].so[1];assert(c);
		while(a[c].so[0])c=a[c].so[0];
		return c;
	}
	int pr(int c){
		splay(c);
		c=a[c].so[0];assert(c);
		while(a[c].so[1])c=a[c].so[1];
		return c;
	}
	int find(int c,int k){
		pushdown(c);
		if(a[c].so[1]&&a[a[c].so[1]].ma>=k&&a[a[c].so[1]].mi<=k)return find(a[c].so[1],k);
		if(a[c].d==k)return c;
		return find(a[c].so[0],k);
	}
}
namespace ma{
	int x,y,dfn;
	vector<int> t[100005];
	void dfs(int c,int f){
		++dfn,ord[dfn]=c,in[c]=dfn;
		for(auto i:t[c])
			dep[i]=dep[c]+1,dfs(i,c);
		++dfn,ord[dfn]=c,out[c]=dfn;
	}
	void work(){
		cin>>n>>q;
		for(int i=1;i<=n;++i){
			cin>>x;
			t[i].resize(x);
			for(int j=0;j<x;++j)cin>>t[i][j];
		}
		dfs(1,0);
	}
} 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	ma::work();
	using namespace sp;
	a[0].ma=-2147483647,a[0].mi=2147483647;
	root=newnode(0,ord[1]);
	for(int i=2;i<=n*2;++i)
		a[root].so[1]=newnode(root,ord[i]),a[nd].f=root,splay(nd);
	int k,x,y,c,d,P,N,s;
	while(q--){
		cin>>k;
		if(k==1){
			cin>>x>>y;
			splay(out[x]),splay(in[y],out[x]);
			if(in[y]!=a[out[x]].so[1]){
				swap(x,y);
				splay(out[x]),splay(in[y],out[x]);
			}
			c=a[in[y]].so[0];
			if(in[y]!=a[out[x]].so[1])cout<<abs(a[out[x]].d-a[in[y]].d)<<'\n';
			else if(!c)cout<<2<<'\n';
			else cout<<a[out[x]].d+a[in[y]].d-2*a[c].mi+2<<'\n';
		}
		if(k==2){
			cin>>x>>y;
			splay(in[x]);
			d=a[in[x]].d;
			P=pr(in[x]),N=ne(out[x]),splay(P),splay(N,P);
			splay(in[x],N);
			c=a[N].so[0],a[c].f=0,a[N].so[0]=0,pushdown(c);
			P=a[root].so[1],a[P].f=a[root].so[1]=0;
			y=a[find(root,d-y)].s;
			if(P)a[P].f=root,a[root].so[1]=P;
			d=pr(out[y]),splay(d),splay(out[y],d);
			a[c].f=out[y],a[out[y]].so[0]=c;
			a[c].tg=a[out[y]].d+1-a[c].d,a[c].ma+=a[c].tg,a[c].mi+=a[c].tg,a[c].d=a[out[y]].d+1;
			splay(c);
		}
		if(k==3){
			cin>>y;
			c=a[find(root,y)].s;
			cout<<c<<'\n';
		}
	}
	return 0;
}
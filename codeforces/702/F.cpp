#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int n,m,rt;
struct node{int q,c;}a[200005];
bool operator<(node a,node b){if(a.q==b.q)return a.c<b.c;return a.q>b.q;}
struct Node{int son[2],key,val,ct,tg,tg1;}t[200005];
#define ls(p) t[p].son[0]
#define rs(p) t[p].son[1]
#define key(p) t[p].key
#define ct(p) t[p].ct
#define val(p) t[p].val
#define tg(p) t[p].tg
#define tg1(p) t[p].tg1
void Add(int p,int v){if(!p)return;tg(p)+=v,val(p)+=v;}
void Add1(int p,int v){if(!p)return;tg1(p)+=v,ct(p)+=v;}
void pd(int p){
	if(tg(p))Add(ls(p),tg(p)),Add(rs(p),tg(p)),tg(p)=0;
	if(tg1(p))Add1(ls(p),tg1(p)),Add1(rs(p),tg1(p)),tg1(p)=0;
}
void split(int p,int &x,int &y,int v){
	if(!p){x=y=0;return;}pd(p);
	if(val(p)<=v)x=p,split(rs(p),rs(x),y,v);
	else y=p,split(ls(p),x,ls(y),v);
}
int merge(int u,int v){
	if(!u||!v)return (u|v);
    if(key(u)<key(v)){rs(u)=merge(rs(u),v);return u;}
    else {ls(v)=merge(u,ls(v));return v;}
}
int Id;
void Ins(int p){
	if(!p)return;pd(p);
	int a=ls(p),b=rs(p),x,y;ls(p)=rs(p)=0;
	split(Id,x,y,val(p));Id=merge(x,p),Id=merge(Id,y);
    Ins(a),Ins(b);
}
void dfs(int p){
	if(!p)return;pd(p);
	dfs(ls(p)),dfs(rs(p));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].c,&a[i].q);
	sort(a+1,a+n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d",&val(i));
		key(i)=rnd();
		int a,b;split(rt,a,b,val(i));
		rt=merge(a,i),rt=merge(rt,b);
	}
	for(int i=1;i<=n;++i){
		int x,y,z;
		split(rt,x,y,a[i].c-1);
		Add(y,-a[i].c),Add1(y,1);
		split(y,y,z,a[i].c-1),Id=x;
		Ins(y),x=Id,rt=merge(x,z);
	}dfs(rt);
	for(int i=1;i<=m;++i)printf("%d ",ct(i));
	return 0;
} 
	 		 	     	  		 				  	 	 			
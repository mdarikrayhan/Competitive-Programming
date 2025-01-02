#include<bits/stdc++.h>
using namespace std;
#define lc c[0][p]
#define rc c[1][p]
const int S=55555;
int c[2][S],f[S],n,m,tf[S];long long w[S],iw[S],as[S],a[S],iss[S],is[S],s[S];char o[3];
void up(int p){
	s[p]=is[p]+s[lc]+s[rc], as[p]=as[lc]+as[rc]+a[p]*is[p],
	w[p]=w[lc]+w[rc]+iw[p]+ a[p]*(is[p]*is[p]-iss[p]) + 2*a[p]*s[rc]*is[p] + 2*as[lc]*(s[p]-s[lc]);
}
bool nr(int p){return c[0][f[p]]==p||c[1][f[p]]==p;}
void spin(int p){
	int F=f[p],G=f[F],d=c[1][F]==p,B=c[!d][p];
	if(nr(F))c[c[1][G]==F][G]=p; c[d][F]=B; c[!d][p]=F;
	f[f[f[B]=F]=p]=G; up(F); up(p);
}
void ctb(int p,int r=1){iw[f[p]]+=r*w[p];iss[f[p]]+=r*s[p]*s[p];is[f[p]]+=r*s[p];}
void splay(int p){for(;nr(p);spin(p));up(p);}
void access(int r){for(int y=0,p=r;p;p=f[y=p])splay(p),ctb(rc),ctb(y,-1),rc=y,up(p);splay(r);}
void link(int a,int b){access(b);access(a);f[b]=a;ctb(b);up(a);}
void cut(int p){access(p);f[lc]=0;lc=0;up(p);}
bool chk(int a,int b){access(a);splay(b);return nr(a);}
void Ans(){access(1);printf("%.9lf\n",(double)w[1]/n/n);}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i)scanf("%d",&tf[i]);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),s[i]=is[i]=1,w[i]=as[i]=a[i];
	for(int i=2;i<=n;++i)link(tf[i],i);
	Ans(); scanf("%d",&m);
	for(int _=1,x,y;_<=m;++_,Ans()){
		scanf("%s%d%d",o,&x,&y);
		if(o[0]=='V')access(x),a[x]=y,up(x);
		else if(chk(y,x))cut(y),link(x,y);
		else cut(x),link(y,x);
	}
}
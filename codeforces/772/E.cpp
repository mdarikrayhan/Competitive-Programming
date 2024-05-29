#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=5e3+3; 
int sz,mn,o,rt,s[N],s2[N],fa[N],ch[N][2],lf[N],cnt; 
bool vis[N];
void findrt(int u){
	if (vis[u]){ s[u]=0; return; }
	int mx;
	if (ch[u][0]){
		int x=ch[u][0],y=ch[u][1]; findrt(x),findrt(y);
		s[u]=s[x]+s[y]+1,mx=max(s2[u]=sz-s[u],max(s[x],s[y]));
	}
	else s[u]=1,mx=s2[u]=sz-s[u];
	if (mx<mn) mn=mx,o=u;
}
void lk(int f,int c,int x){ ch[fa[x]=f][c]=x; }
void solve(int u,int f,int c,int nd){
	vis[u]=true; char str[5];
	int x=ch[u][0],y=ch[u][1];
	if (x){
		printf("%d %d %d\n",lf[x],lf[y],nd);
		fflush(stdout),scanf("%s",str);
	}
	if (!x||str[0]=='X'){
		if (!fa[u]||vis[fa[u]]){
			if (!fa[u]) rt=++cnt; else lk(fa[u],c,++cnt);
			lk(cnt,0,u),lk(cnt,1,nd),lf[cnt]=lf[nd]=nd;
			return;
		}
		sz=mn=s2[u],findrt(f?ch[f][c]:rt),solve(o,f,c,nd); 
	}
	else{
		int t=str[0]=='Y',x=ch[u][t];
		if (vis[x]){
			lk(++cnt,0,x),lk(cnt,1,nd),lk(u,t,cnt),lf[cnt]=lf[nd]=nd;
			return;
		}
		sz=mn=s[x],findrt(x),solve(o,u,t,nd);
	}
}
int main(){
	srand(time(0));
	int n; scanf("%d",&n); cnt=n;
	lk(rt=++cnt,0,1),lk(rt,1,2),lf[1]=lf[rt]=1,lf[2]=2;
	rep(i,3,n){
		memset(vis,0,sizeof(vis));
		sz=mn=2*(i-1)-1,findrt(rt),solve(o,0,0,i);
	}
	puts("-1"); rep(i,1,cnt) printf("%d ",fa[i]?fa[i]:-1);
	fflush(stdout); return 0;
}
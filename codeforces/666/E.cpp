#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int maxn=2e5+5,Maxn=5e5+5;
int n,m,q,nxt[maxn][27],up[maxn][20],dep[maxn],fail[maxn],ct[maxn],len[maxn],tot=1,lst=1,rt=1;
int ql[Maxn],qr[Maxn],tl[Maxn],tr[Maxn];
vector<int>son[maxn],vec[maxn];pii res[500005];
void ins(int ch,int col){
	int np=++tot,p=lst,nq;
	if(col)vec[np].pb(col);
	len[np]=len[p]+1,ct[np]=1,lst=np;
	for(;p&&!nxt[p][ch];p=fail[p])nxt[p][ch]=np;nq=nxt[p][ch];
	if(!p)fail[np]=rt;
	else if(len[nq]==len[p]+1)fail[np]=nq;
	else{
		int New=++tot;for(int i=0;i<27;++i)nxt[New][i]=nxt[nq][i];
		fail[New]=fail[nq],len[New]=len[p]+1,fail[nq]=fail[np]=New;
		for(;p&&nxt[p][ch]==nq;p=fail[p])nxt[p][ch]=New;
	}
}
void dfs(int u){
	up[u][0]=fail[u];
	for(int i=1;(1<<i)<=dep[u];++i)up[u][i]=up[up[u][i-1]][i-1];
	for(int v:son[u])dep[v]=dep[u]+1,dfs(v);
}
void bd(){
	for(int i=2;i<=tot;++i)son[fail[i]].pb(i);
	dfs(rt);
}
char s[Maxn],t[50050];
vector<int>que[Maxn],Ins[maxn];
int Rt[maxn*20],Son[maxn*20][2],tt;pii mx[maxn*20];
#define ls(p) Son[p][0]
#define rs(p) Son[p][1]
#define mid (l+r>>1) 
void pp(int p){
    mx[p].fi=mx[p].se=0;
    if(ls(p))mx[p]=max(mx[p],mx[ls(p)]);
    if(rs(p))mx[p]=max(mx[p],mx[rs(p)]);
}
void add(int &p,int l,int r,int pos){
	if(!p)p=++tt;
	if(l==r){++mx[p].fi;mx[p].se=-pos;return;}
	if(pos<=mid)add(ls(p),l,mid,pos);
	else add(rs(p),mid+1,r,pos);pp(p);
}
int merge(int u,int v,int l,int r){
	if(!u||!v)return (u|v);
	if(l==r){
		mx[u].fi+=mx[v].fi;
		return u;
	}
	ls(u)=merge(ls(u),ls(v),l,mid);
	rs(u)=merge(rs(u),rs(v),mid+1,r);
	pp(u);return u;
}
pii qry(int p,int l,int r,int a,int b){
	if(!p)return mp(0,0);
	if(a<=l&&r<=b)return mx[p];pii ans=mp(0,0);
	if(a<=mid)ans=max(ans,qry(ls(p),l,mid,a,b));
	if(b>mid)ans=max(ans,qry(rs(p),mid+1,r,a,b));
	return ans;
}
void calc(int u){
	for(int v:vec[u])add(Rt[u],1,m,v);
	for(int v:son[u])calc(v),Rt[u]=merge(Rt[u],Rt[v],1,m);
	for(int v:Ins[u]){
		pii Ans=qry(Rt[u],1,m,tl[v],tr[v]);Ans.se=-Ans.se;
		if(!Ans.fi)Ans.se=tl[v];
		res[v]=Ans;
	}
}
int main(){
	scanf("%s",s+1),n=strlen(s+1),cin>>m;
	for(int i=1;i<=m;++i){
		scanf("%s",t+1);int len=strlen(t+1);
		for(int j=1;j<=len;++j)ins((int)(t[j]-'a'),i);
		ins(26,0);
	}bd(),cin>>q;
	for(int i=1;i<=q;++i)scanf("%d%d%d%d",&tl[i],&tr[i],&ql[i],&qr[i]),que[qr[i]].pb(i);
	int now=rt,len1=0;
	for(int i=1;i<=n;++i){
		int ch=(int)(s[i]-'a');
		while(now>rt&&!nxt[now][ch])now=fail[now],len1=len[now];
		if(nxt[now][ch])now=nxt[now][ch],++len1;
		for(int v:que[i]){
			int p=now;
			for(int i=19;i>=0;--i)if(up[p][i]&&len[up[p][i]]>=qr[v]-ql[v]+1)p=up[p][i];
			if(len1>=qr[v]-ql[v]+1)Ins[p].pb(v);
			else res[v].se=tl[v],res[v].fi=0;
		}
	}calc(rt);
	for(int i=1;i<=q;++i)printf("%d %d\n",res[i].se,res[i].fi);
	return 0;
}
 	 		 	 			  	   		 					 				
// LUOGU_RID: 160011026
#include"bits/stdc++.h"
using namespace std;
#pragma GCC optimize(2)
const int maxn = 2010;
#define pI pair<int,int>
int n,X[maxn],Y[maxn],Xt[maxn],Tx,Yt[maxn],Ty;
pI Xp[maxn][maxn],Xs[maxn][maxn],Yp[maxn][maxn],Ys[maxn][maxn];
int f[maxn],Sz[maxn],Cc;
int ff(int x){return f[x]==x?x:f[x]=ff(f[x]);}
void Merge(int u,int v){
	if((u=ff(u))==(v=ff(v)))return;
	if(Sz[u]>Sz[v])swap(u,v);
	f[u]=v,Sz[v]+=(Sz[v]==Sz[u]),Cc--;
}
inline bool E(pI x){return x==make_pair(0,0);}
int Vs[maxn],O[maxn],Tp,K;
inline bool GPT(int Xl,int Yl,int Ln){
	Tp=K=0;
	if(!E(Xp[Xl][Yl])&&abs(Yt[Xp[Xl][Yl].first]-Yt[Yl])<=Ln)O[++Tp]=ff(Xp[Xl][Yl].second);
	if(!E(Xs[Xl][Yl])&&abs(Yt[Xs[Xl][Yl].first]-Yt[Yl])<=Ln)O[++Tp]=ff(Xs[Xl][Yl].second);
	if(!E(Yp[Xl][Yl])&&abs(Xt[Yp[Xl][Yl].first]-Xt[Xl])<=Ln)O[++Tp]=ff(Yp[Xl][Yl].second);
	if(!E(Ys[Xl][Yl])&&abs(Xt[Ys[Xl][Yl].first]-Xt[Xl])<=Ln)O[++Tp]=ff(Ys[Xl][Yl].second);
	for(int i=1;i<=Tp;i++)if(!Vs[O[i]])Vs[O[i]]=1,K++;
	for(int i=1;i<=Tp;i++)Vs[O[i]]=0;
	return K==Cc;
}
bool Chk(int Ln){
	for(int i=1;i<=n;i++)f[i]=i,Sz[i]=1,Cc=n;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(X[i]==X[j]&&abs(Yt[Y[i]]-Yt[Y[j]])<=Ln)Merge(i,j);
			if(Y[i]==Y[j]&&abs(Xt[X[i]]-Xt[X[j]])<=Ln)Merge(i,j);
		}
	if(Cc==1)return 1;
	if(Cc==2)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(ff(i)^ff(j));else continue;
				if(X[i]==X[j]&&abs(Yt[Y[i]]-Yt[Y[j]])<=2ll*Ln)return 1;
				if(Y[i]==Y[j]&&abs(Xt[X[i]]-Xt[X[j]])<=2ll*Ln)return 1;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(GPT(X[i],Y[j],Ln))
				return 1;
	return 0;
}
inline pI G(pI x,pI o){return E(x)?o:x;}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>X[i]>>Y[i],Xt[++Tx]=X[i],Yt[++Ty]=Y[i];
	sort(Xt+1,Xt+Tx+1),Tx=unique(Xt+1,Xt+Tx+1)-Xt-1,sort(Yt+1,Yt+Ty+1),Ty=unique(Yt+1,Yt+Ty+1)-Yt-1;
	for(int i=1;i<=n;i++)X[i]=lower_bound(Xt+1,Xt+Tx+1,X[i])-Xt,Y[i]=lower_bound(Yt+1,Yt+Ty+1,Y[i])-Yt;
	for(int i=1;i<=n;i++)Xs[X[i]][Y[i]]=Xp[X[i]][Y[i]]=make_pair(Y[i],i),Ys[X[i]][Y[i]]=Yp[X[i]][Y[i]]=make_pair(X[i],i);
	for(int Xl=1;Xl<=Tx;Xl++)for(int Yl=1;Yl<=Ty;Yl++)Xp[Xl][Yl]=G(Xp[Xl][Yl],Xp[Xl][Yl-1]),Yp[Xl][Yl]=G(Yp[Xl][Yl],Yp[Xl-1][Yl]);
	for(int Xl=Tx;Xl>=1;Xl--)for(int Yl=Ty;Yl>=1;Yl--)Xs[Xl][Yl]=G(Xs[Xl][Yl],Xs[Xl][Yl+1]),Ys[Xl][Yl]=G(Ys[Xl][Yl],Ys[Xl+1][Yl]);
	int L=1,R=2e9+7;
	while(L<R){int M=(1ll*L+R)>>1;if(Chk(M))R=M;else L=M+1;}
	if(R==2e9+7)cout<<-1<<endl;else cout<<(L&R)<<endl;
}
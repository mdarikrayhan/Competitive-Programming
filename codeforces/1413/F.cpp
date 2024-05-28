// LUOGU_RID: 160031442
#include"bits/stdc++.h"
using namespace std;
#define Sw for(int o=0;o<=1;o++)
const int maxn = 1000100;
const int Inf = 1e7;
int n,q,W,F[maxn];
struct Lnk{int u,v,w;}E[maxn];
struct L{int To,w;};
vector<L>e[maxn];
int Id[maxn],Tp,Fs[maxn],Ls[maxn],Dp[maxn],Ln[maxn];
struct Node{int Mx[2],Mn,Lm[2],Rm[2],Ans,T;}Tr[maxn<<2]; //Lm&Rm : Dp[x]-2*Dp[Lca]
void P(int x){
	Sw Tr[x].Mx[o]=max(Tr[x<<1].Mx[o],Tr[x<<1|1].Mx[o]);
	Tr[x].Mn=min(Tr[x<<1].Mn,Tr[x<<1|1].Mn);
	Sw Tr[x].Lm[o]=max(max(Tr[x<<1].Lm[o],Tr[x<<1|1].Lm[o]),Tr[x<<1].Mx[o]-2*Tr[x<<1|1].Mn);
	Sw Tr[x].Rm[o]=max(max(Tr[x<<1].Rm[o],Tr[x<<1|1].Rm[o]),Tr[x<<1|1].Mx[o]-2*Tr[x<<1].Mn);
	Tr[x].Ans=max(Tr[x<<1].Ans,Tr[x<<1|1].Ans);
	Sw Tr[x].Ans=max(Tr[x].Ans,max(Tr[x<<1].Mx[o]+Tr[x<<1|1].Rm[o],Tr[x<<1|1].Mx[o]+Tr[x<<1].Lm[o]));
}
void aT(int x){
	swap(Tr[x].Mx[0],Tr[x].Mx[1]);
	swap(Tr[x].Lm[0],Tr[x].Lm[1]);
	swap(Tr[x].Rm[0],Tr[x].Rm[1]);
	Tr[x].T^=1;
}
void Pd(int x){if(Tr[x].T)aT(x<<1),aT(x<<1|1),Tr[x].T=0;}
void Md(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return aT(x);
	int M=l+r>>1;Pd(x);
	if(ql<=M)Md(x<<1,l,M,ql,qr);
	if(qr>M)Md(x<<1|1,M+1,r,ql,qr);
	P(x);
}
void Bd(int x,int l,int r){
	if(l==r){
		Tr[x].Mx[Ln[Id[l]]]=Tr[x].Mn=Dp[Id[l]];
		Tr[x].Mx[Ln[Id[l]]^1]=-Inf;
		Tr[x].Lm[Ln[Id[l]]]=Tr[x].Rm[Ln[Id[l]]]=-Dp[Id[l]];
		Tr[x].Lm[Ln[Id[l]]^1]=Tr[x].Rm[Ln[Id[l]]^1]=-Inf;
	}else{
		int M=l+r>>1;
		Bd(x<<1,l,M),Bd(x<<1|1,M+1,r),P(x);	
	}
}
void Gen(int p,int Fa){
	Id[++Tp]=p,Fs[p]=Tp,F[p]=Fa;
	for(auto [To,w]:e[p]){
		if(To==Fa)continue;
		Dp[To]=Dp[p]+1,Ln[To]=Ln[p]^w;
		Gen(To,p),Id[++Tp]=p;
	}
	Ls[p]=Tp;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1,u,v,w;i<n;i++){
		cin>>u>>v>>w,E[i]={u,v,w};
		e[u].push_back({v,w}),e[v].push_back({u,w});
	}
	cin>>q;
	Gen(1,0),Bd(1,1,Tp);
	for(int i=1,Id;i<=q;i++){
		cin>>Id;
		int p=F[E[Id].u]==E[Id].v?E[Id].u:E[Id].v;
		Md(1,1,Tp,Fs[p],Ls[p]);
		cout<<Tr[1].Ans<<endl;
	}
}
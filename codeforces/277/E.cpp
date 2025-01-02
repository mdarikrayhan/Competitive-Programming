// LUOGU_RID: 159723848
#include"bits/stdc++.h"
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
const int maxn = 50010;
const int maxm = 162010;
int n,m,s,t,x[maxn],y[maxn];
int hd[maxn],e[maxm],ne[maxm],c[maxm],Idx;
double ew[maxm],dis[maxn];
int Is[maxn],Incf[maxn],P[maxn];
void add_edge(int u,int v,double W,int C){
	e[Idx]=v,ne[Idx]=hd[u],c[Idx]=C,ew[Idx]=W,hd[u]=Idx++;
	e[Idx]=u,ne[Idx]=hd[v],c[Idx]=0,ew[Idx]=-W,hd[v]=Idx++;
}
bool spfa(){
	memset(dis,0x7f,sizeof(dis));
	memset(Incf,0,sizeof(Incf));
	queue<int>q;
	q.push(s),dis[s]=0,Incf[s]=1e8,Is[s]=1;
	while(q.size()){
		int x=q.front();q.pop(),Is[x]=0;
		for(int i=hd[x];i!=-1;i=ne[i]){
			int to=e[i];
			if(dis[to]>dis[x]+ew[i]&&c[i]){
				dis[to]=dis[x]+ew[i];
				Incf[to]=min(Incf[x],c[i]);
				P[to]=i;
				if(Is[to]==0)q.push(to),Is[to]=1;
			}
		}
	}
	return Incf[t]>0;
}
double EK(){
	int Fl=0;
	double Cst=0;
	while(spfa()){
		Fl+=Incf[t],Cst+=Incf[t]*dis[t];
		for(int i=t;i!=s;i=e[P[i]^1])
			c[P[i]]-=Incf[t],c[P[i]^1]+=Incf[t];
	}
	if(Fl^n-1)return -1;
	else return Cst;
}
int main(){
	memset(hd,-1,sizeof(hd));
	cin>>n;
	s=2*n+1,t=2*n+2;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(y[j]>y[i])
				add_edge(j+n,i,sqrt((y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i])),1);
	for(int i=1;i<=n;i++)add_edge(s,i+n,0,2),add_edge(i,t,0,1);
	printf("%.10lf\n",EK());
}
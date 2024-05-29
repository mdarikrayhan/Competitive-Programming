// LUOGU_RID: 159722601
#include"bits/stdc++.h"
using namespace std;
#define double long double
const int maxn = 1600;
const double eps = 1e-10;
int n,T,r;
double f[maxn][maxn],g[maxn][maxn];
struct Node{
	int Se,Te,Sh,Th;
	double P,Q;
}p[maxn];
bool cmp(Node i,Node j){
	double A=i.Q*j.P*i.Th+j.Q*(i.Th+j.Th);
	double B=j.Q*i.P*j.Th+i.Q*(i.Th+j.Th);
	return A<B;
}
int main(){
	cin>>n>>T;
	for(int i=1;i<=n;i++)cin>>p[i].Se>>p[i].Sh>>p[i].Te>>p[i].Th>>p[i].P,p[i].Q=1.0-p[i].P;
	sort(p+1,p+n+1,cmp);
	memset(f,0xfe,sizeof(f)),memset(g,0x7f,sizeof(g));
	f[0][0]=0.0,g[0][0]=0.0,r=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=T;j++)
			f[i][j]=f[i-1][j],g[i][j]=g[i-1][j];
		for(int j=T;j>=p[i].Te;j--)
			if(f[i][j]<f[i-1][j-p[i].Te]+p[i].Se-eps)
				f[i][j]=f[i-1][j-p[i].Te]+p[i].Se,
				g[i][j]=g[i-1][j-p[i].Te]+p[i].Te;
			else if(f[i][j]<f[i-1][j-p[i].Te]+p[i].Se+eps)
				g[i][j]=min(g[i][j],g[i-1][j-p[i].Te]+p[i].Te);
		for(int j=T;j>=p[i].Te+p[i].Th;j--){
			if(f[i][j]<f[i-1][j-p[i].Te-p[i].Th]+p[i].Se+p[i].Sh*p[i].Q-eps)
				f[i][j]=f[i-1][j-p[i].Te-p[i].Th]+p[i].Se+p[i].Sh*p[i].Q,
				g[i][j]=(g[i-1][j-p[i].Te-p[i].Th]+p[i].Te)*p[i].P+p[i].Q*j;
			else if(f[i][j]<f[i-1][j-p[i].Te-p[i].Th]+p[i].Se+p[i].Sh*p[i].Q+eps)
				g[i][j]=min(g[i][j],(g[i-1][j-p[i].Te-p[i].Th]+p[i].Te)*p[i].P+p[i].Q*j);
		}
	}
	for(int i=0;i<=T;i++)
		if(f[n][r]<f[n][i]||(f[n][r]==f[n][i]&&g[n][r]>g[n][i]))
			r=i;
	printf("%.10Lf %.10Lf\n",f[n][r],g[n][r]);
}
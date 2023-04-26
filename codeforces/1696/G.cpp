#include<bits/stdc++.h>
using namespace std;const double inf=-1e15;const int N=2e5+7;
struct M{
	double c[3][3];
	M(){for(int i=0;i<3;++i)for(int j=0;j<3;++j)c[i][j]=inf;}
	double* operator[](int x){return c[x];}
	friend M operator*(M a, M b){M c;for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)c[i][j]=max(c[i][j],a[i][k]+b[k][j]);return c;}
}t[N<<2],C;int n,m,i,j;double v,ans,X,Y;
void U(int x,int l,int r,int pos,double v){
	if(l==r){t[x][0][0]=0;t[x][1][1]=v/(X+Y);t[x][2][2]=v/Y;return;}int mid=l+r>>1;
	if(pos<=mid)U(x<<1,l,mid,pos,v);else U(x<<1|1,mid+1,r,pos,v);t[x]=t[x<<1]*C*t[x<<1|1];
}
M Q(int x,int l,int r,int a,int b) {
	if(a<=l&&r<=b)return t[x];int mid=l+r>>1;
	if(b<=mid)return Q(x<<1,l,mid,a,b);if(a>mid)return Q(x<<1|1,mid+1,r,a,b);return Q(x<<1,l,mid,a,b)*C*Q(x<<1|1,mid+1,r,a,b);
}
int main(){
	C[0][0]=C[0][1]=C[0][2]=C[1][0]=C[2][0]=C[1][1]=0,C[1][2]=C[2][1]=C[2][2]=inf;
	for(scanf("%d%d%lf%lf",&n,&m,&X,&Y),X>Y?swap(X,Y):void(),i=1;i<=n;++i)scanf("%lf",&v),U(1,1,n,i,v);
	while(m--){
		scanf("%d",&i);
		if(i==1)scanf("%d%lf",&j,&v),U(1,1,n,j,v);else{
			scanf("%d%d",&i,&j);auto ret = Q(1,1,n,i,j);
			ans=inf;for(i=0;i<3;++i)for(j=0;j<3;++j)ans=max(ans,ret[i][j]);
			printf("%.10f\n",ans);
		}
	}
}
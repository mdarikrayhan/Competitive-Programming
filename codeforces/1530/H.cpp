// LUOGU_RID: 160516114
#include<bits/stdc++.h>
using namespace std;
const int N=15005,M=500;
int T,n,a[N],f[2][N][M],m,tr[2][M][N];
inline int query(int o1,int o2,int x){
	int ans=-1e9;
	for(;x;x-=(x&(-x)))ans=max(ans,tr[o1][o2][x]);
	return ans;
}
inline void update(int o1,int o2,int x,int y){
	for(;x<=n;x+=(x&(-x)))tr[o1][o2][x]=max(tr[o1][o2][x],y);
} 
struct node{
	int a,b,c,d;
};
vector<node>ve[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=n;i;--i)scanf("%d",&a[i]);
		m=max((int)(sqrt(n)+sqrt(n)),400);
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[0][i][j]=1e9,f[1][i][j]=-1e9;
		for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)tr[0][i][j]=tr[1][i][j]=-1e9;
		for(int i=1;i<=n;++i)ve[i].clear();
		f[0][1][1]=a[1];
		for(int i=1;i<n;++i){
			for(int j=1;j<=m;++j){
				f[0][i][j]=min(f[0][i][j],-query(0,j,n-a[i]));
				f[1][i][j]=max(f[1][i][j],query(1,j,a[i]-1));
			}
			for(int j=1;j<=m;++j){
				if(f[0][i][j]!=1e9){
					ve[i+1].push_back((node){0,j+1,n-a[i]+1,-f[0][i][j]});
					if(i+j<=n)ve[i+j].push_back((node){1,j+1,f[0][i][j],a[i]});
				}
				if(f[1][i][j]!=-1e9){
					if(i+j<=n)ve[i+j].push_back((node){0,j+1,n-f[1][i][j]+1,-a[i]});
					ve[i+1].push_back((node){1,j+1,a[i],f[1][i][j]});
				}
			}
			for(int j=0;j<ve[i+1].size();++j)update(ve[i+1][j].a,ve[i+1][j].b,ve[i+1][j].c,ve[i+1][j].d);
		}
		for(int i=1;i<=m;++i){
			f[0][n][i]=min(f[0][n][i],-query(0,i,n-a[n]));
			f[1][n][i]=max(f[1][n][i],query(1,i,a[n]-1));
		}
		int ans=0;
		for(int i=m;i;--i){
			for(int j=1;j<=n;++j){
				if(f[0][j][i]!=1e9||f[1][j][i]!=-1e9){
					ans=i;
					break;
				}
			}
			if(ans)break;
		}
		
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[0][i][j]=1e9,f[1][i][j]=-1e9;
		for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)tr[0][i][j]=tr[1][i][j]=-1e9;
		for(int i=1;i<=n;++i)ve[i].clear();
		for(int i=1;i<n;++i){
			f[0][i][1]=f[1][i][1]=a[i];
			for(int j=1;j<=m;++j){
				f[0][i][j]=min(f[0][i][j],-query(0,j,n-a[i]));
				f[1][i][j]=max(f[1][i][j],query(1,j,a[i]-1));
			}
			for(int j=1;j<=m;++j){
				if(f[0][i][j]!=1e9){
					ve[i+1].push_back((node){0,j+1,n-a[i]+1,-f[0][i][j]});
					if(i+j+1<=n)ve[i+j+1].push_back((node){1,j+1,f[0][i][j],a[i]});
				}
				if(f[1][i][j]!=-1e9){
					if(i+j+1<=n)ve[i+j+1].push_back((node){0,j+1,n-f[1][i][j]+1,-a[i]});
					ve[i+1].push_back((node){1,j+1,a[i],f[1][i][j]});
				}
			}
			for(int j=0;j<ve[i+1].size();++j)update(ve[i+1][j].a,ve[i+1][j].b,ve[i+1][j].c,ve[i+1][j].d);
		}
		f[0][n][1]=a[n];
		for(int i=1;i<=m;++i){
			f[0][n][i]=min(f[0][n][i],-query(0,i,n-a[n]));
			f[1][n][i]=max(f[1][n][i],query(1,i,a[n]-1));
		}
		int res=0;
		for(int i=m;i>ans;--i){
			for(int j=1;j<=n;++j){
				if(f[0][j][i]!=1e9||f[1][j][i]!=-1e9){
					res=i;
					break;
				}
			}
			if(res)break;
		}
		printf("%d\n",max(ans,res));
	}
} 
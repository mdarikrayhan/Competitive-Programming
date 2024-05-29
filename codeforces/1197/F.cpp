#include<bits/stdc++.h>
using namespace std;
int n,m,c[64],d[64],ans[4]={1},ans_[4],q[4][4],a[1007],f[4][64][64],g[30][64][64],mex[15]={0,1,0,2,0,1,0,3,0,1,0,2,0,1},p=998244353;vector<pair<int,int> >h[1007];
void fmul(int g[64][64]){for(int a=0;a<64;++a)for(int b=0;b<64;++b)d[b]=(1ll*c[a]*g[a][b]+d[b])%p;for(int i=0;i<64;++i)c[i]=d[i],d[i]=0;}
void mul(int x){for(int i=29;~i;--i)if(x&(1<<i))fmul(g[i]);}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%d",&m);for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),h[x].push_back({y,z});
	for(int i=1;i<=3;++i)for(int j=1;j<=3;++j)scanf("%d",&q[i][j]);
	for(int i=1;i<=3;++i)for(int j=0;j<64;++j){
		int h=(j<<2&63)|mex[(q[i][1]?1<<(j&3):0)|(q[i][2]?1<<(j>>2&3):0)|(q[i][3]?1<<(j>>4&3):0)];
		g[0][j][h]++;f[i][j][h]++;
	}
	for(int i=0;i<29;++i)for(int a=0;a<64;++a)for(int b=0;b<64;++b)for(int c=0;c<64;++c)g[i+1][a][c]=(1ll*g[i][a][b]*g[i][b][c]+g[i+1][a][c])%p;
	for(int i=1;i<=n;++i){
		c[63]=1;if(h[i].empty())mul(a[i]);
		else{
			sort(h[i].begin(),h[i].end());mul(h[i][0].first-1);h[i].push_back({a[i]+1,0});
			for(int j=0;j<h[i].size()-1;++j)fmul(f[h[i][j].second]),mul(h[i][j+1].first-h[i][j].first-1);
		}
		for(int j=4;j<64;++j)c[j&3]=(c[j]+c[j&3])%p,c[j]=0;
		for(int a=0;a<4;++a)for(int b=0;b<4;++b)ans_[a^b]=(1ll*ans[a]*c[b]+ans_[a^b])%p;
		for(int j=0;j<4;++j)ans[j]=ans_[j],ans_[j]=c[j]=0;
	}
	printf("%d\n",ans[0]);
}
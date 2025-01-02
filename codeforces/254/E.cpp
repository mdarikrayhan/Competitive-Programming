#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;
const int N=400;
const int inf=1e9;
int n,v;
int a[N+10];
int m;
int l[N+10],r[N+10],c[N+10];
vector<pii >val[N+10];
int f[N+10][(N+10)<<1],fm[N+10][(N+10)<<1];
int g[(N+10)<<1],gm[N+10][(N+10)<<1];
inline void print(int x,int y){
	if(!x){
		return ;
	}
	if(!(~gm[x][y+val[x][fm[x][y]].first]))exit(2);
	assert(~gm[x][y+val[x][fm[x][y]].first]);
	print(x-1,gm[x][y+val[x][fm[x][y]].first]);
	if(!(~fm[x][y]))exit(3);
	assert(~fm[x][y]);
	if(fm[x][y]>=(int)val[x].size())exit(4);
	assert(fm[x][y]<(int)val[x].size());
	cout<<fm[x][y]<<' ';
	for(int i=1;i<=fm[x][y];++i){
		cout<<val[x][i].second<<' ';
	}
	cout<<'\n';
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>v;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>l[i]>>r[i]>>c[i];
		for(int j=l[i];j<=r[i];++j){
			val[j].push_back({c[i],i});
		}
	}
	for(int i=1;i<=n;++i){
		val[i].push_back({0,0});
		sort(val[i].begin(),val[i].end());
		for(int j=1;j<(int)val[i].size();++j){
			val[i][j].first+=val[i][j-1].first;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=(N<<1);++j){
			f[i][j]=-inf;
			fm[i][j]=-1;
		}
	}
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		int lim=a[i-1]+a[i]-v;
		for(int j=0;j<=lim;++j){
			g[j]=-inf;
			gm[i][j]=-1;
		}
		for(int j=0;j<=(i>1?a[i-2]:0)+a[i-1]-(i>1?v:0);++j){
			if(min(j,a[i-1])+a[i]>=v&&g[min(j,a[i-1])+a[i]-v]<f[i-1][j]){
				g[min(j,a[i-1])+a[i]-v]=f[i-1][j];
				gm[i][min(j,a[i-1])+a[i]-v]=j;
			}
		}
		for(int j=0;j<=lim;++j){
			for(int k=0;k<(int)val[i].size();++k){
				if(j+val[i][k].first<=lim&&f[i][j]<g[j+val[i][k].first]+k){
					f[i][j]=g[j+val[i][k].first]+k;
					fm[i][j]=k;
				}
			}
		}
	}
	int ans=-1,pos=-1;
	for(int i=0;i<=a[n-1]+a[n]-v;++i){
		if(ans<f[n][i]){
			ans=f[n][i];
			pos=i;
		}
	}
	if(!(~pos))exit(1);
	assert(~pos);
	cout<<ans<<'\n';
	print(n,pos);
	return 0;
}
			     		 		  				 	 			   			
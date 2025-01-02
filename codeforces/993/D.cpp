// LUOGU_RID: 158270784
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

int n,m;
int f[105][105];
vector <int> g[105];
pair <int,int> a[105];

inline void in(int &n){
	n=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return ;
}

inline bool check(int K){
	memset(f,0x3f,sizeof(f));
	int V=0;
	f[0][0]=0;
	for(int i=1;i<=m;i++){
		V+=g[i].size();
		for(int j=0;j<=V;j++){
			int s=0;
			for(int k=0;k<=(int)g[i].size()&&k<=j&&j-k>=V-j;k++){
				if(k) s+=-1000*a[g[i][k-1]].first+K*a[g[i][k-1]].second;
				f[i][j]=min(f[i][j],f[i-1][j-k]+s);
			}
		}
	}
	for(int i=0;i<=n;i++) if(f[m][i]<=0) return 1;
	return 0;
}

signed main(){
	in(n);
	for(int i=1;i<=n;i++) in(a[i].first),a[i].first*=-1;
	for(int i=1;i<=n;i++) in(a[i].second),a[i].second*=-1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i].first!=a[i-1].first) m++;
		g[m].emplace_back(i);
	}
	int l=0,r=1e11,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",l);

	return 0;
}
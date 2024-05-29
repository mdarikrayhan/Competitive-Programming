#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=1e9+7;
int cnt,a[2][N],A[2][N],b[N];bool v[N];vector<int>p[N];
void dfs(int x){
	if(x==1)return;
	++cnt;v[x]=1;
	for(auto&i:p[x])if(!v[i])dfs(i);
}
int main(){int n,m,tot=0;
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	for(auto&i:p[1])if(!v[i]){
		cnt=0;dfs(i);b[++tot]=cnt+1;
	}
	a[0][0]=1;int t=0;
	rep(i,1,tot){t^=1;
		rep(j,0,m){
			a[t][j]=A[t][j]=0;
			rep(k,-1,1)if(k){
				int x=j+k*b[i];
				a[t][j]=(a[t][j]+a[t^1][abs(x)])%mo;
				A[t][j]=(ll(A[t][j])+((k<0)?a[t^1][abs(x)]:0)+
				(x>=0?A[t^1][x]:ll(i-1)*a[t^1][-x]+mo-A[t^1][-x]))%mo;
			}
		}
	}
	int ans=(a[t][0]+A[t][1]*4ll)%mo;
	rep(i,1,m)a[t][i]=0;
	a[t][0]=1;
	rep(i,1,tot){t^=1;
		rep(j,0,m){a[t][j]=0;
			rep(k,-1,1){
				int x=abs(j+k*b[i]);
				a[t][j]=(a[t][j]+a[t^1][x])%mo;
			}
		}
	}t^=1;
	rep(i,1,tot){
		dep(j,m,0){
			a[t][j]=(a[t^1][j+b[i]]+mo*2ll-a[t][j+b[i]]-a[t][j+b[i]*2])%mo;
			if(j<=b[i]-2)ans=(ans+a[t][j]*2ll*(j?2:1))%mo;
		}
	}
	printf("%d\n",ans);
}
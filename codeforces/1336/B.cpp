#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Inf=0x3f3f3f3f;
const ll INF=0x7f7f7f7f7f7f7f7f;
const int N=1e5+5;
int _;
ll a[3][N];
ll cc(ll x,ll y,ll z){
	return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}
int main(){
	scanf("%d",&_);
	while(_--){
		for(int i=0;i<3;i++) scanf("%lld",&a[i][0]);
		for(int i=0;i<3;i++){
			for(int j=1;j<=a[i][0];j++)
				scanf("%lld",&a[i][j]);
			sort(a[i]+1,a[i]+a[i][0]+1);
		}
		ll ans=INF;
		for(int x=0;x<3;x++)
			for(int y=0;y<3;y++)
				for(int z=0;z<3;z++){
					if(x==y||y==z||x==z) continue;
					for(int i=1;i<=a[y][0];i++){
						int px=lower_bound(a[x]+1,a[x]+a[x][0]+1,a[y][i])-a[x];
						int pz=upper_bound(a[z]+1,a[z]+a[z][0]+1,a[y][i])-a[z];
						if(px==a[x][0]+1||pz==1) continue;
						pz--;
						ans=min(ans,cc(a[x][px],a[y][i],a[z][pz]));
					}
				}
		printf("%lld\n",ans);
	}
	return 0;
}

	   	  	   			   	 	 		 				 		
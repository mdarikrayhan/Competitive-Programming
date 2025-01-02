#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define forup(i,s,e) for(int i=(s);i<=(e);i++)
#define fordown(i,s,e) for(int i=(s);i>=(e);i--)
#ifdef DEBUG
#define msg(args...) fprintf(stderr,args)
#else
#define msg(...) void()
#endif
using namespace std;
using i64=long long;
#define gc getchar()
inline int read(){
    int x=0,f=1;char c;
    while(!isdigit(c=gc)) if(c=='-') f=-1;
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=gc;}
    return x*f;
}
#undef gc
const int N=150005,inf=0x3f3f3f3f;
int n,m,a[N],r[N];
int dp[N][2];
vector<int> e[N];
void solve(){
	n=read();m=read();
	forup(i,0,n+1){
		e[i].clear();
		r[i]=i;a[i]=0;
		dp[i][0]=dp[i][1]=0;
		if(i>1) e[0].push_back(i);
		if(i<n) e[i].push_back(n+1);
	}
	a[n]=a[0]=1;
	forup(i,1,m){
		int u=read(),v=read();
		if(v==u+1) a[u]=1;
		else e[u].push_back(v);
	}
	fordown(i,n+1,0){
		if(a[i]) r[i]=r[i+1];
	}
	if(r[0]==n+1){
		printf("%lld\n",1ll*n*(n-1)/2);
		return;
	}
	dp[r[0]][0]=1;
	forup(i,r[0],n+1){
		for(auto j:e[i]){
			if(j-1<=r[i+1]){
				dp[j-1][0]|=dp[i][1];
				dp[j-1][1]|=dp[i][0];
			}
		}
	}
	fordown(i,r[0]-1,0){
		for(auto j:e[i]){
			if(j-1<=r[i+1]){
				dp[i][0]|=dp[j-1][1];
				dp[i][1]|=dp[j-1][0];
			}
		}
	}
	int cx0=0,cx1=0,cy0=0,cy1=0,cx01=0,cy01=0;
	forup(i,0,r[0]){
		cy0+=dp[i][0];
		cy1+=dp[i][1];
		cy01+=dp[i][0]&&dp[i][1];
	}
	int lst=n+1;
	while(r[lst]==n+1) --lst;
	forup(i,lst,n){
		cx0+=dp[i][0];
		cx1+=dp[i][1];
		cx01+=dp[i][0]&&dp[i][1];
	}
	i64 ans=1ll*cx0*cy0+1ll*cx1*cy1-1ll*cx01*cy01;
	msg("%d %d %d %d %d %d |",cx0,cy0,cx1,cy1,cx01,cy01);
	if(r[r[0]+1]==n+1) --ans;
	printf("%lld\n",ans);
}
signed main(){
	int t=read();
	while(t--){
		solve();
	}
}
 	 	 			 	 		  		 				 			 	
#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) x*2
#define rs(x) x*2+1
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second 
using namespace std;
typedef long long ll;
const int N=105,M=1005,mo=1e9+7,inf=998244353,bs=19491001;
const double eps=1e-8;
inline void read(int &p){
	int x=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	p=x*w;
}
int n,c[N],b[N],x,dp[N][N*N],low[N],upp,ans;
int main(){
	read(n);
	rep(i,1,n)
	    read(c[i]);
	rep(i,1,n-1)
	    read(b[i]);
	read(x),read(x);
	rep(i,1,n){
		low[i]=i*x;
		rep(j,1,i-1)
		    low[i]+=(i-j)*b[j];
	}
	dp[0][0]=1;
	rep(i,1,n){
		upp+=c[i];
		rep(j,max(0,low[i]),upp){
			rep(k,0,c[i])
			    if(j-k>=0)dp[i][j]+=dp[i-1][j-k],dp[i][j]%=mo;
			if(i==n)ans+=dp[i][j],ans%=mo;
		}
    }
    printf("%d\n",ans);
    return 0;
}
	  			  		 	  		  		   	 	 	 		
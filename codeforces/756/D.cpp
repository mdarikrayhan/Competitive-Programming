#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define ls(x) lson[x]
#define rs(x) rson[x]
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
#define pb push_back
using namespace std;
typedef long long ll;
const int N=5005,M=1e6+2,mo=1e9+7,inf=1e9+7,bs=10;
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
int n;
char s[N];
int dp[N][N],la[N][30],endp[30],sum[N];
int c[N][N];
//新得到的序列，相邻去重后一定是原序列的子序列。因此dpi,j表示原序列中以i结尾，长度为j的相邻字母不同的子序列数，对每个长度的加和
//之后再乘一个组合数即可. 
int main(){
	read(n);
	c[0][0]=1;
	rep(i,1,n){
		rep(j,0,n){
			if(!j)c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
		}
	}
	scanf("%s",s+1);
	rep(i,1,n){
		rep(j,1,26)
	    	la[i][j]=endp[j];
		endp[s[i]-'a'+1]=i;
	}
	rep(i,1,n){
		repp(j,n,1){
			if(j==1)dp[i][j]++;
			dp[i][j]+=(sum[j-1]-dp[la[i][s[i]-'a'+1]][j-1]+mo)%mo,dp[i][j]%=mo;
			sum[j]+=(dp[i][j]-dp[la[i][s[i]-'a'+1]][j]+mo)%mo,sum[j]%=mo;
		}
	}
	ll ans=0;
	rep(i,1,n){			
	    ll res=0;
		rep(j,1,26){
			if(j==s[n]-'a'+1)res+=dp[n][i];
			else res+=dp[la[n][j]][i];
			res%=mo;
		}
		ans+=(ll)res*c[n-1][i-1]%mo,ans%=mo;
	}
	printf("%lld\n",ans);
	return 0;
}
 	 	  										 	 	    	  	 		
#include<bits/stdc++.h> 
#define ll long long 
#define mid ((l+r)>>1)
#define lson u<<1,l,mid
#define rson u<<1|1,mid+1,r
#define inf 0x3f3f3f3f 
using namespace std;
const int mod=(int)1e9+7;
const signed maxn=1505;
typedef int LL;
inline LL Read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int dp[maxn][maxn];
int pre[maxn][maxn];
int stk[maxn],top;
int add(int a,int b){
	return ((a+=b)>=mod)?a-mod:a;
}
int mul(int x,int y){
	return (ll) x*y%mod;
}
signed main()
	{	
		LL T=1;
		while(T--){
			int n=Read(),k=Read();
			for(int i=1;i<=n;i++){
				int a=Read();
				if(a) stk[++top]=i;	
			}
			for(int i=0;i<=n;++i) pre[i][0]=1;
			for(int i=1;i<=top;i++){
				int sx=n-top+i;// 第i个球右端还有top-i个球，最右放在n-top+i
				for(int j=i;j<=sx;j++){
					int v=abs(stk[i]-j);
					if(v>k) v=k+1;
					for(int u=0;u<v;u++) dp[j][u]=0;
					for(int u=v;u<=k;u++) dp[j][u]=pre[j-1][u-v]; 
				}
				for(int u=0;u<=k;u++) pre[i][u]=dp[i][u];
				for(int j=i+1;j<=sx;j++){
					for(int u=0;u<=k;u++) pre[j][u]=add(pre[j-1][u],dp[j][u]); 
				}
			}
			int fin=0;
			for(int i=k;i>=0;i-=2) fin=add(fin,pre[n][i]);
			printf("%d\n",fin);
		}
		return 0;
	}
/*
2
6 5
0 0 0 0 0 0
0
1
2
3
4
6 5
0 0 0 0 0 1
0
1
2
3
4

*/	

#include<bits/stdc++.h>
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int MAXN=5000+10,MOD=1e9+7;
int n,dp[MAXN][MAXN],cnt[MAXN][MAXN];
int lcp[MAXN][MAXN],pre[MAXN],pw[MAXN];
string S;
int calc_val(int l,int r) {return ((pre[r]-1ll*pre[l-1]*pw[r-l+1])%MOD+MOD)%MOD;}
int compare(int l1,int r1,int l2,int r2) { //相等返回 0；前者大返回 1；後者大返回 -1 
	if(r1-l1+1!=r2-l2+1) return r1-l1+1>r2-l2+1?1:-1;
	return (lcp[l1][l2]>=r1-l1+1)?0:(S[l1+lcp[l1][l2]]>S[l2+lcp[l1][l2]]?1:-1);
}
signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	memset(dp,0x3f,sizeof(dp));
	cin>>S,n=S.size(),S="&"+S,dp[0][0]=0,cnt[0][0]=1,pw[0]=1;
	ffor(i,1,n) cnt[0][i]=1,dp[0][i]=0;
	ffor(i,1,n) pw[i]=pw[i-1]*2%MOD,pre[i]=(pre[i-1]*2+S[i]-'0')%MOD;
	roff(i,n,1) roff(j,n,1) lcp[i][j]=(S[i]==S[j])?lcp[i+1][j+1]+1:0;	
	int tval=-1;
	ffor(i,1,n) {
		ffor(j,1,i) if(S[i-j+1]=='1') {
			int st=j;
			if(j+j<=i&&compare(i-j-j+1,i-j,i-j+1,i)==1) st--;
			dp[i][j]=dp[i-j][st]+1,cnt[i][j]=cnt[i-j][st];
		}
		if(i==n) {
			int sum=0,flg=0;
			ffor(j,1,min(13,n)) if(cnt[i][j]) flg=1;
			if(flg) {
				int tans=0; tval=INT_MAX;
				ffor(j,1,min(13,n)) tval=min(tval,dp[n][j]+calc_val(n-j+1,n));
			}
			else ffor(j,1,n) if(cnt[i][j]) {tval=(dp[n][j]+calc_val(n-j+1,n))%MOD;break;}
		}
		ffor(j,1,n) dp[i][j]=min(dp[i][j],dp[i][j-1]),cnt[i][j]=(cnt[i][j]+cnt[i][j-1])%MOD;
	}
	cout<<cnt[n][n]<<'\n'<<tval;
	return 0;
}
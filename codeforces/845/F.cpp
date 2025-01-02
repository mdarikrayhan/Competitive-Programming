#include<bits/stdc++.h>
//#define int long long
#define R(i,a,b) for(int i=(a),i##E=(b);i<=i##E;i++)
#define L(i,a,b) for(int i=(b),i##E=(a);i>=i##E;i--)
using namespace std;
const int mod=1e9+7;

char str[266][266];
int n,m;
int dp[266][66666][2][2];
int cur;
inline void add(int &x,const int y)
{
	x+=y;x>=mod?x-=mod:1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	R(i,0,n-1) cin>>str[i];
	if(n<m) {R(i,0,n-1) R(j,i,m-1) swap(str[i][j],str[j][i]);swap(n,m);}
	dp[0][0][0][0]=1;
	int t,tS,t1,t2;
	R(i,0,n-1) 
	{	
		R(j,0,m-1) R(S,0,(1<<m)-1) R(o1,0,1) R(o2,0,1) if(t=dp[j][S][o1][o2])
		{
			if(str[i][j]=='x')
			{
				tS=S&(~(1<<j)),t1=0,t2=o2;
				add(dp[j+1][tS][t1][t2],t);
			}
			else
			{
				int tt=(o1||(S&(1<<j)));
				tS=S,t1=o1,t2=o2+(1-tt);
				if(t2<=1) add(dp[j+1][tS][t1][t2],t);
				tS|=(1<<j);t1=1,t2=o2;
				add(dp[j+1][tS][t1][t2],t);
 			}
 			dp[j][S][o1][o2]=0;
		}
		R(S,0,(1<<m)-1) R(o1,0,1) R(o2,0,1)
		{
			add(dp[0][S][0][o2],dp[m][S][o1][o2]);
			dp[m][S][o1][o2]=0;
		}
	}
	int ans=0;
	R(S,0,(1<<m)-1) R(o2,0,1) add(ans,dp[0][S][0][o2]);
	cout<<ans<<endl;
}
// LUOGU_RID: 159795858
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
#define pb push_back
using namespace std;
typedef long long ll;
const int N=605,M=205,mo=998244353,inf=1e9+7,bs=19491001;
const double eps=1e-7;
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
int h1,h2,g1,g2,l1,l2,r1,r2,p1,p2;
double pa,pb;
double dp[2][20000][M];
double ans=0;
int main(){
	read(h1),read(g1),read(l1),read(r1),read(p1);
	read(h2),read(g2),read(l2),read(r2),read(p2);
	pa=0.01*p1,pb=0.01*p2;
	if(p1==100){
		puts("0");
		return 0;
	}
	if(p2==100){
		puts("1");
		return 0;
	}
	dp[0][0][h1]=1;
	dp[1][0][h2]=1;
	int nwt=1;
	rep(i,1,15000){
		while((nwt-1)%g1!=0&&(nwt-1)%g2!=0)
		    nwt++;
		rep(j,1,h1){
			if((nwt-1)%g2!=0)dp[0][i][j]+=dp[0][i-1][j];
		    else{
		    	double nwp=1/1.0/(r2-l2+1);
		    	rep(k,l2,r2)
		    	    dp[0][i][max(0,j-k)]+=nwp*dp[0][i-1][j]*(1-pb);
		    	dp[0][i][j]+=dp[0][i-1][j]*pb;
		    }
		}
		rep(j,1,h2){
			if((nwt-1)%g1!=0)dp[1][i][j]+=dp[1][i-1][j];
		    else{
		    	double nwp=1/1.0/(r1-l1+1);
		    	rep(k,l1,r1)
		    	    dp[1][i][max(0,j-k)]+=nwp*dp[1][i-1][j]*(1-pa);
		    	dp[1][i][j]+=dp[1][i-1][j]*pa;
		    }
		}
		rep(j,0,h1)
		    ans+=dp[1][i][0]*dp[0][i][j];
		nwt++;
	}
	printf("%.7lf\n",ans);
	return 0;
}
// becoder Submission #undefined @ 1716814685855
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int SZ=1<<20;
char buf[SZ],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++)
ll read(){
	ll n=0; bool m=0;
	char c=gc();
	while(c<'0'||c>'9')m=c=='-',c=gc();
	while(c>='0'&&c<='9')n=(n<<3)+(n<<1)+(c^'0'),c=gc();
	return m?-n:n;
}
const int N=3005,mod=1e9+7;
int n,m,f[N][N],g[N][N];
char a[N][N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	f[1][2]=g[2][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='#')f[i][j]=g[i][j]=0;
			else{
				f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
				f[i][j+1]=(f[i][j+1]+f[i][j])%mod;
				g[i+1][j]=(g[i+1][j]+g[i][j])%mod;
				g[i][j+1]=(g[i][j+1]+g[i][j])%mod;
			}
		}
	}
	printf("%lld",(((ll)f[n-1][m]*g[n][m-1]-(ll)g[n-1][m]*f[n][m-1])%mod+mod)%mod);
	return 0;
}
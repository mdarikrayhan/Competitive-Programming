// LUOGU_RID: 159806322
#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=45,mod=1e9+7;
int T,K,f[N][2][2][2],g[N][2][2][2];
inline void ad(int &x,LL y){x=(x+y)%mod;}
inline int sol(int x,int y)
{
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));g[31][0][0][0]=1;
	for(int i=30;~i;i--) for(int j=0;j<2;j++) for(int k=0;k<2;k++) for(int l=0;l<2;l++)
	{
		int F=f[i+1][j][k][l],G=g[i+1][j][k][l],u0=j|(x>>i&1),u1=k|(y>>i&1),u2=l||(K>>i&1);
		for(int o=0;o<=u0;o++) for(int p=0;p<=u1;p++) if((o^p)<=u2)
		{
			int J=j|(o<u0),K=k|(p<u1),L=l|((o^p)<u2);
			ad(g[i][J][K][L],G);ad(f[i][J][K][L],2ll*F+G*(o^p));
		}
	}return (f[0][1][1][1]+g[0][1][1][1])%mod;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>T;
	while(T--)
	{
		int l,r,L,R;cin>>l>>L>>r>>R>>K;
		cout<<(2ll*mod+sol(r,R)+sol(l-1,L-1)-sol(l-1,R)-sol(r,L-1))%mod<<"\n";
	}
	return 0;
}
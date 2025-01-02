#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxm=3e5+10;
const int maxn=1010;
ll p[maxm],A[maxm],B[maxm],C[maxm],D[maxm];
ll cnt[55],g[27][maxn][maxn],n,m,k,pz[maxn][maxn],s[27][maxn][maxn];
char zs[maxn][maxn];char ss[55];
int main(){
	ll i,j,x;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=n;i++)scanf("%s",zs[i]+1);
	for(i=1;i<=k;i++){scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
		scanf("%s",ss);p[i]=ss[0]-'a';
		g[p[i]][A[i]][B[i]]++;g[p[i]][C[i]+1][B[i]]--;
		g[p[i]][A[i]][D[i]+1]--;g[p[i]][C[i]+1][D[i]+1]++;
	}int all,ls;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			all=0,ls=0;
			for(x=0;x<26;x++){
				g[x][i][j]+=g[x][i-1][j]+g[x][i][j-1]-g[x][i-1][j-1];
				cnt[x]=g[x][i][j];
				ls+=cnt[x];
				all+=cnt[x]*x;
			}cnt[zs[i][j]-'a']+=k-ls;
			all+=(k-ls)*(ll)(zs[i][j]-'a');
			for(x=0;x<26;x++){
				if(x==zs[i][j]-'a')pz[i][j]=pz[i-1][j]+pz[i][j-1]-pz[i-1][j-1]+all;
				s[x][i][j]=s[x][i-1][j]+s[x][i][j-1]-s[x][i-1][j-1]+all;
				if(x>0)cnt[x]+=cnt[x-1];
				all+=cnt[x]-k+cnt[x];
			}
		}
	}
	ll ans=1e16;
	for(i=1;i<=k;i++){
		ans=min(ans,pz[n][m]-(pz[C[i]][D[i]]-pz[C[i]][B[i]-1]-pz[A[i]-1][D[i]]+pz[A[i]-1][B[i]-1])+s[p[i]][C[i]][D[i]]-s[p[i]][C[i]][B[i]-1]-s[p[i]][A[i]-1][D[i]]+s[p[i]][A[i]-1][B[i]-1]);
	}cout<<ans;
	return 0;
}
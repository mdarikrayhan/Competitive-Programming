#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inv[5]={0,1,3,2,4};
const ll MOD=1e9+7;
int n,m,q,N;
int Lyx;
int a[505][805];
char s[505];
bool vis[505];
void Gauss(){
	for(int i=1;i<=N;i++){
		int pos=0;
		for(int j=i;j<=N;j++)
			if(a[j][i]){
				pos=j;
				break;
			}
		if(!pos) continue;
		for(int j=i;j<=N+q;j++)
			swap(a[pos][j],a[i][j]);
		for(int j=1;j<=N;j++){
			if(j==i) continue;
			int p=a[j][i]*inv[a[i][i]]%5;
			for(int k=i;k<=N+q;k++)
				a[j][k]=(a[j][k]+5-a[i][k]*p%5)%5;
		}
	}
}
ll ksm(ll x,ll y){
	ll ret=1;
	while(y){
		if(y&1) ret=ret*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ret;
}
bool check(int x){
	for(int i=1;i<=N;i++)
		if((!vis[i])&&a[i][x]) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	N=max(n,m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[j][i]=s[j]-'a';
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[j][N+i]=s[j]-'a';
	}
	Gauss();
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			if(a[i][j]){
				vis[i]=1;
				break;
			}
		if(i<=n&&!vis[i]) ++Lyx;
	}
	ll ans=ksm(5,Lyx);
	for(int i=1;i<=q;i++){
		printf("%lld\n",check(N+i)?ans:0);
	}
	return 0;
}
		 		   	  	  			  		  	  				
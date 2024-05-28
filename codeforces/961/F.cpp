// LUOGU_RID: 159666031
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const int base=13331;
const int mod=1e9+7;
typedef long long ll;
int n;
char S[N]; 
int hsv[N],wop[N];
int f[N];
int hsh(int l,int r){
	return (hsv[r]-(ll)hsv[l-1]*wop[r-l+1]%mod+mod)%mod;
}
int p(int x){
	return x-!(x&1);
}
int main(){
	scanf("%d%s",&n,S+1);
	wop[0]=1;for(int i=1;i<=n;i++) wop[i]=(ll)wop[i-1]*base%mod;
	for(int i=1;i<=n;i++) hsv[i]=((ll)hsv[i-1]*base+S[i])%mod;
	int m=(n>>1)+(n&1);
	for(int i=m,j=-1;i>=1;i--){
		j=min(j+2,p(n-(i-1<<1)-1));
		while(j>0&&hsh(i,i+j-1)!=hsh(n-i-j+2,n-i+1)) j-=2;
		f[i]=j;
	} 
	for(int i=1;i<=m;i++) printf("%d ",f[i]);
	return 0;
}

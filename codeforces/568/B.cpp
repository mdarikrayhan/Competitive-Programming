// LUOGU_RID: 158219213
#include<bits/stdc++.h>
using namespace std;
const int ma=4005,mod=1e9+7;
int n,niu[ma],hou[ma][ma];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i){
		hou[i][0]=1;
		for(int j=1;j<=i;++j){
			hou[i][j]=(hou[i-1][j-1]+hou[i-1][j])%mod;
		}
	}
	niu[0]=1;
	for(int i=0;i<=n;++i){
		for(int k=0;k<=i;++k){
			niu[i+1]=(niu[i+1]+(long long)hou[i][k]*niu[k])%mod;
		}
	}
	printf("%d",(niu[n+1]-niu[n]+mod)%mod);
	return 0;
}
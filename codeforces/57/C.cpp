// Hydro submission #664976b1e9f28a76335cfaa2@1716731176739
//或许可以考虑容斥？但是乱序比有序更难处理 
//还是考虑拆位？ 
//总思想是转化，然而我全程一点都没有往转化上想。。。 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxn=2e5+3000;//数组开2倍:)，组合数涉及2n。。 
int n;
int f[maxn],g[maxn];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(){
	f[0]=g[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		g[i]=g[i-1]*qpow(i,mod-2)%mod;
	}
}
int C(int n,int m){
	if(m>n)
		return 0;
	return f[n]*g[m]%mod*g[n-m]%mod;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	init();
	cout<<(2*C(n*2-1,n)%mod-n+mod)%mod<<endl;
}
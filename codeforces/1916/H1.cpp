// LUOGU_RID: 158228958
// Problem: Matrix Rank (Hard Version)
// URL: https://www.luogu.com.cn/problem/CF1916H2
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Author: Nityacke
// Time: 2024-05-06 19:02:57

#include<iostream>
#define int long long
using namespace std;
const int mod=998244353;
int n,k,p;
inline int Qpow(int a,int b){
	int ans=1;
	for(a%=mod;b;b>>=1,a=a*a%mod)
		if(b&1) ans=ans*a%mod;
	return ans;
}
inline int Inv(int x){return Qpow(x,mod-2);}
inline int Add(int a){return (a+mod)%mod;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>p>>k;
	int a=1,b=1;
	for(int r=0;r<=min(n,k);++r){
		cout<<a*Inv(b)%mod<<" ";
		a=a*Add(Qpow(p,n)-Qpow(p,r))%mod;
		b=b*(Qpow(p,r+1)-1)%mod*Inv(Qpow(p,n-r)+mod-1)%mod;
	}
	for(int r=min(n,k)+1;r<=k;++r) cout<<"0 ";
}
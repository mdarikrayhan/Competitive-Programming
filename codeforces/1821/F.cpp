#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
const int maxn=3e5+100;
inline int quick_power(int a,int b){
	int ret=1;while(b){if(b&1)ret=1ll*ret*a%p;b>>=1,a=1ll*a*a%p;}return ret;
}
#define rev(x) (quick_power(x,p-2))
int fct[maxn],rfct[maxn],pw[maxn];
inline int C(int n,int m){
	if(n<0||m<0||m>n)return 0;
	return 1ll*fct[n]*rfct[m]%p*rfct[n-m]%p;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	fct[0]=1,pw[0]=1;for(int i=1;i<=n;++i)fct[i]=1ll*fct[i-1]*i%p,pw[i]=2ll*pw[i-1]%p;;
	rfct[n]=rev(fct[n]);for(int i=n-1;i>=0;--i)rfct[i]=1ll*rfct[i+1]*(i+1)%p;
	if(1ll*m*k>n){cout<<0;return 0;}
	long long ans=0;
	for(int i=0,c=1;i<=m&&i*k<=n;++i,c=-c){
		ans+=1ll*C(n-(m-i)*k-i*(2*k),m)*C(m,i)%p*pw[m-i]%p*c;
	}
	cout<<(ans%p+p)%p;
	return 0;
}
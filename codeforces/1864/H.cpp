#include<bits/stdc++.h>
using namespace std;
const long long p=998244353,i2=(p+1)/2;
long long t,n;
long long power(long long x,long long n) {
	long long cnt=1;
	while(n) {
		if(n&1) cnt=cnt*x%p;
		x=x*x%p;
		n>>=1;
	}
	return cnt; 
}
vector<long long> f;
int main() {
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);f.resize(1000);
		long long l=n,r=2*n-2,k=0,ans=0;
		while(l>1) {
			r=l-1,l=(l+1)/2;long long d=0;
			for(int i=k;i>0;i--) {
				long long t=power(2,(1ll<<i)-1),it=f[i-1]*power(t-1,p-2)%p*i2%p;
				f[i]=p-it;d=(d+it*power(t,r+1))%p;
			}
			f[0]=(d+power(i2,r+1)*(ans+p-2*(++k)))%p;ans=2*k;
			for(long long i=0;i<k;i++) ans=(ans+f[i]*power(power(2,1ll<<i),l))%p;
		}
		printf("%lld\n",ans);f.clear();
	}
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,P=1e9+7;
char c[N],d[N];
int n,C[3],D[3];
char trans[128];
long long p2[N],p[N],invp[N];
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%P;
		a=a*a%P,b>>=1;
	}
	return ans;
} 
long long binom(long long n,long long m)
{
//	cerr<<"BINOM : "<<n<<" "<<m<<"  "<<p[n]*invp[m]%P*invp[n-m]%P<<endl;
	return p[n]*invp[m]%P*invp[n-m]%P;
}
long long sum_p2(long long n){return p2[n+1]-2;}
int mu[N],pr[N],v[N],tt;
long long F(long long a,long long b)
{
//	cerr<<"F "<<a<<" "<<b<<endl;
	if(a<0||b<0)a=-a,b=-b;
	if(!a&&!b)
	{
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			long long r=0;
			for(int d=1;i*d<=n;++d)r+=1ll*mu[d]*(n/i/d)*(n/i/d)%P;
			ans+=p2[i]*(r%P)%P;
		}
		ans=(ans%P+P)%P;
//		cerr<<"RES: "<<ans<<endl;
		return ans;
	}
	if(a*b<=0)return 0;
	int g=__gcd(a,b);a/=g,b/=g;
//	cerr<<" -> F "<<a<<" "<<b<<endl;
//	cerr<<"RES : "<<sum_p2(n/max(a,b))<<endl;
	return sum_p2(n/max(a,b));
}
int main()
{
	cin>>c>>d>>n;mu[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!v[i])pr[++tt]=i,mu[i]=-1;
		for(int j=1;j<=tt&&i*pr[j]<N;++j)
		{
			v[i*pr[j]]=1;if(i%pr[j]==0)break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	trans['A']=1,trans['B']=2;
	for(int i=0;c[i];++i)++C[trans[c[i]]];
	for(int i=0;d[i];++i)++D[trans[d[i]]];
	p2[0]=p[0]=1;for(int i=1;i<N;++i)p[i]=p[i-1]*i%P,p2[i]=p2[i-1]*2%P;
	invp[N-1]=qpow(p[N-1],P-2);for(int i=N-1;i;--i)invp[i-1]=invp[i]*i%P;
	int a=C[1]-D[1],b=D[2]-C[2],x=C[0],y=D[0];
	long long ans=0;
	for(int i=-y;i<=x;++i)ans+=binom(x+y,i+y)*F(a+i,b+y-x+i)%P;
	int z=1;for(int i=0;c[i]||d[i];++i)
	{
//		cerr<<c[i]<<" "<<d[i]<<endl;
		if(c[i]!='?'&&d[i]!='?'&&c[i]!=d[i]){z=0;break;}
		else if(!c[i]||!d[i]){z=0;break;}
		else if(c[i]=='?'&&d[i]=='?')z=z*2%P;
	}
	cerr<<z<<endl;
	if(z)ans-=1ll*z*F(0,0)%P,ans+=1ll*z*sum_p2(n)%P*sum_p2(n)%P;
	cout<<(ans%P+P)%P<<endl;
}
   							   	 	 		   		  			
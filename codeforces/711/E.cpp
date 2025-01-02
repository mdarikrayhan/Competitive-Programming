// LUOGU_RID: 159672502
#include<bits/stdc++.h>
#define int __int128
using namespace std;
int n,k;
int get(int x,int y)
{
	return x/y;
}
long long qpow(int a,int b,int mod)
{
	int s=1,base=a;
	while(b!=0)
	{
		if(b&1==1)
		{
			s*=base;
			s%=mod;
		}
		base*=base;
		base%=mod;
		b>>=1;
	}
	return s;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long N,K;
	cin>>N>>K;
	n=N,k=K;
	if(n<64&&(1ll<<n)<k)
	{
		cout<<1<<" "<<1<<'\n';
		return 0;
	}
	int mxx=62,mnn=0;
	int mx=(1ll<<min(n,mxx)),s=0;
	for(int i=1;i<=62;i++)
	{
		s+=get(mx,(1ll<<i))-get(mx-k,(1ll<<i));
	}
	s+=max((n-62),mnn);
	if(k>1000003)
	{
		cout<<qpow(2,n*k-s,1e6+3)<<" ";
	}
	else
	{
		int us=qpow(2,n*k-s,1e6+3);
		int T=k,z=qpow(2,n,1e6+3),z2=(1ll<<min(n,mxx)),xx=1;
		while(T--)
		{
			if(z<0)
			z+=1e6+3;
			int rz=z,m=z2;
			if(m==(1ll<<62))
			{
				rz*=qpow(qpow(2,1000001,1000003),n-62,1000003);
				rz%=1000003; 
			}
			while(m%2==0)
			{
				m/=2;
				rz*=qpow(2,1000001,1000003);
				rz%=1000003;
			}
			xx*=rz;
			xx%=1000003;
			z--,z2--;
		}
		us-=xx;
		us=(us%(1000003)+1000003)%1000003;
		long long sss=us;
		cout<<sss<<" ";
	}
	cout<<qpow(2,n*k-s,1e6+3);
	return 0; 
}
//2^n^k-A(2^n,k)
//2^n^k
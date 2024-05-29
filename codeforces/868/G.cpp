#include<stdio.h>
#define M 1000000007
int F(int x,int t){if(!t) return 1;
int T=F(x,t>>1);T=1ll*T*T%M;
return (t&1)?1ll*T*x%M:T;}const int hf=(M+1)/2;
int G(int x,int y){return y?G(y,x%y):x;}inline int L(int a,int q){if(q<=0)return 0;
if(a==1)return q;
return 1ll*(F(a,q)-1)*F(a-1,M-2)%M;}inline int C(int a,int q){if(q<=0)return 0;
if(a==1)return 1ll*q*(q+1)/2%M;int t=F(a-1,M-2);
return (1ll*(F(a,q)-1)*t%M*a-q+M)%M*t%M;}
int solve(int n,int k,int a1,int b1,int a2,int b2,int c1,int c2,int c0)
{if(n==k){int x=1ll*b2*F(M+1-a2,M-2)%M;
return (1ll*c1*x+c0)%M;}int q=(n-1)/k,r=n-q*k,A1,B1,A2,B2,C1,C2,C0,a,b;
a=1ll*a2*F(a1,q-1)%M,b=(1ll*a2*b1%M*L(a1,q-1)+b2)%M;
A1=F(a,M-2);
B1=(M-1ll*b*A1%M)%M;
a=1ll*a2*F(a1,q)%M,b=(1ll*a2*b1%M*L(a1,q)+b2)%M;
A2=F(a,M-2);
B2=(M-1ll*b*A2%M)%M;
C1=(c1+1ll*c2*a1%M*L(a1,q))%M;
C2=(c1+1ll*c2*a1%M*L(a1,q-1))%M;
C0=(c0+1ll*c2*b1%M*(1ll*r*L(a1,q)%M+1ll*k*C(a1,q-1)%M))%M;
return solve(k,r,A1,B1,A2,B2,C1,C2,C0);}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)
	{int n,k,d;
	scanf("%d%d",&n,&k);
	d=G(n,k);n/=d,k/=d;
	printf("%d\n",1ll*solve(n,k,1,1,hf,1,1,1,0)*F(n,M-2)%M);}
	return 0;}
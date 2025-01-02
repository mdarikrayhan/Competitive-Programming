// LUOGU_RID: 159878949
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=mul(a,a))if(b&1)c=mul(c,a);
	return c;
}
int n,k;
int fac[N],ifac[N];
inline int C(int a,int b){
	if(b<0||a<b)return 0;
	return mul(fac[a],mul(ifac[b],ifac[a-b]));
}
int p,L,R,sum;
void move(int l,int r){
	while(R<r)sum=add(sum,C(p,++R));
	while(L>l)sum=add(sum,C(p,--L));
	while(R>r)sum=add(sum,mod-C(p,R--));
	while(L<l)sum=add(sum,mod-C(p,L++));
}
int main(){
	cin>>n>>k;
	if(n==k)return cout<<1<<endl,0;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i>=1;i--)ifac[i-1]=mul(ifac[i],i);
	p=0,L=1,R=0;
	int ans=0;
	for(int i=0;i<=k;i++){
		if(i+i<n){
			int l=max(max(k-i-i,0),k+k-i-i-n),r=min(n-i-i-1,k-i);
			l=min(l,r+1);
			move(k-i-r,k-i-l);
			ans=add(ans,sum);
			sum=add(sum,sum),sum=add(sum,add(C(p,L-1),mod-C(p,R))),p++;
		}else{
			ans=add(ans,C(n-i-1,k-i));
		}
	}
	cout<<ans<<endl;
	return 0;
}
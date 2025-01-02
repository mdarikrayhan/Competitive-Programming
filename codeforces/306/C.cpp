// LUOGU_RID: 160507521
#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ans=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return w*ans;
}
const int mod=1e9+9;
int w,b,n;
int p[1000005];
int pm[1000005];
int Pow(int x,int y){
	int push=x,ans=1;
	while(y){
		if(y&1)ans=push*ans%mod;
		push=push*push%mod;
		y>>=1;
	}
	return ans;
}
int C(int x,int y){
	if(x==y)return 1;
	if(y>x)return 0; 
	return p[x]*pm[y]%mod*pm[x-y]%mod;
}
int A(int x){
	return p[x];
}
signed main(){
	int ans=0;
	n=read(),w=read(),b=read();
	p[0]=1;
	for(int i=1;i<=4000;i++)p[i]=p[i-1]*i%mod;
	for(int i=0;i<=4000;i++)pm[i]=Pow(p[i],mod-2);
	for(int i=1;i<n;i++){//1-i 
		for(int j=i+1;j<n;j++){//j+1-n
			int k=j-i;
			if(k>b)continue;
			int q=i+n-j;
			if(q>w)continue;
			ans=(ans+(C(b-1,k-1)%mod*A(b)%mod) * (C(w-1,q-1)%mod*A(w)%mod)%mod)%mod;
		}
	}
	cout<<ans;
	return 0;
}
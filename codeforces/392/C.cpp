#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int quickpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}return ret;
}
int N=83;
int fac[105],inv[105];
void init(int n=100){
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=quickpow(fac[n],mod-2);
	for(int i=n-1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
struct mat{
	int a[105][105];
	mat(){
		memset(a,0,sizeof(a));
	}
	int* operator [](const int &x){
		return a[x];
	} 
};
mat operator *(mat A,mat B){
	mat ret;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				ret[i][j]+=A[i][k]*B[k][j]%mod;
				if(ret[i][j]>=mod) ret[i][j]-=mod;
			}
		}
	}return ret;
}
mat quickpow(mat A,int b){
	mat ret=A;b--;
	while(b){
		if(b&1) ret=ret*A;
		A=A*A;
		b>>=1;
	}return ret;
}
int n,k;
signed main(){
	cin>>n>>k;
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		cout<<1+quickpow(2,k+1);
		return 0;
	}
	init();
	mat A,B;
	for(int i=0;i<=k;i++){
		A[1][i+1+k+1]=1;
		A[1][i+1]=quickpow(2,i+1);
	}
	A[1][k*2+3]=1+quickpow(2,k+1);
//	for(int i=1;i<=k*2+3;i++){
//		cout<<A[1][i]<<' ';
//	}cout<<'\n';
	for(int i=0;i<=k;i++){
		for(int j=0;j<=i;j++){
			B[j+1][i+1]=C(i,j);
			B[j+1+k+1][i+1]=C(i,j)*quickpow(2,i-j)%mod;
			if(i==k){
				B[j+1][k*2+3]=C(i,j);
				B[j+1+k+1][k*2+3]=C(i,j)*quickpow(2,i-j)%mod;
			}
		}
		B[i+1][i+1+k+1]=1;
	}
	B[k*2+3][k*2+3]=1;
//	for(int i=1;i<=k*2+3;i++){
//		for(int j=1;j<=k*2+3;j++){
//			cout<<B[i][j]<<" ";
//		}cout<<'\n';
//	}cout<<'\n';
	B=quickpow(B,n-2);A=A*B;
	cout<<A[1][k*2+3];
}
/*
6 0
*/
					 							  		  	   				   	
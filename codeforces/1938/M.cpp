//Δ_M
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<20;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int add(int x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
	return x;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
void DFT(int *C,int n,int fl){
	int i,j,k,l;
	int u,v,w,cur;
	i=n>>1;
	for(j=1;j<n;j=j+1){
		if(i<j)
			swap(C[i],C[j]);
		for(k=n>>1;i&k;k>>=1)
			i^=k;
		i^=k;
	}
	for(l=2;l<=n;l<<=1){
		w=fpow(3,(MO-1)/l);
		if(fl==-1)
			w=fpow(w);
		for(i=0;i<n;i=i+l){
			cur=1;
			for(j=i;j<i+(l>>1);j=j+1){
				u=C[j],v=mul(C[j+(l>>1)],cur);
				C[j]=add(u,v),C[j+(l>>1)]=add(u,MO-v);
				cur=mul(cur,w);
			}
		}
	}
	if(fl==-1){
		int u=fpow(n);
		for(i=0;i<n;i++)
			C[i]=mul(C[i],u);
	}
}
int A[N],B[N],C[N];
void getinv(int*a,int*b,int n){
	int i,l;
	b[0]=1;
	for(l=1;l<n;l<<=1){
		for(i=0;i<(l<<1);i++)
			A[i]=a[i];
		for(i=0;i<l;i++)
			B[i]=b[i];
		DFT(A,l<<2,1);
		DFT(B,l<<2,1);
		for(i=0;i<(l<<2);i++)
			C[i]=mul(mul(B[i],B[i]),A[i]),A[i]=0,B[i]=0;
		DFT(C,l<<2,-1);
		for(i=0;i<l;i++)
			b[i]=mul(b[i],2);
		for(i=0;i<(l<<1);i++)
			ad(b[i],MO-C[i]);
	}
}
int n,a[N],b[N],c[N],f[N];
int main(){
	int T,i,j,l,x,y;
	n=300005;
	l=1<<20;
	f[0]=1;
	for(j=1;j<=1111;j++){
		for(i=n;i>=1;i--)
			f[i]=f[i-1];
		f[0]=0;
		for(i=j;i<=n;i++)
			ad(f[i],f[i-j]);
		if(j%2==0){
			y=j%4==0?MO-1:1;
			x=(j/2)*(j/2);
			for(i=x;i<=n;i++)
				ad(a[i],mul(y,f[i-x]));
		}
		else{
			y=j%4==3?MO-1:1;
			x=(j/2)*(j/2+1);
			for(i=x;i<=n;i++)
				ad(b[i],mul(y,f[i-x]));
			x=(j/2)*(j/2);
			for(i=x;i<=n;i++)
				ad(b[i],mul(y,f[i-x]));
		}
	}
	for(i=0;i<=n;i++)
		a[i]=(MO+(i==0)-a[i])%MO;
	getinv(a,c,l>>1);
	ad(b[0],2);
	DFT(b,l,1);
	DFT(c,l,1);
	for(i=0;i<l;i++)
		c[i]=mul(c[i],b[i]);
	DFT(c,l,-1);
	for(i=0;i<=n;i++)
		ad(c[i],MO-1);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",c[n]);
	}
	return 0;
}

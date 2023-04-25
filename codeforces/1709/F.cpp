#include<bits/stdc++.h>
using namespace std;const int N=524300, M=998244353, root=3;
int n,k,f,L,nn=1,i,j,t,vv,v[N],R[N];
int PM(int x,int n){int res=1;while(n){if(n&1)res=1LL*res*x%M;x=1LL*x*x%M;n>>=1;}return res;}
void ntt(int *x,int type){
	for(int i=0;i<nn;++i)if(i<R[i])swap(x[i],x[R[i]]);
	for(int i=1;i<nn;i<<=1){
		int wn=PM(root,type==1?(M-1)/(i<<1):M-1-(M-1)/(i<<1));
		for(int p=i<<1,j=0;j<nn;j+=p){
			int w=1;
			for(int k=0;k<i;++k,w=(1LL*w*wn)%M){
				int l=x[j+k],r=1LL*x[j+k+i]*w%M;
				x[j+k]=(l+r)%M;x[j+k+i]=((l-r)%M+M)%M;
			}
		}
	}
	if(type==-1){vv=PM(nn,M-2);for(int i=0;i<nn;++i)x[i]=1LL*x[i]*vv%M;}
}
int main(){
	for(scanf("%d%d%d",&n,&k,&f);nn<=2*k;nn<<=1,L++);
	for(i=1;i<nn;++i)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	for(i=0;i<=k;++i)v[i]=1;
	for(t=1;t<=n;++t){
		for(ntt(v,1),i=0;i<nn;++i)v[i]=1LL*v[i]*v[i]%M;ntt(v,-1);
		if(t!=n){
			for(i=nn-1,j=0;~i;--i){
				vv=v[i];
				if(i>k)v[i]=0;else v[i]=(1LL*vv*(k-i+1)+j)%M;
				j=(j+vv)%M;
			}
		}
	}printf("%d\n",v[f]);
}
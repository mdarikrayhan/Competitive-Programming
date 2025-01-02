#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,N=505;
int F,B,a[N],c[N],r[N],ans[N],tmp[N],t[N],A[N],Ans[N],maxn,p[N],n;
int qpow(int a,int b){
    int ans=1,base=a;
    while(b){
        if(b&1)ans=ans*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ans;
}
int inv(int x){
    return qpow(x,mod-2);
}
void Mul(int *f,int *g,int *ans){
	for(int i=0;i<2*maxn;++i)r[i]=0;
	for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            r[i+j]=(r[i+j]+f[i]*g[j]%mod)%mod;
        }
    }
	for(int i=2*maxn-2;i>=maxn;--i){
        for(int j=maxn-1;~j;--j){
            r[i+j-maxn]=(r[i+j-maxn]+mod-r[i]*c[j]%mod)%mod;
        }
    }
	for(int i=0;i<maxn;++i)ans[i]=r[i];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>F>>B>>n;
	for(int i=1;i<=F;++i)cin>>a[i];
	for(int i=1,x;i<=B;++i)cin>>x,maxn=max(maxn,x),++t[x];
	for(int i=0;i<maxn;++i)c[i]=mod-t[maxn-i];
	c[maxn]=1;
	for(int i=1;i<=F;++i){
		for(int j=0;j<maxn;++j)ans[j]=tmp[j]=0;
        if(maxn>1)tmp[1]=1;
        else tmp[0]=mod-c[0];
        int T=a[i];
        ans[0]=1;
        while(T){
            if(T&1)Mul(ans,tmp,ans);
            Mul(tmp,tmp,tmp);
            T>>=1;
        }
		for(int j=0;j<maxn;++j)A[j]=(A[j]+ans[j])%mod;
	}
    Ans[0]=p[0]=1;
    while(n){
        if(n&1)Mul(Ans,A,Ans);
        Mul(A,A,A);
        n>>=1;
    }
	for(int i=0;i<maxn;++i)for(int j=0;j<=i;++j)p[i]=(p[i]+t[j]*p[i-j]%mod)%mod;
	int answer=0;
	for(int i=0;i<maxn;++i)answer=(answer+Ans[i]*p[i]%mod)%mod;
	cout<<answer;
	return 0;
}
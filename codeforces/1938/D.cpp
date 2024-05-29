#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353,maxn=7;

int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

int n,m,Sum=0,b[10],a[10],fl[10],nf[10],g[210],p1[10],p2[10],c[10];
void dfs(int k,int las){
	if(k==0){
		int d=1;
		for(int i=1;i<=6;i++){
			int t=g[b[i]];
			d=(ll)d*p1[t]%mod;
		}
		for(int i=1;i<=7;i++){
			int t=6-g[a[i]];
			d=(ll)d*p2[t]%mod;
		}
		
		d=(ll)d*fl[7]%mod*fl[6]%mod;
		int las=0;
		for(int i=1;i<=7;i++){
			if(i==7||a[i]!=a[i+1]){
				d=(ll)d*nf[i-las]%mod;
				las=i;
			}
		}
		las=0;
		for(int i=1;i<=6;i++){
			if(i==6||c[i]!=c[i+1]){
				d=(ll)d*nf[i-las]%mod;
				las=i;
			}
		}
		
		Sum=(Sum+d)%mod;
		return ;
	}
	
	for(int i=0;i<=las;i++){
		for(int j=1;j<=6;j++){
			int t=(1<<(j-1));
			if(i&t) c[j]++,b[j]+=(1<<(k-1));
		}
		bool pd=true;
		for(int j=1;j<6;j++)
			if(c[j]>c[j+1]+(k-1)) {pd=false;break;}
		a[k]=i;
		if(pd) dfs(k-1,i);
		for(int j=1;j<=6;j++){
			int t=(1<<(j-1));
			if(i&t) c[j]--,b[j]-=(1<<(k-1));
		}
	}
}

int C(int n,int m){
	if(m<0||m>n) return 0;
	return (ll)fl[n]*nf[m]%mod*nf[n-m]%mod;
}

#define lowbit(x) ((x)&(-(x)))

int main()
{
	
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	scanf("%d%d",&n,&m);

	for(int i=1;i<=127;i++){
		g[i]=g[i-lowbit(i)]+1;
	}
	
	for(int i=0;i<=7;i++){
		for(int j=0;j<=i;j++)
			p1[i]=(p1[i]+mi(C(i,j),n/6))%mod;
	}
	
	for(int i=7;i>=0;i--){
		for(int j=0;j<i;j++){
			int t=(ll)p1[j]*mi(2,i-j)%mod*C(i,j)%mod;
			if((i-j)%2==1) p1[i]=(p1[i]-t+mod)%mod;
			else p1[i]=(p1[i]+t)%mod;
		}
	}
	
	for(int i=0;i<=6;i++){
		for(int j=0;j<=i;j++)
			p2[i]=(p2[i]+mi(C(i,j),m/7))%mod;
	}
	
	dfs(7,63);
	
	printf("%d\n",Sum);
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
int f[203][203][203];
void add(int &x,const int y){if((x+=y)>=mod)x-=mod;}
int mul(int a,int b){return 1ll*a*b%mod;}
int n,m;char s[203];
int qpow(int a,int b){
	int c=1;
	while(b){
		if(b&1)c=mul(c,a);
		a=mul(a,a),b>>=1;
	}return c;
}
int C(int x,int y){
	int res=1,inv=1;
	for(int i=x;i>=x-y+1;++i)res=mul(res,i);
	for(int i=1;i<=y;++i)inv=mul(inv,i);
	return mul(res,qpow(inv,mod-2));
}
int tt;
struct Dot{
	int a[404][404];
	void init(){
	    for(int i=0;i<tt;++i)
		 for(int j=0;j<tt;++j)a[i][j]=0;
	}
	void Init(){
		init();
		for(int i=0;i<tt;++i)a[i][i]=1;
	}
}F,G;
const int maxv=2e9;
Dot operator*(Dot a,Dot b){
	Dot c;
	c.init();
	for(int i=0;i<tt;++i)
	  for(int k=0;k<tt;++k)if(a.a[i][k])
	    for(int j=0;j<tt;++j){
	    	c.a[i][j]+=a.a[i][k]*b.a[k][j];
	    	if(c.a[i][j]>=maxv)c.a[i][j]%=mod;
		}
	for(int i=0;i<tt;++i)
	   for(int j=0;j<tt;++j)if(c.a[i][j]>=mod)c.a[i][j]%=mod;
	return c;
}
Dot Qpow(Dot a,int b){
	Dot c;c.Init();
	while(b){if(b&1)c=c*a;a=a*a;b>>=1;}
	return c;
}
int dp[203],dp1[203];
int id[233][2];
int solve(int x){
memset(dp1,0,sizeof(dp1));
    for(int i=1;i<=n+1;++i){
    	int j=i-1;
    	if(j>=0)
    	   for(int k=0;k<=n;++k)
    	    if(f[i][j][k])add(dp1[k],f[i][j][k]);
	}
	tt=0;
	for(int i=0;i<=n;++i){
		id[i][0]=id[i][1]=-1;
		if(i%2==0)id[i][0]=tt++;
		id[i][1]=tt++;
	}
	++tt;
	G.init(),F.init();
	G.a[tt-1][tt-1]=26;
	for(int i=0;i<=n;++i)
		for(int j=0;j<2;++j){
			if(id[i][j]<0)continue;
			G.a[id[i][j]][id[i][j]]=((!j)?25:24);
			if(i==n){
				if(j)G.a[id[i][j]][tt-1]=1;
				else G.a[id[i][j]][tt-1]=dp1[i>>1];
			}
			if(i+2<=n&&!j)G.a[id[i][j]][id[i+2][j]]=1;
			if(i+1<=n){
				if(!j)G.a[id[i][j]][id[i+1][1]]=dp1[i>>1];
				else G.a[id[i][j]][id[i+1][j]]=1; 
			}
		}
	F.a[0][id[2][0]]=1;
	F.a[0][id[1][1]]=dp1[0];
	F=F*Qpow(G,x);
	int Ans=F.a[0][tt-1];
	memset(dp1,0,sizeof(dp1));
    for(int i=1;i<=n;++i){
    	int j=i;
    	for(int k=0;k<=n;++k)
    	    add(dp1[k],f[i][j][k]);
	}
	tt=0;
	for(int i=0;i<=n;++i){
		id[i][0]=id[i][1]=-1;
		if(i%2==0)id[i][0]=tt++;
		id[i][1]=tt++;
	}
	++tt;
	G.init(),F.init();
	G.a[tt-1][tt-1]=26;
	for(int i=0;i<=n;++i)
		for(int j=0;j<2;++j){
			if(id[i][j]<0)continue;
			if(i==n)G.a[id[i][j]][id[i][j]]=25;
			else G.a[id[i][j]][id[i][j]]=((!j)?25:24);
			if(i==n){
				if(j)G.a[id[i][j]][tt-1]=1;
				else G.a[id[i][j]][tt-1]=dp1[i>>1];
			}
			if(i+2<=n&&!j)G.a[id[i][j]][id[i+2][j]]=1;
			if(i+1<=n){
				if(!j)G.a[id[i][j]][id[i+1][1]]=dp1[i>>1];
				else G.a[id[i][j]][id[i+1][j]]=1; 
			}
		}
	F.a[0][id[2][0]]=1;
	F.a[0][id[1][1]]=dp1[0];
	F=F*Qpow(G,x);
	add(Ans,F.a[0][tt-1]);
	return Ans;
}
int solve1(int x){
	memset(dp1,0,sizeof(dp1));
    for(int i=1;i<=n;++i){
    	for(int k=0;k<=n;++k)
    	  if(f[i][i][k])add(dp1[k],f[i][i][k]);
	}
	tt=0;
	for(int i=0;i<n;++i){
		id[i][0]=id[i][1]=-1;
		if(i%2==0)id[i][0]=tt++;
		id[i][1]=tt++;
	}
	++tt;
	G.init(),F.init();
	G.a[tt-1][tt-1]=25;
	for(int i=0;i<n;++i)
		for(int j=0;j<2;++j){
			if(id[i][j]<0)continue;
			if(i<=n-1)G.a[id[i][j]][id[i][j]]=((!j)?25:24);
		    if(i==n-1){
		    	if(j)G.a[id[i][j]][tt-1]=1;
		    	else G.a[id[i][j]][tt-1]=dp1[i>>1];
			}
			if(i+2<n&&!j)G.a[id[i][j]][id[i+2][j]]=1;
			if(i+1<n){
				if(!j)G.a[id[i][j]][id[i+1][1]]=dp1[i>>1];
				else G.a[id[i][j]][id[i+1][1]]=1;
			}
		}
	if(n-1>=2)F.a[0][id[2][0]]=1;
	F.a[0][id[1][1]]=dp1[0];
	F=F*Qpow(G,x);
	int Ans=F.a[0][tt-1];
	return Ans;
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	cin>>m,m+=n;
	if(n==1){
		int ans=qpow(26,(m+1>>1));
		add(ans,mod-qpow(25,(m+1>>1)));
		cout<<ans;
		exit(0);
	}
	f[1][n][0]=1;
	for(int i=1;i<=n;++i)
	  for(int j=n;j>i;--j){
	  	if(s[i]==s[j]){
	  		for(int k=0;k<=n;++k)
	  		  if(f[i][j][k])add(f[i+1][j-1][k+1],f[i][j][k]);
		}else{
			for(int k=0;k<=n;++k)
	  		  if(f[i][j][k])add(f[i+1][j][k],f[i][j][k]),add(f[i][j-1][k],f[i][j][k]);
		}
	  }
	if(!(m&1)){cout<<solve(m>>1);return 0;}
	int ans=solve(m/2);ans=mul(ans,26);
	add(ans,solve1(m/2));
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,c,A,f[1<<20],r[1<<20],D=998244353;
string s,t; 
main(){
	cin>>T,r[1]=1;
	for(int i=2;i<=1e6;i++)
		r[i]=(D-D/i)*r[D%i]%D;
	while(T--&&cin>>n>>s>>t){
		c=A=0,f[n]=1;
		for(int i=0;i<n;i++)
			c+=s[i]^t[i];
		for(int i=n-1;i;i--)
			f[i]=(n+(n-i)*f[i+1])%D*r[i]%D;
		for(int i=1;i<=c;i++)
			(A+=f[i])%=D;
		cout<<A<<'\n';
	}
}
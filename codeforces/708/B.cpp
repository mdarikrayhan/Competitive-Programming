// LUOGU_RID: 159789568
#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll s=0,k=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*k;
}

ll a,b,c,d,n,m,cnt;
char s[1000010];

int main(){
	a=read();b=read();c=read();d=read();
	n=sqrt(a<<1)+1;
	m=sqrt(d<<1)+1;
	if(n*(n-1)/2!=a||m*(m-1)/2!=d) return !!puts("Impossible");
	if(a+b+c+d==0) return !!puts("0");
	if(m&&a+b+c==0){
		for(int i=1;i<=m;i++) printf("1");
		return 0;
	}
	if(n&&b+c+d==0){
		for(int i=1;i<=n;i++) putchar('0');
		return 0;
	}
	if(n*m!=b+c) return !!puts("Impossible");
	ll k=b/n,p=b%n;
	for(int i=1;i<=m-k-1;i++) s[++cnt]='1';
	ll tot=cnt;
	for(int i=1;i<=p;i++) s[++cnt]='0';
	if(tot+k+1<=m) s[++cnt]='1';
	for(int i=1;i<=n-p;i++) s[++cnt]='0';
	for(int i=1;i<=k;i++) s[++cnt]='1';
	for(int i=1;i<=cnt;i++) putchar(s[i]);
	return 0;
}

// LUOGU_RID: 159169076
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

ll n,m,k;

void solve(){
	n=read();m=read();k=read();
	ll ans=1e18+7;
	if(m>n*(n-1)/2){
		puts("NO");
		return ;
	}
	
	if(m>=n-1){
		ans=2;
		if(m>=n*(n-1)/2){
			ans=1;
		}
	} 
	if(n==1) ans=0;
	if(ans<k-1) puts("YES");
	else puts("NO"); 
}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ll T=read();
	while(T--) solve();
	return 0;
}

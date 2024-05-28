// LUOGU_RID: 160424892
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=505;
int n;
int a[N],f[N];
ll pw[N];
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(~a[i]) ++f[a[i]];
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=n;i++)
		if(a[i]<0) ans=(ans+1-pw[f[i]]+mod)%mod;
	ans=(ans+pw[n-1]-1+mod)%mod;
	printf("%lld",ans); 
 	return 0;
} 
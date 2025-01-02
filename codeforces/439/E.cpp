// LUOGU_RID: 160470380
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f; 
}
const int mxn=1e6,md=1e9+7;
bool vis[mxn+10];
int prime[mxn+10],cnt,mu[mxn+10],pw[mxn+10],inv[mxn+10],finv[mxn+10];
int C(int x,int y){
	if(x>y)return 0;
	return pw[y]*finv[x]%md*finv[y-x]%md;
}
void init(){
int n = 100000;
pw[0] = pw[1] = inv[1] = finv[1] = inv[0] = finv[0] = 1;
for(int i = 2;i <= n;i ++){
pw[i] = (pw[i - 1] * i) % md;
inv[i] = (md - md / i) * inv[md % i] % md;
}
for(int i = 2;i <= n;i ++)finv[i] = (finv[i - 1] * inv[i]) % md;
mu[1] = 1;
for(int i = 2;i <= n;i ++){
if(!vis[i]){
prime[++ cnt] = i;
mu[i] = -1;
}
for(int j = 1;j <= cnt && i * prime[j] <= n;j ++){
vis[i * prime[j]] = true;
if(i % prime[j])mu[i * prime[j]] = -mu[i];
else break;
}
}
}
signed main(){
// 	freopen("in.txt","r",stdin);
// 	freopen("out.txt","w",stdout);
	init();
	int T=read();
	while(T--){
		int n=read(),m=read();
		int ans=0;
		for(int i=1;i*i<=n;i++){
			if(n%i==0){
				ans=(ans+mu[i]*C(m-1,n/i-1))%md;
				if(n/i!=i)ans=(ans+mu[n/i]*C(m-1,i-1))%md;
			}
		}
		printf("%lld\n",(ans+md)%md);
	}
    return 0;
}
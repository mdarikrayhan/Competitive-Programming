// LUOGU_RID: 157472261
#include<bits/stdc++.h>
#define ll long long
#define pir pair<ll,ll>
#define fi first
#define se second
#define pii pair<line,ll>
#define mkp make_pair
#define pb push_back
using namespace std;
const ll maxn=1e5+10, inf=2e9, mod=1e9+7;
char s[maxn]; ll n, a[maxn], t;
char dc(ll x) {return x<=9? x+'0':x-10+'a';}
ll ec(char c) {return c<='9'? c-'0':c-'a'+10;}
bool chk(ll x) {return x>=0&&x<=15;} ll hh[1<<14];
ll d[maxn], w[maxn], r[maxn], f[1<<14], sum[1<<14], ans=5e18, pw[maxn];
void solve(){
	memset(f,0x3f,sizeof f);
	for(ll i=1;i<=n;i++) f[1<<i-1]=0;
	for(ll S=1;S<(1<<n);S++){ sum[S]=sum[S&(S-1)]+r[hh[S&-S]+1];
		for(ll j=1;j<=n;j++)
			if(!(S&(1<<j-1))){
				ll x=sum[S];
				if(chk(x))
					f[S|(1<<j-1)]=min(f[S|(1<<j-1)],f[S]+x*pw[j-1]);
			}
	} ans=min(ans,f[(1<<n)-1]);
}
void dfs(ll i,ll j){
	if(i==n){
		for(ll k=1;k<=n;k++) w[k]=0;
		for(ll k=1;k<n;k++)
			if(d[k]) --w[k+1], w[k]+=16;
		for(ll k=1;k<=n;k++) r[k]=a[k]-w[k];
		solve();
	}
	if(n-1-i>=t-j){
		d[i]=0; dfs(i+1,j);
	}
	if(j<t){
		d[i]=1; dfs(i+1,j+1);
	}
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(ll i=0;i<n;i++) hh[1<<i]=i;
	pw[0]=1;
	for(ll i=1;i<=n;i++) pw[i]=pw[i-1]*16;
	for(ll i=1;i<=n;i++) a[i]=ec(s[n-i+1]), t+=a[i];
	if(t%15) {puts("NO"); return 0;} t/=15;
	dfs(1,0);
	if(ans>4e18) puts("NO");
	else{
		for(ll i=n;i;i--) putchar(dc(ans/pw[i-1]%16));
	}
	return 0;
}
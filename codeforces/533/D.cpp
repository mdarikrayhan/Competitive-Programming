// LUOGU_RID: 158156553
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mkp make_pair
#define pir pair<ll,ll>
#define ull unsigned ll
#define pb push_back
using namespace std;
const ll maxn=2e5+10;
ll n,a[maxn],d[maxn],stk[maxn],top,ans=1e17;
ll pos1[maxn], val1[maxn], l1;
ll pos2[maxn], val2[maxn], l2;
int main(){
	scanf("%lld",&n);
	for(ll i=0;i<=n+1;i++) scanf("%lld",a+i);
	for(ll i=1;i<=n;i++) scanf("%lld",d+i), d[i]<<=1;
	for(ll i=1;i<=n+1;i++){
		while(top&&d[stk[top]]<a[i]-a[stk[top-1]]){
			ll r=a[stk[top-1]]+d[stk[top]];
			if(r<=pos1[l1]) {--top; continue;}
			++l1, pos1[l1]=r, val1[l1]=a[stk[top]];
			--top;
		}
		++l1, pos1[l1]=a[i], val1[l1]=a[stk[top]];
		if(i<=n&&a[i]-a[stk[top]]<d[i]) stk[++top]=i;
	}
	if(top) {puts("0"); return 0;}
	top=0, stk[0]=n+1;
	for(ll i=n;~i;i--){
		while(top&&d[stk[top]]<a[stk[top-1]]-a[i]){
			ll l=a[stk[top-1]]-d[stk[top]];
			if(l>=pos2[l2]) {--top; continue;}
			++l2, pos2[l2]=l, val2[l2]=a[stk[top]];
			--top;
		}
		++l2, pos2[l2]=a[i], val2[l2]=a[stk[top]];
		if(i&&a[stk[top]]-a[i]<d[i]) stk[++top]=i;
	} pos2[l2+1]=a[n]+1;
	reverse(pos2+1,pos2+1+l2);
	reverse(val2+1,val2+1+l2);
	for(ll i=1,j=1;i<=l1;i++){
		while(j<=l2&&pos1[i-1]>=pos2[j+1]) ++j;
		while(j<=l2&&pos2[j]<=pos1[i]) ans=min(ans,val2[j]-val1[i]), ++j;
		if(j>1) --j;
	} printf("%lld.%lld",ans>>1,(ans&1? 5:0));
	return 0;
}
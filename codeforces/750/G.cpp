// LUOGU_RID: 156173172
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,f[54][104][2];
int main(){
	scanf("%lld",&n);
	ans=1;
	for(ll i=1;;i++){
		ll k=(1ll<<i+1);
		--k;
		if(k>n) break;
		ll x=n/k, tmp=n-k*x;
		for(ll j=i;j;j--)
			if(tmp>=(1ll<<j)-1) tmp-=(1ll<<j)-1;
		if(tmp==0) ++ans;
	}
	for(ll i=1;(1ll<<i+1)-1<=n;i++)
		for(ll j=1;(1ll<<i+1)+(1ll<<j+1)+(1ll<<j)-4<=n;j++){
			ll x=(n-(1ll<<j)+1)/((1ll<<i+1)+(1ll<<j+1)-3),
			tmp=n-(1ll<<j)+1-((1ll<<i+1)+(1ll<<j+1)-3)*x;
			for(ll p=0;p<i+j;p++){
				ll t=tmp+p, o=max(i,j)+1;
				if((t>>o)||(t&1)) continue;
				memset(f,0,sizeof f);
				f[1][0][0]=1;
				for(ll k=2;k<=o;k++){ ll c=(t>>k-1)&1;
					for(ll l=0;l<=p;l++){
						for(ll w1=0;w1<=(i>=k);w1++)
							for(ll w2=0;w2<=(j>=k);w2++){
								if(c==(w1+w2&1)) f[k][l+w1+w2][w1+w2>=2]+=f[k-1][l][0];
								if(c==(w1+w2+1&1)) f[k][l+w1+w2][w1+w2>=1]+=f[k-1][l][1];
							}
					}
				} ans+=f[o][p][0];
			}
		} printf("%lld",ans);
	return 0;
}
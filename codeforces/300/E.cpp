// LUOGU_RID: 157772382
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+5;
const int M=1e6+10;

int p[M],tot,mip[N];
ll mx;
bool isp[N];

void ini(){
	for(int i=2;i<=mx;++i){
		if(!isp[i])p[++tot]=i,mip[i]=tot;
		for(int j=1;j<=tot&&p[j]*i<=mx;++j){
			isp[p[j]*i]=true;
			mip[p[j]*i]=j;
			if(i%p[j]==0)break;
		}
	}
}

ll a[M],cnt[M],diff[N];

ll PinN(ll n,ll p){
    ll res=0;
    while(n>1){
        n/=p;
        res+=n;
    }
    return res;
}


bool check(ll x){
	for(int i=1;i<=tot;++i){
		if(PinN(x,p[i])<cnt[i])return false;
	}
	return true;
}

void llz(){
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i],mx=max(mx,a[i]),diff[1]++,diff[a[i]+1]--;
	for(int i=1;i<=mx;++i)diff[i]+=diff[i-1];
	ini();
	for(int i=1;i<=mx;++i){
		int t=i;
		while(t>1){
			cnt[mip[t]]+=diff[i];
			t/=p[mip[t]];
		}
	}
	ll l=mx,r=sum+10;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
}	

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
}
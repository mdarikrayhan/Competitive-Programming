#include<bits/stdc++.h>
using namespace std;
#define rd(i,n) for(int i=0;i<n;i++)
#define rp(i,n) for(int i=1;i<=n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=b;i>=a;i--)
#define st string
#define vt vector
#define pb push_back
//#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=200005;
ll n,m,l,r;
vt<int>fac[N];
map<int,int>mp;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>l>>r;
	rep(i,1,max(n,m)){
		for(int j=i;j<=max(n,m);j+=i)fac[j].pb(i);
	}
	//x=1
	//对于x找出t，要求是t/gcd(x,t)的若干倍数在L,min(m,R)之间
	ll L=min(m+1,l),R=min(m,r);
	for(ll i=L;i<=R;i++){
		for(auto t:fac[i])mp[t]++;
	}
	rep(i,1,n){
		ll nL=min(m+1,(l+i-1)/i),nR=min(m,r/i);
//		cout<<nL<<" "<<nR<<endl;
		//L越来越小，R越来越小
		while(nL<L){
			L--;
			if(L<=m)for(auto t:fac[L])mp[t]++;
		}
		while(nR<R){
			if(R<=m)for(auto t:fac[R]){
				mp[t]--;
				if(!mp[t])mp.erase(t);
			}
			R--;
		}
		//y应该在nL到nR之间
		bool flag=0;
		for(auto g:fac[i]){
			ll lt=i/g+1,rt=n/g;
			auto lk=mp.lower_bound(lt);
			auto rk=mp.lower_bound(rt+1);
			if(lk!=rk){
				ll k=lk->first;
				//现在找到了k满足k*g在i到n之间，并且
				//k*g=t？
				//k的若干倍数在[L,R]之间
				cout<<i<<" "<<(L+k-1)/k*k<<" "<<k*g<<" "<<(L+k-1)/k*i/g<<'\n';
				flag=1;
				break;
			}
		}
		if(!flag)cout<<-1<<'\n';
	}

	
	return 0;
}
//Rain Rain Rain
		  	  		 		  		  				 	      	
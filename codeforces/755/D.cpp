#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6+5;

int n,k,bit[MAX],nw;
long long ans;

inline void upd(int i,int val){
	++i;
	for(; i<=n; i+=i&-i)bit[i]+= val;
}

int ret;
inline int que(int i){
	++i, ret = 0;
	for(; i; i-=i&-i)ret+= bit[i];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	k = min(k, n-k);
	upd(0,1);
	ans = 1;
	--k;
	for(int i = 0; i<n; ++i){
		ans+= que(nw);
		cout<<ans<<" ";
		if(nw-k<0){
			upd(nw-k+n,1);
			upd(0,1);
			upd(nw+k+1,-1);
		}
		else {
			upd(nw-k,1);
			if(nw+k<n){
				upd(nw+k+1,-1);
			}
			else {
				upd(0,1);
				upd(nw+k+1-n,-1);
			}
		}
		nw = (nw+k+1)%n;
	}
	cout<<endl;
	return 0;
}
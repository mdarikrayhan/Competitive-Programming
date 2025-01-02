#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll l,r,cnt[10],ans; 
vector<ll>L,R;
void solve(vector<ll>&num,ll x){while(x)num.push_back(x%10),x/=10;}
bool check(ll p,bool sj,bool xj){
	if(p==-1||sj+xj==0) return 1;
	ll lf=sj?L[p]:0,rf=xj?R[p]:9;
	for(ll i=lf;i<=rf;i++){
		if(cnt[i]){
			cnt[i]--;
			if(check(p-1,sj&&(i==lf),xj&&(i==rf))){cnt[i]++;return 1;}
			cnt[i]++;
		}
	}
	return 0;
}
void dfs(ll x,ll s){
	if(x==9){cnt[x]=s;ans+=check(R.size()-1,1,1);return;}
	for(ll i=0;i<=s;i++){cnt[x]=i;dfs(x+1,s-i);}
}
int main(){
	cin>>l>>r;
	solve(R,r);solve(L,l);
	for(ll i=L.size();i<R.size();i++)L.push_back(0);
	dfs(0,R.size());
	cout<<ans<<endl;
	return 0;
}
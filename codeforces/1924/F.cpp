#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+5;
int n;
int dp[N],sp[N];
int ask(vector<int>&v){
	cout << "? " << v.front() << ' ' << v.back() << endl;
	int res;cin >> res;
	return res==(v.back()-v.front());
}
vector<int>boom(vector<int>v){
	int m=v.size();
	if(m<3) return v;
	vector<int>nv;
	int p=sp[m];
	vector<int>a,b,c;
	for(int i=0; i<m ;i++){
		if(a.size()<p) a.push_back(v[i]);
		else if(b.size()<p) b.push_back(v[i]);
		else c.push_back(v[i]);
	}
	int r1=ask(a);
	int r2=ask(b);
	if(r1==r2){
		r1=ask(a);
		if(r1==r2){
			for(auto p:a) nv.push_back(p);
			for(auto p:b) nv.push_back(p);
			return boom(nv);
		}
	}
	{
		int r3=ask(c);
		if(r1==r3){
			for(auto p:a) nv.push_back(p);
			for(auto p:c) nv.push_back(p);
		}
		else{
			for(auto p:b) nv.push_back(p);
			for(auto p:c) nv.push_back(p);
		}
		return boom(nv);
	}
}
void solve(){
	cin >> n;
	vector<int>v(n);
	for(int i=1; i<=n ;i++) v[i-1]=i;
	auto res=boom(v);
	for(auto x:res){
		cout << "! " << x << endl;
		int res;cin >> res;
		if(res==1) break;
	}
	cout << "#" << endl;
}
int main(){
	ios::sync_with_stdio(false);
	sp[2]=1;
	for(int i=3; i<=100000 ;i++){
		sp[i]=sp[i-1];
		dp[i]=max(4+dp[i-sp[i]],3+dp[2*sp[i]]);
		while(2*(sp[i]+1)<i){
			int np=sp[i]+1;
			int ndp=max(4+dp[i-np],3+dp[2*np]);
			if(ndp<=dp[i]) sp[i]=np,dp[i]=ndp;
			else break;
		}
	}
	int t;cin >> t;
	while(t--) solve();
}
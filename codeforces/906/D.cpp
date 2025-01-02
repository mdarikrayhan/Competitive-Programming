// LUOGU_RID: 159219520
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005];
vector<int> v;
int query(int x){
	int ans=x;
	for(int i=2; i*i<=x; i++){
		if(!(x%i)){
			ans*=(i-1);
			ans/=i;
			while(!(x%i)) x/=i;
		}
	}
	if(x!=1) ans*=(x-1),ans/=x;
	return ans;
}
bool f=false;
int quick_pow(int a,int b,int mod){
	if(!b) return 1ll;
	int sum=quick_pow(a,b>>1,mod);
	sum*=sum,f|=(sum>=mod),sum%=mod;
	if(b&1) sum*=a,f|=(sum>=mod),sum%=mod;
	return sum;
}
int help(int l,int r,int id){
	if(v[id]==1||l>r) return 1;
	int mod=v[id];
	int P=help(l+1,r,id+1);
	f=false;
	return quick_pow(a[l],P,mod)+(f?mod:0);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	v.push_back(m);
	while(m!=1){
		m=query(m);
		v.push_back(m);
	}
	for(int i=1; i<=n; i++)
		cin>>a[i];
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<help(l,r,0)%v[0]<<'\n';
	}
	return 0;
}
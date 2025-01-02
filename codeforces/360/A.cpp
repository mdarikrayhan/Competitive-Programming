#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;cin>>n>>m;
	vl a(n,1e9);
	vector<array<ll,4>> ops(m);
	rep(i,0,m)rep(j,0,4)cin>>ops[i][j];
	rep(i,0,m)ops[i][1]--,ops[i][2]--;
	for(int i = m-1; i>=0; i--){
		if(ops[i][0]==1){
			rep(j,ops[i][1],ops[i][2]+1) a[j]-=ops[i][3];
		}else{
			assert(ops[i][0]==2);
			rep(j,ops[i][1],ops[i][2]+1) a[j]=min(a[j], ops[i][3]);
		}
	}
	vl o=a;
	bool good = true;
	rep(i,0,m){
		if(ops[i][0]==1){
			rep(j,ops[i][1],ops[i][2]+1) a[j]+=ops[i][3];
		}else{
			assert(ops[i][0]==2);
			ll mx = a[ops[i][1]];
			rep(j,ops[i][1]+1,ops[i][2]+1) mx=max(mx, a[j]);
			if(mx!=ops[i][3]) {
				good=false;
				break;
			}
		}
	}
	if(good){
		cout<<"YES\n";
		for(ll x : o)cout<<max(min(x,(ll)1e9),(ll)-1e9)<<' ';
		cout<<'\n';
	}else cout<<"NO\n";
}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 505;
const ll mod = 998244353;

int n,a[N<<1][N],v[N],c[N][N];

void solve(){
	cin>>n;
	memset(c,0,sizeof c);
	memset(v,0,sizeof v);
	for (int i=1; i<=n+n; i++){
		for (int j=1; j<=n; j++){
			cin>>a[i][j];
			c[a[i][j]][j]++;
		}
	}
	ll ans=1;
	vector<int> vc;
	for (int i=1; i<=n; i++){
		int cur=0;
		for (int j=1; j<=n+n; j++){
			if (!v[j]){
				for (int k=1; k<=n; k++){
					if (c[a[j][k]][k]==1){
						cur=j;
						break;
					}
				}
				if (cur){
					break;
				}
			}
		}
		if (!cur){
			ans=ans*2%mod;
			cur=1;
			while (v[cur]){
				cur++;
			}
		}
		v[cur]=1;
		for (int j=1; j<=n+n; j++){
			if (!v[j]){
				for (int k=1; k<=n; k++){
					if (a[j][k]==a[cur][k]){
						v[j]=1;
						break;
					}
				}
				if (v[j]){
					for (int k=1; k<=n; k++){
						c[a[j][k]][k]--;
					}
				}
			}
		}
		for (int j=1; j<=n; j++){
			c[a[cur][j]][j]--;
		}
		vc.push_back(cur);
	}
	cout<<ans<<"\n";
	for (auto u : vc){
		cout<<u<<" ";
	}
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while (t--){
		solve();
	}
	return 0;
}

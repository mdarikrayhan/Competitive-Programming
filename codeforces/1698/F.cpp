#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 505;

int n,a[N],b[N];
vector<pair<int,int> > ans;

void rev(int l,int r){
	ans.push_back({l,r});
	reverse(a+l,a+r+1);
}

int sol(int i){
	for (int j=i; j<n; j++){
		if (a[j]==b[i] && a[j+1]==b[i-1]){
			rev(i-1,j+1);
			return 1;
		}
	}
	for (int p=i; p<n; p++){
		if (a[p]==b[i-1] && a[p+1]==b[i]){
			bool f=0;
			for (int j=i-1; j<=p && !f; j++){
				for (int k=p+1; k<=n && !f; k++){
					if (a[j]==a[k]){
						rev(j,k),f=1;
					}
				}
			}
			if (!f){
				return 0;
			}
			for (int j=i; j<n; j++){
				if (a[j]==b[i] && a[j+1]==b[i-1]){
					rev(i-1,j+1);
					return 1;
				}
			}
		}
	}
	return 0;
}

void solve(){
	cin>>n;
	ans.clear();
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	for (int i=1; i<=n; i++){
		cin>>b[i];
	}
	if (a[1]!=b[1] || a[n]!=b[n]){
		cout<<"NO\n";
		return;
	}
	for (int i=1; i<=n; i++){
		if (a[i]!=b[i] && !sol(i)){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	cout<<ans.size()<<"\n";
	for (auto u : ans){
		cout<<u.first<<" "<<u.second<<"\n";
	}
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

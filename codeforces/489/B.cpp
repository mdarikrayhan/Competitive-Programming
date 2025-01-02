#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back 

void solve(){
	int n,m;
	cin>>n;
	vector<int> a(n);
	for(auto &i: a) cin>>i;
	cin>>m;
	vector<int> b(m);
	for(auto &i: b) cin>>i;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int j=0, cnt=0;
	for(int i=0; i<n; i++){
		if(j>=m) break;

		if(abs(a[i]-b[j])<=1 ){
			cnt++;
			j++;
		}
		else if(b[j]<a[i]){
			i--;
			j++;
		}
	}
	cout<<cnt<<endl;

}

int32_t main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t=1;
	while(t--){
	solve();
	}
	return 0;
}
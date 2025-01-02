#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define pob pop_back
#define read(a) int a;cin>>a
#define MOD 1000000007
#define int ll
using namespace std;
typedef long long ll;
typedef vector<long long>vll;
const double Pi=3.141592653589793;
const int maxn = 10001;
const int INF = 1e9;
int tc = 1;
int check(int a){
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0) return 0;
	}
	return (a > 1);
}
void solve(){
	int n; cin >> n;
	int a[n], sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(check(sum)){
		int ok = 0;
		cout << n - 1 << endl;
		for(int i = 0; i < n; i++){
			if(ok == 0 && a[i] % 2){
				ok = 1;
			}
			else{
				cout << i + 1 << " ";
			}
		}
	}
	else{
		cout << n << endl;
		for(int i = 1; i <= n; i++) cout << i << " ";
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin >> tc;
    while(tc--){
	solve();
	cout <<endl;
}
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;
#define pb  push_back
#define pf  push_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second
const ll mod = 1e9 + 7;
const int N = 1e5;
const ll INF = 1e18;
vll s(25, 0), need(25, 0), has(25, 0);
ll n;
void rec(ll num, ll k){
	if(k == n){
		for(ll i = 0; i < n; i++){
			if(has[i] != need[i]) return;
		}
		cout << "YES" << '\n';
		exit(0);
		return;
	}
	while(s[num]==0) num--;
	has[k] = 1;
	need[k] = num;
	for(ll i = 0; i < k; i++){
		if(num + 1 < need[i] && has[i] + num <= need[i]){
			has[i] += num;
			s[num]--;
			rec(num, k+1);
			has[i] -= num;
			s[num]++;
			if(num == 1) break;	
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(ll i = 0 ;i < n; i++){
		ll x;cin >> x;
		s[x]++;
	}
	if(s[n] != 1){
		cout << "NO" << '\n';
		return 0;
	}
	if(s[1] * 2 <= n){
		cout << "NO" << '\n';
		return 0;
	}
	need[0] = n;
	has[0] = 1;
	rec(n-1, 1);
	cout << "NO" << '\n';
	return 0;
}
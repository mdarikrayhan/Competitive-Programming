#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const ll mod = 998244353;

ll add(ll a, ll b) {
	return (a % mod + b % mod) % mod;
}

ll mul(ll a, ll b) {
	return ((a % mod) * (b % mod)) % mod;
}

ll sub(ll a, ll b) {
	return (a - b + mod) % mod;
}

void ask(int a, int b, int c, int d) {
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
}

int getMxInd(int n) {
	vector<int> can;
	for(int i=0;i<n;i++) can.push_back(i);
	while(can.size()!=1) {
		vector<int> nxtCan;
		int m=can.size();
		for(int i=0;i<m;i+=2){
			if (i==m-1) {
				nxtCan.push_back(can[i]);
			} else {
				ask(can[i], can[i], can[i+1], can[i+1]);
				char ans; cin >> ans;
				if(ans=='>'){
					nxtCan.push_back(can[i]);
				} else nxtCan.push_back(can[i+1]);
			}
		}
		can=nxtCan;
	}
	return can[0];
}

int getMxOrInd(int mx, int n){
	vector<int> can;
	/*for (int i = 0; i < n; i++) if (i != mxInd) { 
		ask(i,mxInd, mxInd, mxInd);
		char ans;cin>>ans;
		if(ans=='=' || ans=='>'){
			can.push_back(i);
		}
	}*/
	
	can.push_back(0);
	int ans2=0;
	for(int i=1;i<n;i++) if(i!=mx){
		ask(mx,ans2, mx,i);
		char c; cin>>c;
		if(c=='<'){
			can.clear();
			can.push_back(i);
			ans2=i;
		} else if(c=='=') can.push_back(i);
	}
	while(can.size()!=1){
		vector<int> nxtCan;
		int m=can.size();
		for(int i=0;i<m;i+=2){
			if(i==m-1){
				nxtCan.push_back(can[i]);
			} else {
				ask(mx, can[i], mx, can[i+1]);
				char ans; cin>>ans;
				if(ans=='='){
					// take smaller b/w can[i] and can[i+1]
					ask(can[i], can[i], can[i+1], can[i+1]);
					char cmp;cin>>cmp;
					if (cmp == '>') nxtCan.push_back(can[i + 1]);// Can it be avoided?
					else nxtCan.push_back(can[i]);
				}
				else if(ans=='>'){
					nxtCan.push_back(can[i]);
				} else nxtCan.push_back(can[i+1]);
			}
		}
		can=nxtCan;
	}
	return can[0];
}

void solve(int tc) {
	int n;cin>>n;
	int mxInd = getMxInd(n);
	int mxOrInd = getMxOrInd(mxInd, n);
	cout << "! " << mxInd << " " << mxOrInd << endl;
	cout.flush();
}

int main() {
	/*freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);*/
	int t = 1;
	bool multi = true;
	if (multi)
		cin >> t;
	for (int i = 0; i < t; i++) {
		solve(i);
	}
}
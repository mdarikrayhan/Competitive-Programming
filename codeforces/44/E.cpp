#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vlli;
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
	FastIO
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);


	// Your code goes here
	ll k, a, b;
	cin >> k >> a >> b;

	string s;
	cin >> s;

	int n = s.size();

	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		v[i] = a;
	}

	if (n < (k * a)) {
		cout << "No solution" << endl;
	}
	else if (n > (k * b)) {
		cout << "No solution" << endl;
	}
	else {
		int left = n - (k * a);
		int diff = b - a;
		for (int i = 0; i < k; i++) {
			if (left > diff) {
				v[i] = b;
				left -= diff;
			}
			else {
				v[i] += left;
				left = 0;
			}
		}
		int ind = 0;
		int csum = v[ind] - 1;
		for (int i = 0; i < n; i++) {
			if (i == csum) {
				cout << s[i];
				ind++;
				csum += v[ind];
				cout << endl;
			}
			else {
				cout << s[i];
			}
		}
	}





	return 0;
}
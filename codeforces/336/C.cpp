#include <bits/stdc++.h>
#define FAST_IO cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define int long long
typedef long long ll;
const int oo = 1e18;
const int OO = 0x3f3f3f3f;
const int N =  1000;
using namespace std;

void S(int T = 0){
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& e : a) cin >> e;

		for (int i=1<<30; i>0; i/=2) {
				vector<int> b;
				int x = (1 << 30) - 1;
				for (int e : a) if (e & i) {
								b.push_back(e);
								x &= e;
						}
				if (x % i == 0) {
						cout << b.size() << '\n';
						for (int e : b) cout << e << ' ';
						cout << '\n';
						return;
				}
		}
}
signed main(){
		FAST_IO
		int TESTCASES = 1;
//	cin >> TESTCASES;
		while(TESTCASES--){
				S(TESTCASES);
		}
}

/*
 *
3 2 2 3
1 3 4
1 2 3
3 6
2 3

 * */
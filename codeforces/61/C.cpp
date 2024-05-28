#include <bits/stdc++.h>
using namespace std;

#define For(i, n) for(int i = 0; i < (n); ++i)
#define rFor(i, n) for(int i = (n - 1); i >= 0; i--)
#define FoR(i, st, ed) for(int i = (st); i < (ed); ++i)
#define rFoR(i, st, ed) for(int i = (ed) - 1; i >= (st); --i)
#define FOR(i, st, ed) for(int i = (st); i <= (ed); ++i)
#define rFOR(i, st, ed) for(int i = (ed); i >= (st); --i)
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(a) a.begin(),a.end()
using i64 = long long;
const int INF  = 1e9+7;
const int MAX = 1e5;
const int mod  = 1e9+7;
const double eps = 0.001;
//--------------------------------------------
i64 power(i64 a, int b){
	i64 res = 1;
	FOR(i, 0, log2(b)){
		if((1 << i) & b) res *= a;
		a = a * a;
	}
	return res;
}
#define toi64(c) ((c <= '9') ? c - '0' : c - 'A' + 10)
#define toch(a) char((a <= 9) ? a + '0' : a + 'A' - 10)
vector<char> R = {'I','V','X','L','C','D','M'};
void solve(){
	int a;
	string b_s;
	cin >> a >> b_s;
	int b;
	if(b_s != "R") b = stoi(b_s);
	string c_a;
	cin >> c_a;
	i64 c_ten = 0;
	rFor(i, c_a.size()){
		c_ten += power(a, (c_a.size() - 1 - i)) * toi64(c_a[i]);
	}
	// cerr << c_ten << "\n";
	if(b_s != "R"){
		string c_b;
		while(c_ten){
			c_b.pb(toch(c_ten % b));
			c_ten /= b;
		}
		reverse(all(c_b));
		//wawaawawwawawawawawwawawawaw
		if(c_b == "") c_b = "0";
		cout << c_b << "\n";
	}
	else{
		string c_s = to_string(c_ten);
		while(!c_s.empty()){
			int x = c_s.front(), k = c_s.size() - 1;
			if(x <= '3') cout << string(x - '0', R[k * 2]);
			else if(x == '4') cout << R[k * 2] << R[k * 2 + 1];
			else if(x <= '8') cout << R[k * 2 + 1] << string(x - '5',R[k * 2]); 
			else cout << R[k * 2] << R[k * 2 + 2];	
			c_s.erase(c_s.begin());	
		}
		cout << "\n";
	}
}

int main() {
	// std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);

	int t = 1;
	//cin >> t;
	while (t--)solve();
	return 0;
}
/*
*/
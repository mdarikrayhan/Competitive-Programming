#include "bits/stdc++.h"
using namespace std;

#define int long long 
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0);
#define all(x) x.begin(),x.end()
#define pi pair<int,int> 
#define vi vector<int>
#define si set<int> 
#define mi map<int,int>
#define mc map<char,int>
#define YES cout<<"Yes"<<endl;
#define NO  cout<<"No"<<endl;
#define pb(x) push_back(x);
#define fi first
#define sc second
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }

const int INF =1e18;
const int mod =1e8;

//每个字母可以对应一个数字。
//不能提前成闭环，所以相邻的都不能在一起（还是不够全面）
//每个字符对应一个字符。不能相互对应。  
//要词性最小，优先把最小的放在前面。最小的是a~z。 当为这一位时，就得后移一位。

struct DSU {
	vector<int> f, siz;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	
	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	
	int size(int x) {
		return siz[find(x)];
	}
};

void solve()
{
	
	int n;
	std::cin >> n;
	
	std::string s;
	std::cin >> s;
	
	std::vector to(26, -1), from(26, -1);
	
	std::string t;
	
	DSU dsu(26);
	
	for (auto ch : s) {
		int x = ch - 'a';
		
		if (to[x] != -1) {
			t += 'a' + to[x];
			continue;
		}
		
		for (int y = 0; y < 26; y++) {
			if (from[y] != -1) {
				continue;
			}
			if (dsu.same(x, y) && dsu.size(x) < 26) {
				continue;
			}
			to[x] = y;
			from[y] = x;
			dsu.merge(x, y);
			t += 'a' + to[x];
			break;
		}
	}
	
	std::cout << t << "\n";
	


}

signed main()
{
	IOS
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}


//123412
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <time.h>
#include <unordered_map> 
#include <math.h>
#include <stack>
#include <random>
#include <bitset>
#define ll long long
#define mod 9999888877776666555
#define inf 1000000000
#define offset 100000005
using namespace std;
const int BLOCK = 350;
std::default_random_engine engine;
std::uniform_int_distribution <long long> dist(1, 1000000);
int n, k;


ll fastpow(ll n, ll x) {
	if (x == 0) {
		return 1;
		
	}
	ll ret = fastpow(n, x / 2);
	if (x % 2 == 0) {
		return ret * ret;
	}
	else {
		return ret * ret * n;
	}
}
ll ucln(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return ucln(b, a % b);
}
ll bcnn(ll a, ll b) {
	if (a == -1) {
		return -1;
	}
	return a * b / ucln(a, b);
}
std::string ask(int a, int b, int c) {
	std::cout << "? " << a << ' ' << b << ' ' << c << std::endl;
	fflush(stdout);
	std::string ret;
	std::cin >> ret;
	return ret;
}

void solve() {
	std::srand(time(NULL));
	cin >> n >> k;
	int numb = n;
	int height = 0;
	while (numb > 0) {
		numb /= k;
		height++;
	}
	int leaf1 = -1;
	int leaf2 = -1;
	vector<int> list;
	while (true) {
		list.clear();
		leaf1 = rand() % n + 1;
		leaf2 = rand() % n + 1;
		if (leaf1 != leaf2) {
			for (int u = 1; u <= n; u++) {
				if (u == leaf1 || u == leaf2) {
					continue;
				}
				string ans = ask(leaf1, u, leaf2);
				if (ans == "Yes") {
					list.push_back(u);
				}
				
			}
			if (height * 2 - 3 == (int)list.size()) {
				break;
			}
		}
	}
	for (int i = 0; i <  list.size(); i++) {
		int root = list[i];
		int cnt = 0;
		for (int j = 0; j < list.size(); j++) {
			int node = list[j];
			if (node == root || node == leaf1) {
				continue;
			}
			string ans = ask(root, node, leaf1);
			if (ans == "Yes") {
				cnt++;
			}
		}
		if (cnt == height - 2) {
			std::cout << "! " << root << std::endl;
			fflush(stdout);
			return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	








}
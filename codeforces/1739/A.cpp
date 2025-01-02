#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define li long long
#define pii pair<int, int>
#define vi vector<int>

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fore(i, b, e) for (int i = (int)b; i <= (int)e; i++)
#define all(x) (x).begin(), (x).end()

int main() {
	int tests;
	cin >> tests;
	forn(test, tests) {
		int n, m;
		cin >> n >> m;
		cout << min(n, 2) << " " << min(m, 2) << "\n";
	}
}

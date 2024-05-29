#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 9, T = 4;
const char* SUITS = "CDSH";
const char* VALS = "6789TJQKA";

vector<ll> masks = {
67515452935,
67515454987,
67515456011,
67515456013,
67515456523,
67515456525,
67515456526,
67517553677,
67517553678,
67517558284,
67518604813,
67521752588,
19592278700,
34336059520,
32688256024,
10934253124,
21497764062,
953865822,
54567319559,
26364203238,
20511443181,
67643379720,
67642331145,
67642331148,
67634991116,
67626602508,
};

string card(int k) {
	return {VALS[k % N], SUITS[k / N]}; 
}

void print(ll mask) {
	forn (j, T * N) {
		if ((mask >> j) & 1) {
			cout << card(j) << " ";
		}
	}
	cout << "\n";
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int k;
	cin >> k;
	ll full = (1ll << (T * N)) - 1;
	forn (i, k) {
		print(masks[i]);
		print(full - masks[i]);
		cout << "\n";
	}
	
	return 0;
}
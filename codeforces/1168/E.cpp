#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <int, int> pii;

mt19937 rng(345435);

void work() {
	int k; cin >> k;
	int n = 1 << k;
	vector <int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum ^= a[i];
	if (sum) {
		cout << "Fou\n";
		return;
	}
	vector <int> p (n, -1), q (n, -1), vp (n, -1), vq (n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vp[j] == -1 && vq[j ^ a[i]] == -1) {
				vp[j] = i;
				vq[j ^ a[i]] = i;
				p[i] = j;
				q[i] = j ^ a[i];
				break;
			}
		}
	}
	vector <int> ud, uu;
	for (int i = 0; i < n; i++) if (p[i] == -1) ud.push_back(i); 
	for (int i = 0; i < n; i++) if (vp[i] == -1) uu.push_back(i); 

	while (ud.size()) {
		int r = rng() % ud.size();
		swap(ud.back(), ud[r]);
		int x = ud.back();
		for (auto &i : uu) {
			if (vq[i ^ a[x]] == -1) {
				p[x] = i;
				vp[i] = x;
				q[x] = i ^ a[x];
				vq[i ^ a[x]] = x;
				ud.pop_back();
				swap(i, uu.back());
				uu.pop_back();
				break;
			}
		}
		if (p[x] == -1) {
			int r2 = rng() % uu.size();
			swap(uu.back(), uu[r2]);
			int v = uu.back();
			int y = vq[v ^ a[x]];
			vq[q[y]] = -1;
			vp[p[y]] = -1;
			ud.back() = y;
			uu.back() = p[y];
			p[y] = -1;
			q[y] = -1;
			p[x] = v;
			q[x] = v ^ a[x];
			vp[v] = x;
			vq[v ^ a[x]] = x;
		}
		
/*	for (auto i : p) cout << i << ' ';
	cout << '\n';
	for (auto i : q) cout << i << ' ';
	cout << '\n';
	cout << "==============\n"; */
	}

	cout << "Shi\n";
	for (auto i : p) cout << i << ' ';
	cout << '\n';
	for (auto i : q) cout << i << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
//	cin >> T;
	for (int ca = 1; ca <= T; ca ++) {
		work();
	}
}


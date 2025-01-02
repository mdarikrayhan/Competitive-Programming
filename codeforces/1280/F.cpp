#include<bits/stdc++.h>
 
using namespace std;
 
 
 
int N;
 
int V[100];
 
 
 
int main() {
 
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	int T; cin >> T;
 
	while (T--) {
 
		int K; cin >> K;
 
		const int R = 2 * K + 1;
 
		N = 2 * R;
 
		int p0 = -1;
 
		for (int i = 0; i < N; i++) {
 
			string s; cin >> s;
 
			if (s == "E") {
 
				V[i] = 0;
 
				p0 = i;
 
			} else {
 
				V[i] = stoi(s);
 
			}
 
		}
 
		assert(p0 != -1);
 
		string ans;
 
		while (p0 % R) {
 
			ans += 'l';
 
			swap(V[p0], V[p0-1]);
 
			p0--;
 
		}
 
		if (p0 == R) {
 
			ans += 'u';
 
			swap(V[p0], V[p0 - R]);
 
			p0 -= R;
 
		}
 
		assert(p0 == 0);
 
 
 
		bool parity = 0;
 
		for (int i = 0; i < N; i++) {
 
			for (int j = i+1; j < N; j++) {
 
				if (V[j] < V[i]) parity ^= 1;
 
			}
 
		}
 
		if (parity) {
 
			cout << "SURGERY FAILED" << '\n';
 
			continue;
 
		}
 
 
 
		for (int i = 0; i < K; i++) {
 
			ans += 'r';
 
			swap(V[p0], V[p0+1]);
 
			p0++;
 
		}
 
		assert(p0 == K);
 
		ans += 'd';
 
		swap(V[p0], V[p0 + R]);
 
		p0 += R;
 
 
 
		auto VtoF = [&](int v) {
 
			assert(v != 0);
 
			if (v <= K) {
 
				return v + K;
 
			} else if (v == K+1) {
 
				return R;
 
			} else if (v <= R) {
 
				return 2 * R - (v - (K+1));
 
			} else if (v <= R + K) {
 
				return (K+1) - (v - R);
 
			} else {
 
				return R + (v - R - K);
 
			}
 
		};
 
 
 
		deque<int> lhs;
 
		deque<int> rhs;
 
		for (int i = K-1; i >= 0; i--) {
 
			lhs.push_front(VtoF(V[i]));
 
		}
 
		for (int i = 0; i < K; i++) {
 
			lhs.push_front(VtoF(V[R+i]));
 
		}
 
 
 
		for (int i = K+1; i < R; i++) {
 
			rhs.push_front(VtoF(V[i]));
 
		}
 
		for (int i = R-1; i > K; i--) {
 
			rhs.push_front(VtoF(V[R+i]));
 
		}
 
		int mid = VtoF(V[K]);
 
		assert(int(lhs.size()) == 2 * K);
 
		assert(int(rhs.size()) == 2 * K);
 
 
 
		auto rotL = [&]() {
 
			ans += 'L';
 
			lhs.push_back(mid); mid = lhs.front(); lhs.pop_front();
 
		};
 
		auto unrotL = [&]() {
 
			ans += 'X';
 
			lhs.push_front(mid); mid = lhs.back(); lhs.pop_back();
 
		};
 
		auto rotR = [&]() {
 
			ans += 'R';
 
			rhs.push_back(mid); mid = rhs.front(); rhs.pop_front();
 
		};
 
		auto unrotR = [&]() {
 
			ans += 'Y';
 
			rhs.push_front(mid); mid = rhs.back(); rhs.pop_back();
 
		};
 
		for (int z = 0; z < 2 * N; z++) {
 
			if (mid <= R) {
 
				rotL();
 
			} else {
 
				rotR();
 
			}
 
		}
 
 
 
		for (int z = 0; z < R; z++) {
 
			rotL();
 
			for (int i = 0; i < R-1; i++) {
 
				if (lhs.front() < mid) {
 
					// do the swap
 
					rotR();
 
					rotL();
 
					unrotR();
 
					unrotL();
 
					rotR();
 
				}
 
				rotL();
 
			}
 
		}
 
 
 
		assert(mid == R);
 
		mid = 2 * R;
 
 
 
		bool f = false;
 
		for (int z = 0; z < R; z++) {
 
			rotR();
 
			for (int i = 0; i < R-1; i++) {
 
				if (rhs.front() < mid) {
 
					// do the swap
 
					f ? unrotL() : rotL();
 
					rotR();
 
					f ? rotL() : unrotL();
 
					unrotR();
 
					f ? unrotL() : rotL();
 
					f = !f;
 
				}
 
				rotR();
 
			}
 
		}
 
		assert(f == false);
 
 
 
		// finalize answer by moving it to the rightmost
 
		for (int i = 0; i < K; i++) {
 
			ans += 'r';
 
		}
 
		cout << "SURGERY COMPLETE" << '\n';
 
		cout << ans << '\n';
 
		cout << "L" << ' ' << string(K, 'l')+"u"+string(K, 'r')+"d" << '\n';
 
		cout << "X" << ' ' << "u"+string(K, 'l')+"d"+string(K, 'r') << '\n';
 
		cout << "R" << ' ' << string(K, 'r')+"u"+string(K, 'l')+"d" << '\n';
 
		cout << "Y" << ' ' << "u"+string(K, 'r')+"d"+string(K, 'l') << '\n';
 
		cout << "DONE" << '\n';
 
	}
 
 
 
	return 0;
 
}
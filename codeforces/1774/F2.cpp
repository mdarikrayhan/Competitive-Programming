#include <stdio.h>

#include <vector>

#define int long long

using namespace std;

int n, top = 0, ignore = 0, w[1000005], counter;

struct {

	int sub, basis;

	vector<int> add;

} state[40];



int count_repr(int val, int i) {

	int ans = 1, j = top;

	while(j >= i) {

		if(val >= state[j].basis) {

			ans += 1 << (j - i);

			val -= state[j].basis;

		}

		j--;

	}

	return ans;

}

void solve() {

	int total = 0, counter = 0;

	for(int i = 0; i <= top; i++) for(int val : state[i].add) {

		for(int j = i; j <= top; j++) val -= state[j].sub;

		if(val > 0) total = (total + w[counter+1] * count_repr(val - 1, i)) % 998244353;

		counter++;

	}

	printf("%lld", total);

}

signed main() {

	scanf("%lld", &n);

	int current = 0, counter = 0;

	for(int i = 0; i < 40; i++) state[i] = {0, (int) 1e10, {}};

	for(int i = 0; i < n; i++) {

		int op, x;

		scanf("%lld", &op);

		if(op == 1) {

			scanf("%lld", &x);

			state[top].add.push_back(x + state[top].sub);

			counter++;

		}

		else if(op == 2) {

			scanf("%lld", &x);

			state[top].sub += x;

		}

		else {

			if(ignore) continue;

			if(top == 0 && state[top].sub == 0) {

				w[counter] = w[counter] == 0 ? 2 : w[counter] * 2 % 998244353;

				continue;

			}

			state[top].basis = state[top].sub + 2*(top == 0 ? 0 : state[top-1].basis);

			if(state[top].basis > 2e9) { ignore = 1; continue; }

			top++;

		}

	}

	for(int i = counter, v = 1; i >= 0; i--) w[i] = w[i] == 0 ? v : v = (w[i] * v) % 998244353;

	solve();

}
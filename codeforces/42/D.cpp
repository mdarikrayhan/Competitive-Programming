#include <bits/stdc++.h>
using namespace std;

int a[30];
signed main() {
	int n;
	cin >> n;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= n; i++) {
		set <int> st;
		for (int x = 1; x < i; x++) {
			for (int y = 1; y < i; y++) {
				if (x != y) {
					for (int j = 1; j < i; j++) {
						st.insert(a[x] + a[y] - a[j]);
					}
				}
			}
		}
		a[i] = 1;
		while (st.find(a[i]) != st.end()) {
			a[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				printf("%d ", a[i] + a[j]);
			}else {
				printf("0 ");
			}
		}printf("\n");
	}
	return 0;
}

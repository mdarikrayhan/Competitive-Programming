// LUOGU_RID: 158785616
#include <bits/stdc++.h>
using namespace std;
string a[220000];
int mx[220000];
signed main() {
	int n;
	cin >> n;
	a[1] = "0";
	mx[1] = 1;
	int l = 1, r = 1, E = 1;
	for (int i = 2; i <= n; i++) {
		int f = 0;
		for (int j = l; j <= r; j++) {
			a[++E] = a[j] + (char)(f + '0');
			mx[E] = max(f + 1, mx[j]);
			for (int x = 2; x <= mx[j]; x++) {
				a[++E] = a[j] + (char)(x + '0');
				mx[E] = max(mx[j], x + 1);
			}
			f = 1 - f;
			a[++E] = a[j] + (char)(f + '0');
			mx[E] = max(f + 1, mx[j]);
		}
		l = r + 1;
		r = E;
	}
	cout << r - l + 1 << endl;
	for (int i = l; i <= r; i++) {
		for (int j = 0; j < mx[i]; j++) {
			printf("{");
			int flag = 0;
			for (int k = 0; k < n; k++) {
				if (a[i][k]-'0' == j) {
					if (flag) {
						printf(",");
					}
					flag = 1;
					printf("%d", k + 1);
				}
			}
			printf("}%c", j == mx[i] - 1 ? '\n' : ',');
		}
	}
	return 0;
}
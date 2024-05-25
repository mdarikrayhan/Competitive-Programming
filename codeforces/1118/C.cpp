// LUOGU_RID: 160144910
#include <bits/stdc++.h>
using namespace std;

int n, x, m[22][22], cnt[1010];
bool ok = 1, flag = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> x;
		cnt[x]++;
	}
	int q1 = 0, q2 = 0, q3 = 0, q4 = n / 2;
	for (int i = 0; i < 1010; i++) {
		while (cnt[i] >= 4 && q1 < n / 2 && q2 < n / 2) {
			m[q1][q2] = i;
			m[q1][n - q2 - 1] = i;
			m[n - q1 - 1][q2] = i;
			m[n - q1 - 1][n - q2 - 1] = i;
			cnt[i] -= 4;
			q1++;
			if (q1 >= n / 2) {
				q1 = 0;
				q2++;
			}
		}
		if (cnt[i] > 0 && n % 2 == 0) {
			ok = 0;
			break;
		}
		while (cnt[i] >= 2 && q3 < n / 2) {
			if (flag) {
				m[q4][q3] = i;
				m[q4][n - q3 - 1] = i;
				q3++;
			} else {
				m[q3][q4] = i;
				m[n - q3 - 1][q4] = i;
			}
			if (flag == 0) {
				flag = 1;
			} else {
				flag = 0;
			}
			cnt[i] -= 2;
		}
		if (cnt[i] > 0) {
			if (m[n / 2][n / 2]) {
				ok = 0;
				break;
			} else
				m[n / 2][n / 2] = i;
		}
	}
	if (ok == 1) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << m[i][0];
			for (int j = 1; j < n; j++) {
				cout << " " << m[i][j];
			}
			cout << endl;
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

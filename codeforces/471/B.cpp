#include <bits/stdc++.h>
using namespace std;

int hashh[2005];
int ans[5][2005];

struct node {
	long long num;
	long long dif;
} task[2005];

bool cmp(struct node x, struct node y) {
	if (x.dif < y.dif) {
		return true;
	} else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;

	long long temp2 = 0, temp3 = 0;
	for (long i = 1; i <= n; i++) {
		cin >> task[i].dif;
		task[i].num = i;
		hashh[task[i].dif]++;
	}

	long long a = 0, b = 0, c = 0, cnt = 0;
	for (long long i = 1; i <= 2000; i++) {
		if (hashh[i] == 2) {
			if (a == 0) {
				a = i;
			} else {
				if (b == 0) {
					b = i;
				}
			}
			temp2++;
		} else if (hashh[i] >= 3) {
			if (c == 0) {
				c = i;
			}
			temp3++;
		}
	}

	if (temp2 < 2 && temp3 == 0) {
		cout << "NO";
		goto end;
	}

	sort(task + 1, task + 1 + n, cmp);

//	cout << a << " " << b << " " << c << " " << temp2 << " " << temp3 << "\n";

	for (long long i = 1; i <= n; i++) {
		ans[2][i] = ans[3][i] = ans[1][i] = task[i].num;
	}

	for (long long i = 1; i <= n; i++) {
		if (a != 0 && task[i].dif == a) {
			ans[2][i] = task[i + 1].num, ans[2][i + 1] = task[i].num;
			i += 2;
		}
		if (b != 0 && task[i].dif == b) {
			ans[3][i] = task[i + 1].num, ans[3][i + 1] = task[i].num;
			i += 2;
			break;
		}
		if (c != 0 && task[i].dif == c) {
			ans[2][i] = task[i + 1].num, ans[2][i + 1] = task[i].num;
			ans[3][i] = task[i + 2].num, ans[3][i + 2] = task[i].num;
			break;
		}
	}

	cout << "YES\n";
	for (long long i = 1; i <= 3; i++) {
		for (long long j = 1; j <= n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
end:
	;
	return 0;
}
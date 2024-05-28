// LUOGU_RID: 158773316
#include <bits/stdc++.h>
using namespace std;

char s1[60], s2[60];
int dp[60][60];
bool is[2][60][60][30];
int change[60][3];
signed main() {
    scanf("%s%s", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2);
    int n;
	cin >> n;
    for (int i = 0; i < n; i++) {
		getchar();
		char a, b, c;
        scanf("%c->%c%c", &a, &b, &c);
        change[i][0] = a - 'a';
		change[i][1] = b - 'a';
		change[i][2] = c - 'a';//cout << a << b << c << endl;
    }
    for (int i = 0; i < len1; i++) {
		is[0][i][i][s1[i] - 'a'] = 1;
    }
	for (int len = 2; len <= len1; len++) {
        for (int i = 0; i <= len1 - len; i++) {
            for (int k = i; k < i + len - 1; k++) {
                for (int c = 0; c < n; c++) {// cout << c <<":" << change[c][0] << endl;
                    if (is[0][i][k][change[c][1]] && is[0][k + 1][i + len - 1][change[c][2]]) {
						is[0][i][i + len - 1][change[c][0]] = 1;
					}
                }
            }
        }
    }
    for (int i = 0; i < len2; i++) {
		is[1][i][i][s2[i] - 'a'] = 1;
    }
	for (int len = 2; len <= len2; len++) {
        for (int i = 0; i <= len2 - len; i++) {
            for (int k = i; k < i + len - 1; k++) {
                for (int c = 0; c < n; c++) {
                    if (is[1][i][k][change[c][1]] && is[1][k + 1][i + len - 1][change[c][2]]) {
						is[1][i][i + len - 1][change[c][0]] = 1;
					}
                }
            }
        }
    }
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            for (int x = 0; x <= i; x++) {
                for (int y = 0; y <= j; y++) {
                    for (int c = 0; c < 26; c++) {
                        if (is[0][x][i][c] && is[1][y][j][c]) {
                            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[x][y] + 1);
                        }
                    }
                }
            }
        }
    }
    if (dp[len1][len2] > 100) {
        cout << -1;
    }else {
        cout << dp[len1][len2];
    }
	return 0;
}
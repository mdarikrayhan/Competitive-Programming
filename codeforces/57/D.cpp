/**
 * @author : cyb1010
 * @date   : 2024-04-25 17:33:23
 * @file   : Journey.cpp
 */
#include <bits/stdc++.h>
using namespace std;
#define fo(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
#define fi first
#define se second
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1010;
int __, n, m, tot, pre[N][2], suf[N][2], tmp[N][2], col[N], row[N];
ll ans;
char s[N][N];
int main() {
    // fo("Journey");
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tmp[j][0] = tmp[j - 1][0], tmp[j][1] = tmp[j - 1][1];
            if (s[i][j] == '.') tot++, tmp[j][0]++, tmp[j][1] += i + j;
            pre[j][0] += tmp[j][0], pre[j][1] += tmp[j][1];
        }
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'X') {
                col[i] = j, row[j] = i;
                continue;
            }
            ans += pre[j][0] * (i + j) - pre[j][1] + suf[j + 1][0] * (i - j)
                   - suf[j + 1][1];
        }
        for (int j = m; j; j--) {
            tmp[j][0] = tmp[j + 1][0], tmp[j][1] = tmp[j + 1][1];
            if (s[i][j] == '.') tmp[j][0]++, tmp[j][1] += i - j;
            suf[j][0] += tmp[j][0], suf[j][1] += tmp[j][1];
        }
    }
    for (int i = 1, tag = 0, cnt = 0; i <= n; i++) {
        if (!col[i]) {
            tag = cnt = 0;
            continue;
        }
        if (!col[i - 1]) {
            ans += (col[i] - 1) * (m - col[i]) * 2;
            continue;
        }
        if (col[i] < col[i - 1]) {
            if (tag == 1)
                cnt += m - col[i];
            else
                cnt = m * 2 - col[i] - col[i - 1], tag = 1;
            ans += (col[i] - 1) * cnt * 2;
        } else {
            if (tag == -1)
                cnt += col[i] - 1;
            else
                cnt = col[i] + col[i - 1] - 2, tag = -1;
            ans += (m - col[i]) * cnt * 2;
        }
    }
    for (int i = 1, tag = 0, cnt = 0; i <= m; i++) {
        if (!row[i]) {
            tag = cnt = 0;
            continue;
        }
        if (!row[i - 1]) {
            ans += (row[i] - 1) * (n - row[i]) * 2;
            continue;
        }
        if (row[i] < row[i - 1]) {
            if (tag == 1)
                cnt += n - row[i];
            else
                cnt = n * 2 - row[i] - row[i - 1], tag = 1;
            ans += (row[i] - 1) * cnt * 2;
        } else {
            if (tag == -1)
                cnt += row[i] - 1;
            else
                cnt = row[i] + row[i - 1] - 2, tag = -1;
            ans += (n - row[i]) * cnt * 2;
        }
    }
    printf("%.12lf\n", ans * 2. / tot / tot);
    return 0 ^ __ ^ 0;
}
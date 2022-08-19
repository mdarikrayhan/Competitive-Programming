/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
    int n, m, sum = 0;
    cin >> n >> m;
    string s;
    int a[n+5][m+5];
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
            sum += a[i][j];
        }
    }
    int minn = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int cnt = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
            if (cnt == 0) continue;
            minn = min(minn, max(1, cnt - 1));
        }
    }
    if (sum == 0) cout << "0\n";
    else cout << 1 + sum - minn << "\n";
    }
    return 0;
}
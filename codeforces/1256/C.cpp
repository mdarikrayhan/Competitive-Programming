// LUOGU_RID: 159990495
/**
 * @Time : 2024/1/30-12:59 PM
 * @Author : yyw@ustc
 * @E-mail : <a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="93eaf2fdf4a3d3fef2faffbde6e0e7f0bdf6f7e6bdf0fd">[email&#160;protected]</a>
 * @Github : https://github.com/ustcyyw
 * @desc :
 */
/*
 *
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000 + 5, mod = 998244353;
int T, n, m, d, arr[N], sum[N], ans[N];


bool solve() {
    for(int i = m; i >= 1; i--)
        sum[i] = arr[i] + sum[i + 1];
    for(int x = 0, i = 1; x < n + 1; ) {
        if(x + d < n + 1 && i == m + 1) return false;
        if(x + d > n - sum[i]) { // 剩余木板靠右紧凑排列也可以
            for(int j = n, k = m; k >= i; j--) {
                ans[j] = k;
                if(--arr[k] == 0) k--;
            }
            return true;
        }
        x = x + d;
        for(int j = 0; j < arr[i]; j++)
            ans[x + j] = i;
        x += arr[i] - 1;
        i++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); // 加速cin, cout
    cin >> n >> m >> d;
    for(int i = 1; i <= m; i++)
        cin >> arr[i];
    if(solve()) {
        cout << "YES\n";
        for(int i = 1; i <= n; i++)
            cout << ans[i] << " ";
    } else cout << "NO";
};
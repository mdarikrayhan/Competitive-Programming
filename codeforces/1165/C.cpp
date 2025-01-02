// LUOGU_RID: 158954835
/**
 * @Time : 2024/1/30-12:59 PM
 * @Author : yyw@ustc
 * @E-mail : <a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="3b425a555c0b7b565a5257154e484f58155e5f4e155855">[email&#160;protected]</a>
 * @Github : https://github.com/ustcyyw
 * @desc :
 */
/*
 * sum of (ai * bi * ci) ai和ci是固定的
 * 可以重排bi，那肯定将小的bi和大的 ai*ci放在一块
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 305, mod = 998244353;
int T, n;
string s;

void solve() {
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i + 1] && (i - cnt) % 2 == 1) {
            s[i] = '.';
            cnt++;
        }
    }
    if((n - cnt) % 2 == 1) {
        cnt++;
        s.back() = '.';
    }
    cout << cnt << "\n";
    for(char c : s)
        if(c != '.') cout << c;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); // 加速cin, cout
    cin >> n;
    cin >> s;
    s = '.' + s;
    solve();
};
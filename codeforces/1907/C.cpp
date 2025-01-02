#include <bits/stdc++.h>

// #define int int64_t

#define OPEN_DEBUG 1
#define DEBUG if(OPEN_DEBUG)
#define DEBUGIF(_x) if(OPEN_DEBUG && _x)

#define INF 0x3f3f3f3f
#define endl "\n";
using namespace std;
typedef long long LL;


/**
 * 理解题目意思
 * 不要偷懒，多打草稿
 * 想好了再开始写
 */

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // 确认好了要不要long long
    // memset(h, -1, sizeof h);
    // 浮点数精度问题，除以一个分数可以先乘上分母在除分子

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> st(26);
        for (char ch : s) {
            st[ch - 'a'] ++;
        }
        int mmax = *max_element(st.begin(), st.end());
        cout << max(mmax - (n - mmax), n & 1) << endl;
    }
    

 

    return 0;
}
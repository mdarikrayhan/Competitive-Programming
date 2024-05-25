// LUOGU_RID: 160086228
#include <bits/stdc++.h>

#define int long long
using namespace std;

int n;
vector<int> a;

bool check_and_get_segment(int &L, int &R) {
    int left = 1, right = n;

    // 找到第一个不匹配的位置
    while (left <= n && a[left] == left) left++;
    if (left > n) return false; // 序列已经是升序

    // 找到最后一个不匹配的位置
    while (right >= 1 && a[right] == right) right--;

    // 反转从 left 到 right 的区间
    reverse(a.begin() + left, a.begin() + right + 1);

    // 检查反转后的序列是否是升序
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            // 如果不是升序，恢复原序列并返回 false
            reverse(a.begin() + left, a.begin() + right + 1);
            return false;
        }
    }

    // 返回区间
    L = left;
    R = right;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int L, R;
    if (check_and_get_segment(L, R)) {
        cout << L << " " << R << endl;
    } else {
        cout << "0 0" << endl;
    }

    return 0;
}

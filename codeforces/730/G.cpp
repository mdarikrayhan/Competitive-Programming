#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pr pair<int, int>
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    int x = 0, mm = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') mm = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * mm;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 205;

int a[N], b[N];

signed main() {
    int n = read(), k = 0;

    auto check = [&](int n, int x, int y) -> int {
        if (!n) return 1;
        for (int i = 1; i < n; i++) {
            if (a[i] > x + y - 1 || b[i] < x) continue;
            return 0;
        }
        return 1;
    };

    for (int i = 1; i <= n; i++) {
        int x = read(), y = read();
        if (check(i, x, y)) {
            a[i] = x;
            b[i] = x + y - 1;
        }
        else {
            int res = 1e16;
            for (int j = 0; j < i; j++) {
                if (check(i, b[j] + 1, y)) {
                    res = min(res, b[j] + 1);
                }
            }
            a[i] = res;
            b[i] = res + y - 1;
        }
        write(a[i]);
        putchar(' ');
        write(b[i]);
        putchar('\n');
    }
}
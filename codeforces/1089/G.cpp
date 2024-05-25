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

int a[10];

signed main() {
    int t = read();

    while (t--) {
        int n = read(), sum = 0;
        for (int i = 1; i <= 7; i++) sum += (a[i] = read());
        int ans = 1e16;
        for (int i = 1; i <= 7; i++) {
            for (int j = 1; j <= 7; j++) {
                int now, len;
                if (j < i) {
                    now = sum;
                    len = 7;
                    for (int k = j + 1; k < i; k++) now -= a[k], len--;
                }
                else {
                    now = 0;
                    for (int k = i; k <= j; k++) now += a[k];
                    len = j - i + 1;
                }
                now = n - now;
                if (now <= 0) ans = min(ans, len);
                else ans = min(ans, len + (now + sum - 1) / sum * 7);
            }
        }
        write(ans);
        putchar('\n');
    }
}
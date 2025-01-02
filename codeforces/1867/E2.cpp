// Created by Henry Yi

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int n, k;
int ans = 0, x;

void print(int i) {
    if (i + k - 1 > n) return;
    printf("? %d\n", i);
    fflush(stdout);
    scanf("%d", &x);
    ans ^= x;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        int a = (k - (n % k)) / 2;
        if (n <= k * 3) a = (k * 3 - n) / 2;
        int i = 1;
        print(i);
        i += k; i -= a;
        print(i);
        i += k; i -= a;
        print(i);
        i += k;
        while (i + k - 1 <= n) {
            print(i);
            i += k;
        }
        printf("! %d\n", ans);
        fflush(stdout);
        ans = 0;
    }

    return 0;
}

// read questions at least 3 times!!!
// think more and then code!!!
// partial points are GOD.
// don't stuck on one question for two long (like 30-45 min)
// Debug: (a) read your code once, check overflow, check edge case(0/1)
// Debug: (b) create your own test case
// Debug: (c) add asserts
// Debug: (d) 对拍
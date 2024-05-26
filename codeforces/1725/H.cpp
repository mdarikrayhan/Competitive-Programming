// LUOGU_RID: 160237799
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, k;
int a[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] %= 3;
        a[i] = a[i] * a[i] % 3;
        k += a[i];
    }
    if (k >= n / 2) {
        puts("0");
        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                if (k > n / 2) putchar('0'), k--;
                else putchar('1');
            } 
            else putchar('0');
        }
        return 0;
    }
    puts("2");
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            if (k < n / 2) putchar('1'), k++;
            else putchar('0');
        }
        else putchar('1');
    }
}
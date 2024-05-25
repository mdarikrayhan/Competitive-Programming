#include <iostream>
#include <algorithm>
using namespace std;

#define N 200000

int a[N], n, s;

bool can(int x) {
    int l = x - 1, r = n - 1;
    while (l < r) {
        if (a[r] > s - a[l]) return false;
        ++l;
        if (l < r) {
            if (a[l] > s - a[r]) return false;
            --r;
        }
    }
    return true;
}


int main() {
    long long sum = 0;
    scanf("%d %d\n", &n, &s);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    sort(a, a + n, greater<int>());

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (can(m)) r = m;
        else l = m + 1;
    }

    long long ans = sum + r;
    cout << ans << endl;

    return 0;
}
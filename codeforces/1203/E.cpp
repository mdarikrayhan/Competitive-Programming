#include <bits/stdc++.h>

using namespace std;
const int N = 150010;
int n, a[N], cnt[N];

int main() {
    scanf("%d", &n);
    memset(cnt, 0, sizeof cnt);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= mx + 1; i++) {
        if(cnt[i - 1]) {
            cnt[i - 1]--;
            ans++;
        }else if(cnt[i]) {
            cnt[i]--;
            ans++;
        }else if(cnt[i + 1]) {
            cnt[i + 1]--;
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
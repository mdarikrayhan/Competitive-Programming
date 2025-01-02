// Author Sai (<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="c3b0a2aab0a6b0a2aa83b2b2eda0acae">[email&#160;protected]</a>)

#include <bits/stdc++.h>

using namespace std;

#define f32 float
#define f64 double
#define i32 int32_t
#define i64 int64_t
#define u32 uint32_t
#define u64 uint64_t

#define rw   reference_wrapper
#define vec  vector
#define hmap unordered_map

#define fast_io() do{ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);}while(0)

int main() {
    fast_io();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        u64 ans(0);
        hmap<int, int> ht;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans += ht[x - i]++;
        }

        cout << ans << endl;
    }

    return 0;
}
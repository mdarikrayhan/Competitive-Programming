#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
// typedef __int128 lll;
// typedef __float128 lld;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> mb(11, -1);
        for(int i = 0; i < n; i++){
            int b, d;
            cin >> b >> d;
            mb[d] = max(mb[d], b);
        }
        int ans = 0;
        bool is_valid = true;
        for(int i = 1; i <= 10; i++){
            if(mb[i] == -1){
                is_valid = false;
            }
            ans += mb[i];
        }
        cout << (is_valid? to_string(ans) : "MOREPROBLEMS") << "\n";
    }
    
    return 0;
}

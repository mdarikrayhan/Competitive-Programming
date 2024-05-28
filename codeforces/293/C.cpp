#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    LL n;
    cin >> n;
    if (n % 3){
        cout << 0 << '\n';
        return 0;
    }
    n /= 3;
    vector<LL> factor;
    for(int i = 1; 1LL * i * i <= n; i++){
        if (n % i == 0){
            factor.push_back(i);
            if (1LL * i * i != n) factor.push_back(n / i);
        }
    }
    sort(factor.begin(), factor.end());
    LL ans = 0;
    for(int i = 0; i < factor.size() && 1LL * factor[i] * factor[i] * factor[i] <= n; i++){
        for(int j = i; 1LL * factor[i] * factor[j] * factor[j] <= n; j++){
            LL x = factor[i], y = factor[j];
            if (n / x % y) continue;
            LL z = n / x / y;
            if ((x + y + z) % 2) continue;
            LL s = (x + y + z) / 2;
            LL a = s - x;
            LL b = s - y;
            LL c = s - z;
            if (a <= 0 || b <= 0 || c <= 0) continue;
            if (a == b && b == c) ans += 1;
            else if (a == b || b == c) ans += 3;
            else ans += 6;
        }
    }
    cout << ans << '\n';

}
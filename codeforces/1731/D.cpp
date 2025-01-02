#include<bits/stdc++.h>
using llt = long long;

void solve(void)
{
    llt n, m;
    std::cin >> n >> m;

    std::vector<std::vector<llt>> a(n + 2, std::vector<llt>(m + 2, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            std::cin >> a[i][j];
        }
    }

    auto check = [&](llt tar) -> bool{
        std::vector<std::vector<llt>> b(n + 2, std::vector<llt>(m + 2, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (a[i][j] >= tar);
            }
        }
        for(int i = tar; i <= n; i++){
            for(int j = tar; j <= m; j++){
                int t = b[i][j] + b[i - tar][j - tar] - b[i - tar][j] - b[i][j - tar];
                if(t == tar * tar) return false;
            }
        }
        return true;
    };

    llt left = 1;
    llt right = std::min(n, m) + 1;
    llt mid;
    while (left < right){
        mid = left + ((right - left) >> 1);
        if(check(mid)) right = mid;
        else left = mid + 1;
    }
    std::cout << left - 1 << '\n';
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while(t--)
        solve();
    return 0;
}
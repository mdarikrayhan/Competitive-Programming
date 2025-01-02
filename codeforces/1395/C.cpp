#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::vector<std::vector<int>> goods;
    for (int i = 0; i < n; i++) {
        std::vector<int> t;
        for (int j = 0; j < m; j++) {
            t.push_back(a[i] & b[j]);
        }
        goods.push_back(t);
    }

    int N = goods.size();
    int M = 1 << 9;
    std::vector dp(N + 1, std::vector<int>(M));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (auto x : goods[i]) {
                dp[i + 1][j | x] |= dp[i][j];
            }
        }
    }
    for (int i = 0; i < M; i++) {
        if (dp[N][i]) {
            std::cout << i << "\n";
            return 0;
        }
    }

    return 0;
}
											 		 		        	  			
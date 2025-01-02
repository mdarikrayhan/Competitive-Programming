#include <bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(n));
    std::vector<int> cnt(n * n);
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            std::cin >> a[i][j];
            a[i][j] -= 1;
            cnt[a[i][j]] += 1;
        }
    }

    int all = std::count_if(cnt.begin(), cnt.end(), [&](int x) {
        return x > 0;
    });

    if (all == m) {
        std::cout << 0 << "\n";
        return 0;
    }

    if (all < m) {
        std::cout << m - all << "\n";
        return 0;
    }

    int cur = 0;

    auto remove = [&](int i, int j, int len) {
        for (int k = i; k < i + len; k += 1) {
            cur -= cnt[a[k][j]] == 0;
            cnt[a[k][j]] += 1;
        }
        for (int k = j + 1; k < j + len; k += 1) {
            cur -= cnt[a[i][k]] == 0;
            cnt[a[i][k]] += 1;
        }
    };

    // auto tmp = cnt;

    auto add = [&](int i, int j, int len) {
        for (int k = i; k > i - len; k -= 1) {
            cnt[a[k][j]] -= 1;
            cur += cnt[a[k][j]] == 0;
        }
        for (int k = j - 1; k > j - len; k -= 1) {
            cnt[a[i][k]] -= 1;
            cur += cnt[a[i][k]] == 0;
        }
    };

    for (int o = 0; o < n; o += 1) {
        int pi = 0;
        int i = 0, j = o, pj = o;
        for (; j < n; i += 1, j += 1) {
            add(i, j, i - pi + 1);
            while(pi <= i and all - cur + 1 < m) {
                remove(pi, pj, i - pi + 1);
                pi += 1;
                pj += 1;
            }
            if (all - cur == m or all - cur + 1 == m) {
                std::cout << "1\n";
                return 0;
            }
        }
        while(pi < i) {
            remove(pi, pj, i - pi);
            pi += 1;
            pj += 1;
        }
        // if (cnt != tmp) {
        //     for (auto x : cnt) {
        //         std::cerr << x << " ";
        //     }
        //     std::cerr << "\n";
        // }
        // assert(cnt == tmp);
    }
    for (int o = 0; o < n; o += 1) {
        int pi = o;
        int i = o, j = 0, pj = 0;
        for (; i < n; i += 1, j += 1) {
            add(i, j, i - pi + 1);
            while(pi <= i and all - cur + 1 < m) {
                remove(pi, pj, i - pi + 1);
                pi += 1;
                pj += 1;
            }
            if (all - cur == m or all - cur + 1 == m) {
                std::cout << "1\n";
                return 0;
            }
        }
        while(pi < i) {
            remove(pi, pj, i - pi);
            pi += 1;
            pj += 1;
        }
        // assert(cnt == tmp);
    }
    std::cout << "2\n";
    return 0;
}
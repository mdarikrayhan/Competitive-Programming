#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using i64 = long long;
using pii = std::pair<int, int>;
template<typename T>
std::vector<T> read(T& n)
{
    std::vector<T> a(n);
    for (auto& i : a) std::cin >> i;
    return a;
}
void solve()
{
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    int d1 = std::min({x1, y1, n - x1 + 1, n - y1 + 1});
    int d2 = std::min({x2, y2, n - x2 + 1, n - y2 + 1});
    std::cout << std::abs(d1 - d2) << '\n';
}
int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int T = 1;
    std::cin >> T;
    while (T --) solve();
    return 0;
}
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <bitset>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <cstring>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define int long long int

const int MOD = 1000000000 + 7;

template <typename T>
void print(T v) {
    for (int i: v)
        std::cout << i << " ";
    std::cout << '\n';
}

template <typename T>
void input(std::vector<T>& a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
}

bool comp(std::pair<int, int>& p1, std::pair<int, int>& p2) {
    int a1 = p1.first;
    int b1 = p1.second;
    int a2 = p2.first;
    int b2 = p2.second;
    return a1 * b2 > a2 * b1;
}

void solve() {
    int n; std::cin >> n;
    std::vector<std::pair<int, int>> greed;
    std::vector<std::pair<int, int>> a;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        std::string str; std::cin >> str;
        int h = 0;
        int s = 0;
        int m = str.length();
        for (int j = m - 1; j >= 0; j--) {
            if (str[j] == 's') {
                ans += h;
                s++;
            } else {
                h++;
            }
        }
        greed.push_back({s, h});
    }
    std::sort(greed.begin(), greed.end(), comp);
    int h = greed[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        ans += greed[i].first * h;
        h += greed[i].second;
    }
    std::cout << ans << '\n';
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int tc = 1;
    //std::cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}

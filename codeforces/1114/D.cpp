// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

int dp[5000][5000][2];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<int> a(n);
    input_seq(ALL(a));

    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            dp[i][j][0] = dp[i][j][1] = (i == j ? 0 : TYPEMAX(int) / 2);
    

    for (int r = 0; r != n; ++r)
        for (int l = r; l >= 0; --l)
            for (int it = 0; it != 2; ++it) {
                int c = (it == 0 ? a[l] : a[r]);
                
                if (l)
                    dp[l - 1][r][0] = min(dp[l - 1][r][0], dp[l][r][it] + int(c != a[l - 1]));

                if (r + 1 != n)
                    dp[l][r + 1][1] = min(dp[l][r + 1][1], dp[l][r][it] + int(c != a[r + 1]));
            }

    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << "\n";
    
    return 0;
}

#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, l, r;
    std::cin >> a >> b >> l >> r;

    if (r - l + 1 >= 2 * (a + b)) {
        if (a <= b)
            std::cout << a + 1;
        else
            std::cout << 2 * a - b;
        return 0;
    }

    --l, --r;
    int len = r - l + 1;
    l %= (a + b), r = l + len - 1;
    int ans = 1E9;
    std::array<std::string, 3> t;
    for (int i = 0; i < 26; ++i) {
        t[0] = std::string(b, i + 'a');
        for (int j = 0; j < 26; ++j) {
            t[1] = std::string(b, j + 'a');
            for (int k = 0; k < 26; ++k) {
                t[2] = std::string(b, k + 'a');
                std::string s = "";
                s.resize(a);
                iota(s.begin(), s.end(), 'a');

                int p = 0;
                while (s.size() <= r) {
                    s += t[p++];
                    std::vector<int> cnt(26, 0);
                    for (int i = 0; i < a; ++i)
                        ++cnt[s[s.size() - i - 1] - 'a'];
                    for (int i = 0, j = 0; i < a; ++i, ++j) {
                        while (cnt[j]) 
                            ++j;
                        s += char('a' + j);
                    }
                }

                std::vector<int> cnt(26, 0);
                for (int i = l; i <= r; ++i)
                    ++cnt[s[i] - 'a'];
                int res = 0;
                for (int i = 0; i < 26; ++i)
                    res += bool(cnt[i]);
                ans = std::min(ans, res);
            }
        }
    }

    std::cout << ans << '\n';
}
			 	   	 	    	  	     	 	 	 	
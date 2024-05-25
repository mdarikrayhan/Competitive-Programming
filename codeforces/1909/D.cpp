#include <bits/stdc++.h>

int64_t gcd(int64_t a, int64_t b)
{
    return a ? gcd(b % a, a) : b;
}

void solve()
{
    int n;
    int64_t k;
    std::cin >> n >> k;
    std::vector<int64_t> a(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int flag = -2, c = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > k) c = 1;
        else if(a[i] < k) c = -1;
        else if(a[i] == k) c = 0;
        if(flag == -2) flag = c;
        else if(flag != c) flag = -3;
    }
    if(flag == -3)
    {
        std::cout << "-1\n";
        return;
    }
    if(flag == 0)
    {
        std::cout << "0\n";
        return;
    }
    int64_t g;
    if(flag) g = a[0] - k;
    else g = k - a[0];
    for(int i = 1; i < n; i++)
    {
        if(flag) g = gcd(g, a[i] - k);
        else g = gcd(g, k - a[i]);
    }
    int64_t ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(flag) ans += (a[i] - k) / g - 1;
        else ans += (k - a[i]) / g - 1;
    }
    std::cout << ans << '\n';
}

int main()
{
    std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);

    int t;
    std::cin >> t;
    while(t--) solve();

    return 0;
}
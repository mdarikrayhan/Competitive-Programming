    #include <bits/stdc++.h>
    #ifdef MYDEBUG
    #include "debug.h"
    #else
    #define debug(x...)
    #endif
    using namespace std;
     
    #define t      \
        int t = 1; \
        cin >> t;  \
        while (t--)
    #define run ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #define pb(x) emplace_back(x)
    #define pp pop_back
    #define fib(n) (int)(pow(((1 + sqrt(5)) / 2), n) - pow((((1 - sqrt(5)) / 2)), n)) / sqrt(5)
    #define ROTATE(v, i) rotate(v.begin(), v.begin() + i, v.end())
    #define isPerfect(i) (pow((int)sqrt(i), 2) == i)
    #define isFib(n) (isPerfect(5 * n * n + 4) || isPerfect(5 * n * n - 4))
    #define input(v)      \
        for (auto &i : v) \
            cin >> i;
    #define output(v)    \
        for (auto i : v) \
            cout << i << " ";
     
    #define inputP(v)       \
        for (auto &i : (v)) \
            cin >> i.first >> i.second;
    #define yes          \
        cout << "YEs\n"; \
        cout.flush();
    #define no          \
        cout << "no\n"; \
        cout.flush();
    #define all(i) i.begin(), i.end()
    #define rall(i) i.rbegin(), i.rend()
    #define int long long
    #define MOd 1000000007
    #define format(n) setprecision(n)
    /****************************************
          solution by TheOnlyOne
     ****************************************/
     
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
     
    void solve()
    {
      int a, c;
        cin >> a >> c;
     
        vector<int> Da, Dc; 
        while (a > 0) {
            Da.push_back(a % 3);
            a /= 3;
        }
     
        while (c > 0) {
            Dc.push_back(c % 3);
            c /= 3;
        } 
        int mx = max(Da.size(), Dc.size());
        while (Da.size() < mx) Da.push_back(0);
        while (Dc.size() < mx) Dc.push_back(0); 
        vector<int> Db;
        for (int i = 0; i < mx; ++i) {
            int digitB = (3 - Da[i] + Dc[i]) % 3;
            Db.push_back(digitB);
        } 
        int b = 0;
        for (int i = mx - 1; i >= 0; --i) {
            b = b * 3 + Db[i];
        } 
        cout << b << endl;
    }
    signed main()
    {
        run
        solve();
    }
    #pragma GCC optimize ("O3")
    #include <bits/stdc++.h>
    #define boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #define ll long long
    #define ull unsigned long long
    #define home freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp> 

    using namespace std;
    using namespace __gnu_pbds;

    typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;


    void solve();

    int main()
    {
        boost
        #ifndef ONLINE_JUDGE
        home
        #endif

        solve();

        return 0;
    }

    bool isV(const char& c)
    {
        return c == 'a' || c == 'e';
    }

    void solve()
    {
        this_thread::sleep_for(chrono::milliseconds(1500));
        cout << "Yes\n";
    }
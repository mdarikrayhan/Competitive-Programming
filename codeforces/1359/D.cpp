#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

//@Etohari
using namespace std;
using namespace __gnu_pbds;

template < class T, class G > bool minimum(T& a, const G b) { return b < a ? a = b, 1 : 0; }
template < class T, class G > bool maximum(T& a, const G b) { return a < b ? a = b, 1 : 0; }

template < class T > using heap_min = priority_queue < T, vector < T >, greater < T > >;
template < class T > using heap_max = priority_queue < T, vector < T >, less < T > >;
template < class T > using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < class T > using ordered_multiset = tree < T, null_type, less_equal < T >, rb_tree_tag, tree_order_statistics_node_update >;

#define my_wife "Thu"
#define bit(mask,i) ((mask>>i)&1)
#define cntbit(mask,i) (__builtin_popcountll(mask))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define __lcm(a,b) ((int64_t)(a) / __gcd((a), (b)) * (b))
#define rand(l, r) uniform_int_distribution < int64_t > (l, r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int32_t MOD = 1e9 + 7;
constexpr int32_t MAXN = 2e5 + 10;
constexpr int32_t MAXM = 1e6 + 10; 
constexpr int32_t INF32 = 0x3f3f3f3f;
constexpr int64_t INF64 = 0x3f3f3f3f3f3f3f3f;
constexpr int32_t BLOCK_SIZE = 333;

constexpr int16_t DR[] = { };
constexpr int16_t DC[] = { };

void etohari(){         
        //@Etohari
        int n;
        cin >> n;
        
        vector < int > a(n);
        for (auto& v : a)cin >> v;

        int64_t ans = 0;
        for (int maxi = 1; maxi <= 30; maxi ++){
                int64_t cur = 0;
                int64_t sum = 0;
                for (auto& v : a){
                        sum += v > maxi ? -INF32 : v;
                        ans = max(ans, sum - cur - maxi);
                        cur = min(cur, sum);
                }
        }

        cout << ans;
}        

signed main() {
        cin.tie(nullptr)->sync_with_stdio(false);
        // https://www.facebook.com/hai290605
        constexpr bool MULTITEST = 0;
        // https://codeforces.com/profile/Etohari
        int32_t test = 1;
        if (MULTITEST) cin >> test;
        for (int32_t i_test = 1; i_test <= test; i_test ++){
                etohari();
                cout << "\n";
        }
        return (0 ^ 0);
}

/* Cho tới khi nào ? */


   					  			    			  	     	
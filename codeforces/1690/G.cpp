// It is an infinity loop!
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <queue>
#include <stack>
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define INF 1e18+9
#define inf 2147483647
#define MAXN 300005
#define prm 13331
#define pb push_back
#define in insert
#define fi first
#define se second
#define LL __int128
#define PII pair<int,int>
const ll mod = 1e9+7;
const ll mod1 = 954169327;
const ll mod2 = 906097321;
const ll base1 = 131;
const ll base2 = 131;
const double eps = 1e-6;
const double PI = acos(-1.0);
using namespace __gnu_pbds;
using namespace std;
template <typename T, typename U> T ceil(T x, U y) {return (x > 0 ? (x + y - 1) / y : x / y);}
template <typename T, typename U> T floor(T x, U y) {return (x > 0 ? x / y : (x - y + 1) / y);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int a[100005];
map<int,int> mp;
void add(int i,int x)
{
    mp[i] = x;
    auto it = mp.find(i);
    if(it != mp.begin() && prev(it)->second <= x)
    {
        mp.erase(i);
        return;
    }
    while(next(it) != mp.end() && next(it)->second >= x)
        mp.erase(next(it));
}
void solve()
{
    mp.clear();
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        add(i,a[i]);
    }
    for(int i = 1;i <= m;i++)
    {
        int p,x;
        cin >> p >> x;
        a[p] -= x;
        add(p,a[p]);
        cout << mp.size() << ' ';
    }
    cout << "\n";
}
signed main ()
{   
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}

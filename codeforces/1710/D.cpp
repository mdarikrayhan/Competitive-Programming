#include<bits/stdc++.h>
using namespace std;

#include<tr2/dynamic_bitset>
using namespace tr2;
using bset = tr2::dynamic_bitset<__uint128_t>;

#define fastio() cout.tie(NULL)

#define all(a) a.begin(),a.end()
#define endl "\n"
#define sp " " 
#define pb push_back
#define mp make_pair

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) {cerr << "[" << #x << "] = ["; _print(x);}
#define reach cerr << "reached" << endl
#else
#define debug(x...)
#define reach 
#endif

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;
const int64_t inf = 0x3f3f3f3f, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// #define int int64_t

const int N = 2e3+5;

bool good[N][N];
int rep[N][N];

void reset(int n)
{
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            good[i][j] = rep[i][j] = 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tt = 1;
    cin >> tt;
    for(int t = 1; t <= tt; t ++)
    {
        int n;
        cin >> n;

        vector<pair<int, pair<int, int>>> seg;
        char ch;
        for(int i = 1; i <= n; i ++)
            for(int j = i; j <= n; j ++)
            {
                cin >> ch;
                good[i][j] = (ch == '1');

                if(good[i][j] and i != j)
                    seg.pb(mp(j - i + 1, mp(i, j)));
            }
        sort(all(seg));
        
        if(n == 1)
            continue;
        
        for(int i = 1; i <= n; i ++)
            rep[i][i] = i;

        set<pair<int, int>> edge;
        auto ins = [&](int u, int v) -> void
        {
            if(u > v)
                swap(u, v);
            edge.insert(mp(u, v));
        };
        auto connect = [&](vector<int> re) -> int
        {
            int m = re.size();
            sort(all(re));

            assert(m > 3);

            ins(re[0], re[m - 1]);
            ins(re[1], re[m - 1]);

            for(int i = 2; i < m - 1; i ++)
                ins(re[0], re[i]);
            
            return re[1];
        };

        vector<int> p(n + 1, 0);
        auto query = [&](int l, int r) -> int
        {
            return p[r] - p[l - 1];
        };
        auto upd = [&](int i) -> void
        {
            for(int j = i; j <= n; j ++)
                p[j] ++;
        };

        vector<int> y(n + 1, 0);
        for(int i = 1; i <= n; i ++)
            y[i] = i;
        
        for(auto [_, s] : seg)
        {
            auto [l, r] = s;

            int x = query(l, r - 1);
            if(x < r - l)
            {
                vector<int> re;

                int j = l;
                while(j < r)
                    re.pb(rep[j][y[j]]), j = y[j] + 1;
                
                if(j == r)
                    re.pb(rep[j][j]);
                
                re.erase(re.begin());
                re.insert(re.begin(), l);

                re.pop_back();
                re.push_back(r);

                if(re.size() == 2)
                {
                    ins(re.front(), re.back());
                    rep[l][r] = l + 1;
                }
                else
                    rep[l][r] = connect(re);

                for(int i = l; i < r; i ++)
                    if(query(i, i) != 1)
                        upd(i);
            }
            else
                rep[l][r] = l + 1;

            y[l] = r;
        }

        for(auto [u, v] : edge)
            cout << u << sp << v << endl;
        cout << endl;

        reset(n);
    }
}
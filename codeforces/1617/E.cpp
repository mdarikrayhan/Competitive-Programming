#include<bits/stdc++.h>
#pragma GCC optimize("03")

using namespace std;

#define ll long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

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

const int MOD = 1e9+7;
const int64_t inf = 0x3f3f3f3f, INF = 1e18, BIG_MOD = 489133282872437279;
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



const int MAXN = 2e5+5;



bool on(int i, int x)   {return (((int)1) << i) & x;}
int msb(int x)          {return 31 - (__builtin_clz(x));}
int lsb(int x)          {return msb(x & -x);}
int cnt(int x)          {return __builtin_popcount(x);}
void modify(int &x)       {x &= (x - 1);}
string bin(ll n)        {return bitset<7>(n).to_string();}

int zero(int x)
{
    if(x == 0)  return 0;

    int ans = 1; 
    for(int i = 31; i > lsb(x) + 1; i --)
        ans += (on(i, x) != on(i - 1, x));
    return ans;
}


vector<pair<int, int>> store[32];

int n;
vector<int> a(MAXN);

int32_t main()
{
    fastio();
    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    vector<pair<int, int>> opt_zero(33, mp(0, 0));
    pair<int, pair<int, int>> ans = mp(0, mp(0, 0));

    for(int i = 1; i <= n; i ++)
    {
        int x = a[i];
        if(x == 0)
        {
            for(int l = 0; l <= 32; l ++)
                ans = max(ans, mp(opt_zero[l].first, mp(i, opt_zero[l].second)));

            opt_zero[32] = mp((int)0, i);
            continue;
        }

        int l = lsb(x), r = msb(x), z = zero(x);

        //reduce to zero options
        for(int l2 = 0; l2 <= 32; l2 ++)
            if(l2 != l and opt_zero[l2].second > 0)   
                ans = max(ans, mp(z + opt_zero[l2].first, mp(i, opt_zero[l2].second)));

        opt_zero[l] = max(opt_zero[l], mp(z, i));

        //equal lsb options
        int val = 0;
        x >>= (l + 1);
        for(int i = 0; i < 31; i ++)    
            val += (on(i, x) != on(i + 1, x)) * (1 << i);

        store[l].pb(mp(val, i));
    }

    for(int l = 0; l < 32; l ++)
    {
        function<void(int, int, vector<pair<int, int>>)> dfs = [&](int level, int next, vector<pair<int, int>> current)
        {
            vector<pair<int, int>> pass[32];
            vector<pair<int, int>> mx(32, mp(-inf, -inf));

            pair<int, int> leave_here = mp(-inf, -1);

            for(auto &p : current)
            {
                if(cnt(p.first) == 0)
                    leave_here = mp(0, p.second);
                else 
                {
                    if(level == -1)
                    {
                        int l = lsb(p.first);
                        pass[l].pb(p);
                        mx[l] = max(mx[l], mp(cnt(p.first), p.second));
                    }
                    else
                    {
                        modify(p.first);
                        if(cnt(p.first) == 0)
                        {
                            pass[0].pb(p);
                            mx[0] = max(mx[0], mp(0, p.second));
                        }
                        else
                        {
                            int l = lsb(p.first);
                            pass[l].pb(p);
                            mx[l] = max(mx[l], mp(cnt(p.first), p.second));
                        }
                    }
                }
            }
            current.clear();

            pair<int, int> mx1 = mp(-inf, -inf), mx2 = mp(-inf, inf);

            mx.push_back(leave_here);
            for(auto M : mx)
            {
                if(M > mx2) mx2 = M;
                if(mx2 > mx1)   swap(mx1, mx2);
            }

            if(mx2.second > 0)
            {
                ans = max(ans, mp(mx1.first + mx2.first, mp(mx1.second, mx2.second)));
            }

            for(int nextnext = level + 1; nextnext < 32; nextnext ++)
                if(!pass[nextnext].empty())
                    dfs(level + 1, nextnext, pass[nextnext]);

            return;
        };

        if(!store[l].empty())   dfs(-1, 0, store[l]);
    }

    cout << ans.second.first << sp << ans.second.second << sp << ans.first << endl;
}

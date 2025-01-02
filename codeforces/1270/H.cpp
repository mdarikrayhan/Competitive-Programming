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
#define vecvec(type, name, n, m, value) vector<vector<type>> name(n + 1, vector<type> (m + 1, value))

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

int ceil_div(int x, int y)  {return (x + y - 1)/y;}

const int N = 5e5+5, X = 1e6+5, B = 1000;

int n, q;
int a[N];

//query
int pos[N], val[N], ans[N];

//block
bool in[N];
int pmn[N], smx[N], split[N];
int bck_static[X], nxt_static[X];
int bpmn[B + 5], bsmx[B + 5];

int query(int l, int r)
{
    if(l > r)   return 0;
    return split[r] - split[l - 1];
}

int32_t main()
{
    fastio();
    
    cin >> n >> q;

    for(int i = 1; i <= n; i ++)    cin >> a[i];
    for(int i = 1; i <= q; i ++)    cin >> pos[i] >> val[i];

    for(int b = 1; b <= ceil_div(q, B); b ++)
    {
        int L = (b - 1) * B + 1, R = min(q, b * B);

        vector<int> mark, sign;
        for(int i = L; i <= R; i ++)
        {
            mark.pb(pos[i]), in[pos[i]] = true;
            sign.pb(a[pos[i]]), bck_static[a[pos[i]]] = n + 1, nxt_static[a[pos[i]]] = 0;
            sign.pb(val[i]), bck_static[val[i]] = n + 1, nxt_static[val[i]] = 0;
        }

        sort(all(mark)), mark.erase(unique(mark.begin(), mark.end()), mark.end());
        sort(all(sign)), sign.erase(unique(sign.begin(), sign.end()), sign.end());

        auto rsign = sign;
        reverse(all(rsign));

        pmn[0] = inf, smx[n + 1] = 0, split[0] = 0;

        for(int i = 1; i <= n; i ++)
            pmn[i] = min(pmn[i - 1], (!in[i] ? a[i] : pmn[i - 1]));

        for(int i = n; i >= 1; i --)
            smx[i] = max(smx[i + 1], (!in[i] ? a[i] : smx[i + 1]));

        for(int i = 1; i <= n; i ++)
            split[i] = split[i - 1] + (pmn[i] > smx[i + 1]);
        
        for(int i = 1; i <= n; i ++)
            while(!in[i] and !sign.empty() and sign.back() > a[i])
                bck_static[sign.back()] = i, sign.pop_back();

        for(int i = n; i >= 1; i --)
            while(!in[i] and !rsign.empty() and rsign.back() < a[i])
                nxt_static[rsign.back()] = i, rsign.pop_back();

        int m = mark.size();
        bsmx[m] = 0, bck_static[0] = n + 1;

        for(int t = L; t <= R; t ++)
        {
            a[pos[t]] = val[t];

            bpmn[0] = a[mark[0]];
            for(int i = 1; i < m; i ++)
                bpmn[i] = min(bpmn[i - 1], a[mark[i]]); 
            for(int i = m - 1; i >= 0; i --)
                bsmx[i] = max(bsmx[i + 1], a[mark[i]]);

            ans[t] = split[n] - query(bck_static[bsmx[0]], mark[0] - 1);

            for(int j = 0; j < m; j ++)
            {
                int i = mark[j];

                bpmn[j] = min((j == 0 ? a[i] : bpmn[j - 1]), a[i]);
                int till = (j == m - 1 ? n + 1 : mark[j + 1]);

                int pbound = nxt_static[bpmn[j]], sbound = bck_static[bsmx[j + 1]];

                if(bpmn[j] < bsmx[j + 1] or pbound >= till or sbound <= i or pbound >= sbound)
                    ans[t] -= query(i, till - 1);
                else
                    ans[t] -= query(i, pbound - 1) + query(sbound, till - 1);
            }
        }

        for(auto i : mark)  in[i] = false;
    }

    for(int i = 1; i <= q; i ++)    cout << ans[i] << endl;
}
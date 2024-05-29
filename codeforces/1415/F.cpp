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

#define int int64_t

const int N = 2e5+5;

int n;
int t[N], x[N];

int erl[N];
bool rch[N];


int32_t main()
{
    fastio();

    cin >> n;
    for(int i = 1; i <= n; i ++)    cin >> t[i] >> x[i];

    fill(erl, erl + N, INF);
    fill(rch, rch + N, false);

    t[0] = x[0] = 0;
    erl[0] = 0;

    bool can = true;

    for(int i = 0; i < n; i ++)
        if(t[i] + abs(x[i] - x[i + 1]) > t[i + 1])
            can = false;
    
    
    for(int r = 1; r <= n and !can; r ++)
    {
        erl[r] = min(erl[r], max(t[r - 1], erl[r - 1] + abs(x[r] - x[r - 1])));
        erl[r] = min(erl[r], (rch[r - 1] ? max(t[r - 1], t[r - 2] + abs(x[r] - x[r - 2])) : INF));

        bool place = false;
        for(int l = r - 1; l >= 0 and !rch[r]; l --)
        {
            if(l != r - 1 and erl[l] != INF)
            {
                if(erl[l] + abs(x[l] - x[l + 1]) <= t[l + 1])
                {
                    int time_at = max(t[l], erl[l] + abs(x[l] - x[r])) + abs(x[r] - x[l + 1]);

                    bool place_here = (time_at <= t[l + 1]);

                    if(place or place_here)
                        rch[r] = true;
                }
            }

            if(l != r - 1 and l >= 1 and rch[l])
            {
                if(t[l - 1] + abs(x[l - 1] - x[l + 1]) <= t[l + 1])
                {
                    int time_at = max(t[l], erl[l] + abs(x[l - 1] - x[r])) + abs(x[r] - x[l + 1]);

                    bool place_here = (time_at <= t[l + 1]);

                    if(place or place_here)
                        rch[r] = true;
                }
            }

            if(l != r - 1)
            {
                if(t[l] + abs(x[l] - x[l + 1]) > t[l + 1])  break;

                int time = abs(x[l] - x[r]) + abs(x[r] - x[l + 1]);
                if(t[l] + time <= t[l + 1])   place = true;
            }
        }

        if(erl[r] > t[r])   erl[r] = INF;

        if(rch[r])
        {
            if(r == n)
            {
                can = true;
                continue;
            }

            bool here = (t[r - 1] + abs(x[r - 1] - x[r + 1]) <= t[r + 1]);

            for(int i = r + 1; i < n; i ++)
                if(t[i] + abs(x[i] - x[i + 1]) > t[i + 1])
                    here = false;

            can = (can or here);
        }

        if(erl[r] < t[r])
        {
            if(r == n)
            {
                can = true;
                continue;
            }

            bool here = (erl[r] + abs(x[r] - x[r + 1]) <= t[r + 1]);

            for(int i = r + 1; i < n; i ++)
                if(t[i] + abs(x[i] - x[i + 1]) > t[i + 1])
                    here = false;

            can = (can or here);
        }

    }

    cout << (can ? "YES" : "NO") << endl;
}
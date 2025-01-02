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

const int N = 2e5+5, X = 2e5, B = 600;

int n, q;
int a[N];
int pos[N], val[N];

//block
int l_pos[N], r_pos[N], freq[N];

int block_id[N];
int l_block[N], r_block[N], mx_block[N];

int block_cid[N];
int l_cblock[N], r_cblock[N], mx_cblock[N], sum_mx_cblock[N];

int rs_cblock[N], rs_pos[N];

bool p_mark[N], v_mark[N], b_mark[N];

void reset()
{
    fill(p_mark, p_mark + N, false);
    fill(b_mark, b_mark + N, false);
    fill(v_mark, v_mark + N, false);

    fill(l_pos, l_pos + N, inf);
    fill(r_pos, r_pos + N, 0);
    
    fill(l_block, l_block + N, inf);
    fill(r_block, r_block + N, 0);

    fill(l_cblock, l_cblock + N, inf);
    fill(r_cblock, r_cblock + N, 0);

    fill(rs_cblock, rs_cblock + N, 0);
    fill(rs_pos, rs_pos + N, 0);

    fill(freq, freq + N, 0);
    fill(block_id, block_id + N, 0);
    fill(block_cid, block_cid + N, 0);
    fill(mx_block, mx_block + N, 0);
    fill(mx_cblock, mx_cblock + N, 0);
    fill(sum_mx_cblock, sum_mx_cblock + N, 0);
}

int32_t main()
{
    fastio();
    
    cin >> n >> q;
    ++ q;

    for(int i = 1; i <= n; i ++)    cin >> a[i];

    pos[1] = 1, val[1] = a[1];
    for(int i = 2; i <= q; i ++)    cin >> pos[i] >> val[i];

    for(int b = 1; b <= ceil_div(q, B); b ++)
    {
        reset();

        int L = (b - 1) * B + 1, R = min(q, b * B);

        vector<int> mark;
        for(int i = L; i <= R; i ++)
            p_mark[pos[i]] = v_mark[a[pos[i]]] = v_mark[val[i]] = true, mark.pb(pos[i]);

        for(int i = 1; i <= n; i ++)
        {
            if(p_mark[i])   continue;

            ++ freq[a[i]];
            l_pos[a[i]] = min(l_pos[a[i]], i);
            r_pos[a[i]] = max(r_pos[a[i]], i);
        }

        int id = 0;

        for(int i = 1; i <= n; i ++)
        {
            int ext = i;
            
            ++ id;
            while(i <= n)
            {
                block_id[i] = id;

                if(!p_mark[i])
                {
                    ext = max(ext, r_pos[a[i]]);
                    mx_block[id] = max(mx_block[id], freq[a[i]]);
                }

                if(i == ext)    break;
                i ++;
            }
        }

        for(int x = 1; x <= X; x ++)
        {
            if(l_pos[x] != inf)
            {
                int b_id = block_id[l_pos[x]];

                l_block[b_id] = min(l_block[b_id], l_pos[x]);
                r_block[b_id] = max(r_block[b_id], r_pos[x]);
                if(v_mark[x])   b_mark[b_id] = true;
            }
        }


        for(int i = 1; i <= n; i ++)
        {
            if(p_mark[i])
            {
                b_mark[block_id[i]] = true;

                l_block[block_id[i]] = min(l_block[block_id[i]], i);
                r_block[block_id[i]] = max(r_block[block_id[i]], i);
            }
        }

        int cid = 0;
        //compress blocks
        for(int i = 1; i <= n; i ++)
        {
            ++ cid;
            if(b_mark[block_id[i]])
            {
                mx_cblock[cid] = mx_block[block_id[i]];

                l_cblock[cid] = l_block[block_id[i]];
                r_cblock[cid] = r_block[block_id[i]];

                block_cid[block_id[i]] = cid;

                i = r_block[block_id[i]];
                continue;
            }

            while(i <= n and !b_mark[block_id[i]])
            {
                block_cid[block_id[i]] = cid;
                mx_cblock[cid] = max(mx_cblock[cid], mx_block[block_id[i]]);

                l_cblock[cid] = min(l_cblock[cid], l_block[block_id[i]]);
                r_cblock[cid] = max(r_cblock[cid], r_block[block_id[i]]);

                sum_mx_cblock[cid] += mx_block[block_id[i]];

                i = r_block[block_id[i]] + 1;
            }
            i --;
        }

        vector<int> change = mark;
        sort(all(change));
        change.erase(unique(change.begin(), change.end()), change.end());

        for(int c = 1; c <= cid; c ++)
            mark.pb(l_cblock[c]), mark.pb(r_cblock[c]);
        
        sort(all(mark));
        mark.erase(unique(mark.begin(), mark.end()), mark.end());

        int m = mark.size();

        for(int i = 1; i <= n; i ++)
            if(p_mark[i])
                freq[a[i]] ++;
        
        for(int i = L; i <= R; i ++)
        {
            bool now = (i == 5);

            freq[a[pos[i]]] --;
            a[pos[i]] = val[i];
            freq[a[pos[i]]] ++;
            
            for(auto j : change)
            {
                int idx = r_pos[a[j]];

                if(idx != 0)
                {
                    int c_idx = block_cid[block_id[idx]]; 
                    rs_cblock[c_idx] = max(rs_cblock[c_idx], j);
                }
                rs_pos[a[j]] = max(rs_pos[a[j]], j);
            }

            int ans = n;

            for(int i = 0; i < m; i ++)
            {
                int x = mark[i];

                int ext = x;
                int mx = 0, sm = 0;
                bool marked = false;

                while(i < m)
                {
                    x = mark[i];

                    if(x > ext) break;

                    if(p_mark[x])
                    {
                        mx = max(mx, freq[a[x]]), ext = max(ext, max(r_pos[a[x]], rs_pos[a[x]]));

                        if(r_pos[a[x]] != 0)
                            ext = max(ext, r_cblock[block_cid[block_id[r_pos[a[x]]]]]);
                    }

                    int c_idx = block_cid[block_id[x]];

                    if(b_mark[block_id[x]])
                        marked = true;

                    ext = max(ext, max(r_cblock[c_idx], rs_cblock[c_idx]));
                    mx = max(mx, mx_cblock[c_idx]);

                    if(!marked)
                        sm = sum_mx_cblock[c_idx];

                    i ++;
                }

                ans -= mx;

                if(!marked)
                    ans -= sm - mx;
                
                i --;
            }

            cout << ans << endl;

            for(auto j : change)
            {
                rs_pos[a[j]] = 0;

                int idx = r_pos[a[j]];
                if(idx != 0)
                {
                    int c_idx = block_cid[block_id[idx]]; 
                    rs_cblock[c_idx] = 0;
                }
            }
        }
    }
}
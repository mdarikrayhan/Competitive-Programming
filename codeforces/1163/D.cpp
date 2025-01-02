#include <bits/stdc++.h>

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
#define all(a) a.begin(), a.end()
#define sz(a) (ll) a.size()
#define fi first
#define se second
#define endl '\n'

using namespace std;

const ll mod = 1e9 + 7;
const ll md = 998244353;
const int lim = 1e5 + 1;
const int N = 2e5 + 5;
const ll inf = 1e18;
const int imx = 1e9;
const int blocksz = 500;

// Target:
// 1. Stop myself from getting too deep into a problem and move to the next one
// (This habit killed me many times)
// 2. Reach Candidate Master (287 pts left)
// 3. VOI (2025-2026)

/* Yay KMP */
string all, s, t;
int kmp[N], kmp2[N], aut[N][26], aut2[N][26];
ll dp[1002][52][52];

void maximize(ll &x, ll y)
{
    if (x < y)
        x = y;
}

int main()
{
    IOS;
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> all >> s >> t;

    aut[0][s[0] - 'a'] = 1;
    for (int i = 1; i < sz(s); i++)
    {
        kmp[i] = aut[kmp[i - 1]][s[i] - 'a'];
        for (char c = 'a'; c <= 'z'; c++)
            if (s[i] == c)
                aut[i][c - 'a'] = i + 1;
            else
                aut[i][c - 'a'] = aut[kmp[i - 1]][c - 'a'];
    }
    for (char c = 'a'; c <= 'z'; c++)
        aut[sz(s)][c - 'a'] = aut[kmp[sz(s) - 1]][c - 'a'];
    for (int i = sz(s); i >= 0; i--)
        for (int j = 0; j < 26; j++)
            aut[i + 1][j] = aut[i][j];
    fill_n(aut[0], 26, 0);

    aut2[0][t[0] - 'a'] = 1;
    for (int i = 1; i < sz(t); i++)
    {
        kmp2[i] = aut2[kmp2[i - 1]][t[i] - 'a'];
        for (char c = 'a'; c <= 'z'; c++)
            if (t[i] == c)
                aut2[i][c - 'a'] = i + 1;
            else
                aut2[i][c - 'a'] = aut2[kmp2[i - 1]][c - 'a'];
    }
    for (char c = 'a'; c <= 'z'; c++)
        aut2[sz(t)][c - 'a'] = aut2[kmp2[sz(t) - 1]][c - 'a'];
    for (int i = sz(t); i >= 0; i--)
        for (int j = 0; j < 26; j++)
            aut2[i + 1][j] = aut2[i][j];
    fill_n(aut2[0], 26, 0);

    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 52; j++)
            for (int k = 0; k < 52; k++)
                dp[i][j][k] = -1e18;
    dp[0][0][0] = 0;
    for (int i = 1; i <= sz(all); i++)
    {
        if (all[i - 1] == '*')
        {
            for (int j = 0; j <= sz(s); j++)
                for (int k = 0; k <= sz(t); k++)
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        ll t1 = aut[j + 1][c - 'a'] == sz(s) ? 1 : 0;
                        ll t2 = aut2[k + 1][c - 'a'] == sz(t) ? 1 : 0;
                        maximize(dp[i][aut[j + 1][c - 'a']][aut2[k + 1][c - 'a']], dp[i - 1][j][k] + t1 - t2);
                    }
        }
        else
        {
            for (int j = 0; j <= sz(s); j++)
                for (int k = 0; k <= sz(t); k++)
                {
                    ll t1 = aut[j + 1][all[i - 1] - 'a'] == sz(s) ? 1 : 0;
                    ll t2 = aut2[k + 1][all[i - 1] - 'a'] == sz(t) ? 1 : 0;
                    // cout << t1 << " " << t2 << endl;
                    maximize(dp[i][aut[j + 1][all[i - 1] - 'a']][aut2[k + 1][all[i - 1] - 'a']], dp[i - 1][j][k] + t1 - t2);
                }
            /*for (int j = 0; j <= sz(s); j++)
            {
                for (int k = 0; k <= sz(t); k++)
                    cout << dp[i][j][k] << " ";
                cout << endl;
            }
            cout << endl;*/
        }
    }

    ll ans = -1e18;
    for (int i = 0; i <= sz(s); i++)
        for (int j = 0; j <= sz(t); j++)
            ans = max(ans, dp[sz(all)][i][j]);
    cout << ans;

    cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
}

  	    	 	    		  	 	    	 		 	
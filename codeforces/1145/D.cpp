#include <bits/stdc++.h>
#include <unordered_set>
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define endl '\n'
#define int long long
using namespace std;
const ll mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279;
ll gcd(ll a, ll b) { return (!a) ? b : gcd(b % a, a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll fac(ll a) { ll res = 1; for (ll i = 1; i <= a; i++) res *= i; return res; }
bool prime(int a) {
    if (a == 1) return 0; if (a == 2) return 1;
    for (int i = 2; i * i <= a; i++) if (a % i == 0) return 0;
    return 1;
}
ll fast_power(ll x, ll n) {
    /*x pow n*/ ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) res *= x;
        x *= x, n /= 2;
    }
    return res;
}
bool isPalindrome(string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return str == reversed;
}
int mult(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
int fp(ll a, ll b) {
    if (!b) return 1;
    int ret = fp(a, b / 2);
    ret = mult(ret, ret);
    if (b % 2) ret = mult(ret, a);//(b%2==1)
    return ret;
}
//(x+m)%mod is congurent to x
int modInv(ll y) { return fp(y, mod - 2); }
int divi(ll a, ll b) { return mult(a, modInv(b)); }
int subt(ll a, ll b) { return (a % mod - b % mod + mod) % mod; }
int pwr(int a, int b) { int p = 1; for (int i = 1; i <= b; i++) p *= a; return p; }
bool des(const vector<int>& v) { for (int i = 1; i < v.size(); i++) if (v[i] < v[i - 1]) return 0; return 1; }
int mex(set<int>& s) { int mex = 0; while (s.count(mex)) mex++; return mex; }
ll fact(int n) { if (n == 0) return 1; return (n * fact(n - 1)); }
ll factArr[200005];
void initialize() {
    factArr[0] = 1;
    for (int i = 1; i < 200005; i++) factArr[i] = mult(factArr[i - 1], i);
}
int ncr(ll n, ll r) {
    if (n < r || n < 0 || r < 0) return 0;
    if (n == r || r == 0) return 1;
    return divi(factArr[n], mult(factArr[r], factArr[n - r]));
}
int strsnbars(ll n, ll k) { return ncr(n + k - 1, n); }
int MEX(vector <int>& a) {
    int n = a.size();
    unordered_set<int> hash(all(a));
    for (int i = 1; i <= n + 1; i++) if (hash.find(i) == hash.end()) return i;
}
vector<string> g;
bool seen[30][30];
int N;
int n, m, k;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
vector <bool> Vis;
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
/*void dfs(int i, int j) {
    if (seen[i][j]) return;
    seen[i][j] = 1;
    for (int k = 0; k < 8; k++) {
        int nx = dx[k] + i, ny = dy[k] + j;
        if (valid(nx, ny) && !seen[nx][ny] && g[nx][ny] == '1') dfs(nx, ny);
    }
}*/
vector<vector<int>> adj;
vector<bool> vis;
void dfs(int node)
{
    vis[node] = 1;
    for (int i : adj[node])
    {
        if (!vis[i]) dfs(i);
    }
}
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cubes.in", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n, mn = INT_MAX; cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i]; mn = min(mn, v[i]);
        }
        cout<<2+(mn^v[2]);
    }
    return 0;
}
/*
ll l[1000][1000] = {};
void initialize(){
    l[0][0] = 1;
    for (int i = 1; i < 1001; i++) {l[i][0] = 1;
        for (int j = 1; j < i + 1; j++) { l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]);}}}
ll Ncr(ll n, ll r){
    return l[n][r];} */
/*
char grid[30][30];
bool seen[30][30];
int n;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
vector<vector<int>> g;
vector <bool> vis;
int cntr = 0, far = 0, mx = 0;
bool valid(int i, int j)
{
    return i >= 0 && i < n && j < n;
}
void dfs(int i, int j)
{
    if (seen[i][j]) return;
    seen[i][j] = 1;
    for (int k = 0; k < 8; k++)
    {
        int xc = dx[k] + i;
        int yc = dy[k] + j;
        if (valid(xc, yc) && !seen[xc][yc] && grid[xc][yc] == '1')
            dfs(xc, yc);
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("cubes.in", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        while (scanf_s("%d", &n) != EOF)
        {
            for (int i = 0; i < n; i++)
            {
                scanf_s("%s", grid[i]);
            }
            memset(seen, 0, sizeof(seen));
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!seen[i][j] && grid[i][j] == '1')
                    {
                        dfs(i, j);
                        ans++;
                    }
                }
            }
            printf("Image number %d contains %d war eagles.\n", t++, ans);
        }
    }
    return 0;
}*/
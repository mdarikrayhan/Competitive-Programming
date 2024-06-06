#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sort1(v) sort(v.begin(), v.end());
#define sort2(v) sort(v.rbegin(), v.rend());
#define pb(x) push_bak(x);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define loop(n, m, name, k)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            name[i][j] = k;
#define endl '\n'
#define llu unsignedlonglong
#define out(v)        \
    for (auto &a : v) \
        out << a << "";
#define vi(n) vetor<int> v(n);
#define all(v) v.begin(), v.end()
// #define mod (ll)1000000007
#ifndef PI
#define PI 3.14159265358979323846f
#endif
#ifndef DEG2RAD
#define DEG2RAD (PI / 180.0f)
#endif
#ifndef RAD2DEG
#define RAD2DEG (180.0f / PI)
#endif
#define double long double

ll fast_power(ll n, ll p, ll MOD)
{
    if (p == 0)
        return 1;
    ll sq = fast_power(n, p / 2, MOD);
    sq = (sq % MOD * sq % MOD) % MOD;
    if (p & 1)
        sq = (n * sq) % MOD;
    return sq;
}
ll gcd(ll a, ll b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}
ll to_int(bitset<20> &v)
{
    int s = 0, base = 1;
    for (int i = 0; i < 64; i++)
    {
        if (v[i])
            s += base;
        base *= 2;
    }
    return s;
}

void prime_num()
{
    vector<int> prime(100000 + 9, 1), primes;
    for (int i = 2; i <= 1000000; i++)
    {
        if (prime[i] == 1)
        {
            primes.push_back(i);
            for (int j = i; j <= 1000000; j += i)
            {
                prime[j] = i;
            }
        }
    }
}
double dist(double x1, double x2, double y1, double y2)
{
    return sqrt(pow(abs(x2 - x1), 2) + pow(abs(y1 - y2), 2));
}

int sum_of_digit(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

/*char grid[1009][1009];
int vis[1009][1009];
int n;
int Dx[4] = { 1, -1}, Dy[4] = { -1, 1};
int flood_fill(int i, int j,char c)
{
    if (i <= 0 || i > n || j <= 0 || j > n)
        return 0;
    if (vis[i][j] || grid[i][j] !=c)
        return 0;
    int ans=1;
    vis[i][j] =1;
    for (int k = 0; k < 2; k++)
    {

        ans+=flood_fill(i + Dx[k], j ,c);
    }
    for (int h = 0; h < 2; h++)
    {
        ans+=flood_fill(i , j + Dy[h],c);
    }
    return ans;
}

pair<int, int> diameter(int i, int par = -1)
{
    int diam = 0;
    int maxHeigths[] = {-1, -1, -1};
    for (auto &a : edge[i])
    {
        if (a != par)
        {
            pair<int, int> p = diameter(a, i);
            diam = max(diam, p.first);

            maxHeigths[0] = p.second + 1;
            sort(maxHeigths, maxHeigths + 3);
        }
    }
    for (int i = 0; i < 3; i++)
        if (maxHeigths[i] == -1)
            maxHeigths[i] = 0;
    diam = max(diam, maxHeigths[2] + maxHeigths[1]);
    dis[i] = maxHeigths[2];
    return {diam, maxHeigths[2]};
}
vector<int>color(300009,-1),vis(300009,0);
vector<vector<int>> edge(300009);
bool bfs_col(int node,int&c,int&c1){//to find two group that each group has a distains color
  vis[node]=1;
  color[node]=1;
  queue<int>q;q.push(node);
  while(!q.empty()){
    int s=q.front();q.pop();
    c+=color[s];
    c1+=!color[s];
    for(auto&a:edge[s]){
      if(!vis[a]){
        vis[a]=1;
        q.push(a);

      }
      if(color[a]==-1)
        color[a]=!color[s];
    }
  }
  return 1;
}*/
void fun();
ll fast_power(ll n, ll p)
{
    if (p == 0)
        return 1;
    ll sq = fast_power(n, p / 2);
    sq = (sq * sq);
    if (p & 1)
        sq = (n * sq);
    return sq;
}
int add(int a, int b)
{
    while (b > 0)
    {
        int carry = a & b;
        a ^= b;
        b = carry << 1;
    }
    return a;
}
int prod(int a, int b)
{
    int c = 0;
    while (b > 0)
    {
        if ((b & 1) == 1)
        {
            c = add(c, a); // Use the addition function we coded previously
        }
        a <<= 1;
        b >>= 1;
    }
    return c;
}

bool get_bit(ll a, ll i)
{
    return (a & ((ll)1 << i));
}
string f(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }
    return s;
}
bool is_big(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] > s[n - i - 1])
            return 1;
    }
    return 0;
}
ll inv(ll x, ll MOD)
{
    if (x <= 1)
    {
        return x;
    }
    return MOD - MOD / x * inv(MOD % x, MOD) % MOD;
}

long long sqrt1(long long a)
{
    long long l = 0, r = 5000000001;
    while (r - l > 1)
    {
        long long mid = (l + r) / 2;
        if (1ll * mid * mid <= a)
            l = mid;
        else
            r = mid;
    }
    return l;
}

const int MAXN = 0;
const int MOD1 = 1000000007;
const int MOD2 = 998244353;
const int INF = 1e9;
ll fac[MAXN + 1];
ll inv1[MAXN + 1];

/** Precomputes n! from 0 to MAXN. */
void factorial(int MOD)
{
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * (ll)i % MOD;
    }
}
/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses(int MOD)
{
    inv1[MAXN] = fast_power(fac[MAXN], MOD - 2, MOD);
    for (int i = MAXN; i >= 1; i--)
    {
        inv1[i - 1] = inv1[i] * (ll)i % MOD;
    }
}
/** Computes nCr mod p */
int choose(int n, int r, int p)
{
    return fac[n] * (ll)inv1[r] % p * (ll)inv1[n - r] % p;
}

bool f(int n, int a, int b)
{
    while (n)
    {
        if (n % 10 != a && n % 10 != b)
        {
            return 0;
        }
        n /= 10;
    }
    return 1;
}
// The longest common subsequence in C++
void lcsAlgo(char *S1, char *S2, int m, int n)
{
    int LCS_table[m + 1][n + 1];

    // Building the mtrix in bottom-up way
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }

    int index = LCS_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }

    // Printing the sub sequences
    cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}
int lis(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l - 1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++)
    {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}
ll accurateFloor(ll a, ll b)
{
    ll val = a / b;
    while (val * b > a)
        val--;
    return val;
}
void dp_subarry(int n)
{
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    vector<ll> v(n + 1), v1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = v[i] * v1[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j + i - 1 <= n; j++)
        {
            dp[j][i] = dp[j + 1][i - 2] + v[j] * v1[j + i - 1] + v1[j] * v[j + i - 1];
        }
    }
}
void Ternary_Search()
{
    double l = 0, r = 1e18;
    double mn = 1e18;
    while (r - l >= 1e-10)
    {
        double mid1 = (r + l * 2) / 3.0;
        double mid2 = (r * 2 + l) / 3.0;
        double k1, k3, k2, k4, d1, d3, d2, d4;
        if (dist(d1, d3, d2, d4) < dist(k1, k3, k2, k4))
        {
            r = mid2;
        }
        else if (dist(d1, d3, d2, d4) > dist(k1, k3, k2, k4))
        {
            l = mid1;
        }
        else
        {
            r = mid2;
            l = mid1;
        }
    }
}
const double Pi = acos(-1.0);
double toDegreeFromMinute(double m)
{
    return m / 60;
}
double toRadians(double degree)
{
    return degree * Pi / 180;
}
double toDegree(double radian)
{
    if (radian < 0)
        radian += 2 * Pi;
    return radian * 180 / Pi;
}
double fixAngel(double A)
{
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}
double getSide_a_bAB(double b, double A, double B)
{
    return sin(A) * b / sin(B);
}
double getAngel_A_abB(double a, double b, double B)
{
    return asin(fixAngel(a * sin(B) / b));
}
double getAngel_A_abc(double a, double b, double c)
{
    return acos(fixAngel((b * b + c * c - a * a) / (2 * b * c)));
}
void solve()
{
    int n,m,k;cin>>n>>m>>k;
    vector<int>v(n),cnt(101);
    for(auto&a:v){
        cin>>a;
        cnt[a]++;
        }
    int num=v[m-1];
    sort2(v);
    v.push_back(0);
    if(v[k-1]==num&&v[k]==num){
        cout<<"MAYBE"<<endl;
    }else if(v[k-1]<=num){
        yes;
    }else{
        no;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("moocast.in","r",stdin);
    //  freopen("moocast.out","w",stdout);
    // fun();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
void fun()
{
    prime_num();
}
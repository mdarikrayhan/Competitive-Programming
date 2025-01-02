// author: ziadelsayed
#include <bits/stdc++.h>
#include <cctype>

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define c(s) cout << s << endl
#define no cout << "NO" << "\n"
#define yes cout << "YES" << "\n"
#define forr(i, y, n) for (int i = y; i < n; i++)
#define forrr(i, y, n) for (int i = n - 1; i >= y; i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fix(y, x) fixed << setprecision(y) << x // double x=.54676879780778976;
#define endl "\n"
#define pb push_back
#define pf push_front
#define ll long long int
#define ld long double
#define len length()
#define sz size()
#define str string
#define ts to_string
#define PI 3.14159265358979323846

using namespace std;
const int MAX = 5e5 + 7;
int pl[MAX];
vector<ll> factorial;
void Bismillah()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool isSorted(const string &s) // string // there is build in function to check sorting of vec (is_sorted(all(vec)));
{
    for (int i = 1; i < s.len; i++)
    {
        if (s[i] < s[i - 1])
        {
            return false;
        }
    }
    return true;
}
bool isPrime(ll num)
{
    if (num <= 1)
        return false;
    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool check(string s, ll n)
{
    // string h = "";
    // vector<char> v;
    // set<char> s;
    int y;
}

bool isSubset(string s, string h) // string subset from another string
{
    // int cnt = 0;
    for (char ch : h)
    {
        if (s.find(ch) == string::npos)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n, m, ans = 0, a, b, c, d;
    // string s, h;
    // cin >> s;
    cin >> n >> m;
    vector<int> v(n), vv(m);
    forr(i, 0, n) cin >> v[i];
    forr(i, 0, m) cin >> vv[i];
    if (n >= m)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vv[i] == v[j])
                {
                    yes;
                    cout << 1 << " " << vv[i] << endl;
                    return;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i] == vv[j])
                {
                    yes;
                    cout << 1 << " " << v[i] << endl;
                    return;
                }
            }
        }
    }
    no;
}
int main()
{
    Bismillah();

    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
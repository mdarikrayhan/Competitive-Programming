#include <bits/stdc++.h>
#define elif else if
#define rep1(a) for (int i = 0; i < (a); i++)
#define rep2(i, a) for (int i = 0; i < (a); i++)
#define rep3(i, a, b) for (int i = a; i < (b); i++)
#define rep4(i, a, b, c) for (int i = a; i < (b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define per1(a) for (int i = (a) - 1; i >= 0; i--)
#define per2(i, a) for (int i = (a) - 1; i >= 0; i--)
#define per3(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define per4(i, a, b, c) for (int i = (a) - 1; i >= (b); i -= (c))
#define rep(args...) overload4(args, rep4, rep3, rep2, rep1)(args)
#define per(args...) overload4(args, per4, per3, per2, per1)(args)
#define INT(args...) \
    int args;        \
    rd(args)
#define FOR(i, n) for (auto &i : n)
#define ret return
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define sz(v) int(v.size())
#define SUM(a) accumulate(all(a), 0ll)
#define MIN(v) (*min_element(all(v)))
#define MAX(v) (*max_element(all(v)))
#define unisort(v) sort(all(v)), v.resize(unique(all(v)) - v.begin())
#define ff first
#define ss second
#ifndef ONLINE_JUDGE
#define debug(args...)                             \
    {                                              \
        string _s = #args;                         \
        size_t p;                                  \
        while ((p = _s.find(' ')) != string::npos) \
        {                                          \
            _s.erase(_s.begin() + p);              \
        }                                          \
        replace(_s.begin(), _s.end(), ',', ' ');   \
        stringstream _ss(_s);                      \
        istream_iterator<string> _it(_ss);         \
        err(_it, args);                            \
    }
#define FAST ios::sync_with_stdio()
#else
#define debug(args...) 114514
#define FAST cin.tie(0)->sync_with_stdio(false)
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using haxi = pair<ull, ull>;
using mp = map<int, int>;
using st = set<int>;
template <class T>
using maxheap = priority_queue<T>;
template <class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
const string yes = "YES", no = "NO";
auto RANDSEED = chrono::steady_clock::now().time_since_epoch().count() ^ (uintptr_t)make_unique<char>().get();
mt19937_64 rng(RANDSEED);

template <class T, class S>
inline ostream &operator<<(ostream &i, const pair<T, S> &a) { return i << a.first << ' ' << a.second; }
template <class T, class S>
inline istream &operator>>(istream &i, pair<T, S> &a) { return i >> a.first >> a.second; }
template <class T>
inline ostream &operator<<(ostream &i, const vector<T> &a)
{
    for (auto j : a)
        i << j << ' ';
    return i;
}
template <class T>
inline istream &operator>>(istream &i, vector<T> &a)
{
    for (auto &j : a)
        i >> j;
    return i;
}

void err(istream_iterator<string> it) { it.~istream_iterator(); }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
void wt() { cout << '\n'; }
template <class T, class... Args>
void wt(const T &a, const Args &...args)
{
    cout << a << ' ';
    wt(args...);
}
template <class T>
void wt(vector<vector<T>> &a)
{
    for (auto &i : a)
        wt(i);
}
template <class T, class S>
void wt(vector<pair<T, S>> &a)
{
    for (auto &i : a)
        wt(i);
}
template <class... T>
void rd(T &...a) { (cin >> ... >> a); }

void solve()
{
    INT(n, k);
    if (1ll * k * (k + 1) / 2 > n)
    {
        wt(no);
        ret;
    }
    if (k == 1)
    {
        wt(yes);
        wt(n);
        ret;
    }
    vi ans(k);
    iota(all(ans), 1);
    int delta = n - k * (k + 1) / 2;
    if (delta / k == 0)
    {
        if (delta <= k - 2)
        {
            rep(delta)
            {
                ans[k - 1 - i]++;
            }
        }
        else
        {
            rep(k - 2)
            {
                ans[k - 1 - i]++;
            }
            ans[k - 1]++;
            if (ans[k - 1] > ans[k - 2] * 2)
            {
                wt(no);
                ret;
            }
        }
    }
    else
    {
        rep(k)
        {
            ans[i] += delta / k;
        }
        rep(delta % k)
        {
            ans[k - 1 - i]++;
        }
    }
    wt(yes);
    wt(ans);
    return;
}

int main(void)
{
    FAST;
    cout << setiosflags(ios::fixed);
    cout.precision(15);
    int t = 1;
    // rd(t);
    rep(t)
    {
        solve();
    }
    return 0;
}

/*      بسم الله الحمن الرحيم    */
/*
 *  اللهم انت ربي لا اله الا انت خلقتني وانا عبدك وان على عهدك ووعدك ما استطعت
 *  ابوء لك من شر ما صنعت وابوك لك بنعمتك علي
 *  وابوء بذنبي فاغفر لي فانه لا يغفر الذنوب الا انت
 */
#include <bits/stdc++.h>
using namespace std;

#define Or ||
#define And &&
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define mostafa ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ull = unsigned long long;
const ll inf = (1ll << 32) - 1;
#define to_ll __int128_t
#define For(n) for (ll i = 0; i < n; i++)
#define FOR(n) for (ll i = 1; i <= n; i++)
#define sep(n) cout << fixed << setprecision(n);
#define enl cout << '\n';
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define vec vector<ll>
const int N = 2e5 + 7;
void Yes(bool c) { cout << (c ? "YES \n" : "NO \n"); }

bool cmp(int x, int y)
{
    return x > y;
}

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}

int f (int n)
{
    string s = to_string(n);
    return s.size();
}
void solution ()
{
    int n;
    cin >> n;
    priority_queue<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push(x);
    }
    int cnt = 0;
    while (!a.empty() && !b.empty())
    {
        if (a.top() == b.top())
        {
            a.pop();
            b.pop();
        }
        else if (a.top() > b.top())
        {
            int x = a.top();
            a.pop();
            a.push(f(x));
            cnt++;
        }
        else
        {
            int x = b.top();
            b.pop();
            b.push(f(x));
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    mostafa;
    int t = 1;
    cin >> t;
    while(t--)
        solution();
}
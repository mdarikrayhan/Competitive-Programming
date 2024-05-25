#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 5e5 + 9;
const ll MOD = 1e9 + 7;

vector<bool> v1(N, false);
class cmp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        if (a.second != b.second)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};
void solve()
{
    ll i;
    for (i = 1; i <= N; i++)
        v1[i] = false;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq1;
    ll q, n, j = 1;
    cin >> q;
    i = 1;
    while (q--)
    {
        cin >> n;
        if (n == 1)
        {
            cin >> n;
            v1[i] = true;
            pq1.push({i, n});
            i++;
        }
        else if (n == 2)
        {
            while (!v1[j])
                j++;
            cout << j << ' ';
            v1[j] = false;
        }
        else
        {
            while (!v1[pq1.top().first])
                pq1.pop();
            cout << pq1.top().first << ' ';
            v1[pq1.top().first] = false;
            pq1.pop();
        }
    }
    cout << endl;
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
     										 				     		   	
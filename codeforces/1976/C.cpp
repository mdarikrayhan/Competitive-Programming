#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define size(x) (int)x.size()
#define CY cout << "YES\n";
#define CN cout << "NO\n";
#define T     \
    int t;    \
    cin >> t; \
    while (t--)
#define FASTER               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define VALID auto isvalid = [](int X, int Y) \
{ return (X < n && Y < m && X >= 0 && Y >= 0); };
int movex[4] = {1, -1, 0, 0};
int movey[4] = {0, 0, -1, 1};
int MOD = 1e9 + 7;

int power(int a, int b)
{
    if (b == 0)
        return 1;
    int res = power(a, b / 2);
    res = res * res;

    if (b % 2)
        res = res * a;

    return res;
}

// cout << setprecision (9) << fixed

/*





*/

const int N = 3e6 + 100;
const int PROG = 0, TEST = 1;
int mycnt[2][N] = {0}, emp[2][N] = {0}, occur[2][N] = {0};
int n, k, m;
// int pro[N], test[N];

void solve()
{

    cin >> n >> m;
    for (int i = 0; i < n + m + 1; i++)
    {
        mycnt[0][i] = 0;
        occur[0][i] = 0;
        cin >> emp[PROG][i];
    }
    for (int i = 0; i < n + m + 1; i++)
    {
        occur[1][i] = 0;
        mycnt[1][i] = 0;

        cin >> emp[TEST][i];
    }

    int sum = 0;
    vector<pair<int, int>> values;
    for (int i = 0; i < n + m; i++)
    {

        if (i != 0)
        {
            mycnt[PROG][i] += mycnt[PROG][i - 1], mycnt[TEST][i] += mycnt[TEST][i - 1];
            occur[PROG][i] += occur[PROG][i - 1], occur[TEST][i] += occur[TEST][i - 1];
        }
        if ((emp[PROG][i] > emp[TEST][i] && mycnt[PROG][i] < n) || mycnt[TEST][i] == m)
        {
            sum += emp[PROG][i];
            values.push_back({emp[PROG][i], PROG});
            mycnt[PROG][i]++;
        }
        else
        {
            sum += emp[TEST][i];
            values.push_back({emp[TEST][i], TEST});
            mycnt[TEST][i]++;
        }
        if (emp[PROG][i] > emp[TEST][i])
        {
            occur[PROG][i]++;
        }
        else
        {

            occur[TEST][i]++;
        }
    }

    int current;
    int t_tmp, p_tmp;
    int all_sum = sum;

    int n_or_m, last_one, next_el;
    for (int i = 0; i < n + m; i++)
    {
        sum = all_sum;
        current = values[i].second;
        sum -= emp[current][i];

        if (current == PROG)
            n_or_m = n;
        else
            n_or_m = m;

        last_one = lower_bound(mycnt[current], mycnt[current] + n + m, n_or_m) - mycnt[current];

        next_el = upper_bound(
                      occur[current],
                      occur[current] + n + m,
                      occur[current][last_one]) -
                  occur[current];

        if (next_el < n + m)
        {
            sum += emp[current][next_el];
            sum -= values[next_el].first;
            sum += emp[!current][n + m];

        }
        else
        {
            sum += emp[current][n + m];
        }

        cout << sum << " ";
    }
    cout << all_sum;
    cout << endl;
}

int32_t main()
{

    FASTER
    T
    {
        solve();
    }
}

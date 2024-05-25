#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define Wrong                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int main()
{
    Wrong;
    ll n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for (ll i = 0; i < n; i++)
        cin >> vs[i];
    ll ans = 0, black = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (vs[i][j] == 'B')
                black++;
        }
    }
    // cout << black << '\n';
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (vs[i][j] == 'B')
            {
                vector<vector<ll>> v(n, vector<ll>(m, 0));
                v[i][j] = 1;
                for (ll k = j - 1; k >= 0; k--)
                {
                    if ((vs[i][k] == 'B'))
                    {
                        for (ll l = i; l >= 0; l--)
                        {
                            if (vs[l][k] == 'B')
                                v[l][k] = 1;
                            else
                                break;
                        }
                        for (ll l = i; l < n; l++)
                        {
                            if (vs[l][k] == 'B')
                                v[l][k] = 1;
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
                for (ll k = j + 1; k < m; k++)
                {
                    if ((vs[i][k] == 'B'))
                    {
                        for (ll l = i; l >= 0; l--)
                        {
                            if (vs[l][k] == 'B')
                                v[l][k] = 1;
                            else
                                break;
                        }
                        for (ll l = i; l < n; l++)
                        {
                            if (vs[l][k] == 'B')
                                v[l][k] = 1;
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
                for (ll k = i - 1; k >= 0; k--)
                {
                    if ((vs[k][j] == 'B'))
                    {
                        for (ll l = j; l >= 0; l--)
                        {
                            if (vs[k][l] == 'B')
                                v[k][l] = 1;
                            else
                                break;
                        }
                        for (ll l = j; l < m; l++)
                        {
                            if (vs[k][l] == 'B')
                                v[k][l] = 1;
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
                for (ll k = i + 1; k < n; k++)
                {
                    if ((vs[k][j] == 'B'))
                    {
                        for (ll l = j; l >= 0; l--)
                        {
                            if (vs[k][l] == 'B')
                                v[k][l] = 1;
                            else
                                break;
                        }
                        for (ll l = j; l < m; l++)
                        {
                            if (vs[k][l] == 'B')
                                v[k][l] = 1;
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
                ll cnt = 0;
                for (ll k = 0; k < n; k++)
                {
                    for (ll l = 0; l < m; l++)
                    {
                        if (v[k][l] == 1)
                            cnt++;
                    }
                }
                // cout << i << " " << j << " " << cnt << '\n';
                if (cnt != black)
                {
                    ans++;
                    break;
                }
            }
        }
        if (ans)
            break;
    }
    if (ans)
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
    return 0;
}
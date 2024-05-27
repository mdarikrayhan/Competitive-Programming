/*जय श्री महाकाल!*/
/* जय श्री गणेश! */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define int long long
#define double long double
#define inp0(a, n)              \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define out1(x) cout << x << endl;
#define out2(a, b) cout << a << " " << b << endl;
#define out3(a, b, c) cout << a << " " << b << " " << c << endl;
#define out0(a, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << a[i] << " ";    \
    }                           \
    cout << endl;
#define sz(s) (long long)(s.size())
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ff first
#define ss second
#define pb insert_back
#define rep(i, a, b) for (long long i = a; i < b; ++i)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define vi vector<long long>
#define vv vector<vector<long long>>
const int MOD = 1e9 + 7;
#define INF (int)1e18

#define dbg(x) cout << #x << " is " << x << endl;
#define dbgarr(x)                      \
    cout << #x << " is:" << endl;      \
    for (int i = 0; i < x.size(); i++) \
    {                                  \
        cout << x[i] << " ";           \
    }                                  \
    cout << endl;
#define dbgarrp(x)                                               \
    cout << #x << " is:" << endl;                                \
    cout << "( ";                                                \
    for (int i = 0; i < x.size(); i++)                           \
    {                                                            \
        cout << "[" << x[i].first << " " << x[i].second << "],"; \
    }                                                            \
    cout << " )";                                                \
    cout << endl;

const int MAXN = 1000001;

int bs(vector<pair<pii, pii>> &arr, int target)
{
    int s = 0;
    int e = sz(arr);
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid].ff.ff > target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<pii, pii>> arr;
    for (int i = 0; i < n; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        arr.push_back({{l, r}, {c, i}});
    }
    vi ans(n, INT_MAX);
    sort(all(arr));

    set<pii> st;
    vi coc(n + 1, INT_MAX);
    for (int i = sz(arr) - 1; i >= 0; i--)
    {
        int curr_end = arr[i].ff.ss;
        int curr_start = arr[i].ff.ff;
        int color = arr[i].ss.ff;
        if (i == sz(arr) - 1)
        {
            st.insert({curr_start, color});
            coc[color] = curr_start;
        }
        else
        {
            int temp_start = (*(st.begin())).ff;
            int temp_color = (*(st.begin())).ss;
            if (color == temp_color)
            {
                st.erase(st.begin());

                if (st.empty())
                {
                    coc[color] = min(curr_start, temp_start);
                    st.insert({coc[color], color});
                    continue;
                }
                auto it = (st.begin());
                pii x = *it;
                ans[arr[i].ss.ss] = min(ans[arr[i].ss.ss], max(0ll, (x.ff) - curr_end));
                coc[color] = min(curr_start, temp_start);
                st.insert({coc[color], color});
            }
            else
            {
                auto it = (st.begin());
                pii x = *it;
                // if (i == 0)
                // {
                //     dbg(x.ff);
                // }
                ans[arr[i].ss.ss] = min(ans[arr[i].ss.ss], max(0ll, (x.ff) - curr_end));
                if (coc[color] == INT_MAX)
                {
                    coc[color] = curr_start;
                    st.insert({coc[color], color});
                }
                else
                {
                    if (coc[color] < curr_start)
                    {
                    }
                    else
                    {
                        auto it = st.find({coc[color], color});
                        st.erase(it);
                        coc[color] = curr_start;
                        st.insert({coc[color], color});
                    }
                }
            }
        }
    }
    set<pii> s;
    vi cocc(n + 1, INT_MIN);
    for (int i = 0; i < n; i++)
    {
        int curr_start = arr[i].ff.ff;
        int curr_end = arr[i].ff.ss;
        int color = arr[i].ss.ff;
        if (i == 0)
        {
            s.insert({curr_end, color});
            cocc[color] = curr_end;
        }
        else
        {
            int temp_end = (*(s.rbegin())).ff;
            int temp_color = (*(s.rbegin())).ss;
            if (color == temp_color)
            {
                s.erase(--s.end());
                if (s.size() == 0)
                {
                    cocc[color] = max(curr_end, temp_end);
                    s.insert({cocc[color], color});
                    continue;
                }
                auto it = (s.rbegin());
                pii x = *it;
                ans[arr[i].ss.ss] = min(ans[arr[i].ss.ss], max(0ll, curr_start - x.ff));
                cocc[color] = max(curr_end, temp_end);
                s.insert({cocc[color], color});
            }
            else
            {

                auto it = (s.rbegin());
                pii x = *it;
                ans[arr[i].ss.ss] = min(ans[arr[i].ss.ss], max(0ll, curr_start - x.ff));
                if (cocc[color] == INT_MIN)
                {
                    cocc[color] = curr_end;
                    s.insert({cocc[color], color});
                }
                else
                {
                    if (cocc[color] > curr_end)
                    {
                    }
                    else
                    {
                        auto it = s.find({cocc[color], color});
                        s.erase(it);
                        cocc[color] = curr_end;
                        s.insert({cocc[color], color});
                    }
                }
            }
        }
    }
    out0(ans, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
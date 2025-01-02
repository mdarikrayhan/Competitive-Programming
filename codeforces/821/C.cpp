#include <bits/stdc++.h>
using namespace std;

#define zedanov                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define el "\n"
const int N = 1e5, md = 1e9 + 7;

void doWork()
{
    int q;
    cin >> q;
    q <<= 1;
    stack<int> st;
    int cnt = 0, x, ans = 0, cur = 1, nw = 1;
    string op;
    while (q--)
    {
        cin >> op;
        if (op[0] == 'a')
        {
            cin >> x;
            st.push(x);
        }
        else
        {
            if (st.empty())
            {
                cur++;
                continue;
            }
            if (cur == st.top())
                st.pop();
            else
            {
                ans++;
                while (st.size())
                    st.pop();
            }
            cur++;
        }
    }
    cout << ans;
}

signed main()
{
    zedanov int t = 1;
    // cin >> t;
    while (t--)
        doWork();

    return 0;
}
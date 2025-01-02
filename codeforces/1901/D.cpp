/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

#define ll unsigned long long int
#define vl vector<ll>
#define rep(i, a, b) for (ll i = a; i < b; i++)

const int N = 3e5 + 5;
int a[N], pre[N], suf[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pre[i] = max(pre[i - 1], a[i] + n - i);
    }

    for (int i = n; i >= 1; --i)
    {
        suf[i] = max(suf[i + 1], a[i] + i - 1);
    }
    int ans = 2e9 + 100;
    for (int i = 1; i <= n; ++i)
    {
        ans = min(ans, max({a[i], pre[i - 1], suf[i + 1]}));
    }
    cout << ans << "\n";
    return 0;
}
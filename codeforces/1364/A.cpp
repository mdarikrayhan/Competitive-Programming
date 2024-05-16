#include <bits/stdc++.h>
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define INF 1e18
#define int long long
#define print(a)      \
    for (auto it : a) \
        cout << it << " ";
#define loopi(a, b) for (int i = a; i < b; i++)
#define loopj(a, b) for (int j = a; j < b; j++)
using namespace std;
int M = 998244353;
const int N = 2e18;
//-------------------------------------------------------------------------------------------------------------
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    int sum=0;
    for (int i = 0; i < n; i++)
    {
       cin >> v[i];
       sum+=v[i];
    }
    if(sum%x!=0){
        cout<<n<<endl;
        return;
    }
    int l = -1, r = -1;
    loopi(0,n){
        if(v[i] % x != 0){
            l = i + 1;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(v[i] % x != 0){
            r = i;
            break;
        }
    }
    if(l == -1)
        cout << r << endl;
    else 
        cout << max(n - l, r) << endl;
}
//--------------------------------------------------------------------------------------------------------------
signed main()
{
    fastio();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

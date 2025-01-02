#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    ll a[n];

    ll s = 0;
    ll m = 1e18;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += abs(a[i]);
        m = min(m, abs(a[i]));
    }   

    if (n == 1){
        cout << a[0] << endl;
        return;
    }

    int flag = 0;
    for (int i = 0; i < n-1; i++){
        if (a[i] * a[i+1] <= 0) flag = 1;
    }


    if (flag) cout << s << endl;
    else cout << s - 2*m << endl;

}
    
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);   
    cout.tie(0);
    int t = 1;
    // cin >> t; 
    while (t-->0)
    {   
        solve();
    }
}
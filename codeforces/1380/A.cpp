#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &m:a) cin >> m;
    for(int i = 1; i<n-1; i++) 
    {
        if(a[i]>a[i-1] && a[i]>a[i+1])
        {
            cout << "YES" << endl;
            cout << i << ' ' << i+1 << ' ' << i+2 << endl; // i is i-1 in orignal array
            return;
        }
    }
    cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n, size = 0;
    cin >> n;
    set<int> s1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s1.insert(a);
    }
    size = s1.size();
    if(n%2!= size%2){
        size--;
    }
    cout<<size<<nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
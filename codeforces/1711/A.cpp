#include <bits/stdc++.h>
const int mod = 10007;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    if(n%2 == 1)
    {
        a[0] = 1;
        for(int i=1;i<n;i+=2)
        {
            a[i] = i+2;
            a[i+1] = i+1;
        }
    }
    else
    {
        for(int i=0;i<n;i+=2)
        {
            a[i] = i+2;
            a[i+1] = i+1;
        }
    }
    for(int x : a)
        cout<<x<<' ';
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();
}
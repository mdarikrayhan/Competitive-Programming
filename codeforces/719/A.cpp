#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define mod 1000000007
#define speed cin.tie(0) -> sync_with_stdio(0);ios_base::sync_with_stdio(false);cin.tie(0);
signed main()
{
    speed
    
    int n;
    cin>>n;
    int a[n+5];
    
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    if (a[n-1] == 15) cout<<"DOWN";
    else if (a[n-1] == 0) cout<<"UP";
    else if (n == 1)
    {
        cout<<-1;
    }
    else
    {
        cout<<(a[n-1] - a[n-2] < 0 ? "DOWN" : "UP");
    }
    
    return 0;
}
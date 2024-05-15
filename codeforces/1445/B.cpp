#include <iostream>
#include <bits/stdc++.h>
#define nl "\n"
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define scan(x,n) for(int i = 0; i < n; i++) cin >> x[i]
#define ll long long

using namespace std;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    cout<<max(a+b,c+d)<<nl;

}

int main()
{
    fastio();
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++)  solve();
    return 0;
}

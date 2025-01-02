#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pi 3.141592653589793238462643383279502884197
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];

    }
    ll move=n-a[0];
    a[0]=0;
    for(ll i=1;i<n;i++)
    {
        if(i&1)
        {
            a[i]-=move;
        }
        else
        {
            a[i]+=move;
        }
    }

    for(ll i=1;i<n;i++)
    {
        if(a[i]<0)
        {
            a[i]=abs(a[i]);
            a[i]=n-a[i];
            
        }
        else
        {
           a[i]=a[i]%n;
        }
    }
   
    bool f=true;
    for(ll i=0;i<n;i++)
    {
        if(a[i]!=i)
        {
            f=false;
            break;
        }

    }
    if(f)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
        solve();
    
}

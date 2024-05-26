#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ll N=1e5+100,h[]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("a.inp","r"))
    {
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    ll n;
    cin>>n;
    ll ch=0;
    for (ll i=1,x;i<=n;i++)
    {
        cin>>x;
        ch^=h[x];
    }
    if (ch)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
}
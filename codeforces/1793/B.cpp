#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define IOS ios::sync_with_stdio(0),cin.tie(0)
typedef long long ll; 
typedef pair<ll,ll> p;
const int N=2e5+5;
int main()
{
    IOS;
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<1<<'\n';
            cout<<a<<'\n';
            continue;
        }
        cout<<(a-b)*2<<'\n';
        
        for(int i=b;i<=a;i++)
        {
            cout<<i<<' ';
        }
        for(int i=a-1;i>b;i--)
        {
            cout<<i<<' ';
        }
        
        cout<<'\n';
    }
}

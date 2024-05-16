#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define IOS ios::sync_with_stdio(0),cin.tie(0)
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> p;
const int N=2e5+5;
bool mk[N];
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        s=' '+s;
        for(int i=1;i<=n;i++) mk[i]=0;
        for(int l=1,r=n;l<=r;l++,r--)
        {
            if(s[l]==s[r])
            mk[r]=0;
            else
            mk[r]=1;
        }
        ll ct=0;
        for(int i=(n+1)/2;i<=n;i++)
        {
            if(mk[i]!=mk[i-1])
            ct++;
        }
        if(ct>=3)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
}

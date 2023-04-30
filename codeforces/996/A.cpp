#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    long long n;
    cin>>n;
    int ans=0;
    if(n>=100)
    {
        ans+=n/100;
        n=n%100;
    }
    if(n>=20)
    {
        ans+=n/20;
        n=n%20;
    }
    if(n>=10)
    {
        ans+=n/10;
        n=n%10;
    }
    if(n>=5)
    {
        ans+=n/5;
        n=n%5;
    }
    if(n>=1)
    {
        ans+=n/1;
        n=n%1;
    }
    cout<<ans<<nl;

return 0;
}
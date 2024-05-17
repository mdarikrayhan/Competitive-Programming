#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back()
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
typedef long long ll;
//fixed<<setprecision()
using namespace std;
/****************************************************/
ll Mod = 1e9+7;
 
ll n;
bool good(ll k)
{
ll num = n;
ll sum=0;
while(num>0)
{
    sum += min(k,num);
    num -=k;
    num -= num/10;
}
return n <= 2*sum;
}
int main()
{
fast
cin>>n;
ll ans=n;
ll l=1,r=n;
while(l<=r)
{
    ll m=(l+r)/2;
    if(good(m))
    {
        ans = m;
        r = m-1;
    }
    else
        l=m+1;
}
cout<<ans;
}
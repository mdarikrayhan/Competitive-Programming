#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nn "\n"
#define mod 1000000007
#define N 1000005

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll cnt1,cnt2,x,y;
    cin >> cnt1 >> cnt2 >> x >> y;
    ll lo=1,up=10000000000;
    while(lo<up)
    {
        ll mid=(lo+up)/2;

        ll a=mid-mid/x;
        ll b=mid-mid/y;
        ll c=mid-(mid/(x*y));

        if(a>=cnt1&&b>=cnt2&&c>=(cnt1+cnt2))    up=mid;
        else    lo=mid+1;
    }
    cout << lo << nn;
    return 0;
}
#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define yes cout<<"yes\n";
#define no cout<<"no\n";
#define en cout<<"\n";
#define ct(x) cout<<x;
#define fi first
#define se second
#define fast() ios_base::sync_with_stdio(false);cin.tie(0);
#define fx(x) cout<<fixed<<setprecision(x);
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define br break;
#define cn continue;
#define all(a) a.begin(), a.end()
#define rall(x) (x).rbegin(), (x).rend()
#define for1(i, a, b) for(ll i = a;i < b;i++)
#define for2(i, a, b) for(ll i = a;i >= b;i--)
#define for3(i, a) for(auto i : a)
const ll inf1 = 1e18;
const ll inf2 = -1e18;
const ld pi = 3.141592653589793;
using namespace std;
///-------------------------------------------
ll polindrom(string s)
{
    for1(i, 0, s.size())
    {
        if(s[i] != s[s.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}
ll nok(ll n1, ll n2)
{
    return n1 * n2 / __gcd(n1, n2);
}
ll ll_sum(ll n)
{
    ll sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll str_sum(string s)
{
    ll sum = 0;
    for1(i, 0, s.size())
    {
        sum += s[i] - '0';
    }
}
ll binarySearch(vector<ll> arr, ll low, ll high, ll x)
{
    while(low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] < x)
        {
            low = mid + 1;
        }else high = mid - 1;
    }
    return -1;
}
///-------------------------------------------
void solve()
{
    ll n, x, sum = 0, cnt = 0;
    cin>>n>>x;
    vector<ll> a(n);
    for1(i, 0, n)
    {
        cin>>a[i];
        sum += a[i];
    }
    while(sum != 0)
    {
        if(abs(sum) <= x)
        {
            sum = 0;
        }else if(sum > 0)
        {
            sum -= x;
        }else sum += x;
        cnt++;
    }
    cout<<cnt;en
}
///-------------------------------------------
signed main()
{
    fast()
    ll _ = 1;
//    cin>>_;
    while(_--)
    {
        solve();
    }
}
///-------------------------------------------

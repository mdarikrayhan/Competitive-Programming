#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fast cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
#define all(x) x.begin(),x.end()
#define alr(x) x.rbegin(),x.rend()
#define endl '\n'
#define emb emplace_back
#define F first
#define S second
#define yes cout << "YES\n"
#define no cout <<"NO\n"
#define ll long long
#define pii pair< ll , ll>
#define PI acos(-1.0)
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
ll const N = 2e5+3, mod = 1e9+7, mod2 = 998244353;
void solve()
{
    int n;cin >> n;
    int a[n] , b [n];
    for(int i = 0 ;i < n ;i ++)
    {
        cin >> a[i];
    }
    multiset<int>st;
    for(int i = 0 ; i < n ;i ++)
    {
        int x; cin >> x;
        st.insert(x);
    }
    for(int i = 0 ; i < n ;i ++)
    {
        if(a[i]==0)
        {
            int x = *st.begin();
            cout << x << " ";
            st.erase(st.find(x));
        }
        else
        {
            auto p = st.lower_bound(n - a[i]);
            if(p == st.end())
            {
                p--;
            }
            int y  = *p;
            int x = *st.begin();
            if( (a[i] + y)%n <= (a[i] + x)%n)
            {
                cout << (a[i] + y)%n << " ";
                st.erase(st.find(y));
            }
            else
            {
                cout << (a[i] + x)%n << " ";
                st.erase(st.find(x));
            }
        }
    }
}
int main()
{

    fast;
    int test = 1;
//   cin >> test;
    while(test--)solve();
}

////////////////////////////////////////////////////
//bool isPrime(ll n)
//{
//    if (n <= 1)return false;
//    if (n <= 3)return   true;
//    if (n % 2 == 0||n % 3 == 0)return false;
//    for (ll i = 5; i * i <= n; i = i + 6)
//        if (n % i == 0||n % (i + 2) == 0)return false;
//    return true;
//}
//
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////
//ll GCD(ll  a,ll  b )
//{
//    return b ? GCD(b, a % b ) : a ;
//}
/////////////////////////////////////////////////////
//ll LCM(ll a, ll b)
//{
//    return (a / GCD(a, b)) * b;
//}

//ll  po(ll  x, ll os)
//{
//    if( os == 0 )
//        return 1;
//    ll z = po(x,os/2);
//    if( os&1 )
//        return z*z%mod*x%mod;
//
//    return z*z%mod;
//}
////////////////////////////////////////////////////
//ll exEuclid(ll a, ll b, ll& x, ll& y)
//{
//    if (b==0)
//    {
//        x=1;
//        y=0;
//        return a;
//    }
//    ll x1,y1;
//    ll d=exEuclid(b,a%b,x1,y1);
//    x=y1;
//    y=x1-y1*(a/b);
//    return d;
//}
/////////////////////////////////////////////////////////
//bool cmp(const pair<int, int>& a, const pair<int, int>& b)
//{
//    if (a.first != b.first)return a.first > b.first;
//    return a.second > b.second;
//}
/////////////////////////////////////////////////////////
///// indexed set
/////#include <ext/pb_ds/assoc_container.hpp>
/////#include <ext/pb_ds/tree_policy.hpp>
/////#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/////using namespace __gnu_pbds;
/////////////////////////////////////////////////////////

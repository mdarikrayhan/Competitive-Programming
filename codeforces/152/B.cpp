/*
 █████╗  ██╗ ██╗ ███╗   ███╗ ███████╗ ██████╗  ██╗ ██╗  █████╗  ███╗   ███╗ ██████╗ ╔██     ██╗
██╔══██╗ ██║ ██║ ████╗ ████║ ██╔════╝ ██╔══██╗ ██║ ██║ ██╔══██╗ ████╗ ████║ ██╔══██╗╚╗██   ██╔╝
███████║ ██████║ ██╔████╔██║ █████╗   ██║  ██║ ██████║ ███████║ ██╔████╔██║ ██║  ██║ ╚╗██ ██╔╝
██╔══██║ ██╔═██║ ██║╚██╔╝██║ ██╔══╝   ██║  ██║ ██╔═██║ ██╔══██║ ██║╚██╔╝██║ ██║  ██║  ╚╗ █ ╔╝
██║  ██║ ██║ ██║ ██║ ╚═╝ ██║ ███████╗ ██████╔╝ ██║ ██║ ██║  ██║ ██║ ╚═╝ ██║ ██████╔╝   ╚╗█╔╝
╚═╝  ╚═╝ ╚═╝ ╚═╝ ╚═╝     ╚═╝ ╚══════╝ ╚═════╝  ╚═╝ ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝ ╚═════╝     ╚█╝
*/
#include<bits/stdc++.h>
#include<cstdlib>
#include <iostream>
#include<cmath>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include<sstream>//classes library
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <deque>
#include <stack>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bitset>
#define pie 3.1415926535897932384626433
#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define ld long double
#define biggest_signed_int INT_MAX
#define smalled_signed_int INT_MIN
#define biggest_unsigned_int UINT_MAX
#define line cout<<"\n";
#define ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define EBS 1e-10
//find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
//order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
// *st.find_by_order(x) --> value in index x
// st.order_of_key(x) --> index of first value of x
//priority_queue<int,vector<int>,greater<int>>myque;for sorted queue
//sort(arr,arr+sizeof(arr)/sizeof(int),greater<int>());for reversed sort function
//multiset<ll,greater<ll>>reversedset;// set ordered reversed
using namespace std;
using namespace __gnu_pbds;
bool getBit(ll num, ll idx);
int find_my_word(string word,string wanted)
{
    if(word.find(wanted)!=string::npos)
        return word.find(wanted);
    else
        return -1;
}
ll nCr(ll n, ll r)
{
    ll mod=1e9+7;
    ll ans = 1;
    ll div = 1; // r!
    for (ll i = r + 1; i <= n; i++)
    {
        ans = (ans)* (i);
        ans/= div;
        div++;
    }
    return ans;
}
ll NpR(ll n, ll r)
{
    ll mod=1e9+7;
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
}
bool compare(pair<int,string> left,pair<int,string>right)// left and right converted so left is on final
{
    if(left.first<right.first)
        return 1;
    else if(left.first==right.first)
    {
        if(left.second>right.second)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
void Date_now()
{
    cout<<__DATE__<<"\n";   //prints current date
}
void Time_now()
{
    cout<<__TIME__<<"\n";   //prints current time
}
void Alking()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void onlinejudge()
{
    freopen("open.in","r",stdin);
    freopen("output.file","w",stdout);
}
bool is_prime(ll n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else if(n%2==0)
        return 0;
    int flag=1;
    for(ll c=3; c*c<=n; c+=2)
    {
        if(n%c==0)
        {
            flag=0;
            break;
        }
    }
    return(flag);
}
vector<ll> divisors(ll n)
{
    vector<ll> v;
    ll i;
    for(i = 1 ; i*i<n  ; ++i)
        if(n%i == 0)
            v.push_back(i), v.push_back(n/i);
    if(i*i == n)
        v.push_back(i);
    return v;
}
vector<ll> prime_factors(ll n)
{
    vector<ll>f;
    while (!(n % 2))
    {
        n >>= 1;
        f.push_back(2);
    }
    for(ll c=3; c*c<=n; c+=2)
    {
        while(n%c==0)
        {
            n/=c;
            f.push_back(c);
        }
    }
    if(n>2)
        f.push_back(n);
    return f;
}
vector<bool>sieve(ll n)
{
    vector<bool> isPrime(n+1, true);    // set all of them to primes
    isPrime[0] = isPrime[1] = 0;        // 0, 1 are not primes
    for (ll i = 4; i <= n; i += 2)
    {
        isPrime[i] = 0;
    }
    for (ll i = 3; i*i <= n; i+=2)
    {
        if (isPrime[i])
        {
            for (ll j = i * 2; j <= n; j += i)
                isPrime[j] = 0;
        }
    }
    return isPrime;
}
// & AND | OR ~ NOT ^ XoR << leftshift >> rightshift
// __gcd(x,y) for greatest common divisor
// x*y /__gcd(x,y)=lcm(x,y) for least common multiple
// notes: any number at most have one prime number bigger than its square root
// notes:you must check after square root if it square small or equal value dowe the root
// directional array 8 neighbours
int dx8[]= { 0,0,-1,1,-1,-1, 1,1};
int dy8[]= {-1,1, 0,0, 1,-1,-1,1};
// directional array 4 neighbours up down right left
int dx4[]= { 0,0,-1,1};
int dy4[]= {-1,1, 0,0};
bool can(ll midpoint,ll arr[],int siz)
{
    int saved[20]= {0};
    int frq[20]= {0};
    for(int c=0; c<midpoint; ++c)
    {
        for(int v=0; v<20; ++v)
        {
            if(getBit(arr[c],v))
            {
                ++saved[v];
                ++frq[v];
            }
        }
    }
    for(int v=midpoint; v<siz; ++v)
    {
        for(int c=0; c<20; ++c)
        {
            if(getBit(arr[v],c))
                ++frq[c];
        }
        for(int c=0; c<20; ++c)
        {
            if(frq[c])
            {
                if(getBit(arr[v-midpoint],c))
                {
                    --frq[c];
                }
            }
        }
        for(int c=0; c<20; ++c)
        {
            if(frq[c]==0&&saved[c]==0);
            else if(frq[c]&&saved[c]);
            else
                return 0;
        }
    }
    return 1;
}
ll binary_monotonic(ll startpoint,ll endpoint,ll s1,ll s2,ll x0,ll y0,ll n,ll m)
{
    ll ans=-1;
    while(endpoint>=startpoint)
    {
        ll midpoint=startpoint+(endpoint-startpoint)/2;
        if(x0+midpoint*s1<=n&&
           y0+midpoint*s2<=m&&
           x0+midpoint*s1>=1&&
           y0+midpoint*s2>=1)
        {
            ans=midpoint;
            startpoint=midpoint+1;
        }
        else
            endpoint=midpoint-1;
    }
    return ans;
}
bool getBit(ll num, ll idx)
{
    if((num&(1ll<<idx)))
        return  1;
    else
        return 0;
}
ll setBit(ll num, ll idx, bool val)
{
    return val ? (num | (1ll << idx)) : (num &~(1ll<< idx));
}
ll flipBit(ll num, ll idx)
{
    return (num ^ (1ll << idx));
}
ll turnOnLastZero(ll S)
{
    return S | (S + 1ll);   // make 1001 to 1011
}
ll turnOnLastConsecutiveZeroes(ll S)
{
    return S | (S - 1ll);
}
ll turnOffLastBit(ll S)
{
    return S & (S - 1ll);
}
ll turnOffLastConsecutiveBits(ll S)
{
    return S & (S + 1ll);
}
ll lowBit(ll S)
{
    return S & -S;
}
ll setAll(ll N)
{
    return (1ll << N) - 1ll;
}
ll modulo(ll S, ll N)
{
    return (S &( N - 1ll));
}
bool isPowerOfTwo(ll S)
{
    if(S<=0)
        return 0;
    return (S & (S - 1ll)) == 0;
}
string max_num(string x,string y)// max num of big strings
{
    if(x.size()>y.size())
        return x;
    else if(x.size()==y.size())
        return max(x,y);
    else
        return y;
}
void myerase(ordered_set &t, int v)  // to delet elments from multiorderd set
{
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
int gray_code(ll x)
{
    return x^(x>>1ll);
}
ll fastpower(ll num,ll base,ll mod)
{
    if(base==0)
        return 1;
    ll ans=fastpower(num,base/2,mod);
    ans=(ans*ans)%mod;
    if(base%2==1)ans=(ans*num)%mod;
    return ans;
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
ll md(ll val,ll md)  // take mod of positive and negative value
{
    return (val%md + md) % md;
}
int last_smaller_equal(int startpoint,int endpoint,vector<int>arr,int start,int endd)
{
    int ans=-1;
    while(endpoint>=startpoint)
    {
        ll midpoint=startpoint+(endpoint-startpoint)/2;
        if(arr[midpoint]<=endd)
        {
            ans=arr[midpoint];
            startpoint=midpoint+1;
        }
        else
            endpoint=midpoint-1;
    }
    return ans;
}
int main()
{
    Alking();
    // onlinejudge();
    int t(1);
    //cin>>t;
    //ll mod=1ll<<30;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll x0,y0;
        cin>>x0>>y0;
        int x;
        cin>>x;
        ll ans=0;
        for(int c=0;c<x;++c)
        {
            ll s1,s2;
            cin>>s1>>s2;
            ll mod=binary_monotonic(0,1e9,s1,s2,x0,y0,n,m);
            ans+=mod;
            x0+=mod*s1;
            y0+=mod*s2;
        }
        cout<<ans;
    }
    return 0;
}

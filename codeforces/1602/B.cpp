#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <limits>
#include <iomanip>
#include <set>
#include <queue>
using namespace std;

#define pb push_back
#define fo(i, n) for (long long i = 0; i < n; i++)
#define fo1(i, n, s, d) for (int i = s; i < n; i += d)
#define all(v) v.begin(), v.end()
#define mii map<long long, long long>
#define mib map<long long, bool>
#define en "\n"
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define mpr make_pair
#define f first
#define s second
#define vec vector
#define N 1000000007
#define pii pair<int, int>
#define ll long long
const int MOD = 998244353;

long long fact(ll n)
{
    long long res = 1;
    for (ll i = 1; i <= n; ++i)
    {
        res *= i;
        res %= MOD;
    }
    return res % MOD;
}

vector<ll> digitsToVector(string numberStr)
{
    vector<ll> digitsVector;
    ll sz = numberStr.size();
    fo(i, sz)
    {
        char digitChar = numberStr[i];
        ll digit = digitChar - '0';
        digitsVector.push_back(digit);
    }
    return digitsVector;
}

ll vectorToNumber(const vector<ll> &digitsVector)
{
    ll number = 0;
    fo(i, digitsVector.size())
    {
        ll digit = digitsVector[i];
        number = number * 10 + digit;
    }
    return number;
}

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

///////// CODE FROM HERE /////////////

void solve()
{   
    ll n;
    cin>>n;
    vec<ll>a(n);
    fo(i,n){
        cin>>a[i];

    }
    vec<ll>temp;
    unordered_map<ll,ll>map;
    vec<vec<ll> >res;
    res.pb(a);
    
    while(true){
        if(temp==a){
            break;
        }
        else{
            temp = a;
            for(auto& e:map){
                e.second = 0;
            }
            fo(i,n){
                map[temp[i]]++;
            }
            fo(i,n){
                a[i] = map[a[i]];
            }
            res.pb(a);
        }
    }
    res.pop_back();
    // for (ll i = 0; i < res.size(); ++i) {
    //     for (ll j = 0; j < res[i].size(); ++j) {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << en;
    // }
    ll q;
    cin>>q;
    while(q--){
        ll x,k;
        cin>>x>>k;
        x--;
        if(k<res.size()){
            cout<<res[k][x]<<en;
        }
        else{
            cout<<res.back()[x]<<en;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}

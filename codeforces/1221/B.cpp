// Author: AkhandSJx
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define fi first
#define gin(a) \
    ll a;      \
    cin >> a;
#define se second
#define vecin(v, n) \
    vl v;           \
    loop(i, 0, n)   \
    {               \
        gin(x);     \
        v.pb(x);    \
    }
#define lin(a) \
    ll a;      \
    cin >> a;
#define lin2(a, b) \
    ll a, b;       \
    cin >> a >> b
#define lin3(a, b, c) \
    ll a, b, c;       \
    cin >> a >> b >> c
#define max3(a, b, c) max(max((a), (b)), (c))
#define max4(a, b, c, d) max(max((a), (b)), max((c), (d)))
#define min3(a, b, c) min(min((a), (b)), (c))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define revloop(i, b, a) for (long long i = b; i >= a; i--)

// int x = min({a, b, c, d});
int printFrequency(vector<int> vec, int key)
{
    map<int, int> M;
    for (int i = 0; vec[i]; i++)
    {
        if (M.find(vec[i]) == M.end())
        {
            M[vec[i]] = 1;
        }
        else
        {
            M[vec[i]]++;
        }
    }
    for (auto &it : M)
    {
        if (it.first == key)
        {
            return it.second;
        }
    }
}
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    gin(n);
    loop(i,0,n){
        loop(j,0,n){
            if(i%2==0 && j%2==0){
                cout<<"W";
            }
            if(i%2==0 && j%2==1){
                cout<<"B";
            }
            if(i%2==1 && j%2==1){
                cout<<"W";
            }
            if(i%2==1 && j%2==0){
                cout<<"B";
            }
        }
            cout<<endl;

    }
    // cout<<fixed<<setprecision(10);
    // cerr<<1000*((double)clock())/(double)CLOCKS_PER_SEC;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long  int
#define ll int
#define endl "\n"
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(vector) vector.begin(), vector.end()

#define invecll(n, name)       \
    vector<ll> name;           \
    for (ll i = 0; i < n; i++) \
    {                          \
        ll lwjfh;              \
        cin >> lwjfh;          \
        name.push_back(lwjfh); \
    }

#define vecp(vector)                                \
                                                    \
    for (ll qqqq = 0; qqqq < vector.size(); qqqq++) \
        cout << vector[qqqq] << " ";                \
    cout << endl;

#define inll(name) \
    ll name;       \
    cin >> name;

#define ins(name) \
    string name;  \
    cin >> name;

ll mod = 998244353;
ll binpowmod(ll a, ll b);
ll binpow(ll a, ll b);

vector<ll> fac[100005];
void seive(){

    for(ll i=1; i<=100000;i++){

        for(ll j = 1; j*j<=i;j++){

            if(i%j ==0){
                fac[i].push_back(j);
                if(j*j!=i)
                fac[i].push_back(i/j);
            }
        }

        sort(all(fac[i]));
        reverse(all(fac[i]));
    }

}

void solve()
{
   inll(x) inll(y) inll(a) inll(b) 
   if(a==b){ cout<<min(x/a,y/a)<<endl; return;}
   if(b>a) swap(a,b);
   ll ans = 0;
   ll l =0;
   ll r = max(x/b,y/b);
   while(r>=l){

        int mid = (r+l)/2;
        ll flag =1;
        ll temp = x-b*mid;
        if(temp<0) flag =0;
        temp/=(a-b);
        temp = min(temp,mid);
        ll temp2 = b*temp + a*(mid-temp);
        if(temp2>y) flag =0;
        if(flag){ans = mid; l = mid+1;}
        else r = mid-1;
   }
   cout<<ans<<endl;

}

// ----------------x-----------------main---------------------------x----------------------------

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif

    ll test;
    test = 1;
    cin >> test;
    seive();
    for (ll i = 1; i <= test; i++)
    {
        solve();
    }

    return 0;
}

// ----------------x---------------x----------------------------x----------------------------

//

// ----------------x-----------------------x-------------------------------------x-----------

//

ll binpowmod(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = ((binpowmod(a, b / 2)) % mod);
    if (b % 2 == 0)
        return (((res) % mod * (res) % mod) % mod);
    else
        return ((((((res) % mod) * ((res) % mod)) % mod) * a) % mod);
}

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = (binpow(a, b / 2));
    if (b % 2 == 0)
        return ((res * res));
    else
        return ((res * res * a));
}
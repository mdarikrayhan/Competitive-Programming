#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <time.h>
using namespace std;

#define ll long long
#define i28 __int128
#define str string
#define ld long double
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define query       \
    {               \
        ll q;       \
        cin >> q;   \
        while (q--) \
            liam(); \
    }


pair<ll, ll> dir[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

const ll N = 1e7;
const ll MOD = 1e9 + 7;

void input(ll a[],ll s) {for(ll i=1;i<=s;i++)cin>>a[i];}
void print(ll a[],ll s,ll e){for(ll i=s;i<=e;i++)cout<<a[i]<<" ";cout<<"\n";}
void print(vector<ll> &v,ll s,ll e){for(ll i=s;i<=e;i++)cout<<v[i]<<" ";cout<<"\n";}
void print(vector<ll> &v){for(ll i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<"\n";}



ll bit_count(ll _x){ll _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
ll bit(ll _mask,ll _i){return (_mask&(1<<_i))==0?0:1;}
ll power(ll _a,ll _b){ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a);_b/=2;_a=(_a*_a);}return _r;}
ll powermod(ll _a,ll _b,ll _m){ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
ll add(ll a,ll b,ll m=MOD){ll x=a+b;while(x>=m)x-=m;return x;}
ll mul(ll a,ll b,ll m){return (a%m)*(b%m)%m;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll invmod(ll a,ll m){return powermod(a,m-2,m);}
ll r_d, r_x, r_y;
void extendedEuclid(ll r_A, ll r_B) {
	if(r_B == 0){r_d = r_A;r_x = 1;r_y = 0;}
	else{extendedEuclid(r_B, r_A%r_B);ll r_temp = r_x;r_x = r_y;r_y = r_temp - (r_A/r_B)*r_y;}
}
ll modInverse(ll r_A, ll r_M){extendedEuclid(r_A,r_M); return (r_x%r_M+r_M)%r_M;}

void liam()
{
    ld a,b,c; cin >> a >> b >> c;
    ld delta = (b*b) - (4*a*c);
    ld x1 = (-b + sqrt(delta)) / (2*a);
    ld x2 = (-b - sqrt(delta)) / (2*a);

    cout << fixed << setprecision(12) << max(x1, x2) << "\n" << min(x1, x2) << "\n";
}

void time()
{
    auto start = std::chrono::high_resolution_clock::now();
    liam();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " ms" << std::endl;
}

signed main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(fopen("williams.inp", "r"))
    {
        freopen("williams.inp", "r", stdin);
        freopen("williams.out", "w", stdout);
    }
    liam();
}

// fuck you CP

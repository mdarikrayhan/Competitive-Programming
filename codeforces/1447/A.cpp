#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inarr(arr, n) ll arr[n]; for (ll i = 0; i < n; i++) cin>>arr[i]
#define in(n) ll n;cin>>n
#define rr return
#define inn(n,k) ll n,k;cin>>n>>k
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define on(n) cout<<n<<endl
#define ff first
#define ss second
#define pb emplace_back
#define sortv(v) sort(v.begin(), v.end())
#define vinp(x) for(auto &i:x) cin>>i
#define vll vector<ll>
#define rev(v) reverse(v.begin(), v.end())
//rotate(v.begin(),v.begin()+v.size()-r,v.end()); //for rotating vector r times right
//rotate(v.begin(),v.begin()+r,v.end()); //for rotating vector r times left
#define all(x) x.begin(), x.end()
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
ll power(ll n,ll a){ ll res=1; while(a){ if(a%2) res*=n,a--; else   n*=n,a/=2;} return res;}

ll modpower(ll n,ll a,ll p){ ll res=1; while(a){ if(a%2) res= ((res*n)%p) ,a--; else n=((n*n)%p),a/=2;} return res;}

ll fastprime(ll a){ if (a != 2 && a % 2 == 0 || a < 2) return 0;  for(ll i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}

ll mod_mul_inverse(ll a,ll b) {return modpower(a , b-2, b);}

ll gcd(ll a, ll b){return (b == 0 ? a : gcd(b, a % b));}

ll ask(ll l, ll r) {
    cout << "? " << l << ' ' << r << endl;
    fflush(stdout);
    ll ans;
    cin >> ans;
    return ans;
}
// In-place rotates s towards left by d
void leftrotate(string &s, ll d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

// In-place rotates s towards right by d
void rightrotate(string &s, ll d)
{
    leftrotate(s, s.length()-d);
}

bool sortbysec(const pair<ll,ll> a,
               const pair<ll,ll> b)
{
    if (a.second!=b.second){
        return a.second<b.second;
    }
    else{
        return a.first<b.first;

    }
}
bool is_prime(int n) {                                    // in O(sqrt(n))
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1) {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i*i <= n) {
        // Check if i divides x without leaving a remainder
        if (n % i == 0) {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}
bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        // if product of square root 
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
// to findout distance from starting of vector to element which greater than or equal to x
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
// to findout distance from starting of vector to element which greater than x
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
 
 
//rotate(v.begin(),v.begin()+v.size()-r,v.end()); //for rotating vector r times right
//rotate(v.begin(),v.begin()+r,v.end()); //for rotating vector r times left
#define all(x) x.begin(), x.end()
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
//cout << fixed<<setprecision(15); ///activate it if the answers are in decimal.
 
/*(a+b)%M=((a%M)+(b%M))%M
        * (a-b)%M=((a%M)-(b%M)+M)%M
                  * (a*b)%M=((a%M)*(b%M))%M
                            * (a/b)%M=((a%M)*((b^-1)%M))%M
                                   */
 
 
const ll mod=1e9+7;

int highestPowerof2(unsigned int n)
{
    // Invalid input
    if (n < 1)
        return 0;
    int res = 1;
    // Try all powers starting from 2^1
    for (int i = 0; i < 8 * sizeof(unsigned int); i++) {
        int curr = 1 << i;
        // If current power is more than n, break
        if (curr > n)
            break;
        res = curr;
    }
    return res;
}
void solve(){

in(n);
on(n-1);
ll ans=2;
fi(0,n-1)
{
    cout<<ans<< ' ';
    ans++;
}
cout<<endl;

}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    in(t);
    while(t--)
    {
        solve();
    }
}
#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define db double
#define vb vector <bool>
#define vll vector <ll>
#define nl '\n'
#define vf v[i].first
#define vs v[i].second
#define pll vector<pair<ll, ll>>
#define fl(i, n) for(ll i = 0; i < n; i++)
#define s(v) sort(v.begin(), v.end())
#define rs(v) sort(v.rbegin(), v.rend())
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define MOD (ll)1e9 + 7
#define dis(v, n) FOR(i, 0, n) cout << v[i] << " ";
#define mp make_pair
#define F first
#define S second
#define pi atan(1)*4
// #define a.pb a.push_back
using namespace std;

ll G(ll x, ll y) {
    if (x == 0) return 1;
    if (y == 0) return 1;
    return __gcd(x, y);
}

bool ckmin(ll& a, ll b) { return b < a ? a = b, true : false;}

vector <bool> get_prime(ll n) {
    //sieve of eratosthenes
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (ll)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

const auto start_time = std::chrono::high_resolution_clock::now();
void bruhumma()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time-start_time;
        cerr<<"Time Taken : "<<diff.count()<<"\n";
    }

ll bin_con(const vll& v, ll q) {
    ll left = 0, right = v.size() - 1, result = -1;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (q > v[mid] && q <= v[mid + 1]) {
            result = mid;
            break;
        } 
        else if (q <= v[mid]) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }

    return result+1;
}

vll precompute_powers(long long n) {
    vector<long long> powers(n + 1, 1);
 
    for (long long i = 1; i <= n; ++i) {
        powers[i] = (powers[i - 1] << 1) % MOD;
    }
 
    return powers;
}

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

long long nCr(ll n, ll r) {
    if (r < 0 || r > n) {
        return 0;
    } 
    else {
        
        if (r > n - r) {
            r = n - r; 
        }

        long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result *= n - i + 1;
            result /= i;
        }

        return result;
    }
}

ll LCM(ll a, ll b){
    return (a*b)/G(a, b);
}

ll sumdg(ll number) {
    ll sum = 0;
    
    while (number != 0) {
        sum += number % 10; 
        number /= 10; 
    }

    return sum;
}

bool pfs(ll num) {
    if (num < 0)
        return false;
    
    ll root = sqrt(num);
    return root * root == num;
}

ll power(ll a, ll n){
    ll ans = 1;

    while (n > 0) {

        int last_bit = (n & 1);
        if (last_bit) {
            ans = ans * a;
        }

        a = a * a;
        n = n >> 1;
    }

    return ans;
}



void solve(){
    ll n, f, x, y, ans = 0; cin >> n >> f;
    vll a(n), b(n), c(n);
    fl(i,n){
        cin >> a[i] >> b[i];
        ans += min(a[i], b[i]);
        if(a[i] == 0){
            c[i] = 0;
        }
        else{
            if(a[i] >= b[i]) c[i] = 0;
            else if(2*a[i] >= b[i]) c[i] = b[i] - a[i];
            else if(2*a[i] < b[i]) c[i] = a[i];
        }
    }
    rs(c);
    ll i = 0;
    while(f--){
        if(i == n)break;
        ans+= c[i];
        i++;
    }
    cout << ans;



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t ;
    t=1;
    // cin >> t;
    while (t--){
        solve();
        // cout << nl;
    }
    // bruhumma();

    return 0;
}
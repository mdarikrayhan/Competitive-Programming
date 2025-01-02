//------------------Kratos457-----------------------------------

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
#define be begin()
#define en end()
#define pb push_back
#define pyes cout << "Yes\n"
#define pno cout << "No\n"
#define ce cout << '\n'
#define endl '\n'
#define pie 3.141592653589793238462643383279502884197169399
#define print(x) cout<<x<<endl
#define printb(x) cout<<x<<" "
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define fi first
#define se second
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define show(C) for(auto J: C) cout<<J<<" "; cout << endl;


ll mod = 1e8;
const ll inf= 1e18;

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll binary(const std::vector<ll>& arr, ll target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents potential overflow

         if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}

//power with mod
ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

//Power with modular inverse
ll sumOfDivisors(vp primeFactors, ll power, ll mod) {
    ll totalSum = 1;
    for (auto& factor : primeFactors) {
        ll prime = factor.first;
        ll exponent = factor.second;
        ll term1 = modExp(prime, (long long)(exponent + 1) * power, mod) - 1;
        if (term1 < 0) term1 += mod; // Make sure term1 is positive
        ll term2 = modExp(prime, power, mod) - 1;
        if (term2 < 0) term2 += mod; // Make sure term2 is positive
        term2 = modExp(term2, mod - 2, mod); // Multiplicative inverse
        totalSum = (totalSum * (term1 * term2 % mod)) % mod;
    }
    return totalSum;
}

//PATTERN IN STRING
vll kmp(string s) {
    ll n = s.length();
    vll prefix(n, 0);
    for (ll i = 1; i < n; ++i) {
        ll j = prefix[i - 1];
        while (j > 0 && s[i] != s[j]) j = prefix[j - 1];
        if (s[i] == s[j]) ++j;
        prefix[i] = j;
    }
    return prefix;
}

//PATTERN IN VECTORS
vll kmp2(vll a) {
    ll n = a.size();
    vll prefix(n, 1);
    for (ll i = 1, j=0 ; i < n; ++i) {
        while(j>1 && a[i]-a[i-1]!=a[j]-a[j-1]) j=prefix[j-1];
        if(j>0 && a[i]-a[i-1]==a[j]-a[j-1]) j++;
        prefix[i]=max(j,1LL);
        j=prefix[i];
    }
    return prefix;
}

bool is_prime[1000005];
void sieve_of_eratosthenes(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

ll ciel(ll a,ll b){
    if(a%b){return a/b+1;}
    else{return a/b;}
}

ll count_factors(ll number, ll divisor) {
    ll count = 0;
    while (number % divisor == 0 && number != 0) {
        count++;
        number /= divisor;
    }
    return count;
}

pair<ll, string> findMinimumPath(ll n, vector<vll>& matrix) {
    vector<vector<int>> dp_two(n, vector<int>(n, 0));
    vector<vector<int>> dp_five(n, vector<int>(n, 0));

    // Handle the first cell
    dp_two[0][0] = count_factors(matrix[0][0], 2);
    dp_five[0][0] = count_factors(matrix[0][0], 5);

    // Initialize first row and first column
    for (int i = 1; i < n; i++) {
        dp_two[i][0] = dp_two[i-1][0] + count_factors(matrix[i][0], 2);
        dp_five[i][0] = dp_five[i-1][0] + count_factors(matrix[i][0], 5);
        dp_two[0][i] = dp_two[0][i-1] + count_factors(matrix[0][i], 2);
        dp_five[0][i] = dp_five[0][i-1] + count_factors(matrix[0][i], 5);
    }

    // Fill the rest of dp table
    for (ll i = 1; i < n; i++) {
        for (ll j = 1; j < n; j++) {
            dp_two[i][j] = min(dp_two[i-1][j], dp_two[i][j-1]) + count_factors(matrix[i][j], 2);
            dp_five[i][j] = min(dp_five[i-1][j], dp_five[i][j-1]) + count_factors(matrix[i][j], 5);
        }
    }

    // Calculate the minimum path trailing zeros
    ll min_trailing_zeros = min(dp_two[n-1][n-1], dp_five[n-1][n-1]);
    bool k=false;
    if(min_trailing_zeros==dp_two[n-1][n-1]) k=true;
    string path;
    ll r = n - 1, c = n - 1;
    if(k){
    while (r > 0 && c > 0) { // Simplified path reconstruction for demonstration
        if (r>0 && dp_two[r-1][c] <= dp_two[r][c-1]) {
            path +='D';
            r--;
        }
        else if(dp_two[r][c-1] <= dp_two[r-1][c]) {
            path += 'R';
            c--;
        }
    }
    while (r > 0) {
        path += 'D';
        r--;
    }
    while (c > 0) {
        path += 'R';
        c--;
    }
    }
    else{
       while (r > 0 && c > 0) {
        if (r>0 && dp_five[r-1][c] <= dp_five[r][c-1]) {
            path +='D';
            r--;
        } else if(dp_five[r][c-1] <= dp_five[r-1][c]) {
            path += 'R';
            c--;
        }
    }
    while (r > 0) {
        path += 'D';
        r--;
    }
    while (c > 0) {
        path += 'R';
        c--;
    }
    }
    rev(path);
    return {min_trailing_zeros, path};
}

void solve(){
    ll n;
    cin >> n;
    vector<vll> matrix(n, vll(n,-1));
    bool ans=false;
    ll l=-1,r=-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if( matrix[i][j] == 0){
                ans=true;
                r=i;
                l=j;
            }
        }
    }
    auto [min_trailing_zeros, path] = findMinimumPath(n, matrix);
    if(min_trailing_zeros>=1 && ans){
        cout<<1<<endl;
        for(ll i=0;i<r;i++) cout<<"D";
        for(ll j=0;j<n-1;j++) cout<<"R";
        for(ll j=r;j<n-1;j++) cout<<"D";
        return;
    }
    cout << min_trailing_zeros << endl;
    cout << path << endl;
}

int32_t main(){
    int t=1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    //cin>>t;
    while(t--){
        solve();
    }
}

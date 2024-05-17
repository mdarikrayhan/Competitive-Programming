#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double
#define endl '\n'    
#define all(x) x.begin(), x.end()
#define vll vector<long long>
#define vld vector<long double>
#define vc vector<char>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fori(start, end) for(int i = start; i < end; ++i)
#define forj(start, end) for(int j = start; j < end; ++j)
#define fork(start, end) for(int k = start; k < end; ++k)
#define mod (1000000007)

long long lcm(long long a, long long b) {
    return ((a *b)/ __gcd(a, b));
}

vector<ll> primes_up_to_sqrt(ll n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    for (ll p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (ll i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    return primes;
}

vector<ll> input(ll n){
    vector<ll> v(n);
    fori(0, n)
        cin >> v[i];
    return v;
}

void output(vector<ll>& v, ll n){
    fori(0, n)
        cout << v[i] << " ";
    cout << endl;
}

void print(char c){
    if(c=='y')
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

bool isPowerOfTwo(ll n ) {
    return n > 0 && (n & (n - 1)) == 0;
}
vector<ll> findSetBits(int n) {
    vector<ll> result;
    int bitPosition = 0;
    while (n > 0) {
        if (n & 1)
            result.push_back(1 << bitPosition);
        n >>= 1; 
        bitPosition++; 
    }
    
    return result;
}
bool compare(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.first > b.first; // Sort in descending order by the first element of the pair
}

ll solve() {
    ll d;
    cin>>d;
    cout<<fixed<<setprecision(10);
    ld disc = pow(d,2) - 4*d;
    if(disc < 0){
        cout<<"N"<<endl;
    }else{
        ld p = sqrtl(disc);
        ld a= (d+p) / 2.0000000000;
        ld b = (d-p)/ 2.0000000000;
        cout<<"Y"<<" "<<a<<" "<<b<<endl;
    }
    
    return 1;

    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int t;
    cin>>t;
    while(t--)  
        solve();
    return 0;
}

#include <bits/stdc++.h>
#define int long long int
#define ll long long
#define ld long double
#define each const auto &
#define fk(i,n) for(ll i=0;i<n;i++)
#define uwu(t) while(t--)
#define endl '\n'
#define coder ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
int taken;
vector<bool> isprime(1e7+1, true);
void seive(ll n) {
    isprime[1] = isprime[0] = false;
    for (int i = 2; i * i <= 1e7 + 1; ++i) {
        if (isprime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isprime[j] = false;
            }
        }
    }
}
ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}
int fast_power(ll n, ll p) {
    if (p == 0) {
        return 1;
    } else if (p == 1) {
        return n % 100;
    }
    int sq = fast_power(n, p / 2);
    return sq % 100 * sq % 100 * ((p % 2) ? n : 1) % 100;
}
int mod_inverse(int x, int mod) {
    for (int i = 1; i < mod; ++i) {
        if (x * i % mod == 1) {
            return i;
        }
    }
    return 0;
}
int fast_mod_inverse(int x, int y, int mod = 1e9) {
    if (gcd(x, y) != 1) return 1;
    return fast_power(x, y - 2);
}
void solve(){
    // Your problem-solving code goes here
}
signed main() {
    coder
    int n , k;
    cin >> n >> k;
    int arr[n + 1] = {}, sleep[n + 1] = {} , total = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        cin >> sleep[i];
        if(sleep[i] == 1){
            total += arr[i];
            arr[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i-1];
    }
    int maxi = -1;
    for (int i = 1; i <= n - k + 1; i++)
    {
        if(arr[i + k - 1] - arr[i - 1] > maxi){
            maxi = arr[i + k - 1] - arr[i - 1] ;
        }
    }
    cout << total + maxi;
    
    return 0;
}
// 
					 			 		 		  	  	   	 	 	 	
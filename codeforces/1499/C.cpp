// $$\   $$\  $$$$$$\  $$$$$$$\ $$$$$$$$\ $$$$$$\ $$\   $$\ $$$$$$$$\ $$\     $$\       $$\      $$\  $$$$$$\  $$$$$$$\  $$$$$$\ $$\     $$\  $$$$$$\  $$\       
// $$ | $$  |$$  __$$\ $$  __$$\\__$$  __|\_$$  _|$$ | $$  |$$  _____|\$$\   $$  |      $$ | $\  $$ |$$  __$$\ $$  __$$\ \_$$  _|\$$\   $$  |$$  __$$\ $$ |
// $$ |$$  / $$ /  $$ |$$ |  $$ |  $$ |     $$ |  $$ |$$  / $$ |       \$$\ $$  /       $$ |$$$\ $$ |$$ /  $$ |$$ |  $$ |  $$ |   \$$\ $$  / $$ /  $$ |$$ |
// $$$$$  /  $$$$$$$$ |$$$$$$$  |  $$ |     $$ |  $$$$$  /  $$$$$\      \$$$$  /        $$ $$ $$\$$ |$$$$$$$$ |$$$$$$$  |  $$ |    \$$$$  /  $$$$$$$$ |$$ |
// $$  $$<   $$  __$$ |$$  __$$<   $$ |     $$ |  $$  $$<   $$  __|      \$$  /         $$$$  _$$$$ |$$  __$$ |$$  __$$<   $$ |     \$$  /   $$  __$$ |$$ |
// $$ |\$$\  $$ |  $$ |$$ |  $$ |  $$ |     $$ |  $$ |\$$\  $$ |          $$ |          $$$  / \$$$ |$$ |  $$ |$$ |  $$ |  $$ |      $$ |    $$ |  $$ |$$ |
// $$ | \$$\ $$ |  $$ |$$ |  $$ |  $$ |   $$$$$$\ $$ | \$$\ $$$$$$$$\     $$ |          $$  /   \$$ |$$ |  $$ |$$ |  $$ |$$$$$$\     $$ |    $$ |  $$ |$$$$$$$$\ 
// \__|  \__|\__|  \__|\__|  \__|  \__|   \______|\__|  \__|\________|    \__|          \__/     \__|\__|  \__|\__|  \__|\______|    \__|    \__|  \__|\________|

/*======================== =========== I Bow to Lord Shiva  =================================*/









#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define endl "\n"
#define yes() cout << "YES" << endl
#define no() cout << "NO" << endl
#define pb push_back
#define pp pop_back
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define sti stack<int>
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define umap(a, b) unordered_map<a, b>
#define omap(a, b) map<a, b>
#define ll long long
#define pri pair<int, int>
#define print1(a) cout << a << endl
#define SIZE(x) ((int)(x).size())
template <typename Container>
void print(const Container &container) {
    for (const auto &element : container) {
        cout << element << " ";
    }
    cout << endl;
}
#define MOD 1000000007

#define forl(i, a, b) for (int i = a; i < b; i++)

bool isVowel(char ch)
{
    char lowerChar = std::tolower(ch);
    return lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u';
}

string dtb(int decimalNumber)
{
    return bitset<32>(decimalNumber).to_string();
}

int setbits(int N)
{
    int u = 0;
    for (int i = 1; i <= N; i <<= 1)
    {
        int quotient = N / (i << 1);
        int remainder = N % (i << 1);
        u += quotient * i + max(0, remainder - i + 1);
    }
    return u;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int floorSqrt(int x)
{
    if (x == 0 || x == 1) {
        return x;
    }

    int left = 1, right = x, result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) {
            left = mid + 1;
            result = mid;
        } else {
            right = mid - 1;
        }
    }

    return result;
}
ll largest_bit(ll n) {
    return n==0?-1:31-__builtin_clz(n);
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; ++p)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p)
    {
        if (isPrime[p])
        {
            primes.push_back(p);
        }
    }

    return primes;
}

ll mypow(ll base, ll exponent)
{
    ll result = 1;
    base = base % MOD;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % MOD;
        }

        base = (base * base) % MOD;
        exponent = exponent / 2;
    }

    return result;
}

vector<int> factorize(int n, int k) {
    vector<int> factors;

    for (int i = 2; i * i <= n && factors.size() < k - 1; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1 && factors.size() < k - 1) {
        factors.push_back(n);
    }

    return factors;
}


void solve() {
   ll n;
   cin>>n;
   vector<ll>c(n);
   for(ll &i:c)cin>>i;
    //if first move is in right direction
    ll right=0,up=0;
    ll max1=INT_MAX,max2=INT_MAX;
    vector<ll>cost;
    ll rightCost=0,upCost=0;
    for(int i=0;i<n;i++){
        if(i==0){
            max1=min(max1,c[i]);

        }
        else if(i==1){
            max2=min(max2,c[i]);
            ll u=1ll*(max1*n)+(max2*n);
            cost.push_back(u);
        }
        else{

            if(i%2!=0){
                if(c[i]<max2){
                    upCost+=max2;
                    max2=c[i];

                }
                else{
                    upCost+=c[i];
                }
                up++;
            }
            else{
                if(c[i]<max1){
                    rightCost+=max1;
                    max1=c[i];

                }
                else{
                    rightCost+=c[i];
                }
                right++;
            }
            ll u=max1*(n-right)+rightCost;
            ll io=max2*(n-up)+upCost;
            cost.push_back(u+io);
        }
    }
    right=0,up=0;
     max1=INT_MAX,max2=INT_MAX;
     rightCost=0,upCost=0;
      for(int i=0;i<n;i++){
        if(i==0){
            max2=min(max2,c[i]);

        }
        else if(i==1){
            max1=min(max1,c[i]);
            ll u=(max1*n)+(max2*n);
            cost.push_back(u);
        }
        else{
            if(i%2==0){
                if(c[i]<max2){
                    upCost+=max2;
                    max2=c[i];

                }
                else{
                    upCost+=c[i];
                }
                up++;
            }
            else{
                if(c[i]<max1){
                    rightCost+=max1;
                    max1=c[i];

                }
                else{
                    rightCost+=c[i];
                }
                right++;
            }
            ll u=max1*(n-right)+rightCost;
            ll io=max2*(n-up)+upCost;
            cost.push_back(u+io);
            // mistake is that max2 is as it is max2 and it get added in upCost fix that
        }
    }
    sort(all(cost));
    cout<<cost[0]<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
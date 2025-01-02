#include <bits/stdc++.h>
using namespace std;
#define test int T;cin>>T;while(T--)
#define int long long
#define pb push_back
#define bits(x) __builtin_popcount(x)
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define re(i,a,b) for(int i=a;i>=b;i--)
#define pVec(v) for(auto e:v)cout<<e<<" ";cout<<"\n"
#define aut(e,v) for(auto e:v)
const int MOD = 998244353;
const int N = 1e5 + 7;
inline int gcd(int a, int b) {if (b == 0) return a; return gcd(b, a % b);}
 int max2(int x, int y)
{
    if(x < y) return y;else return x;
}
int bs_sqrt(int x) {
  int left = 0, right = 2000000123;
  while (right > left) {
      int mid = (left + right) / 2;

      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
int modFact(int n, int p)
{
    if (n >= p)
        return 0;

    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}
 void init_code() {
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
int getClosest(int val1, int val2,
               int target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}
int findClosest(int arr[], int n, int target)
{
    // Corner cases
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];

    // Doing binary search
    int i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;

        if (arr[mid] == target)
            return arr[mid];

        /* If target is less than array element,
            then search in left */
        if (target < arr[mid]) {

            // If target is greater than previous
            // to mid, return closest of two
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1],
                                  arr[mid], target);

            /* Repeat for left half */
            j = mid;
        }

        // If target is greater than mid
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid],
                                  arr[mid + 1], target);
            // update i
            i = mid + 1;
        }
    }

    // Only single element left after search
    return arr[mid];
}

 bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;

   return (ceil(log2(n)) == floor(log2(n)));
}

int fpow(int x, int y, int p = MOD) {
 x = x % p; int sum = 1; while (y) {
  if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
 } return sum;
}
int lcm(int a, int b) {
 return (a * b) / __gcd(a, b);
}
int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}


int nCrModPDp(int n, int r, int p)
{
 int C[r + 1];
 memset(C, 0, sizeof(C));
 C[0] = 1;
 for (int i = 1; i <= n; i++)
 {
  for (int j = min(i, r); j > 0; j--)
  {
   C[j] = (C[j] + C[j - 1]) % p;
  }
 }
 return C[r];
}

vector<int> primes(N + 1, 1);
void sieve_of_eratothenes()
{
 primes[0] = 0;
 primes[1] = 0;
 for (int i = 2; i <= sqrt(N); i++)
 {
  if (primes[i] == 1)
  {
   for (int j = 2; i * j <= N; j++)
   {
    primes[i * j] = 0;
   }
  }
 }

}

void binary_exponentiation(int base, int power)
{
 long long ans = 1;
 while (power > 0)
 {
  if ((power % 2) == 0)
  {
   base = base * base;
   power /= 2;
  }
  else
  {
   ans *= base;
   power -= 1;
  }
 }

 cout << ans << endl;
}

int factorial(int n)
{
 int factorial = 1;
 for (int i = 2; i <= n; i++)
  factorial = factorial * i;
 return factorial;
}

int nCr(int n, int r)
{
 int C[r + 1];
 memset(C, 0, sizeof(C));
 C[0] = 1;
 for (int i = 1; i <= n; i++)
 {
  for (int j = min(i, r); j > 0; j--)
  {
   C[j] = (C[j] + C[j - 1]);
  }
 }
 return C[r];
}

void prime_factorization(int n)
{
    int sum=0;
    map<int,int> m;
 for (int i = 2; i <= sqrt(n); i++)
 {
  if ((n % i) == 0)
  {
   int cnt = 0;
   while ((n % i) == 0)
   {
    n = n / i;
    cnt++;
   }

   cout << i << " raised to " << cnt;


  }
 }

 if((n!= 1)){
  cout << n << " " << 1 << endl;


 }

 }


vector<int> Divisors(int n)
{   vi divisors;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                divisors.pb(i);

            else // Otherwise print both
                divisors.pb(i);divisors.pb(n/i);
        }
    }
    return divisors;
}
int countDivisors(int n)
{   int ans=0;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                ans++;

            else // Otherwise print both
                ans+=2;
        }
    }
    return ans;
}
int min2(int a,int b)
{return a<b ? a :b;}
int adjacentElements(vi &arr,int element)//Assuming the element isn't present in the vector.
{
    int top=arr.size()-1;
    int bottom=0;
    int mid=(top+bottom)/2;
    while(top>bottom)
    {
        if(element>arr[mid])
        {
            bottom=mid+1;
        }
        else
        {
            top=mid-1;
        }
        mid=(top+bottom)/2;
    }
    return mid;
}
void returnParents(vector<vi> & tree, int parent[],int cur,int par)
{
    rep(i,0,tree[cur].size())
    {
        if(tree[cur][i]!=par)
        {
            parent[tree[cur][i]] = cur;
            returnParents(tree,parent,tree[cur][i],cur);
        }
    }
}


void compute()
{
  string s;
  cin>>s;
  int n=s.size()-1;
  if(s[0]=='a' && s[1]=='b')
  {
      cout<<s[0]<<' ';
      for(int i=1;i<n;i++)
      {
          cout<<s[i];
      }
      cout<<' ';
      cout<<s[n]<<endl;
  }
  else
  {
      cout<<s[0]<<' '<<s[1]<<' ';
      for(int i=2;i<=n;i++)
      {
          cout<<s[i];
      }
      cout<<endl;
  }

}
signed main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 test
  compute();
  return 0;
}

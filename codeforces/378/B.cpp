#include <bits/stdc++.h>
#define CY cout << "YES\n";
#define CN cout << "NO\n";
#define Cy cout << "Yes\n";
#define Cn cout << "No\n";
#define all(x) (x).begin(), (x).end()
#define sz(s) ((int)((s).size()))
#define torad(x) (x) * ((2 * acos(0)) / 180.0)
#define vll vector<long long>

#define ite vector<long long>::iterator
typedef long long ll;
#define pll pair<ll,ll>
#define pb push_back
#define forr for (int i = 0; i < n; i++)
#define big(v) *max_element(all(v))
#define small(v) *min_element(all(v))
#define PI 2 * acos(0)
#define pob pop_back
  
#define vcin(a, n)             \
  vll a (n);\
for (ll i = 0; i < n; i++)\
cin >> a[i];

#define print(a)              \
{\
for (auto u:a)\
cout << u << " ";\
cout << endl;\
}


#define ad(i, j, k) for (ll i = j; i < k; i++)
#define od(i, j, k) for (ll i = j; i >= k; i--)
#define nothing                   \
  ios_base::sync_with_stdio (0);\
cin.tie (0);\
cout.tie (0);

using namespace std;

ll getbit (ll n, ll pos) 
 { 
return ((n & (1 << pos)) != 0);

}

ll setbit (ll n, ll pos) 
 { 
return (n | (1 << pos));

}

ll clearbit (ll n, ll pos) 
 { 
ll mask = ~(1 << pos);
  
return (n & mask);

}

ll updatebit (ll n, ll pos, ll value) 
 { 
ll mask = ~(1 << pos);
  
n = n & mask;
  
return (n | (value << pos));

}


int
  double_comp (double a, double b) 
 { 
if (fabs (a - b) <= 1e-10)
	
return 0;
  
return a < b ? -1 : 1;

}
  
ll GCD (ll x, ll y) 
 { 
if (y == 0)
	
return x;
  
  else
	
return GCD (y, x % y);

}

ll LCM (ll x, ll y) 
 { 
return (x * y / (GCD (x, y)));

}

ll stringbinarytodecimal (string s) 
 { 
ll sum = 0, i;
  
ll a[55] = { 0 };
  
reverse (all (s));
  
for (i = 0; i < 30; i++)
	
	{
	  
a[i] = (1 << i);
	
}
  
for (i = 0; i < sz (s); i++)
	
	{
	  
 
if (s[i] == '1')
		
sum += a[i];
	
}
  
return sum;

}


#define sch(a,n) binary_search(all(a),n)
#define lo(a,n) lower_bound(all(a),n)-a.begin()
#define up(a,n) upper_bound(all(a),n)-a.begin()
#define lq "\n"
const double eps = 1e-12;

double
sq (ll x) 
 { 
double l = 0, r = x;
  
	// while(r-l>eps)
	for (ll i = 0; i < 100; i++)
	
	{
	  
double mid = (l + r) / (2 * 1.00);
	  
if (mid * mid > x)
		
r = mid;
	  
	  else
		
l = mid;
	
}
  
return l;
  
	// cout<<l<<" ";
}




#define a5 100010
ll prme[10000];
void seve()
{
	ll i,j;
	prme[1]=1;
	for(i=2;i<=10;i++)
	{
		if(prme[i]==0)
		{
			for(j=2;i*j<=10;j++)
			{
				prme[i*j]=1;
			}
		}
	}
}
  bool
sieve (int n) 
 { 

int prime[100000]={0};
prime[0] = prime[1] = 1;

for (int i = 2; i <= n; i++)
  
  {
	
if (prime[i] == 0)
	  
	  {
		
for (int j = i * i; j <= n; j += i)
		  
prime[j] = 1;
	  
}

} 
if (prime[n] == 0)
  
return true;
  
else
  
return false;

 
}


#define sp " ";
int spf[1000000] = { 0 };


ll
primefactor (ll n) 
 { 
	for (int i = 2; i <= n; i++)
	
spf[i] = i;
  
for (int i = 2; i <= n; i++)
	
	{
	  
if (spf[i] == i)
		
		{
		  
for (int j = i * i; j <= n; j += i)
			
			{
			  
if (spf[j] == j)
				
spf[j] = i;
			
}
		
}
	
}
  map<ll,ll>mp;
ll   sum=0;
 // sum1=0;
while (n != 1)
	
	{
	  
mp[ spf[n]]++;// << sp;

	 //cout<<spf[n]<<" ";
n = n / spf[n];
	
}
for(auto u : mp)
{
	ll sum1=0;
	ll x=u.first;
	 ll y=u.second;
	while(x>0)
	{
		x=x/10;
		sum1++;
	}
	while(y>0)
	{
		y=y/10;
		sum1++;
	}
	sum+=sum1;
}
//cout<<lq;
mp.clear();
return sum;

}
  
 
ll factorial (ll n) 
 { 
if (n == 0)
	
return 1;
  
return n * factorial (n - 1);

}

ll lrs (string X, string Y, ll m, ll n) 
 { 
 
 
ll L[m + 1][n + 1];
  
 
for (ll i = 0; i <= m; i++)
	{
	  
for (ll j = 0; j <= n; j++)
		{
		  
if (i == 0 || j == 0)
			
L[i][j] = 0;
		  
 
		  else if (X[i - 1] == Y[j - 1] && (i != j))
			
L[i][j] = L[i - 1][j - 1] + 1;
		  
 
		  else
			
L[i][j] = max (L[i - 1][j], L[i][j - 1]);
		
}
	
}
  
 
return L[m][n];

}



  
ll bs (ll n, vll v) 
 { 
	// print(v);
	// cout<<n<<"n";
	ll i = 0;
  
ll j = v.size () - 1;
  
ll ans = 0, ans1 = 0;
  
while (i <= j)
	
	{
	  
ll mid = (i + j) / 2;	//cout<<mid<<"mid "<<v[mid]<<"mmc";
	  if (n % v[mid] == 0)
		
		{
		  
if (ans == 0)
			
ans = v[mid];
		  
if (ans != 0)
			
			{
			  
if (ans > v[mid])
				
				{
				  
ans = v[mid];
				
}
			
}
		  
if (v[mid] >= n)
			
j = mid - 1;
		  
		  else
			
i = mid + 1;
		
}
	  
	  else
		
		{
		  
if (v[mid] >= n)
			
j = mid - 1;
		  
		  else
			
i = mid + 1;
		
}
	
}
  
i = 0;
  
j = v.size () - 1;
  
	while (i <= j)
	
	{
	  
ll mid = (i + j) / 2;	
	  if (n % v[mid] == 0)
		
		{
		  
if (ans == 0)
			
ans = v[mid];
		  
if (ans != 0)
			
			{
			  
if (ans > v[mid])
				
				{
				  
ans = v[mid];
				
}
			
}
		  
if (v[mid] > n)
			
i = mid + 1;
		  
		  else
			
j = mid - 1;
		
}
	  
	  else
		
		{
		  
if (v[mid] > n)
			
i = mid + 1;
		  
		  else
			
j = mid - 1;
		
}
	
}
  
if (ans != 0 && ans1 != 0)
	
ans = min (ans, ans1);
  
  else if (ans1 == 0)
	
ans = ans;
  
  else if (ans == 0)
	
ans = ans1;
  
cout << ans << " ";
  
return ans;

 
}


#define lo(a,n) lower_bound(all(a),n)-a.begin()
  
ll suum (vll z, ll n) 
 { 
ll sum = 0, i;
  
ad (i, 0, n) 
 { 
sum += z[i];
  
}
  
return sum;

}

ll ispalindrome (string s) 
 { 
ll n = sz (s), m = n - 1;
  
ll f = 0;
  
for (ll i = 0; i < n; i++)
	
	{
	  
if (s[i] == '0')
		
		{
		  
			f++;
		
}
	
}
  
 
return f;

}
const int MOD = 1000000007;
void showdq(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll subtract(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
ll multiply(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
int divide(int a, int b) {

    int bInverse = 1;
    int exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            bInverse = (bInverse * b) % MOD;
        }
        b = (b * b) % MOD;
        exp /= 2;
    }
     return (a * bInverse) % MOD;
}
long long int bigmod(long long int base, long long int exponent, long long int modulus) {
    if (exponent == 0) {
        return 1; 
    }

    if (exponent % 2 == 0) {
        long long int temp = bigmod(base, exponent / 2, modulus) % modulus;
        return (temp * temp) % modulus;
    } else {
        return ((base % modulus) * bigmod(base, exponent - 1, modulus)) % modulus;
    }
}
string addBigInt(string x, string y){
	string result = "";
	int sum, carry=0;
	for(int i=x.length()-1; i>=0; i--){
		sum = (int)x[i]-'0' + (int)y[i]-'0' + carry;
		if(sum > 9){
			result = to_string(sum%10) + result;
			carry = sum/10;
		}else{
			result = to_string(sum) + result;
			carry = 0;
		}
	}
	if(carry != 0){
		result = to_string(carry) + result;
	}
return result;
}
int modInverse(int A, int M)
{
	for (int X = 1; X < M; X++)
		if (((A % M) * (X % M)) % M == 1)
			return X;
}
string subbigint(string str1, string str2) {
    
   // string n1 = num1, n2 = num2;
   int n1 = str1.length(), n2 = str2.length(); 
    if (n1< n2 || (n1 == n2 && str1 < str2))
        swap(str1, str2);
    n1 = str1.length(), n2 = str2.length(); 
     string str = ""; 
      reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
  
  for (int i = 0; i < n2; i++) {   
        int sub     = ((str1[i] - '0') - (str2[i] - '0') - carry); 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    }
     for (int i = n2; i < n1; i++) { 
        int sub = ((str1[i] - '0') - carry); 
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        str.push_back(sub + '0'); 
    } 
    reverse(str.begin(), str.end()); 
    return str;  
}
string divbigint(string number, ll divisor) {
 
   string result;
   int index = 0;
 
   int dividend = number[index] - '0';
   while (dividend < divisor) {
      dividend = dividend * 10 + (number[++index] - '0');
   }
   
   while (number.size() > index) {
      result += (dividend / divisor) + '0';
      dividend = (dividend % divisor) * 10 + number[++index] - '0';
   }
   if (result.length() == 0) {
      return "0";
   }
   return result;
}
int divisor(string a, int b)
{
	 int j = 0;
        if (a[0] == '-') j = 1;
        if (b < 0) b = abs(b);
        long rim = 0;
        for ( ; j < a.size(); j++)
        {
            rim = rim*10 + (a[j] - '0');
            rim %= b;
        }
        return rim;//if rim==0 divisible else not
}
 string multiplybigint(string num1, string num2) {
   if (num1 == "0" || num2 == "0") {
      return "0";
   }
   string product(num1.size() + num2.size(), 0);
   for (int i = num1.size() - 1; i >= 0; i--) {
      for (int j = num2.size() - 1; j >= 0; j--) {
            int n = (num1[i] - '0') * (num2[j] - '0') + product[i + j + 1];
            product[i + j + 1] = n % 10;
            product[i + j] += n / 10;
      }
   }
   for (int i = 0; i < product.size(); i++) {
      product[i] += '0';
   }
   if (product[0] == '0') {
      return product.substr(1);
   }
   return product;
}

ll cnt=0;
const int mx=3e4;
bool vis[mx];
vll adj[mx];
void dfs(ll u)
{
	vis[u]=1;
	for(auto v : adj[u])
	{
		if(vis[v]==0)
		{
			dfs(v);
		}
	}
	return;
}
double dis(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
long long get(int x) {
    return x * 1ll * (x + 1) / 2;
}
int
main () 
 { 
nothing 
 ll tc,n,m,i,j,k,z,x,f,y,sum,ans;
  ll s,t;
 map<ll,ll>mp,mp1;
ll q;
vector< pair<ll,ll> > vp;
vector<ll>vs,vt;
multiset<ll>ms;
cin>>n;
vll a;
for(i=0;i<n;i++)
{
	cin>>s>>t;
	vs.pb(s);
	a.pb(s);
	a.pb(t);
	vt.pb(t);
	
}
x=n/2;
sort(all(a));
y=a[n-1];
if(n!=1)

{
//if(n%2==0)	

//y=max(vs[x-1],vt[x-1]);


for(i=0;i<x;i++)
cout<<"1";
for(i=x;i<n;i++)
{
	if(vs[i]>y)
	cout<<"0";
	else
	cout<<"1";
}
cout<<lq;
for(i=0;i<x;i++)
cout<<"1";
for(i=x;i<n;i++)
{
	if(vt[i]>y)
	cout<<"0";
	else
	cout<<"1";
}

cout<<lq;}
else
{y=max(vs[0],vt[0]);
if(y==vs[0])
cout<<"0\n1\n";
else
cout<<"1\n0\n";}
/*cin>>tc;
while(tc--)
{
	cin>>n;
ll		pos,pos1,pos2;
ll mxx=-1,mnn=1e9+7;
	while(n--)
	{
	ll	mx=-1;
	cin>>x;
	for(i=0;i<x;i++)
		{cin>>m;
		m=m-i;
		if(m>mx)
		{
			mx=m;
			pos=i;
		}
		
	}
	if(mxx<mx)
	{mxx=mx;pos1=pos;}
cout<<pos1<<" ";
	
	vp.pb({mx,x});}
//	vp[0].second=pos2;
ad(i,0,sz(vp))
cout<<vp[i].first<<" "<<vp[i].second<<lq;
		sort(all(vp));
			vp[sz(vp)-1].second=pos1;
			ad(i,0,sz(vp))
cout<<vp[i].first<<" "<<vp[i].second<<lq;
	for(i=1;i<sz(vp);i++)
	{//cout<<vp[i].second<<" ";
	if(i==sz(vp)-1||vp[i].first!=vp[i+1].first)
		vp[i].second+=vp[i-1].second;
		else
		{
			for(j=i+1;j<sz(vp);j++)
			{
				if(vp[j].first!=vp[i].first)
			break;
			}
			reverse(vp.begin()+i,vp.begin()+j);
			for(k=i;k<j;k++)
					vp[k].second+=vp[k-1].second;
					i=j-1;
			
		}
		
		
		
		}
	ad(i,0,sz(vp))
cout<<vp[i].first<<" "<<vp[i].second<<lq;
	ans=vp[0].first+1;
	
	for(i=1;i<sz(vp);i++)
	{
		
		 x=vp[i].first+1;
		x=x-vp[i].second;
		if(x>ans)
		ans=x;
		
	}
	cout<<ans<<lq;
	vp.clear();
	}*/

return 0;
}
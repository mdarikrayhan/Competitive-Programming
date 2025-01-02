#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <iterator>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;


#define int long long 



#define pf push_front
#define pb push_back
#define pob pop_back
#define pof pop_front 
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define kill(x) {cout <<(x) << endl; return;}
#define kandam std::ios_base::sync_with_stdio(0); 
#define vazhi cin.tie(NULL);
#define endl "\n"

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" " <<(x) << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;


ll mod= 1e9 +7;//  998244353  ;
const ll inf= 2e18 +37 ;  const int infi=2e9+37;
const int  N= 3e5 + 37;      
vector <ll> fact ={1};


 ll fpow(ll b, ll p){ll ans=1; while(p){if(p%2)ans=(ans*b)%mod;b=b*b%mod;p/=2;} return ans;}
 ll sprime(ll n){for(int i=2;i*i<=n;i++)if(n%i==0)return i;return n; }
 inline ll ceil(ll a , ll b) {return (a+b-1)/b; }
 inline ll inv(ll n) { return fpow(n,mod-2); }
 void factorial(int Nf){for(int i=1;i<Nf;i++) fact.pb(fact[i-1]*i %mod); }
 ll C(ll n,ll r) {  if(n<r)return 0; return fact[n] *inv(fact[n-r]) % mod *inv(fact[r]) % mod; } 
 
 


     void kingpin()
{       

int n,m;
cin >> n >> m;

vector <vector <int>> a(n, vector <int>(m,0));

auto b=a;

for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> a[i][j];

for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> b[i][j];



   map <int, pair <int,int>> pos;
   
   for(int i=0;i<n;i++)for(int j=0;j<m;j++)pos[b[i][j]]={i,j};
   
   vector <int> row(n,-1), column (m,-1);
   
   for(int i=0;i<n;i++)for(int j=0;j<m;j++)
   {
   	auto [r,c]=pos[a[i][j]];
   	
   	if(row[i]==-1)row[i]=r;
   	else if(row[i]!=r)kill("NO")
   	
   	if(column[j]==-1)column[j]=c;
   	else if(column[j]!=c)kill("NO")
   	
   	
   }

   cout << "YES" << endl;
	
	
	
	
			
			
			
			
	
	   }
	   
	   
      
      
      
      
	   
   	  
   
	
	

       



int32_t main(void)      
 {  kandam vazhi	
 
 
 
 
 
  
  int T=1;
  
  cin >> T;
   

   
   
cout << fixed << setprecision(7);


	

  for(int ii=1;ii<=T;ii++) {
  	cerr<< "Test Case "<< " " << ii << endl;
  	kingpin();
  	
  	
  	cerr << "-----------------" << endl;
  }
  
  
  
  
   return 0; }
   

  
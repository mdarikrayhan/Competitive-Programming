#include <bits/stdc++.h>

#define int long long int
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define endl '\n'
#define vpi vector<pair<int,int>>
#define vii vector<vector<int,int>>
#define pii pair<int,int>
#define bitcount(x) __builtin_popcount(x)
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

using namespace std;

const int M = 1e9+7;
const int N = 2e5 + 10;
#define debug(x) cout << #x << " is " << x << endl
#define debugg(x) cout << x.first << " -> " << x.second << endl
#define all(arr) arr.begin(), arr.end()
#define lup(i,j,n) for(int i = j; i < n; i++)
#define lupr(i,j,n) for(int i = j; i >= n; i--)
 
bool sortbysec(const pair<int, int> &a,
  const pair<int, int> &b)
{
if (a.second == b.second)
return (a.first > b.first);
return ((a.second < b.second));
}
 
bool sortbyfirst(const pair<int, int> &a,
  const pair<int, int> &b)
{
if (a.first == b.first)
return (a.second < b.second);
return ((a.first > b.first));
}

int inv(int i) {if (i == 1) return 1; return (M - ((M / i) * inv(M % i)) % M) % M;}
int mod_mul(int a, int b) {a = a % M; b = b % M; return (((a * b) % M) + M) % M;}
int mod_add(int a, int b) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
int pwr(int a, int b) {a %= M; int res = 1; while (b > 0) {if (b & 1) res = res * a % M; a = a * a % M; b >>= 1;} return res;}
 
int sieve[N];
vector <int> primes;
void pre()
{
    for (int i=2; i<N; i++)
    {
        if (sieve[i]!=0)continue;
       
        primes.push_back(i);
        for (int j=i; j<N; j+=i)
        sieve[j] = 1;
    }
}
int lcm(int a,int b){
	int temp=a*b;
	return temp/__gcd(a,b);
}
void solve(){
    int n;
    cin >> n;
    vi crush(n+1);
    //set<int> s;
    vi indeg(n+1,0);
    lup(i,1,n+1){
    	cin >> crush[i];
    	//if(i==crush[i]) s.insert(i);
    	indeg[crush[i]]++;
    }
    lup(i,1,n+1){
    	if(indeg[i]==0){
    		cout << -1 << endl;
    		return;
    	}
    }
    int ans=1;
    vi vis(n+1,0);
    lup(i,1,n+1){
    	int cnt=0;
    	int j=i;
    	while(!vis[j]){
    		vis[j]=1;
    		cnt++;
    		j=crush[j];
        }
    	//cout << i << ' ' << cnt << endl; 
    	if(cnt==0) continue;
    	if(cnt%2) ans=lcm(ans,cnt);
    	else ans=lcm(ans,cnt/2);

    }
    cout << ans << endl;
}
int32_t main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL); //remove for online queries
    int t=1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

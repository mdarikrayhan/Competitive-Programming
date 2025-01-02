#include <bits/stdc++.h>
#define nl "\n"
#define spc " "
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pip pair<int,pi>
#define pl pair<ll,ll>
#define plp pair<ll,pl>
#define vi vector<int>
#define vl vector<ll>
#define all(x) x.begin(), x.end()
#define ins insert
#define lb lower_bound  // First element NOT LESS than val
#define ub upper_bound  // First element GREATER than val
#define sz(q) (int)(q.size())
 
using namespace std;
typedef long long int ll;
typedef long int li;
typedef double ld;

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define fo(a,b) for(auto i=a;i<b;++i)
#define nfo(a,b) for(auto i=a;i>=b;--i)
#define jfo(a,b) for(auto j=a;j<b;++j)
#define njfo(a,b) for(auto j=a;j>=b;--j)
#define tt ll t; cin>>t; while(t--)
#define YES cout<<"YES"<<nl
#define NO cout<<"NO"<<nl

void swap(ll &x,ll &y){
	ll temp = y;
	y = x;
	x = temp;
}

ll powa(ll a, ll b, ll m = mod){
	if (b == 0)
		return 1ll;
	else if (b == 1)
		return a;
	else
	{
		ll x = powa(a, b/2, m);
		x *= x;
		// x %= m;
		if (b%2)
		{
			x *= a;
			// x %= m;
		}
		return x;
	}
}

int ReverseNum(int n){
    int reverse = 0;
    while (n != 0) {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }
    return reverse;
}

int findGcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0) {
        return b;
    }
    return a;
}

int sum(int k){
    int ans = 0;
    while (k) {
        ans += k % 10;
        k /= 10;
    }
    return ans;
}

void solve() {
    int n,k;
    cin >> n >> k;
    vi arr(n);
    for0(i,n){
        cin >> arr[i];
    }
    int ans=0;
    for0(i,n){
        int j=3;
        while(j--){
            if(arr[i]<k){
                break;
            }
            arr[i]-=k;
        }
        ans+=arr[i];
    }
    cout << ans << endl;
}

int32_t main(){
  //cout << fixed << setprecision(5);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);  
  freopen("output.txt", "w", stdout); 
  solve();
//   int t=1; cin>>t;
//   while(t--)solve();
}
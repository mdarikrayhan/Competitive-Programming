#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::vector<ld> vld;
typedef std::vector<std::vector<ll> > vvll;
typedef std::vector<std::vector<ld> > vvld;
typedef std::vector<string> vstr;
typedef std::vector<bool> vbl;
typedef std::vector<std::pair<ll,ll> > vpll;
typedef std::pair<ll,ll> pll;
#define f(i, x, n) for (ll i = x; i < n; ++i)
#define rf(i, x, n) for (ll i = x; i >= n; --i)
#define in(n) long long int n;   cin >> n
#define inarr(n, arr)   vector<ll> arr(n); f(i,0,n) cin >> arr[i]
#define input(vec,a,b) for(ll i_itr = a;i_itr<b;++i_itr) cin>>vec[i_itr]
#define print(vec,a,b) for(ll i_itr=a;i_itr<b;++i_itr) cout<<vec[i_itr]<<" "; cout<<"\n"
#define ha cout<<"YES"<<endl
#define na cout<<"NO"<<endl
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
const ll mod = 1000000007;
const ll MOD = 998244353;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;

// const ll N=1e6;
// bool isp[N];
// vector<ll> pr;
 
// void build_primes() // 79000 primes for N=1e6 in O(N)
// {
//     isp[0]=0;
//     isp[1]=0;
//     pr.push_back(1);
//     for(ll i=2;i<N;i++)isp[i]=1;
//     for(ll i=2;i<N;i++)
//     {
//         if(isp[i])
//         {
//             pr.push_back(i);
//             for(ll j=i;j<N;j+=i){
//                 isp[j]=0;
//             }
//         }
//     }
// }

// ll fastPrime(ll a)
// { 
//     if (a != 2 && a % 2 == 0 || a < 2) 
//         return 0;  
//     for(ll i = 3; i * i <= a; i += 2) 
//     {
//         if(a % i == 0) 
//             return 0; 
//     }
//     return 1;
// }

// ll digit_sum(ll n) 
// {
//     ll ret = 0;
//     while(n) 
//     {
//         ret += n % 10;
//         n /= 10;
//     }
//     return ret;
// }

// stoi(str) string to int conversion
// to_string(num) number to string conversion
// transform(str.begin(), str.end(), str.begin(), ::tolower); 
// transform(str.begin(), str.end(), str.begin(), ::toupper; 
// str[i]=tolower(str[i]); for single character

// ll binarySearch(ll low,ll high,vector<ll> &v,ll element) // strictly less element
// {
//     ll ans=high+1;
//     while(low<=high)
//     {
//         ll mid=(low+high)/2;
//         if(v[mid]>=element)
//         {
//             ans=mid;
//             high=mid-1;
//         }
//         else
//             low=mid+1;
//     }
//     return ans;
// }

void solve()
{
    in(n);
    in(a);
    cout<<"2 1 "<<max(3ll, min(n, (n*a+90)/180+2));
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << fixed<<setprecision(15); ///activate it if the answers are in decimal.
    ll T=1;
// 	cin>>T;
	while(T--)
	{
	    solve();
	}
	return 0;
}

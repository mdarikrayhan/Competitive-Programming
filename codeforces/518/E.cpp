// Problem: E. Arthur and Questions
// Contest: Codeforces - Codeforces Round 293 (Div. 2)
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// UTC +7: 2024-05-17 14:37:00

//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     //
//         Nhan qua khong no chung ta thu gi          //
//                 Vay nen dung oan han               //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     //
//                                                    //    
//                       _oo0oo_                      //
//                      o8888888o                     //
//                      88" . "88                     //					  
//                      (| -_- |)                     //
//                      0\  =  /0                     //
//                    ___/`---'\___                   //
//                  .' \\|     |// '.                 //
//                 / \\|||  :  |||// \                //  			  
//                / _||||| -:- |||||- \               // 			  
//               |   | \\\  -  /// |   |              //			  
//               | \_|  ''\---/''  |_/ |              //			  
//               \  .-\__  '-'  ___/-. /              //			  
//             ___'. .'  /--.--\  `. .'___            //			  
//          ."" '<  `.___\_<|>_/___.' >' "".          //  		  
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |        //		  
//         \  \ `_.   \_ __\ /__ _/   .-` /  /        //    	  
//     =====`-.____`.___ \_____/___.-`___.-'=====     //     
//                       `=---='                      //
//                                                    //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     //
//   Duc Phat noi day phu ho Code con chay khong Bug  //
//                 Nam mo a di da phat                //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     //

#include<bits/stdc++.h>
using namespace std;
#define cebug(...) \
    do { \
        cerr << "[" #__VA_ARGS__ "] = "; \
        _print(__VA_ARGS__); \
        cerr << '\n'; \
    } while (0)
template<typename T>
void _print(const T& arg) {cerr<<arg<<' ';}
template<typename T, typename... Args>
void _print(const T& first, const Args&... args) 
{
    cerr<<first<<' ';
    _print(args...);
}

#define int long long
#define fi first 
#define se second
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int> 
#define vll vector<ll>
#define vii vector<ii>
const ll mod = 1e9 + 7;
const ll INF = 2e9 + 1;
const int block = 320;
const int N = 2e5;
int tc, tt = 1;

int n, k;
int a[2*N + 5];
string c[N + 5];
bool check()
{
	for(int i=1; i<=n-k; i++)
		if(a[i] >= a[i + k]) return false;
	return true;
}
void solve()
{
	cin>>n>>k;
	for(int i=1; i<=n; i++) 
	{
		cin>>c[i];
		if(c[i] == "?") a[i] = INF;
		else a[i] = stoi(c[i]);
	}
	a[0] = -INF;
	for(int i=n+1; i<=2*n; i++)
		a[i] = INF;
	for(int i=1; i<=k; i++)
	{
		int prv = 0;
		for(int j=i; j<=2*n; j+=k)
			if(c[j] != "?")
			{
				int pos = a[j] - a[prv] - 1;
				int ned = (j - k - prv) / k;
				if(ned > pos || (a[prv] >= a[j] && j <= n))
				{
					cout<<"Incorrect sequence";
					return;
				}
				int cur = min(a[j] - 1, ned/2);
				if(cur - ned + 1 > a[prv])
				{
					for(int it=j-k; it>prv; it-=k)
					{
						a[it] = cur;
						cur--;
					}
				}
				else
				{
					cur = max(a[prv] + 1, -ned/2);
					if(cur + ned - 1 < a[j])
					{
						cur = cur + ned - 1;
						for(int it=j-k; it>prv; it-=k)
						{
							a[it] = cur;
							cur--;
						}
					}
					else
					{
						cout<<"Incorrect sequence";
						return;	
					}
				}
				
				prv = j;
				if(j > n) break;
			}
	}
	for(int i=1; i<=n; i++)
		cout<<a[i]<<' ';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".INP", "r", stdin);
    // freopen(".OUT", "w", stdout);
    for(int tc=1; tc<=tt; tc++) solve();
    cerr<<"\nTime elapsed: "<<1000.0*clock()/CLOCKS_PER_SEC<<" ms.\n";
    return 0;
}
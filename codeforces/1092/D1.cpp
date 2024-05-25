#include <bits/stdc++.h>
using namespace std;

typedef int i32;
typedef long long i64;
typedef i64 let;
typedef float f32;
typedef double f64;
typedef long double f128;
typedef string str;
const let MOD = 998244353;
const double eps = 1e-12;

#define dbg(x) cout << #x << " = " << x << ln
#define ln "\n"
#define var auto
#define umap unordered_map
#define uset unordered_set
#define vec vector
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((let)(x).size())
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define cln cout << ln
#define isok(ok) cout << ((ok) ? "YES" : "NO") << ln
#define forsn(i, s, n) for (let i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#define rforsn(i, n, s) for (let i = n; i > s; i--)
#define rforn(i, n) rforsn(i, n, -1)
#define fora(i, arr) for (var & i : arr)
#define cinarr(arr, n) forn(i, n) cin >> arr[i]
#define coutarr(arr, n) forn(i, n) cout << arr[i] << ' '

const int N = 200 * 1000 + 13;

int n;
int a[N];
int t;

int main() {
    ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	cin >> n;
	forn(i, n){
		cin >> t;
		a[i] = t& 1;
	}
	
	vec<int> st;
	forn(i, n){
		if (!st.empty() && a[i] == st.back())
			st.pop_back();
		else
			st.push_back(a[i]);
	}
	
	puts((st.size() <= 1)?"YES":"NO");
	return 0;
}
		 			 					 			  		   	  				
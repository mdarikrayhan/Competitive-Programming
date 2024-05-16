// NAME --->>> Suraj Gupta // Scholar ID --->>> 2212119
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

//DEBUG FUNCTION
#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
// #define cerr cout
namespace __DEBUG_UTIL__{ using namespace std; template <typename T> concept is_iterable = requires(T &&x) { begin(x); end(x); size(x); } && !is_same_v<remove_cvref_t<T>, string>; void print(const char *x) { cerr << x; } void print(char x) { cerr << "\'" << x << "\'"; } void print(bool x) { cerr << (x ? "T" : "F"); } void print(_Bit_reference x) { cerr << (x ? "T" : "F"); } void print(string x) { cerr << "\"" << x << "\""; } template <typename T> void print(T &&x) { if constexpr (is_iterable<T>) /* Every iterable Ever */ if (size(x)) if constexpr (is_iterable<decltype(*(begin(x)))>) { int f = 0; cerr << "\n~~~~~\n"; for (auto &&i : x) { cerr << setw(2) << left << f++, print(i), cerr << "\n"; } cerr << "~~~~~\n"; } else { int f = 0; cerr << "{"; for (auto &&i : x) cerr << (f++ ? "," : ""), print(i); cerr << "}"; } else cerr << "{}"; else if constexpr (requires(T &&x) { x.pop(); }) /* Stacks, Priority Queues, Queues */ { T temp = x; int f = 0; cerr << "{"; if constexpr (requires(T &&x) { x.top(); }) while (!temp.empty()) cerr << (f++ ? "," : ""), print(temp.top()), temp.pop(); else while (!temp.empty()) cerr << (f++ ? "," : ""), print(temp.front()), temp.pop(); cerr << "}"; } else if constexpr (requires(T &&x) { x.first; x.second; }) /* Pair */ { cerr << '(', print(x.first), cerr << ',', print(x.second), cerr << ')'; } else if constexpr (requires(T &&x) { get<0>(x); }) /* Tuple */ { int f = 0; cerr << '(', apply([&f](auto... args) { ((cerr << (f++ ? "," : ""), print(args)), ...); }, x); cerr << ')'; } else cerr << x; } template <typename T, typename... V> void printer(const char *names, T &&head, V &&...tail) { int i = 0; for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++) if (names[i] == '(' or names[i] == '<' or names[i] == '{') bracket++; else if (names[i] == ')' or names[i] == '>' or names[i] == '}') bracket--; cerr.write(names, i) << " = "; print(head); if constexpr (sizeof...(tail)) cerr << " ||", printer(names + i + 1, tail...); else cerr << "]\n"; } template <typename T> void printerArr(const char *name, T arr[], size_t N) { cerr << name << " = {"; for (size_t i = 0; i < N; i++) cerr << (i ? "," : ""), print(arr[i]); cerr << "}"; cerr << "]\n"; }}
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__);
#define debugArr(arr, n) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#arr, arr, n);
#else
#define debug(...)
#define debugArr(arr, n)
#endif
#endif

int gcd(int a, int b) { if(a == 0) return b; return gcd(b%a, a);}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
//-----------------------------------------SuRaJ_GuPta+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void solve() {
   int n, d, h;
        cin >> n >> d >> h;
        vector<int> y(n);
        for(int i = 0; i < n; i++){
            cin >> y[i];
        }
        long double ans = (long double)d * h / 2.0;
        for (int i = 0; i + 1 < n; ++i) {
            if (y[i + 1] >= y[i] + h) ans += (long double)d * h / 2.0;
            else{
                long double d2 = (long double)d * (y[i] + h - y[i + 1]) / h;
                long double nh = y[i + 1] - y[i];
                ans += (d + d2) / 2.0 * nh;
            }
        }
        cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.precision(10); cout.setf(ios::fixed);
    int tc = 1;
    cin>>tc;
    while(tc--){
      solve();
    }
    return 0;
}
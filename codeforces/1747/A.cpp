/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
const char nl = '\n';

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define rep(i,a,b) for (int i=a; i<(b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= a; i--)
#define print_map(m) for (const auto &[key, value] : m){cout << '[' << key << ']' << ' ' << '=' << ' ' << value << '\n';}
#define print_vector(v)int vadnfiv=0;for (const auto &value : v){cout <<vadnfiv<<' '<<value<< '\n';vadnfiv++;}
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))

#define start_time using std::chrono::duration;using std::chrono::duration_cast;using std::chrono::high_resolution_clock;using std::chrono::milliseconds;auto t1111 = high_resolution_clock::now();
#define end_time auto t2222 = high_resolution_clock::now();duration<double, std::milli> ms_double = t2222 - t1111;std::cout << ms_double.count() << 'm'<<'s'<<nl;
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define multicase int NoOfTestCase = 1;cin >> NoOfTestCase;for(int testcaseno=1;testcaseno<=NoOfTestCase;testcaseno++)
bool isPrime(int n){if (n == 2 || n == 3){return true;}if (n <= 1 || n % 2 == 0 || n % 3 == 0){return false;}for (int i = 5; i * i <= n; i += 6){if (n % i == 0 || n % (i + 2) == 0){return false;}}return true;}
bool isPalindrome(string S){string P = S;reverse(P.begin(), P.end());if (S == P) {return true;}else {return false;}}
bool isPowerof(long long num, long long base){if (num <= 0){return false;}if (num % base == 0){return isPowerof(num / base, base);}if (num == 1){return true;}return false;}

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
fastio
multicase
{
long long n;
cin>>n;
long long sum=0;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    sum+=x;
}
cout<<abs(sum)<<nl;
}
return 0;
}
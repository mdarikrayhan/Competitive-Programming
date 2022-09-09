/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
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

    int n;
    cin >> n;

    int a[n], b[n];

    map<int, int> map1, map2, map3, map4;

    for (int i = 0; i < n; i++)
    {

        cin >> a[i];

        map1[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {

        cin >> b[i];

        map2[b[i]]++;
    }

    for (int i = 0; i < n; i++)
    {

        if (map1[a[i]] >= 1 && map2[a[i]] >= 1)
        {

            map1[a[i]]--, map2[a[i]]--;
        }
    }

    int op = 0;

    vector<int> odd, even;

    for (int i = 0; i < n; i++)
    {

        if (map1[a[i]] >= 1 && a[i] >= 10)
        {

            int el = a[i], cnt = 0;

            map1[el]--;

            while (el != 0)
            {

                cnt++;

                el /= 10;
            }

            odd.push_back(cnt);

            map3[cnt]++;

            op++;
        }

        else if (map1[a[i]] >= 1)
        {

            odd.push_back(a[i]);

            map1[a[i]]--;

            map3[a[i]]++;
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (map2[b[i]] >= 1 && b[i] >= 10)
        {

            int el = b[i], cnt = 0;

            map2[el]--;

            while (el != 0)
            {

                cnt++;

                el /= 10;
            }

            even.push_back(cnt);

            map4[cnt]++;

            op++;
        }

        else if (map2[b[i]] >= 1)
        {

            even.push_back(b[i]);

            map2[b[i]]--;

            map4[b[i]]++;
        }
    }

    int fnt = 0;

    for (int i = 0; i < odd.size(); i++)
    {

        if (map3[odd[i]] >= 1 && map4[odd[i]] >= 1)
        {

            map3[odd[i]]--;

            map4[odd[i]]--;

            fnt++;
        }
    }

    for (int i = 0; i < odd.size(); i++)
    {

        if (map3[odd[i]] != 0 && odd[i] != 1)
        {

            op++;

            map3[odd[i]]--;
        }
    }

    for (int i = 0; i < even.size(); i++)
    {

        if (map4[even[i]] != 0 && even[i] != 1)
        {

            op++;

            map4[even[i]]--;
        }
    }

    cout << op << endl;
}
return 0;
}
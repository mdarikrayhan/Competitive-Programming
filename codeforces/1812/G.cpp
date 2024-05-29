/***********************************************************************************
****    ______         _____       _______        _____        _____    ____    ****
****   |   _  |_    __|  _  |__   |   __  |_   __|  _  |__    |     \  /    |   ****
****   |  |_|  _|  |   _| |_   |  |  |__|  _| |   _| |_   |   |  |\  \/ /|  |   ****
****   |   ___|    |  |_____|  |  |      _|   |  |_____|  |   |  | \___/ |  |   ****
****   |  |        |   _____   |  |  |\  \    |   _____   |   |  |       |  |   ****
****   |__|        |__|     |__|  |__| \__\   |__|     |__|   |__|       |__|   ****
****                                                                            ****
***********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define Author_ParamSavjani ios_base::sync_with_stdio(0); cin.tie(0);

// Define type
#define ll long long
#define lli long long int
#define ull unsigned long long
#define dd double
#define ld long double

// Input
#define in(n) int n; cin >> n;
#define inll(n) ll n; cin >> n;
#define inarr(arr, n) int arr[n]; for (int i = 0; i < n; i++) cin >> arr[i];
#define outarr(arr, n) for (int i = 0; i < n; i++) cout << arr[i] << " ";
#define invector(v, n) vi v(n); for(int i=0; i<n; i++) cin>>v[i];

// Vector
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvs vector<vector<string>>

// Pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define ff first
#define ss second

// Push-Pop
#define pb push_back  // O(1)
#define pf push_front // O(1)
#define pob pop_back  // O(1)

// Loop
#define all(c) c.begin(), c.end()
#define allr(c) c.rbegin(),c.rend()
#define loop(i, in, n) for (int i = in; i < n; i++)
#define loopr(i, in, n) for (int i = in; i >= n; i--)
#define loopll(i, in, n) for (ll i = in; i < n; i++)
#define looplli(i, in, n) for (lli i = in; i >= n; i--)

// Sort
#define sort(v) sort(v.begin(),v.end())

// Precision
#define ps(x, y) fixed << setprecision(y) << x

// Binary-Search Related
#define ub upper_bound
#define lb lower_bound

// Cout
#define ptwo(n,k) cout<<n<<" "<<k<<endl;
#define parr(arr,low,high) for(int i =low;i<high;i++) cout<<arr[i]<<" ";

// Extra
#define mod 1000000007
#define yes cout << "YES" <<endl;
#define no cout << "NO" <<endl;
#define TEST  long long t;cin >> t;  while (t--)
#define PI 3.14159265358979323846264338327950288
#define EPS 1e-9
#define inf 1e18
#define mod 1000000007

void solve() {
    int t, n;
    {
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        bool good = true;
        for (int i = 0; i < s1.size(); i++)
        {
            if ((s1[i] == 'R') != (s2[i] == 'R'))
            {
                good = false;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }
}

int main() {
    Author_ParamSavjani
    int testcase;
    cin >> testcase;
    // testcase=1;
    while (testcase--) {
        solve();
    }
    return 0;
}
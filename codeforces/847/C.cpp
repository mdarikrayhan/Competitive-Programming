#include <bits/stdc++.h> 

using namespace std;

#define int long long
#define deb(x) cout << #x << " = " << x << endl;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define fo(i, j) for(i=0;i<j;i++)
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i++:i--)

#define imax INT_MAX
#define imin INT_MIN
#define PI 3.1415926535897932384626433832795
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
#define sortall(x) sort(all(x))

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

void WVI(VI ar){
    int i;
    fo(i, ar.size()){
        cout << ar[i] << " ";
    }cout << endl;
}

void setIO(string name){
    ios_base::sync_with_stdio(0);cin.tie(0);
    if(!name.empty()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
#define here cout << "-----PASS-----" << endl;
const int mxN = 1e5+5;
const int MOD = 998244353;
const int INF = 4e18+50;

//*********************************************************************************


void solve(){
    int n, k; cin >> n >> k;
    int stack = 0;
    int i=0;
    for(;i<n;i++) {
        stack+=i;
        if(stack+i+1>k) break;
    }
    n-=i+1;
    k-=stack;

    string ans ="";

    for(int j=0;j<=i;j++) {
        ans+="(";
    }

    for(;i>=0;i--){
        ans += ")";
        if(i==0) break;
        //cout << n << " " << k << " " << i << endl;
        while(n>0&&k-i>=0) {
            ans += "()";
            n--;
            k-=i+1;
        }
    }
    if(k>0) {
        cout << "Impossible" << endl;
        return;
    }

    cout << ans;
    while(n--) cout << "()";
    cout << endl;


}

int32_t main(){
    string name = "";
    setIO(name);
    int test_cases = 1;
    //cin >> test_cases;
    while(test_cases--) {
        solve(); //cout << endl;
    }

    return 0; 
}
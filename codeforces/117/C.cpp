#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvpi = vector<vpi>;
// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define er erase
#define ub upper_bound
#define lb lower_bound

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!=

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
using indexed_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order

void solve(){
    int n;
    cin >> n;
    vector<vb> l(n + 1, vb(n + 1));
    vpi io(n + 1);
    F0R(i, n){
        str s;
        cin >> s;
        F0R(j, n) {
            l[i][j] = (s[j] == '1');
            io[i].f += l[i][j];
            io[i].s += (!l[i][j]);
        }
    }
    F0R(i, n){
        F0R(j, n){
            if(i == j || !l[i][j] || (io[i].f > io[j].f))continue;
            //cout << io[i].f << " " << io[j].f <<  "\n";
            F0R(k, n){
                if(k == i || k == j)continue;
                if(l[j][k] && l[k][i]){
                    cout << i + 1 << " " << j + 1 << " " << k + 1<< "\n";
                    return;
                }
            }
        }
    }
    cout <<  -1 << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; t = 1;while(t--){
        solve();
    }
    return 0;
}

 		  			 	  	 		     	  		  		
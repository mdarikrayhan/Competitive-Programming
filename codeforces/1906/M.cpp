#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long int
#define ll long long
#define double long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define fm(i,a,b) for(int i=b-1;i>=a;i--)
#define input(a) for(auto &x:a) cin>>x
#define all(x) x.begin(),x.end()
#define rsort(c) sort(all(c)); reverse(all(c))
#define sz(c) (int)c.size()
#define print_v(a) for(auto x : a) cout << x << " "; cout << endl
#define print_p(a) for(auto x : a) cout << x.first << " " << x.second << endl
#define print_vij(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define print_mat(a) for(auto x:a){ print_v(x); } cout<<endl
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define atharv main
#define PY cout << "YES\n"
#define PN cout << "NO\n"
#define Py cout << "Yes\n"
#define Pn cout << "No\n"
#define se second
#define fe first
#define lc "\n"

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef map<int, int> mi;

const int mod = 1e9 + 7;
const int inf  = 1e18;
const int minf = - inf;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC, typename typD> istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template<typename typC> istream &operator>>(istream &cin, vector<typC> &a) { for (auto &x : a) cin >> x; return cin; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) { for (auto &x : a) cout << x << '\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout, const vector<typC> &a) { int n = a.size(); if (!n) return cout; cout << a[0]; for (int i = 1; i < n; i++) cout << ' ' << a[i]; return cout; }
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ===================================END Of the input module ==========================================

void codeInEditor() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif
}

// ............Solution starts here.............. //


void sol() {

    int n;
    cin >> n;

    vi arr(n);
    cin >> arr;

    sort(all(arr));

    int sum = 0;

    f(i, 0, n-1){
        sum += arr[i];
    }

    int m = arr[n-1];

    if(m > 2 * sum){
        cout << sum << lc;
    }
    else{
        cout << (sum + m)/3 << lc;
    }

	// cout << fixed << setprecision(6) << x << endl;
}

// ............ Code by atharv ................ //

signed atharv() {
	// codeInEditor();

	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	// 	t = 1;

	while (t--) {
		sol();
	}

	return 0;
}



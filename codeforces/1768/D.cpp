#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL) , cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int , int> >
#define vc vector<char>
#define vvc vector<vector<char> >
#define pii pair<int , int>
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pb push_back
#define ff first
#define ss second
#define fr(i,n) for(int i=0; i<(n); i++)
#define dbg(var) cout<<#var<<" : "<<var<<"\n"
#define all(v) v.begin(),v.end()
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define set_bits(x) __builtin_popcountll(x)  // number of set bits
#define first_set(x) __builtin_ctzll(x)      // ...001000 -> 3 
#define last_set(x) __builtin_ctzll(x)       // 00010000 00000000 00000000 00000000 -> 3 (for 32 bit int), not very useful tho

using namespace std;
const int MOD=1e9+7;      // Hardcoded, directly change from here for functions!

// to get a random number in the range (0 , M-1)
// mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
// int B = uniform_int_distribution<ll>(0, M - 1)(rng);

// using namespace __gnu_pbds;
using __gnu_pbds::tree;
using __gnu_pbds::rb_tree_tag;
using __gnu_pbds::tree_order_statistics_node_update;
using __gnu_pbds::null_type;

// _GLIBCXX_DEBUG must not be defined otherwise some internal check will fail
#undef _GLIBCXX_DEBUG

template <typename K, typename V, typename Comp = less<K>>
using indexed_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename Comp = less<K>>
using indexed_set = indexed_map<K, null_type, Comp>;

// ¡¡IMPORTANT!! (for using less_equals<K>)
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for erase use: any.erase(any.find_by_order(any.order_of_key(val)));
// don't use .find() because it will always return .end()
template <typename K, typename V, typename Comp = less_equal<K>>
using indexed_multimap = indexed_map<K, V, Comp>;

template <typename K, typename Comp = less_equal<K>>
using indexed_multiset = indexed_map<K, null_type, Comp>;

// find_by_order(k): returns an iterator to the (k+1)-th largest element (0-based)
// order_of_key(num):  #elements in the set strictly smaller "num"

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const set<typC> &a) { for (auto it:a) cout<<it << " "; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const multiset<typC> &a) { for (auto it:a) cout<<it << " "; return cout; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const map<typC , typD> &m) { for (auto it:m) cout<<it.ff << " : " << it.ss << endl; return cout; }
// ===================================END Of the input module ==========================================

void solve(){
    int n;
    cin >> n;
    vi a(n+1 , 0);
    for(int i=1;i<=n;i++)cin >> a[i];

    // main idea: if you have to get to a specific permutation, think of it as cycles
    // now, for it to be a reqd permutation, only one i should be ..[i+1 , i].. (obvious)
   	// so, my idea was to check for each i(correct but no idea how to proceed)
    // THINK OF PERMUTATION AS CYCLES, if(i , i+1) are in the same cycle => #cycles++;
    // else #cycles--;  [nice proof]
    // (For implementation, used the "DSU" idea, or, just numbered the cycles)
    // ans = n - #cycles

    // I didn't search in google
    // i thought min swaps reqd to sort a permutation is to just naively swap if not in correct position
    // but GFG => ans = n - #cycles  

	vi ult_par(n+1);
	for(int i=1;i<=n;i++)ult_par[i] = i;

	int cycles = 0;
    for(int i=1;i<=n;i++){
    	if(ult_par[i] == i){
    		// start a loop here
    		cycles++;
    		int x = i;
    		while(1){
    			x = a[x];
    			ult_par[x] = i;
    			if(x == i)break;
    		}
    	}
    }

    for(int i=1;i<=n-1;i++){
    	if(ult_par[i] == ult_par[i+1]){
    		cout << n - (cycles+1) << endl;
    		return;
    	}
    }

    cout << n - (cycles-1) << endl;

    // CLEAR ALL GLOBAL VARIABLES(use it at the end/start of this function)
}

int32_t main()
{
    FAST;

    int T;
    cin >> T;
    for (int _=1;_<=T;_++)
    {
        // cout << "Case #" << _ << ": " << endl;
        solve();
    }
    return 0;
}

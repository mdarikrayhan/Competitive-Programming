#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL) , cout.tie(NULL)
#define endl "\n"
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

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
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
    int n , k;
    cin >> n >> k;

    // idea 1: maximum number of unique palindromes in length n is n
  	// idea 2: how to stop palindromes "abcabcabc..."
  	// so, each time if(req > len)cout "NO"!! ELSE  add "reqd" number of char "ch", then add "abcabc.." to the remaining len
    // i == 0 case is slightly different because "b" and "c" count as unique palindromes too (good since x1,c1 >= 0) 

    // ex: if x = {2 , 4} and c = {1 , 4} isn't possible since can't add > 1 "unique" palindrome thorough each character
    // easy proof: if with si added, s[j..i] and s[k..i] are both palindromes => only the smallest "k" forms a "unique palindrome" 

    vi x(k) , c(k);
    cin >> x >> c;
    char ch = 'd';

    char kk;

    string s;
    fr(i,k){
    	int len = x[i];
    	if(i>0)len -= x[i-1];
    	int req = c[i];
    	if(i>0)req -= c[i-1];

    	// dbg(len);
    	// dbg(req);

    	if(req > len){
    		cout << "NO" << endl;
    		return;
    	}
    	// len >= req
    	if(i == 0){
    		// here, req >= 3
    		for(int j=0;j<req-2;j++)s += 'a';
    		
    		char y = 'a';
    		for(int j=0;j<len- (req-2);j++){
				if(y == 'c')s += 'a';
				else if(y == 'b')s += 'c';
				else s += 'b';
				y = s.back();
			}
    		// dbg(s);
    		kk = s.back();
    		continue;
    	}

    	for(int j=0;j<req;j++)s += ch;
    	ch++;

    	char x = kk;
    	for(int j=0;j<len-req;j++){
			if(x == 'c')s += 'a';
			else if(x == 'b')s += 'c';
			else s += 'b';
			x = s.back();
		}	
		if(len != req)kk = s.back();
		// dbg(s);
    }

    cout << "YES" << endl;
    cout << s << endl;

    // CLEAR ALL GLOBAL VARIABLES
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

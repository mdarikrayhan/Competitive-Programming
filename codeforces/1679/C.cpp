#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
// #define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long
 
// typedef long long int;
typedef unsigned long long ull;
typedef long double lld;
 
 
 
// -------------------------ORDERED_SET-----------------------------------------------------
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
 
// -------------------DEBUG---------------------------------------------
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
// void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
#define YES cout<<"Yes"<<"\n"
#define NO  cout<<"No"<<"\n"
// ------------------------------------------------------------------------------------------------------


void solve(){ 
	int n;
	cin>>n;
	int q;
	cin>>q;
vector<int>row(n+1,0);
vector<int>col(n+1,0);
set<int>r,c;
for(int i=1;i<=n;i++){
	r.insert(i);
	c.insert(i);
}

while(q--){

	int t;
	cin>>t;
	debug(t);
	if(t==1){
		int x,y;
		cin>>x>>y;
		row[x]++;
		if(r.find(x)!=r.end()){
			r.erase(x);
		}
		col[y]++;
		if(c.find(y)!=c.end()){
			c.erase(y);
		}
	}
	else if(t==2){
		int x,y;
		cin>>x>>y;
		row[x]--;
		if(row[x]==0){
			r.insert(x);
		}
		col[y]--;
		if(col[y]==0){
			c.insert(y);
		}

	}
	else{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		auto it1=r.lower_bound(min(x1,x2));
		auto it2=c.lower_bound(min(y1,y2));
		if(it1==r.end()||*it1>max(x1,x2)){
			YES;

		}
		else if(it2==c.end()||*it2>max(y1,y2)){
			YES;

		}
		else{
			NO;
		}
	}
}

}

	
    
   
   




	



	
	
 
 
 
 
 
 
		
 
 
 
	
	
 
	
 
 
	
	
	
	
	
 
	
 
	
	
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  int32_t main(){
  #ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
	
#endif
	 fastio();
 
    int _=1;
    // cin>>_;  
    while(_--){
        solve(); 
    }
    return 0;
 
}
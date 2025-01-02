#include<bits/stdc++.h>

using namespace std;

//remove fastio in interactive problems
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long >
#define vc vector<char>
#define vf vector<float>
#define vd vector<double>
#define vst vector<string>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"<<endl;}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}

vector<ll> divisors(ll n)
{
	//excluding 1 and n 
	// if need to use then push in vector 1 and n
	vector<ll> res;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			res.pb(i);
			if((n/i)!=i)
			{
				res.pb(n/i);
			}
		}
		return res;
	}
}
void primeSieve()
{
	
}

//for interactive problem


// int n;
// map<int ,int > prev_values;
// int query(int index)
// {
// 	if(prev_values.contains(index))
// 	{
// 		return prev_values[index];
// 	}
// 	if(index==0 or index==n+1)
// 	{
// 		return INT_MAX;
// 	}
// 	cout<<"? "<<index<<endl;
// 	int val;
// 	cin>>val;
// 	return prev_values[index]=val;
// }

// -----------------------------Start Code---------------------------------------------------------------


int main() 
{

#ifndef ONLINE_JUDGE
 freopen("error.txt", "w", stderr);
#endif

freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);


int n;
cin>>n;
vi arr;
for(int i=0;i<n;i++)
{
	int val;
	cin>>val;
	arr.pb(val);	
}
sort(all(arr));
int i=0;
int ans=-1;

for(int j=0;j<n;j++)
{
	while(arr[j]>2*arr[i])
	{
		i++;
	}
	int len=j-i+1;
	ans=max(ans,len);
}
cout<<n-ans<<endl;

}
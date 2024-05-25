#include<bits/stdc++.h>
using namespace std;
#define int long long


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// // order_of_key(k) : no. of elements < k
// // *find_by_order(i) : value at index i (0-based)

//typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef map<char,int> mc;
#define py cout<<"Yes\n";
#define pn cout<<"No\n";
#define endl "\n";
#define all int i=0;i<n;i++
#define allj int j=0;j<n;j++
#define all1 int i=1;i<=n;i++
#define all1j int j=1;j<=n;j++
#define allm int i=0;i<m;i++
#define sorti(v) sort(v.begin(),v.end());
#define sortig(v) sort(v.begin(),v.end(),greater<int>());
#define take int n;cin>>n;int a[n]; for(all){cin>>a[i];}
#define show(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
#define mnv(v) *min_element(v.begin(), v.end());
#define mxv(v) *max_element(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define set_bits __builtin_popcountll
#define debug(x) cerr<<#x<<" is "; _print(x); cerr<<endl;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 

const int N=1e9+7; //largeprime
//int N=998244353;
const int inf=1e18;
const int NN=1e5+10;
const int sis=2e5+7;


int n,tot;
vii v;

bool check(int x){
    vii vv;
    for(auto y:v){
        if(y.first >= x){
            vv.push_back({y.second,y.first});
        }
    }
    sorti(vv);
    int sum = 0;
    int cnt = 0;
    for(auto x:vv){
        if(x.first + sum <= tot){
            sum += x.first;
            cnt++;
        }
    }

    return cnt >= x;
}

vi get(int x){
    vector<pair<ii,int>> vv;
    for(int i = 0; i < n; i++){
        if(v[i].first >= x){
            vv.push_back({{v[i].second,v[i].first},i});
        }
    }
    sort(vv.begin(),vv.end());
    int sum = 0;
    vi ans;
    for(int i = 0; i < vv.size(); i ++){
        if(vv[i].first.first + sum <= tot){
            sum += vv[i].first.first;
            ans.push_back(vv[i].second);
            if(ans.size() == x){
                break;
            }
        }
    }

    return ans;
}

void solve(){
    cin>>n>>tot;

    for(all){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }

    int low = 0;
    int high = 1e18;

    while(high - low > 1){
        int mid = (low + high)/2;
        if(check(mid)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }

    if(check(high)){
        low = high;
    }

    cout<<low<<endl;
    vi ans = get(low);
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x + 1<<" ";
    }
}

int t=1;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t; cin>>t;
    while(t--){
        solve();
    }
}


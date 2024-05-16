#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define int ll
#define tc int TEST_CASES; cin >> TEST_CASES; while(TEST_CASES--)
#define qc int QUERY; cin >> QUERY; while(QUERY--)
#define next continue
#define nxt continue
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define all(v,x,y) v.begin() + x,v.end() + y
#define allr(v) v.rbegin(),v.rend()
#define ones(x) __builtin_popcount(x)
#define bit_length(x) log2(x) + 1
#define YN(x,a,b) (x == 1 ? a : b)

const double PI = acos(-1);
string line;

// useful input/output functions

// cin >> pair
template<typename T,typename E>
istream& operator >>(istream& cin,pair<T,E>& p){
    cin >> p.first >> p.second;
    return cin;
}

// cout << pair
template<typename T,typename E>
ostream& operator <<(ostream& cout,pair<T,E>& p){
    cout << p.first << ' ' << p.second;
    return cout;
}

// cin >> vector
template<typename T>
istream& operator >>(istream& cin,vector<T>& v){
    for(int i = 0;i < v.size();i++){
        cin >> v[i];
    }
    return cin;
}

// cout << vector
template<typename T>
ostream& operator <<(ostream& cout,vector<T>& v){
    for(int i = 0;i < v.size();i++){
        cout << v[i] << line;
    }
    return cout;
}

// cin >> set;
template<typename T>
istream& operator >>(istream& cin,set<T>& st){
    int size = *st.begin();
    st.clear();
    for(int i = 0;i < size;i++){
        int val; cin >> val;
        st.insert(val);
    }
    return cin;
}


template <class T>
vector<pair<T, ll>> factors(T x) {
    vector<pair<T, ll>> v;
    int t = 0;
    while (x % 2 == 0) {
        x /= 2;
        t++;
    }
    if (t > 0) v.push_back({ 2, t });
    for (T i = 3; i * i <= x; i += 2) {
        t = 0;
        while (x % i == 0) {
            x /= i;
            t++;
        }
        if (t > 0) v.push_back({ i, t });
    }
    if (x > 1) v.push_back({ x, 1 });
    return v;
}

int bpow(int b, int p, int mod) {
    if (p == 0) return 1;
    int e = 1;
    while (p > 1) {
        if (p & 1) {
            e = e * b % mod;
            p--;
        }
        b = b * b % mod;
        p /= 2;
    }
    b = b * e % mod;
    return b;
}

//m*(n/m)*(n/m+1)/2

int nCr(int n, int r) {
    int x = 1;
    for(int j = 0; j < min(r, n - r); j++){
        x = x * (n - j) / (j + 1);
    }
    return x;
}

int32_t main() {
    FAST
    line = ' ';
   
   
   tc{
       int n,x; cin >> n >> x;
       cout << x * 2 << endl;
   }
   
    return 0;
}

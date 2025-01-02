#include<bits/stdc++.h>
using namespace std;

/* clang-format off */
namespace _DEBUG_UTIL_ { void print(const char *x) {} void print(bool x) { cerr << (x ? "T" : "F"); } void print(char x) { cerr << '\'' << x << '\''; } void print(signed short int x) { cerr << x; } void print(unsigned short int x) { cerr << x; } void print(signed int x) { cerr << x; } void print(unsigned int x) { cerr << x; } void print(signed long int x) { cerr << x; } void print(unsigned long int x) { cerr << x; } void print(signed long long int x) { cerr << x; } void print(unsigned long long int x) { cerr << x; } void print(float x) { cerr << x; } void print(double x) { cerr << x; } void print(long double x) { cerr << x; } void print(string x) { cerr << '\"' << x << '\"'; } template <size_t N> void print(bitset<N> x) { cerr << x; } void print(vector<bool> x) { int f = 0; cerr << '{'; for (bool i : x) { cerr << (f++ ? "," : ""); cerr << (i ? "T" : "F"); } cerr << "}"; } /* Template Datatypes Declarations */ template <typename T> void print(T x); template <typename T> void print(vector<vector<T>> mat); template <typename T, size_t N> void print(T (&arr)[N]); template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]); template <typename F, typename S> void print(pair<F, S> x); template <typename T> void print(priority_queue<T> pq); template <typename T> void print(priority_queue<T, vector<T>, greater<T>> pq); template <typename T> void print(stack<T> st); template <typename T> void print(queue<T> q); /* Template Datatypes Definitions */ template <typename T> void print(T x) { int f = 0; cerr << '{'; for (auto i : x) cerr << (f++ ? "," : ""), print(i); cerr << "}"; } template <typename T> void print(vector<vector<T>> mat) { int f = 0; cerr << "{\n"; for (auto i : mat) cerr << (f++ ? ",\n" : ""), print(i); cerr << "}\n"; } template <typename T, size_t N> void print(T (&arr)[N]) { int f = 0; cerr << '{'; for (auto &i : arr) cerr << (f++ ? "," : ""), print(i); cerr << "}"; } template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]) { int f = 0; cerr << "{\n"; for (auto &i : mat) cerr << (f++ ? ",\n" : ""), print(i); cerr << "}\n"; } template <typename F, typename S> void print(pair<F, S> x) { cerr << '('; print(x.first); cerr << ','; print(x.second); cerr << ')'; } template <typename T> void print(priority_queue<T> pq) { int f = 0; cerr << '{'; while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop(); cerr << "}"; } template <typename T> void print(priority_queue<T, vector<T>, greater<T>> pq) { int f = 0; cerr << '{'; while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop(); cerr << "}"; } template <typename T> void print(stack<T> st) { int f = 0; cerr << '{'; while (!st.empty()) cerr << (f++ ? "," : ""), print(st.top()), st.pop(); cerr << "}"; } template <typename T> void print(queue<T> q) { int f = 0; cerr << '{'; while (!q.empty()) cerr << (f++ ? "," : ""), print(q.front()), q.pop(); cerr << "}"; } /* Printer */ template <typename T> void printer(const char *name, T &&head) { cerr << name << " = "; print(head); cerr << "]\n"; } template <typename T, typename... V> void printer(const char *names, T &&head, V &&...tail) { int bracket = 0, i = 0; while (names[i] != ',' or bracket != 0) { if (names[i] == '(') bracket++; else if (names[i] == ')') bracket--; i++; } cerr.write(names, i) << " = "; print(head); cerr << " ||"; printer(names + i + 1, tail...); } /* PrinterArr */ template <typename T> void printerArr(const char *name, T arr[], int N) { cerr << name << " : {"; for (int i = 0; i < N; i++) { cerr << (i ? "," : ""), print(arr[i]); } cerr << "}]\n"; } }
#ifndef ONLINE_JUDGE
#define debug(...) cerr << __LINE__ << ": [", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__) 
#define debugArr(arr, n) cerr << __LINE__ << ": [", _DEBUG_UTIL_::printerArr(#arr, arr, n) 
#else
#define debug(...)
#define debugArr(arr, n)
#endif
/* clang-format on */

#define int long long
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<< #x <<" : "<<(x)<<endl;
#define dbgv(v) cout<< #v <<" : ";for(auto &i:v) cout<<(i)<<" ";cout<<endl;
void solve(){
    int n,k;cin>>n>>k;
    vector<vector<int>> adj(n);
    vector<int> d(n);
    vector<pair<int,int>> edges(n-1);
    map<pair<int,int>,int> mp;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++;
        d[v]++;
        edges[i-1]  = {min(u,v),max(u,v)};
    }
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {v[i] = {d[i],i};}
    sort(all(v));
    int p = -1;
    for(int i=0;i<n;i++)
    {
        if((i == n-1 || (v[i+1].first > v[i].first)) && (n-(i+1) <= k)){
            p = i;
            break;
        }
    }
    if(p == -1){
        cout<<1<<endl;
        for(int i=1;i<n;i++) cout<<"1 ";
        cout<<endl;
        return;
    }
    vector<int> good(n);
    for(int i=0;i<=p;i++) good[v[i].second] = 1;
    int ans = v[p].first;
    function<void(int,int,int)> dfs = [&](int r,int p,int per){
        int cur = 1;
        for(int i:adj[r]) if(i != p){       
            if(cur == per) {cur++;}
            int assgn = -1;
            if(good[r]){
                assgn = cur;
                cur++;
            }   
            else{
                assgn = per;
            }
            mp[{min(i,r),max(i,r)}] = assgn;
            dfs(i,r,assgn);
        }
    };
    dfs(v[p].second,-1,-1);

    cout<<ans<<endl;
    for(auto pr:edges){
        cout<<mp[pr] << " ";
    }
    cout<<endl;




}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
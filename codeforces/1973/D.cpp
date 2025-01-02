#include "bits/stdc++.h"
#define pb push_back
#define endl '\n'
#define mp make_pair
#define pb push_back
using namespace std;;void __print(const int& x) {cerr << x;};void __print(const long& x) {cerr << x;};void __print(const long long& x) {cerr << x;};void __print(const unsigned& x) {cerr << x;};void __print(const unsigned long& x) {cerr << x;};void __print(const unsigned long long& x) {cerr << x;};void __print(const float& x) {cerr << x;};void __print(const double& x) {cerr << x;};void __print(const long double& x) {cerr << x;};void __print(const char& x) {cerr << '\'' << x << '\'';};void __print(const char *x) {cerr << '\"' << x << '\"';};void __print(const string &x) {cerr << '\"' << x << '\"';};void __print(const bool& x) {cerr << (x ? "true" : "false");};template<typename T> concept Container = requires(T t) { begin(t); end(t); size(t); };void __print(const stack<auto>& s);void __print(const deque<auto>& x);void __print(const queue<auto>& q);void __print(const pair<auto, auto>& p);template <Container C> void __print(const C& c);;        void __print(const stack<auto>& s) {;            auto c = s; ;            cerr<<"{STACK_TOP  ";;            while(c.size()) {;                auto v=c.top();;                c.pop(); ;                __print(v);;                cerr<<(c.size()?",":"");;            };            cerr<<"}";;        };    ;;        void __print(const queue<auto>& q) {;            auto c = q;;            cerr<<"{QUEUE_FONT ";;            while(c.size()) {;                auto v=c.front();;                c.pop();;                __print(v);;                cerr<<(c.size()?",":"");;            };            cerr<<"}";;        };    ;;        void __print(const deque<auto>& x) {;            cerr<<"{"; ;            for(auto& v: x) {;                __print(v);;;                if(&v != &x.back()) cerr<<","; ;            };            cerr<<"}";;        };    ;void __print(const pair<auto, auto> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';};template <Container C> void __print(const C &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";};void _print() {cerr << "]\n";};template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);};auto min_many(auto a) {return a;};auto min_many(auto a, auto b, auto... c) {return min_many(std::min(a,b),c...);};auto max_many(auto a) {return a;};auto max_many(auto a, auto b, auto... c) {return max_many(std::max(a,b),c...);};typedef complex<double> cd;typedef complex<long double> cld;typedef unsigned int ui;typedef unsigned long long ull;typedef long long ll;typedef vector<int> vi;typedef vector<bool> vb;typedef vector<long long> vll;typedef vector<vector<int>> vvi;typedef vector<vector<long long>> vvll;typedef pair<int, int> pii;typedef pair<long long, long long> pll;typedef vector<pair<int, int>> vpii;typedef vector<vector<pair<int, int>>> vvpii;typedef vector<pair<long long, long long>> vpll;typedef vector<vector<pair<long long, long long>>> vvpll;
#ifdef ONLINE_JUDGE
    # define debug(x...)
    # define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#else
    # define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    # define fastio
#endif

int find_max(int N) {
    for(int i=1;i<=N;i++) {
        cout<<"? "<<1<<" "<<i*N<<endl;
        cout.flush();
        int ret; cin>>ret;
        if(ret == N) {
            return i;
        }
    }
}

bool test_ans(int M, int N, int K) {
    int last = 1;
    while(K != 0) {
        if(last == N+1) {
            return false;
        }
        cout<<"? "<<last<<" "<<M<<endl;
        cout.flush();
        int ret; cin>>ret;
        if(ret == N+1) {
            return false;
        }
        last = ret+1;
        K--;
    }
    return (last==N+1);
}

int find_ans(int maxe, int N, int K) {
    int best = -1;
    for(int mgsize=1;mgsize<=N/K;mgsize++) {
       int M = maxe * mgsize; 
       if(test_ans(M, N, K)) {
           best = max(best, M); 
       }
    }
    return best;
}

int main() {
    fastio;
    int T; cin>>T;
    for(int tc=0;tc<T;tc++) {
        int N,K; cin>>N>>K;
        int maxe = find_max(N); 
        debug(maxe);
        int ans = find_ans(maxe, N, K);
        cout<<"! "<<ans<<endl;
        cout.flush();
        int ret; cin>>ret;
        if(ret != 1) return -1;
    }
}

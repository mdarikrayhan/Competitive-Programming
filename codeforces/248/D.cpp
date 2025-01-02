/**
 *    author:  BaN
 *    link:
**/

#include<bits/stdc++.h>

using namespace std;

//debugger
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//template
#define foru(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define pil pair <int, ll>
#define pli pair <ll, int>
#define pll pair <ll, ll>
#define vii vector <pii>
#define vi vector <int>
#define all(A) A.begin(), A.end()
#define S second
#define F first
#define PB push_back
#define BIT(x, i) ((x >> i) & 1)
#define task "a"

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, t, szH, szS, maxH;
vi H, S;

void Read(){
    cin >> n >> t;
    foru(i, 1, n){
        char c;
        cin >> c;
        if (c == 'H') H.PB(i), maxH = i;
        if (c == 'S') S.PB(i);
    }
}

bool Check(int mid){
    int needed = 0;
    int min_needed = 2*n;
    for (int i=mid;i<szH;i++){
            if (min_needed>needed+max(0,2*(S[szH-1-mid]-maxH))+2*maxH-H[i]) min_needed = needed+max(0,2*(S[szH-1-mid]-maxH))+2*maxH-H[i];
            needed+= 2*max(0,min(H[i+1]-H[i],S[i-mid]-H[i]));
    }
    min_needed = min(min_needed, needed + maxH);
//    debug(min_needed);
    return (min_needed <= t);
}

void Solve(){
    szH = H.size(), szS = S.size();
    H.PB(MOD);
    if (t < maxH){
        cout << -1;
        return;
    }
    int l = -1, r = szH + 1;
    if (szH>szS) l = szH-szS -1;
    while (r - l > 1){
        int mid = (r + l) / 2;
        if (Check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(fopen(task".inp", "r")){
        freopen( task".inp", "r", stdin );
        freopen( task".out", "w", stdout );
    }
    Read();
    Solve();
    return 0;
}

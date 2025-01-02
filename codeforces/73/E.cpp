#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll,ll> pll;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;

#define forr(_a,_b,_c) for(int _a = (_b); _a <= (_c); ++_a)
#define ford(_a,_b,_c) for(int _a = (_b) + 1; _a --> (_c);)
#define forf(_a,_b,_c) for(int _a = (_b); _a < (_c); ++_a)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define mask(i) (1LL << (i))
#define bit(x, i) (((x) >> (i)) & 1)
#define bp __builtin_popcountll
#define file "test"

const int N = 5e5 + 5;
const ll oo = 1e9;
const ll mod = 1e9 + 7; // 998244353;
const int M = 14e5;

int n, a[N], x;
int f[M + 5];
map <int, int> g;
vector <int> v;

void sieve (){
    forr (i, 2, M){
        if (!f[i]){
            for (int j = i * 2; j <= M; j += i)
                f[j] = 1;
            v.pb(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef hqm
        freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    #endif

    cin >> n >> x;

    if (x == 2){
        cout << 0;
        return 0;
    }

    forr (i, 1, n){
        cin >> a[i];
        g[a[i]] = 1;
        if (a[i] == 1){
            cout << 1;
            return 0;
        }
    }


    sieve();
    
    for (int i = 0; i < v.size(); i++){
        if (v[i] >= x){
            cout << i;
            return 0;
        }
        if (!g[v[i]]){
            cout << "-1";
            return 0;
        }
    }


    return 0;
}
/*



*/


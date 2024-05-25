#include<bits/stdc++.h>

using namespace std;

void process();

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #define TASK ""
    if(fopen(TASK".inp","r")) {
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }

    if(fopen("main.inp","r")) {
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    srand(time(0));

    process();

    cerr << "\n" << (double)clock() / CLOCKS_PER_SEC * 1000 << "ms";
    return 0;
}

long long Rand(long long L,long long R) {
    return rand() % (R - L + 1) + L;
}

#define fi first
#define se second
#define BIT(i) (1LL << (i))
#define GBIT(mask,i) (((mask) >> (i)) & 1)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define sz(v) ((int)v.size())
#define forr(i,a,b,d) for(int i = a; i <= b; i += d)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD = 1e9 + 7;
const int inf = 2e9 + 7;
const long long infll = 1e18 + 7;

template<class T1,class T2> bool maximize(T1 &a,T2 b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T1,class T2> bool minimize(T1 &a,T2 b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T1,class T2> void add(T1 &a,T2 b) {
    ll t = a + b;
    if(t >= MOD) t -= MOD;
    if(t < 0) t += MOD;
    a = t;
}

template<class T1,class T2> void sub(T1 &a,T2 b) {
    ll t = a - b;
    if(t >= MOD) t -= MOD;
    if(t < 0) t += MOD;
    a = t;
}

#define MAX

ll n,q;

void process() {
    cin >> n >> q;
    while(q--) {
        ll x;
        cin >> x;
        while(x % 2 == 0) {
            x = n + x / 2;
        }
        cout << (x + 1) / 2 << "\n";
    }
}


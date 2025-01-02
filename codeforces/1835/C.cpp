//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define fi first
#define se second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

template<typename T>
bool umin(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool umax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#ifdef KIVI
#define DEBUG for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl

template<class ...Ts>
auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }

#else
#define DEBUG while (false)
#define LOG(...)
#endif

mt19937 rng(4242);

const int max_n = -1, inf = 1000111222;

void solve() {
    int k;
    cin >> k;
    int n = (1 << (k + 1));
    vector<ll> a(n);
    vector<ll> pxor1(n), pxor2(n);
    map<ll, int> last_pos;
    map<ll, vector<pair<int, int> > > av;
    last_pos[0] = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i) {
            pxor1[i] = pxor1[i - 1];
            pxor2[i] = pxor2[i - 1];
        }
        pxor1[i] ^= a[i];
        pxor2[i] ^= (a[i] % (1 << k));
        auto it = last_pos.find(pxor2[i]);
        if(it != last_pos.end()) {
            int l = it->se + 1;
            int r = i;
            av[pxor1[r] ^ (l == 0 ? 0 : pxor1[l - 1])].pb({l, r});
        }
        last_pos[pxor2[i]] = i;
    }
    for(auto& x : av) {
        if(len(x.se) < 2) continue;
        int l1, r1, l2, r2;
        tie(l1, r1) = x.se[0];
        tie(l2, r2) = x.se[1];
        if(l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        if(r1 >= l2) {
            vector<int> kek(n);
            for (int i = l1; i <= r1; i++) kek[i]++;
            for (int i = l2; i <= r2; i++) kek[i]++;
            l1 = -1, l2 = -1;
            for (int i = 0; i < n; i++) {
                if (kek[i] != 1) continue;
                int l = i;
                while (i + 1 < n && kek[i + 1] == 1) i++;
                int r = i;
                if (l1 == -1) l1 = l, r1 = r;
                else l2 = l, r2 = r;
            }
        }
        cout << l1 + 1 << ' ' << r1 + 1 << ' ' << l2 + 1 << ' ' << r2 + 1 << '\n';
        return;
    }
//    assert(false);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    cin >> t;

    while (t--) solve();

}

/*
KIVI
*/

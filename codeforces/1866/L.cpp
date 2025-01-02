#include "bits/stdc++.h"
using namespace std;

typedef long long           lol;
typedef std::pair<int,int>  pii;
#define pb                  push_back
#define ub                  upper_bound
#define lb                  lower_bound
#define fo(i,l,r,d)         for (auto i=(l); (d)<0?i>(r):((d)>0?i<(r):0); i+=(d))
#define all(x)              x.begin(), x.end()
#define ff                  first
#define ss                  second

std::mt19937 rng (std::chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> std::ostream& operator<< (std::ostream &cout, const std::pair<A, B> &p) { return cout << p.first << ' ' << p.second; } template <typename A, size_t n> std::ostream& operator<< (std::ostream &cout, const std::array<A, n> &v) { for (int i = 0; i < int(n) - 1; ++i) cout << v[i] << ' '; return (n ? cout << v.back(): cout << '\n'); } template <typename A> std::ostream& operator<< (std::ostream &cout, const std::vector<A> &v) { for (int i = 0; i < int(v.size()) - 1; ++i) cout << v[i] << ' '; return (v.size() ? cout << v.back(): cout << '\n'); }
template <typename A, typename B> std::istream& operator>> (std::istream &cin, std::pair<A, B> &p) { cin >> p.first; return cin >> p.second; } template <typename A, size_t n> std::istream& operator>> (std::istream &cin, std::array<A, n> &v) { for (int i = 0; i < n; i++) cin >> v[i]; return cin; } template <typename A> std::istream& operator>> (std::istream &cin, std::vector<A> &v) { for (int i = 0; i < v.size(); i++) cin >> v[i]; return cin; }
template <typename A, typename B> auto amax (A &a, const B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> auto amin (A &a, const B b){ if (b < a) a = b ; return a; }



int main () {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m; cin >> n >> m;
    vector z(m+1, 0ll);
    z[0] = -1;

    auto sum = [](lol a, lol b, lol k) {
        assert(a%k == b%k);
        return max(0ll, (((b-a) / k) * (a+b-k)) / 2);
    };

    fo(k,2,m+1,1) {
        set<lol> s;
        if (k < n) {
            for (lol t = k, j = 1; s.count(t) == 0; ) {
                s.insert(t);
                auto a = ((j-t+k-1)/(k-1))*k+t;
                auto b = ((n-t+k)/k)*k+t;
                z[k] += sum(a, b, k);
                j += (b-t)/k;
                t = (j*k-1)%n+1;
            }
        } else {
            vector a(n+1, 0); iota(all(a), 0);
            fo(i,1ll,n+1,1)
                a[i] = 0, z[k] += a[(i*k-1)%n+1], a[(i*k-1)%n+1] = 0;
        }

    }

    cout << max_element(all(z)) - begin(z) << '\n';
    // cout << z[7] << ' ' << z[563] << '\n';
    // cout << "\n" << z << '\n';


}
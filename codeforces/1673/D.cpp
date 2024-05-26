#include<bits\stdc++.h>

using namespace std;
#define Hassouna std::ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define all(c) (c).begin(),(c).end()
const long long N = 2e5 + 5, M = 1e9 + 7, OO = 0x3f3f3f3, mod = 1e9 + 7;
#define Count(s, a) (std::count((s).begin(), (s).end(),(a)))
int dx[] = {1, 0, -1, 0, -1, -1, 0, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
string D[] = {"D", "R", "U", "L", "RD", "LD", "RU", "LU"};
#define ll long long
#define ii pair<int,int>
#define stl(i, s) for(auto i : s)

vector<ll> getDiv(ll x) {
    vector<ll> Div;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i) continue;
        Div.push_back(i);
        if (i * i != x) Div.push_back(x / i);
    }
    sort(Div.begin(), Div.end());
    return Div;
}

ll b, q, y, c, r, z;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }


void TestCase() {
    cin >> b >> q >> y >> c >> r >> z;
    ll val[4];
    val[0] = b, val[1] = b + (y - 1) * q, val[2] = c, val[3] = (c + (z - 1) * r);
    if (abs(b - c) % q != 0 || r % q != 0 || val[2] < val[0] || val[3] > val[1]) {
        cout << 0 << endl;
    } else {

        ll ans = 0;
        ll less = val[2] - r, greater = val[3] + r;
        if (less < val[0] || greater > val[1]) {
            cout << -1 << endl;
            return;
        }
        auto LCMS = getDiv(r);
        for (const auto &p: LCMS) {
            if (lcm(p, q) == r)
                ans += ((r / p) * (r / p)) % mod;
        }
        cout << ans % mod << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        TestCase();
    }
}
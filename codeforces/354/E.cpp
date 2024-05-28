#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 998244353;

int nums[] = {0,4,7};
map<int,vector<int>> poss;

template<typename T>
std::ostream& operator<<(std::ostream& os, const vector<T> v) {
    for(auto x : v) os << x << " ";
    return os;
}

template <typename T, typename D>
std::ostream& operator<<(std::ostream& os, const pair<T,D> &p) {
    os << '(' << p.first << ", " << p.second << ") ";
    return os;
}

template<typename T, typename D>
std::ostream& operator<<(std::ostream& os, map<T,D> m) {
    for(auto &x: m) os << x.first << " " << x.second << " | ";
    return os;
}

void recur(int i, int sum, vector<int> &a) {
    if(i == 6) {
        poss[sum] = a;
        return;
    }
    for(int j = 0; j < 3; j++) {
        a.push_back(nums[j]);
        recur(i+1,sum+nums[j],a);
        a.pop_back();
    }
}

int get_digit(ll num, int d) {
    while(d--) num /= 10;
    return num % 10;
}

void add_digit(ll &num, ll d, ll pos) {
    while(pos--) d *= 10;
    num += d;
}

void solve() {
    ll num; cin >> num;

    vector<vector<pair<ll,ll>>> dp(20,vector<pair<ll,ll>>(10,{-1,-1}));
    dp[0][0] = {0,0};
    pair<ll,ll> p = {-1,-1};
    //push dp bc easier 
    for(int i = 0; i < 19; i++) {
        int d = get_digit(num,i);
        for(int j = 0; j < 10; j++) {
            if(dp[i][j] != p) {
                for(auto [u, v] : poss) {
                    if(u % 10 + j == d || i != 18 && (u + j) % 10 == d) {
                        dp[i+1][get_digit(j + u,1)] = {j,u};
                    }
                }
            }
        }
    }

    bool found = 0;
    vector<ll> res(6);
    int curr = -1;
    
    for(int i = 0; i < 10; i++) {
        if(dp[19][i] != p) curr = i;
    }

    if(curr == -1) {
        cout << curr << '\n';
        return;
    }

    curr = dp[19][curr].first;

    for(int i = 18; i > 0; i--) {
        for(int j = 0; j < 6; j++) {
            ll t = 0;
            add_digit(t,poss[dp[i][curr].second][j],i-1);
            // cout << "i : " << i << " add val : " << t << '\n';
            add_digit(res[j],poss[dp[i][curr].second][j],i-1);
        }
        curr = dp[i][curr].first;
    }

    for(int i = 0; i < 6; i++) {
        cout << res[i] << " \n"[i == 5];
    }


}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout << get_digit(12345,3) << '\n';
    vector<int> a;
    recur(0,0,a);
    // cout << "poss : " << poss << '\n';

    int casi; cin >> casi;
    while(casi-->0) solve();

    return 0;
}
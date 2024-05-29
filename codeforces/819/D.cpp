#include<bits/stdc++.h>
using namespace std;
using LL = long long;

template<typename T>
T exgcd(T a, T b, T &x, T &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    T r = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T, n;
    cin >> T >> n;
    vector<int> a(n + 1), s(n + 1);
    cin >> a[n];
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        s[i] = (s[i - 1] + a[i]) % T;
    }
    int sum = s.back();
    int g = gcd(sum, T);
    if (sum == 0){
        set<int> st;
        for(int i = 0; i < n; i++){
            cout << !st.contains(s[i] % T) << ' ';
            st.insert(s[i] % T);
        }
        cout << '\n';
        return 0;
    }
    T /= g;
    sum /= g;
    map<int, vector<int> > pos;
    set<int> st;
    for(int i = 0; i < n; i++){
        if (st.contains(s[i] % (T * g))) continue;
        st.insert(s[i] % (T * g));
        pos[s[i] % g].push_back(i);
    }
    int inv = -1;
    {
        int x, y;
        exgcd(sum, T, x, y);
        inv = (x % T + T) % T;
    }
    vector<int> ans(n, 0);
    for(auto &[x, v] : pos){
        for(auto u : v) ans[u] = T;
        {
            set<int> st;
            for(auto u : v){
                int t = 1LL * s[u] / g * inv % T;
                if (!st.empty()){
                    int nxt = -1;
                    if (t > *st.rbegin()){
                        nxt = *st.begin();
                    }
                    else{
                        nxt = *st.lower_bound(t);
                    }
                    ans[u] = min(ans[u], (nxt - t + T) % T);
                }
                st.insert(t);
            }
        }
        reverse(v.begin(), v.end());
        {
            set<int> st;
            for(auto u : v){
                int t = 1LL * s[u] / g * inv % T;
                if (!st.empty()){
                    int nxt = -1;
                    if (t > *st.rbegin()){
                        nxt = *st.begin();
                    }
                    else{
                        nxt = *st.lower_bound(t);
                    }
                    int k = (nxt - t + T) % T;
                    if (k == 0) k += 1;
                    ans[u] = min(ans[u], k);
                }
                st.insert(t);
            }
        }
    }
    for(auto x : ans) cout << x << ' ';
    cout << '\n';

}
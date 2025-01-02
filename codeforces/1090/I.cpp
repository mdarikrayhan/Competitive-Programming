#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(s) (int)(s).size()
#define all(s) s.begin(),s.end()

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void radix_sort(vector<pair<ll, int>> &v, int base) {
    vector<pair<ll, int>> tmp(v.size());
    ll p = 1;
    for (int it = 0; it < 10; it++, p *= base) {
        vector<int> frq(base);
        for (auto &[val, id]: v)
            frq[(val / p) % base]++;
        for (int i = 1; i < base; i++)
            frq[i] += frq[i - 1];
        for (int i = sz(v) - 1; i >= 0; i--)
            tmp[--frq[(v[i].first / p) % base]] = v[i];
        v = tmp;
    }
}

void solve() {
    int n;
    cin >> n;
    ll l, r, x, y, z;
    vector<ll> b(n), a(n);
    cin >> l >> r >> x >> y >> z >> b[0] >> b[1];
    for (int i = 2; i < n; ++i) {
        b[i] = b[i - 2] * x + b[i - 1] * y + z;
        b[i] &= UINT_MAX;
    }
    ll mn = LLONG_MAX, ans = LLONG_MAX;
    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        a[i] = b[i] % (r - l + 1) + l;
        if (a[i] > mn) {
            ans = min(ans, a[i] * mn);
        } else
            mn = a[i];
        if (a[i] < 0) {
            v.emplace_back(a[i]);
        }
    }

    stack<int> st;
    vector<int> nxt(v.size(), - 1);
    for(int i = sz(v) - 1; i >= 0; i--){
        while(st.size() &&  v[st.top()] <= v[i])
            st.pop();
        if(st.size())
            nxt[i] = st.top();
        st.push(i);
    }

    for(int i = 0; i < v.size(); i++){
        if(nxt[i] != -1){
            ans = min(ans , 1LL * v[i] * v[nxt[i]]);
        }
    }

    while(st.size())
        st.pop();
    nxt = vector<int> (v.size() , -1);
    for(int i = 0; i < sz(v); i++){
        while(st.size() && v[st.top()] >= v[i])
            st.pop();
        if(st.size())
            nxt[i] = st.top();

        st.push(i);
    }

    for(int i = 0; i < v.size(); i++){
        if(nxt[i] != -1){
            ans = min(ans , 1LL * v[i] * v[nxt[i]]);
        }
    }

    if (ans == LLONG_MAX)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << "\n";
}

int main() {
    Speed();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
		 	 	  	 		   		 		  	     		
#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

struct segTree{
    int size;
    vector<pair<ll, int>> mx;
    vector<ll> upd;
    void init(int n){
        size = 1;
        while (size < n) size *= 2;
        mx.assign(2 * size, {-1e18, -1});
        upd.assign(2 * size, 0ll);
    }
    void set(int l, int r, ll v, int x, int lx, int rx){
        if (lx >= l && rx <= r){
            mx[x].first += v;
            if(mx[x].second == -1) mx[x].second = lx;
            upd[x] += v;
            return;
        }else if(lx >= r || rx <= l) return;
        int m = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, m);
        set(l, r, v, 2 * x + 2, m, rx);
        mx[x] = max(mx[x * 2 + 1], mx[x * 2 + 2]);
        mx[x].first += upd[x];
    }
    void set(int l, int r, ll v){
        set(l, r, v, 0, 0, size);
    }

    pair<ll, int> calc(int l, int r, int x, int lx, int rx){
        if (lx >= r || l >= rx)
            return {-1e18, -1};
        if (lx >= l && rx <= r){
            return mx[x];
        }
        int m = (lx + rx) / 2;
        pair<ll, int> s1 = calc(l, r, 2 * x + 1, lx, m);
        pair<ll, int> s2 = calc(l, r, 2 * x + 2, m, rx);
        pair<ll, int> ans = max(s1, s2); ans.first += upd[x];
        return ans;
    }

    pair<ll, int> calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
};

void solve(){
	int n; cin >> n;
	vector<pair<int, int>> mn(n);
	vector<pair<int, int>> mx(n);
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y >> c[i];
		mx[i] = {max(x, y), i};
		mn[i] = {min(x, y), i};
	}
	sort(mx.begin(), mx.end());
	sort(mn.begin(), mn.end());
	vector<int> ind(n);
	segTree st; st.init(n);
	vector<int> revInd;
	int curr = -1;
	ll lst = -1e6 - 1;
	for(int i = 0; i < n; i++){
		if(mx[i].first != lst){
			curr++;
			revInd.push_back(mx[i].first);
			st.set(curr, curr + 1, (ll)1e18 - mx[i].first);
			lst = mx[i].first;
		}
		ind[mx[i].second] = curr;
		st.set(curr, n, c[mx[i].second]);
	}
	lst = -1e6 - 1;
	st.set(0, n, lst);
	ll ans = 0;
	int lind = 0;
	curr = -1;
	ll lst2 = -1e6 - 1;
	pair<int, int> coords = {2e9, 2e9};
	for(int i = 0; i < n; i++){
		st.set(0, n, mn[i].first - lst);
		while(lind < n && mx[lind].first < mn[i].first){
			if(mx[lind].first != lst2){
				curr++;
				st.set(curr, curr + 1, -1e18);
				lst2 = mx[lind].first;
			}
			lind++;
		}
		if(mn[i].first != lst){
			pair<ll, int> score = st.calc(0, n);
			if(score.first > ans){
				ans = score.first;
				coords.first = mn[i].first;
				coords.second = revInd[score.second];
			}
		}
		lst = mn[i].first;
		st.set(ind[mn[i].second], n, -c[mn[i].second]);
	}
	cout << ans << "\n";
	cout << coords.first << " " << coords.first << " " << coords.second << " " << coords.second << "\n";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// int tt; cin >> tt;
	int tt = 1;
	while(tt--) solve();
}
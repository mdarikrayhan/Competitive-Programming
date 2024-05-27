#include<bits/stdc++.h>

using namespace std;
#define int long long
#define ll long long
#define el '\n'
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define input(v) for(auto&it:v){cin>>it;}
#define output(v) for(auto&it:v){cout<<it<<" ";}

// our mind is filled with the basic algorithm definition.
int n;
map<int, set<int>> val;
map<pair<int, int>, int> mp;

int dist(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

pair<int, int> help(int l, int i) {
    return (i <= l ? make_pair(l, i) : make_pair(2 * l - i, l));
}

int dope(int l, int i) {
    if (mp.find({l, i}) == mp.end()) {
        auto it = val.find(l);
        it++;
        if (it == val.end())
            return 0;
        int nextl = it->first;
        auto it1 = it->second.begin(), it2 = it->second.end();
        it2--;
        int be = *it1, en = *it2;
        pair<int, int> me = help(l, i);
        pair<int, int> bep = help(nextl, be);
        pair<int, int> enp = help(nextl, en);
        int one = dist(me, bep) + dist(bep, enp) + dope(nextl, en);
        int two = dist(me, enp) + dist(enp, bep) + dope(nextl, be);
        mp[{l, i}] = min(one, two);
    }
    return mp[{l, i}];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int l = max(x, y);
        int ind = x == l ? y : 2 * l - x;
        val[l].insert(ind);
    }
    val[0] = { 0 };
    cout << dope(0, 0);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
					 					 	 	 			    	  	 	 	
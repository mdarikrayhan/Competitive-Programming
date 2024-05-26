#include <iostream>

#include <limits>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
typedef long long ll;

using namespace std;


int n, a, b, k, f;

typedef pair<string, string> pss;

vector<pss> edges;

pss get_norm(pss p) {
    if(p.first < p.second) {
        return p;
    } else {
        return {p.second, p.first};
    }
}

void solve() {
    cin>>n>>a>>b>>k>>f;

    edges = vector<pss>(n);
    vector<pss> partial_ordered_edges = vector<pss>(n);
    for(int i=0; i<n; i++) {
        cin>>edges[i].first>>edges[i].second;
        partial_ordered_edges[i] = get_norm(edges[i]);
    }

    map<pss, int> cnts;
    string cur = "";
    for(int i=0; i<n; i++) {
        if(cur == edges[i].first) {
            cnts[partial_ordered_edges[i]] += b;
        } else {
            cnts[partial_ordered_edges[i]] += a;
        }
        cur = edges[i].second;
    }

    set<pss> bought_passes;
    vector<pair<int, pss>> vs;
    for(auto kv: cnts) {
        vs.push_back({kv.second, kv.first});
    }

    sort(vs.begin(), vs.end(), greater<>());

    for(int i=0; i<min(k, (int) vs.size()); i++) {
        if(vs[i].first > f) {
            bought_passes.insert(vs[i].second);
            // cout<<"bought pass for "<< vs[i].first<<" "<<vs[i].second.first<<" "<<vs[i].second.second<<endl;
        }
    }

    int ans = bought_passes.size() * f;
    cur = "";
    for(int i=0; i<n; i++) {
        if(bought_passes.find(partial_ordered_edges[i]) == bought_passes.end()) {
            if(cur == edges[i].first) {
                ans += b;
            } else {
                ans += a;
            }
        } 
        cur = edges[i].second;
    }

    cout<<ans<<endl;


}


int main() {
    // speed up
    ios::sync_with_stdio(0);
	cin.tie(0);

    solve();

    return 0;
}

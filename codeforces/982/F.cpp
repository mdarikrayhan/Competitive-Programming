#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> in(n), out(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        out[--x].insert(--y);
        in[y].insert(x);
    }

    // Recursivelly remove nodes without outgoing edges
    function<void(int)> dfs = [&](int node) {
        if (!out[node].empty()) {
            return;
        }
        for (int p : in[node]) {
            out[p].erase(node);
            dfs(p);
        }
        in[node].clear();
    };

    // Check for nodes with no outgoing edges
    for (int i = 0; i < n; i++) {
        if (out[i].empty()) {
            dfs(i);
        }
    }

    // Reduce cycles by popping out nodes
    vector<int> st;
    vector<bool> seen(n);
    for (int i = 0; i < n; i++) {
        if ((int)out[i].size() == 1) {
            st.push_back(i);
            seen[i] = true;
        }
    }
    while (!st.empty()) {
        int node = st.back(), next = *out[node].begin();
        st.pop_back();
        if (node == next) {
            continue;
        }
        in[next].erase(node);
        in[next].insert(in[node].begin(), in[node].end());
        for (int p : in[node]) {
            out[p].erase(node);
            out[p].insert(next);
            if ((int)out[p].size() == 1 && !seen[p]) {
                st.push_back(p);
                seen[p] = true;
            }
        }
        out[node].clear();
        in[node].clear();
    }

    // Get the last node standing. If there are multiple nodes, then there is no
    // intersection
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (!out[i].empty()) {
            if (ans == -1) {
                ans = i + 1;
            } else {
                ans = -1;
                break;
            }
        }
    }

    cout << ans << endl;
}

 	 						 	       	 		      		
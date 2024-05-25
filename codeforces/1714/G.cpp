#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <stack>

using namespace std;

void dfs(int start, map<int, vector<tuple<int, int, int>>>& d, vector<int>& final) {
    vector<long long> path;
    stack<tuple<int, int, long long, long long, bool>> st;
    st.push({start, -1, 0, 0, true});
    
    while (!st.empty()) {
        auto [cur, par, s1, s2, isEntry] = st.top();
        st.pop();
        
        if (isEntry) {
            path.push_back(s2);
            auto it = upper_bound(path.begin(), path.end(), s1);
            if (cur != 1) {
                final[cur - 2] = it - path.begin() - 1;
            }
            st.push({cur, par, s1, s2, false});
            
            for (auto it = d[cur].rbegin(); it != d[cur].rend(); ++it) {
                auto [node, a1, b1] = *it;
                if (node != par) {
                    st.push({node, cur, s1 + a1, s2 + b1, true});
                }
            }
        } else {
            path.pop_back();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<int, vector<tuple<int, int, int>>> d;
        int n;
        cin >> n;
        vector<int> final(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            int p, a, b;
            cin >> p >> a >> b;
            d[p].emplace_back(i + 2, a, b);
        }
        dfs(1, d, final);
        for (int i = 0; i < n - 1; ++i) {
            cout << final[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

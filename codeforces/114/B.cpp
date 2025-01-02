#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> names;
unordered_map<string, int> name_to_index;
bool conflict[16][16];
vector<string> best_team;
vector<string> current_team;

void backtrack(int idx, int bitmask) 
{
    if (idx == n) {
        if (__builtin_popcount(bitmask) > best_team.size()) 
        {
            best_team.clear();
            for (int i = 0; i < n; ++i) {
                if (bitmask & (1 << i)) {
                    best_team.push_back(names[i]);
                }
            }
        }
        return;
    }

    backtrack(idx + 1, bitmask);

    bool can_add = true;
    for (int i = 0; i < n; ++i) {
        if (bitmask & (1 << i)) {
            if (conflict[idx][i]) {
                can_add = false;
                break;
            }
        }
    }
    if (can_add) {
        backtrack(idx + 1, bitmask | (1 << idx));
    }
}

int main() {
    cin >> n >> m;
    names.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        name_to_index[names[i]] = i;
    }
    
    memset(conflict, false, sizeof(conflict));
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        int idx_a = name_to_index[a];
        int idx_b = name_to_index[b];
        conflict[idx_a][idx_b] = true;
        conflict[idx_b][idx_a] = true;
    }

    backtrack(0, 0);

    sort(best_team.begin(), best_team.end());

    cout << best_team.size() << endl;
    for (const string &name : best_team) {
        cout << name << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;

int ct[300], ne[300];
int To[8], Cnt[8];
pair<int, int> From[8];

int CT[300];

vector<pair<int, int>> edges;

void add(int x, int y) {
    edges.push_back(make_pair(x, y));
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ne[i] = (a << 2) | (b << 1) | c;
        Cnt[ne[i]]++;
        CT[i] = ne[i] != 1 && ne[i] != 2 && ne[i] != 4; 
    }

    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ct[i] = (a << 2) | (b << 1) | c;
        To[ne[i]] |= 1 << (ct[i] & ne[i]);
    }
    int sta = (1 << 7);
    for (; ;) {
        int nwS = sta;
        for (int i = 0; i < 8; i++) {
            if (sta >> i & 1) {
                for (int j = 0; j < 8; j++)  {
                    if (To[i] >> j & 1) {
                        if (~nwS >> j & 1) {
                            From[j] = make_pair(i, -1), nwS |= 1 << j;
                        }
                    }

                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int ii = 0; ii < 8; ii++) {
                if ((sta >> ii & 1) && (To[ii] >> (1 << i) & 1)) {
                    for (int j = i + 1; j < 3; j++) {
                        for (int jj = 0; jj < 8; jj++) {
                            if ((sta >> jj & 1) && (To[jj] >> (1 << j) & 1)) {
                                if (~nwS >> ((1 << i) + (1 << j)) & 1) {
                                    From[(1 << i) + (1 << j)] = make_pair(ii, jj);
                                    nwS |= 1 << ((1 << i) + (1 << j));
                                }
                            }
                        }
                    }
                }
            }
        }
        if (nwS == sta) {
            break;
        }
        sta = nwS;
    }
    for (int i = 1; i < 8; i++) {
        if (Cnt[i] && (~sta >> i & 1)) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 1; i < 7; i++) {
        if (From[i].second == -1) {
            int id = 0;
            for (int j = 1; j <= n; j++) {
                if (ne[j] == From[i].first && (ne[j] & ct[j]) == i) {
                    id = j;
                    break;
                }
            }
            for (int j = 1; j <= n; j++) {
                if (ne[j] == i) {
                    add(id, j);
                }
            }
        } else {
            int id1 = 0, id2 = 0;
            int x = i & -i;
            int y = i - x;
            for (int j = 1; j <= n; j++) {
                if (ne[j] == From[i].first && (ne[j] & ct[j]) == x) {
                    id1 = j;
                    break;
                }
            }
            for (int j = 1; j <= n; j++) {
                if (ne[j] == From[i].second && (ne[j] & ct[j]) == y) {
                    id2 = j;
                    break;
                }
            }
            int pp = 0;
            for (int j = 1; j <= n; j++) {
                if (ne[j] == i) {
                    pp = j;
                    break;
                }
            }
            if (pp) {
                CT[pp] = 0;
                add(id1, pp);
                add(id2, pp);
            }
            for (int j = 1; j <= n; j++) {
                if (ne[j] == i && pp != j) {
                    add(pp, j);
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (ne[i] == 7) {
            add(1, i);
        }
    }
    cout << "Possible\n";
    for (int i = 1; i <= n; i++) {
        cout << CT[i] << ' ';
    }
    cout << '\n';
    cout << edges.size() << '\n';
    for (auto [i, j] : edges) {
        cout << i << ' ' << j << "\n";
    }
    return 0;
} 
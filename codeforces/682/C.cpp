#include <bits/stdc++.h>
using namespace std;
int n, a[100001], p, c, ans, subtree[100001];
vector<int> child[100001], cost[100001];

void count(int x) {
    int cnt = 0, sz = child[x].size();
    for (int i = 0; i < sz; i++) {
        if (!subtree[child[x][i]]) {
            count(child[x][i]);
        }
        cnt += subtree[child[x][i]];
    }
    subtree[x] = cnt + 1;
}

void run(int x, int dist) {
    dist = max(0, dist);
    int childs = child[x].size();
    for (int i = 0; i < childs; i++) {
        if (cost[x][i] + dist > a[child[x][i]]) {
            if (!subtree[child[x][i]]) {
                count(child[x][i]);
            }
            ans += subtree[child[x][i]];
        } else run(child[x][i], dist + cost[x][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        cin >> p >> c;
        child[p].push_back(i);
        cost[p].push_back(c);
    }
    run(1, 0);
    cout << ans;
}
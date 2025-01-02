/*
Problem: 746G
Date: 27-05-2024 08:39 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// maximum number of leaves: all nodes at level i have common parent in level i - 1.
// minimum number of leaves: max(0, a_1 - a_2) + max(0, a_2 - a_3) + ...

// first, generate min number, then add leaves one by one by parent changes
// until it reaches k or we can add no more

const int N = 2e5 + 5;
int n, t, k, a[N];

vector<int> id[N];
int par[N];
bool nonleaf[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t >> k;
    int cnt = 1;
    id[0].push_back(cnt++);
    for(int i = 1; i <= t; i++) {
        cin >> a[i];
        for(int j = 0; j < a[i]; j++) {
            if(j < (int) id[i - 1].size()) {
                par[cnt] = id[i - 1][j];
                nonleaf[id[i - 1][j]] = true;
            }else {
                par[cnt] = id[i - 1][0];
                nonleaf[id[i - 1][0]] = true;
            }
            id[i].push_back(cnt++);
        }
    }
    int leaves = 0;
    for(int i = 1; i <= n; i++) {
        leaves += !nonleaf[i];
    }
    if(leaves > k) {
        cout << "-1\n";
        return 0;
    }
    for(int i = 1; i <= t; i++) {
        for(int x : id[i]) {
            if(leaves == k) break;
            if(par[x] != id[i - 1][0]) {
                par[x] = id[i - 1][0];
                leaves++;
            }
        }
    }
    if(leaves != k) {
        cout << "-1\n";
        return 0;
    }
    cout << n << endl;
    for(int i = 2; i <= n; i++) {
        cout << i << " " << par[i] << endl;
    }
}
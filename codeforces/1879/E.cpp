// Created by Henry Yi

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int n, pa[N], dep[N], color[N], anc[N], up[N];
vector<int> adj[N];
bool flag = true;
int max_depth = 0;

void dfs(int u) {
    max_depth = max(max_depth, dep[u]);
    for (int i : adj[u]) {
        dep[i] = dep[u] + 1;
        dfs(i);
    }
}

void mark(int u, int a) {
    anc[u] = a;
    for (int v : adj[u]) mark(v, a);
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &pa[i]);
        adj[pa[i]].push_back(i);
    }
    dep[1] = 0;
    dfs(1);
    memset(up, -1, sizeof up);

    if (max_depth <= 2) {
        printf("%d\n", max_depth);
        fflush(stdout);
        for (int i = 2; i <= n; i++) {
            printf("%d ", dep[pa[i]] % 3 + 1);
        }
        puts("");
        fflush(stdout);
        int x;
        while (~scanf("%d", &x)) {
            if (x == 1 || x == -1) break;
            int min_v = 4;
            for (int i = 1; i <= max_depth; i++) {
                scanf("%d", &color[i]);
                if (color[i]) min_v = min(min_v, i);
            }
            printf("%d\n", min_v);
            fflush(stdout);
        }
    } else {
        for (int v : adj[1]) {
            mark(v, v);
        }
        for (int i = 2; i <= n; i++) {
            if (adj[i].size() != 1) continue;
            if (up[anc[i]] == -1) up[anc[i]] = dep[i] % 2;
            else if (up[anc[i]] != dep[i] % 2) flag = false;
        }
        if (!flag) {
            printf("%d\n", 3);
            fflush(stdout);
            for (int i = 2; i <= n; i++) {
                printf("%d ", dep[pa[i]] % 3 + 1);
            }
            puts("");
            fflush(stdout);
            int x;
            while (~scanf("%d", &x)) {
                if (x == 1 || x == -1) break;
                int min_v = 4;
                for (int i = 1; i <= 3; i++) {
                    scanf("%d", &color[i]);
                    if (color[i] == 1) min_v = min(min_v, i);
                }
                if (color[1] && color[3]) {
                    printf("%d\n", 3);
                    fflush(stdout);
                } else {
                    printf("%d\n", min_v);
                    fflush(stdout);
                }
            }
        } else {
            printf("%d\n", 2);
            fflush(stdout);
            for (int i = 1; i <= n; i++)
                if (up[i] == -1) up[i] = 0;
            for (int i = 2; i <= n; i++) {
                printf("%d ", ((dep[pa[i]] % 2) ^ up[anc[i]]) + 1);
            }
            puts("");
            fflush(stdout);
            int x;
            while (~scanf("%d", &x)) {
                int path = 0;
                for (int i = 1; i <= 2; i++) {
                    scanf("%d", &color[i]);
                    if (color[i] == 1) path = i;
                }
                if (color[1] == 1 && color[2] == 1) {
                    printf("%d\n", 2);
                } else {
                    printf("%d\n", path);
                }
                fflush(stdout);
            }
        }
    }

    return 0;
}

// read questions at least 3 times!!!
// think more and then code!!!
// partial points are GOD.
// don't stuck on one question for two long (like 30-45 min)
// Debug: (a) read your code once, check overflow, check edge case(0/1)
// Debug: (b) create your own test case
// Debug: (c) add asserts
// Debug: (d) 对拍
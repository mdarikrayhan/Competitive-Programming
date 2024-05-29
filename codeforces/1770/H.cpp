// Hydro submission #663244f25bf84ebcd47e1fbb@1714570482125
#include <bits/stdc++.h>

constexpr int N = 202;

int n, p1[N], p2[N];

std::vector<std::pair<int, int>> path1[N], path2[N];

void work(int p[N], std::vector<std::pair<int, int>> path[N]) {
    const auto swap = [&](int x, int i, int y, int j) {
        std::vector<std::pair<int, int>> tmpx, tmpy;
        for (int t = i; t < path[x].size(); t++) tmpx.push_back(path[x][t]);
        for (int t = j; t < path[y].size(); t++) tmpy.push_back(path[y][t]);
        path[x].resize(i);
        path[y].resize(j);
        for (auto t : tmpx) path[y].push_back(t);
        for (auto t : tmpy) path[x].push_back(t);
    };
    std::vector<std::pair<int, int>> ans;
   
    for (int i = n; i >= 1; i--) for (int j = 1; j < i; j++) if (p[j] < p[j + 1]) {
        std::swap(p[j], p[j + 1]);
        ans.push_back({j, j + 1});
    }
    std::reverse(ans.begin(), ans.end());
    for (auto [x, y] : ans) 
    {
        for (int i = 0; i < path[y].size(); i++)
            for (int j = 0; j < path[x].size(); j++)
                if (path[y][i] == path[x][j]) {
                    swap(y, i, x, j);
                    goto OUT;
                }
        assert(false);
        OUT:;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p1[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &p2[i]);
    bool flag = 1;
    for (int i = 1; i <= n; i++) flag &= p1[i] == i;
    for (int i = 1; i <= n; i++) flag &= p2[i] == i;
    if (flag) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", n);
            for (int j = 1; j <= n; j++) printf("%d %d ", j, i);
            puts("");
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", n);
            for (int j = 1; j <= n; j++) printf("%d %d ", i, j);
            puts("");
        }
        return 0;
    }
    
    for (int i = 1; i <= n; i++) {
        int t = n - i + 1;
        if (t >= i) {
            for (int j = 1; j <= i; j++) path1[i].push_back({j, i});
            for (int j = i + 1; j <= t; j++) path1[i].push_back({i, j});
            for (int j = i + 1; j <= n; j++) path1[i].push_back({j, t});
            for (int j = 1; j <= i; j++) path2[i].push_back({i, j});
            for (int j = i + 1; j <= t; j++) path2[i].push_back({j, i});
            for (int j = i + 1; j <= n; j++) path2[i].push_back({t, j});
        }
        else {
            for (int j = 1; j <= t; j++) path1[i].push_back({j, i});
            for (int j = i - 1; j >= t; j--) path1[i].push_back({t, j});
            for (int j = t + 1; j <= n; j++) path1[i].push_back({j, t});
            for (int j = 1; j <= i; j++) path2[i].push_back({i, j});
            for (int j = i - 1; j >= t; j--) path2[i].push_back({j, i});
            for (int j = i + 1; j <= n; j++) path2[i].push_back({t, j});
        }
    }
    work(p1, path1);
    work(p2, path2);
    for (int i = 1; i <= n; i++) {
        printf("%lu ", path1[i].size());
        for (auto [x, y] : path1[i]) printf("%d %d ", x, y);
        puts("");
    }
    for (int i = 1; i <= n; i++) {
        printf("%lu ", path2[i].size());
        for (auto [x, y] : path2[i]) printf("%d %d ", x, y);
        puts("");
    }
    return 0;
}
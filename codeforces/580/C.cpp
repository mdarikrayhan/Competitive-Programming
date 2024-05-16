#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> cats;
int m, count = 0;

void dfs(int v, int parent, int cat_count) {
    if (cats[v]) cat_count++; // Если в текущей вершине есть кот, увеличиваем счетчик котов
    else cat_count = 0; // Иначе сбрасываем счетчик котов

    if (cat_count > m) return; // Если встречено более m котов подряд, завершаем обход

    bool is_leaf = true;
    for (int u : tree[v]) {
        if (u != parent) {
            is_leaf = false;
            dfs(u, v, cat_count);
        }
    }

    if (is_leaf) count++; // Если текущая вершина лист, увеличиваем счетчик
}

int main() {
    int n;
    cin >> n >> m;

    cats.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cats[i];
    }

    tree.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, -1, 0);

    cout << count << endl;

    return 0;
}

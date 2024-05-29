// LUOGU_RID: 160333412
#include <bits/stdc++.h>

using namespace std;

const int N = 1010, INF = 1e9;
int n, tot; vector<int> E[N];

int a[N];
inline int Ask() {
    cout << "? 1";
    for(int i = 1; i <= n - 1; i ++)
        cout << ' ' << a[i];
    cout << endl;
    int res; cin >> res; return res;
}

vector<int> son[N];
int node[N];
// node[i]:= i 号边深度较大的端点
// son[i]:= i 号点的子结点

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    
    cin >> n;
    for(int i = 2; i <= n - 1; i ++) {
        cout << "? 2 1 " << i << endl;
        int x; cin >> x; E[x].emplace_back(i);
    }
    
    int dep = 0, leaf = 0; vector<int> last_E;    // last_E := 上一层的边，顺序与权值对应
    last_E.emplace_back(1), last_E.emplace_back(1); tot = 2;
    for(dep = 0; dep <= n && !E[dep].empty(); dep ++) {
        // 处理第 dep 层的边
        for(int i = 1; i <= n - 1; i ++) a[i] = 1;
        for(int i = 0; i < last_E.size() - 1; i ++) a[last_E[i]] = (i + 1) * n;
        a[last_E.back()] = ((int)last_E.size() - 1) * n;

        vector<int> vec = E[dep];
        int flag = 0;
        while(!vec.empty()) {
            int e = vec.back(); vec.pop_back();
            a[e] = INF; int D = (Ask() - INF) / n - ((int)last_E.size() - 1); a[e] = 1;
            if(dep == 0 || D == (int)last_E.size() - 1) {flag = e; break; }
            node[e] = ++tot; son[node[last_E[D - 1]]].emplace_back(tot);
        }
        if(flag) {
            vector<int> A, B; node[flag] = ++tot, A.emplace_back(flag);
            a[flag] = INF;
            while(!vec.empty()) {
                int e = vec.back(); vec.pop_back();
                a[e] = INF; int D = (Ask() - INF - INF) / n; a[e] = 1;
                if(D == 0) node[e] = ++tot, A.emplace_back(e);
                else if(dep == 0 || D - ((int)last_E.size() - 1) == ((int)last_E.size() - 1)) node[e] = ++tot, B.emplace_back(e);
                else node[e] = ++tot, son[node[last_E[D - ((int)last_E.size() - 1) - 1]]].emplace_back(tot);
            }
            if(B.size() > A.size()) swap(A, B);
            int u, v;   // 两个特殊边
            if(A.size() == 1) {
                if(B.size() == 0) {
                    cout << "? 2 " << A[0] << ' ' << last_E.back() << endl;
                    int T; cin >> T;
                    if(T == 0) son[dep ? node[last_E[last_E.size() - 2]] : 1].emplace_back(node[A[0]]), leaf = last_E[last_E.size() - 2];
                    else son[dep ? node[last_E[last_E.size() - 1]] : 2].emplace_back(node[A[0]]), leaf = last_E.back();
                    dep ++; break;
                } else {
                    // B.size() == 1
                    son[dep ? node[last_E[last_E.size() - 2]] : 1].emplace_back(node[A[0]]);
                    son[dep ? node[last_E[last_E.size() - 1]] : 2].emplace_back(node[B[0]]);
                    u = A[0], v = B[0];
                }
            } else {
                for(auto x : A) son[dep ? node[last_E[last_E.size() - 2]] : 1].emplace_back(node[x]);
                for(auto x : B) son[dep ? node[last_E[last_E.size() - 1]] : 2].emplace_back(node[x]);
                u = A[0], v = A[1];
            }
            last_E.clear();
            for(auto e : E[dep]) 
                if(e != u && e != v) last_E.emplace_back(e);
            last_E.emplace_back(u), last_E.emplace_back(v);
        } else {leaf = last_E.back(), dep ++; break; }  // 两个特殊边是叶子
    }
    if(leaf) {
        for(; dep <= n && !E[dep].empty(); dep ++) {
            for(int i = 1; i <= n - 1; i ++) a[i] = 1;
            for(int i = 0; i < E[dep - 1].size(); i ++)
                a[E[dep - 1][i]] = (i + 1) * n;
            a[leaf] = INF;

            for(auto e : E[dep]) {
                a[e] = INF; int D = (Ask() - INF - INF) / n - 1; a[e] = 1;
                node[e] = ++tot, son[node[E[dep - 1][D]]].emplace_back(node[e]);
            }
        }
    }
    cout << "!" << '\n';
    cout << "1 2" << '\n';
    for(int i = 1; i <= tot; i ++)
        for(auto x : son[i])
            cout << i << ' ' << x << '\n';
    cout << flush;

    return 0;
}
// LUOGU_RID: 160421376
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int u, v, num, start, start_color;
int n, m, cnt, ei, ei2, ci;
stack<int> s; 
int instack[N], weight[N], flag[N];
int indeg[N], dist[N];
struct perEdge{
    int to, num, next;
} edges[N], edges2[N];
struct node{
    int to;
    int weight;
}; vector<node> G[N];
int vertex[N], vertex2[N], dfn[N], low[N], color[N];

inline int calc(int x){//抄来的函数
    int tt=sqrt(2*x+0.25)-0.5;
    return x+tt*x-(tt+1)*(tt+2)*tt/6;
}

void add(int v1, int v2, int num){
    ei++;
    edges[ei].to = v2;
    edges[ei].num = num;
    edges[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void add2(int v1, int v2, int num){
    ei2++;
    edges2[ei2].to = v2;
    edges2[ei2].num = num;
    edges2[ei2].next = vertex2[v1];
    vertex2[v1] = ei2;
    return ;
}

void tarjan(int x){
    dfn[x] = low[x] = ++cnt;
    instack[x] = 1; s.push(x);
    for (int index=vertex[x]; index; index=edges[index].next){
        int to = edges[index].to;
        if (!dfn[to]){
            tarjan(to);
            low[x] = min(low[x], low[to]);
        } else if (instack[to])
            low[x] = min(low[x], dfn[to]);
    }
    int k;
    if (low[x] == dfn[x]){
        ci++;
        do{
            k = s.top();
            s.pop();
            color[k] = ci;
            instack[k] = 0;
            if (k == start) start_color = ci;
        } while(k != x);
    }
    return ;
}

void topological_sort(){
    queue<int> que;
    for (int i=1; i<=ci; i++){
        dist[i] = -1000000000000000000LL;
        if (!indeg[i])
            que.push(i);
    }
    dist[start_color] = weight[start_color];
    flag[start_color] = 1;
    while(!que.empty()){
        int t = que.front();
        que.pop();
        for (int index=vertex2[t]; index; index=edges2[index].next){
            int to = edges2[index].to;
            int total = edges2[index].num;
            indeg[to] -= 1;
            if (indeg[to] == 0) que.push(to);
            if (flag[t]){
                dist[to] = max(dist[to], dist[t] + total + weight[to]);
                flag[to] = 1;
            }
        }
    }
    return ;
}

signed main(){
    // freopen("a.in", "r", stdin);
    // freopen("a1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> u >> v >> num;
        add(u, v, num);
    }
    cin >> start;
    for (int i=1; i<=n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i=1; i<=n; i++){
        for (int index=vertex[i]; index; index=edges[index].next){
            int x = color[i];
            int y = color[edges[index].to];
            int total = edges[index].num;
            if (x == y){
                // 将权重添加进来。
                int t = 1;
                weight[x] += calc(total);
            } else {
                add2(x, y, total);
                indeg[y] += 1;
            }
        }
    }
    topological_sort();
    int ans = 0;
    for (int i=1; i<=ci; i++) 
        ans = max(ans, dist[i]);
        // cout << dist[i] + weight[i] << " ";
    cout << ans << endl;
    return 0;
}
// LUOGU_RID: 160242953
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define int long long
using namespace std;

const int N = 3e5 + 5;
int n, m, k;
struct perEdge{
    int to;
    int next;
    int weight;
    int id;
} edges[N * 2];
struct node{
    int position;
    int distance;
    int previous;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    }
};
int total; vector<int> ans;
priority_queue<node> que;
int vertex[N], dist[N], vis[N], pre[N], ei;

void add(int v1, int v2, int weight, int id){
    ei++;
    edges[ei].to = v2;
    edges[ei].weight = weight;
    edges[ei].id = id;
    edges[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dijkstra(){
    memset(dist, 0x7f7f, sizeof dist);
    dist[1] = 0;
    que.push((node){1, 0, 0});
    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;
        if (t.previous && k){
            k -= 1;
            cout << t.previous << " ";
        }
        if (!k) return ;
        for (int index=vertex[t.position]; index; index=edges[index].next){
            int to = edges[index].to;
            int weight = edges[index].weight;
            if (dist[t.position] + weight <= dist[to]){
                dist[to] = dist[t.position] + weight;
                que.push((node){to, dist[to], edges[index].id});
            }
        }
    }
    return ;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1, u, v, w; i<=m; i++){
        cin >> u >> v >> w;
        add(u, v, w, i); add(v, u, w, i);
    }
    cout << min(k, n-1) << endl;
    dijkstra();

    return 0;
}
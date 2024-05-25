// LUOGU_RID: 160269593
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#define int long long
using namespace std;

const int N = 3e5 + 5;
int n, m, s;
struct perEdge{
    int to;
    int weight;
    int id;
    int next;
} edges[2*N];
int vertex[N], ei;
struct node{
    int position;
    int distance;
    bool friend operator < (node a, node b){
        return a.distance > b.distance;
    }
}; int dist[N], vis[N], pre[N];

void add(int v1, int v2, int weight, int id){
    ei++;
    edges[ei].id = id;
    edges[ei].to = v2;
    edges[ei].weight = weight;
    edges[ei].next = vertex[v1];
    vertex[v1] = ei;
}

void dijkstra(){
    priority_queue<node> que;
    memset(dist, 0x7f7f, sizeof dist);
    dist[s] = 0;
    que.push((node){s, 0});
    while(!que.empty()){
        node t = que.top();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;
        for (int index=vertex[t.position]; index; index=edges[index].next){
            int to = edges[index].to;
            int weight = edges[index].weight;
            if (dist[to] >= dist[t.position] + weight){
                dist[to] = dist[t.position] + weight;
                pre[to] = index;
                que.push((node){to, dist[to]});
            }
        }
    }
    return ;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=1, u, v, w; i<=m; i++){
        cin >> u >> v >> w;
        add(u, v, w, i);
        add(v, u, w, i);
    }
    cin >> s;
    dijkstra();
    int sum = 0;
    vector<int> ans;
    for (int i=1; i<=n; i++){
        if (i == s) continue;
        sum += edges[pre[i]].weight;
        ans.push_back(pre[i]);
    }
    cout << sum << endl;
    for (int i : ans) cout << (i + 1) / 2 << " ";
    // 头疼，为什么一直显示judging again
    return 0;
}
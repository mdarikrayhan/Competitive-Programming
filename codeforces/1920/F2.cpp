#include <bits/stdc++.h>
using namespace std;
const int MAXNM = 3e5 + 5;
class DisjointSetUnion{
private:
    const static int MAXNODE = 4 * MAXNM;
    int fa[MAXNODE];
public:
    /**
     * @brief 初始化并查集
     */
    void init(){
        for (int i = 0; i < MAXNODE; i++)
            fa[i] = i;
    }
    /**
     * @brief 获取 x 节点所在连通块的代表员，并进行路径压缩
     * @param x 要获取代表员的节点
     * @return int x 节点所在连通块的代表员
     */
    int getfa(int x){
        if (fa[x] == x)
            return x;
        return fa[x] = getfa(fa[x]);
    }
    /**
     * @brief 合并两个点所在的连通块
     * @param x 第一个连通块的任一成员
     * @param y 第二个连通块的任一成员
     */
    void merge(int x, int y){
        int fx = getfa(x);
        int fy = getfa(y);
        fa[fy] = fx;
    }
};
class Graph{
private:
    const static int MAXNODE = 4 * MAXNM;
    const static int MAXEDGE = MAXNODE;
public:
    struct Edge{
        int v, next;
    };
    int h[MAXNODE], tot;
    Edge t[MAXEDGE];
    /**
     * @brief 清空图
    */
    void init(){
        memset(h, 0, sizeof(h));
        tot = 0;
    }
    /**
     * @brief 建边
     * @param u 边的起点
     * @param v 边的终点
    */
    void addEdge(int u, int v){
        ++tot;
        t[tot].v = v;
        t[tot].next = h[u];
        h[u] = tot;
    }
};
class LowestCommonAncestor{
private:
    const static int MAXNODE = 4 * MAXNM, MAXK = 20;
	int dep[MAXNODE], f[MAXNODE][MAXK + 1];
	void dfs(int u){
		vis[u] = 1;
		for (int j = 1; j <= MAXK; j++){
			if (dep[u] < (1 << j))
                break;
			f[u][j] = f[f[u][j - 1]][j - 1];
		}
		for (int i = G.h[u]; i; i = G.t[i].next){
			int v = G.t[i].v;
			if (vis[v])
                continue;
			dep[v] = dep[u] + 1;
			f[v][0] = u;
			dfs(v);
		}
	}
public:
    Graph G;
	bool vis[MAXNODE];
    void solve(int x){
        dfs(x);
    }
	int getLCA(int u, int v){
		if (dep[u] < dep[v])
            swap(u, v);
		int t = dep[u] - dep[v];
		for (int i = 0; i <= MAXK; i++)
			if(t & (1 << i))
				u = f[u][i];
		if (u == v)
            return u;
		for(int i = MAXK; i >= 0; i--){
			if (f[u][i] != f[v][i]){
				u = f[u][i];
				v = f[v][i];
			}
		}
		return f[u][0];
	}
};
Graph G;
int val[4 * MAXNM];
class Kruskal{
private:
    const static int MAXEDGE = 4 * MAXNM;
private:
    struct Edge{
        int u, v, c;
    };
    DisjointSetUnion DSU;
    Edge e[MAXEDGE];
    static bool cmpLess(Edge a, Edge b){
        return a.c < b.c;
    }
    static bool cmpGreater(Edge a, Edge b){
        return a.c > b.c;
    }
    int tot = 0;
public:
    void init(){
        tot = 0;
    }
    /**
     * @brief 加入一条边
     * @param u 边的一端
     * @param v 边的另一端
     * @param c 边的权值
     */
    void addEdge(int u, int v, int c){
        // cout << u << ' ' << v << ' ' << c << endl;
        e[++tot] = {u, v, c};
    }
    /**
     * @brief 构建kruskal生成树并计算
     * @param n 点数
     * @param greaterFlag false为最小生成树，true为最大生成树
     * @return int kruskal重构树的根节点
     */
    int solve(int n, bool greaterFlag){
        int num = n;
        if (!greaterFlag)
            sort(e + 1, e + tot + 1, cmpLess);
        else
            sort(e + 1, e + tot + 1, cmpGreater);
        DSU.init();
        for (int i = 1; i <= tot; i++){
            int fu = DSU.getfa(e[i].u);
            int fv = DSU.getfa(e[i].v);
            if (fu == fv)
                continue;
            num++;
            DSU.merge(num, fu);
            DSU.merge(num, fv);
            val[num] = e[i].c;
            G.addEdge(num, fu);
            G.addEdge(num, fv);
            if (num == 2 * n - 1)
                break;
        }
        return num;
    }
};
int n, m;
struct Point{
    int x, y, k;
    Point(int a = 0, int b = 0, int c = 0){
        x = a, y = b, k = c;
    }
    Point(Point T, int a){
        x = T.x, y = T.y, k = a;
    }
    Point operator + (Point T){
        return Point(x + T.x, y + T.y);
    }
    bool isLegal(int n, int m){
        return (1 <= x && x <= n && 1 <= y && y <= m);
    }
    operator int(){   
        return ((x - 1) * m + y) + k * n * m;
    }
};
Point nxt[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool vis[MAXNM];
int mp[MAXNM], dis[MAXNM];
Kruskal Kru;
LowestCommonAncestor LCA;
int main(){
    int q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if (c == '#')
                mp[Point(i, j)] = -1;
            else if (c == 'v')
                mp[Point(i, j)] = 1;
        }
    }
    queue <Point> Q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[Point(i, j)] == 1)
                Q.push(Point(i, j)), vis[Point(i, j)] = true;
    while (!Q.empty()){
        Point u = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++){
            Point v = u + nxt[i];
            if (!v.isLegal(n, m) || vis[v])
                continue;
            dis[v] = dis[u] + 1;
            vis[v] = true;
            Q.push(v);
        }
    }
    int x, y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[Point(i, j)] == -1){
                x = i, y = j;
            }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            Point u = Point(i, j);
            if (mp[u] == -1)
                continue;
            for (int k = 0; k < 2; k++){
                Point v = u + nxt[k];
                if (!v.isLegal(n, m) || mp[v] == -1)
                    continue;
                if (k == 0 && v.x == x && v.y < y){
                    Kru.addEdge(Point(u, 0), Point(v, 1), min(dis[u], dis[v]));
                    Kru.addEdge(Point(u, 1), Point(v, 0), min(dis[u], dis[v]));
                }else{
                    Kru.addEdge(Point(u, 0), Point(v, 0), min(dis[u], dis[v]));
                    Kru.addEdge(Point(u, 1), Point(v, 1), min(dis[u], dis[v]));
                }
            }
        }
    }
    int rt = Kru.solve(2 * n * m, true);
    // cout << rt << endl;
    LCA.G = G;
    LCA.solve(rt);
    for (int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        // cout << "LCA: " << LCA.getLCA(x, y) << endl;
        Point u(x, y, 0), v(x, y, 1);
        cout << val[LCA.getLCA(u, v)] << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define INF 1e17
#define FOR(a, b, c) for (int a = b; a < c; a++)
#define int long long
#define pb push_back
typedef vector <int> vint;
const int N = 1e5 + 2;
vector < vector < pair < int , int > > > v;
vint subtree, dist;
vector < pair < int , int > > from,dia;
int n, k, cnt;
void dfs(int s, int u){
    for(auto [child, w] : v[s]){
        if(child != u){
            from[child] = {s, w};
            dist[child] = dist[s] + w;
            dfs(child, s);
            subtree[s] = max(subtree[s], subtree[child] + w);
        }
    }
}
int get_center(){
    dist.assign(n+1,0);
    subtree.assign(n+1,0);
    from.assign(n+1,{-1,-1});
    dfs(1,0);
    int end1 = 0, end2 = 0, root = 0;
    FOR(i,1,n+1){
        if(dist[i] > dist[end1]) end1 = i;
    }
    dist.assign(n+1,0);
    dfs(end1,0);
    FOR(i,1,n+1) if(dist[i] > dist[end2]) end2 = i;
    int x = end2, d = dist[end2];
    while(x != end1){
        dia.pb(from[x]);
        x = from[x].first;
    }
    int mini = INF, curr = 0, center = -1;
    for(auto [x, w] : dia){
        curr += w;
        if(max(d - curr, curr) < mini){
            mini = max(d - curr, curr);
            center = x;
        }
    }
    return center;
}
int check(int s, int u, int mid){
    int gmid = 0;
    cnt++;
    // cout << s << " " << cnt << endl;
    for(auto [child, w] : v[s]){
        if(w + subtree[child] > mid && child != u){
            check(child, s, mid);
            gmid++;
        }
    }
    if(u == 0 && gmid > 2) cnt += INF;
    if(u && gmid > 1) cnt += INF;
    return cnt <= k;
}
void solve(){
    cin >> n >> k;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    v.assign(n+1,vector < pair < int , int > >());
    subtree.assign(n+1,0);
    FOR(i,0,n-1){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    int root = get_center();
    subtree.assign(n+1, 0);
    dfs(root, 0);
    int l = 0, r = 1e10;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        cnt = 0;
        if(check(root, 0, mid)) r = mid;
        else l = mid;
    }
    cnt = 0;
    cout << (check(root, 0, l) ? l : r) << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10) << endl;
    int t;
    t = 1;
    while(t--)
    solve();
}
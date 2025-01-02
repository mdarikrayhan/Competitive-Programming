#include <bits/stdc++.h>
using namespace std;

#define int long long 

void init(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif //
}

const int N = 1e5+5;
const int INF = 1e18;
vector <int> graph[N];

vector<int> bfs(int source){
    vector <int> depth(N);
    for(int i=0; i<N; i++){
        depth[i] = INF;
    }
    depth[source] = 0;

    queue <int> q;
    q.push(source);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt:graph[cur]){
            if(depth[nxt]==INF){
                depth[nxt] = 1+depth[cur];
                q.push(nxt);
            }
        }
    }
    return depth;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0); init();

    int n,k;
    cin >> n >> k;
    for(int i=0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector <int> dist1 = bfs(1);
    int b;
    int d = 0;
    for(int i=1; i<=n; i++){
        if(dist1[i]>d){
            d = dist1[i];
            b = i;
        }
    }
    vector <int> dist2 = bfs(b);

    int a;
    d = 0;
    for(int i=1; i<=n; i++){
        if(dist2[i]>d){
            d = dist2[i];
            a = i;
        }
    }
    vector <int> dist3 = bfs(a);

    vector <int> centre;
    for(int i=1; i<=n; i++){
        if(dist3[i]==k && dist2[i]==k){
            centre.push_back(i);
        }
    }

    if(centre.size()!=1){
        cout << "No" << "\n";
        return 0;
    }
    else{
        queue <vector<int>> q;
        q.push({centre[0],0,centre[0]});
        while(!q.empty()){
            int cur = q.front()[0];
            int di = q.front()[1];
            int par = q.front()[2];
            q.pop();
            int cnt = 0;

            if(di==k){
                if(graph[cur].size()==1){
                    continue;
                }
                else{
                    cout << "No" << "\n";
                    return 0;
                }
            }

            for(auto nxt:graph[cur]){
                if(nxt!=par){
                    cnt++;
                    q.push({nxt,di+1,cur});
                }
            }
            if(cnt<3){
                cout << "No" << "\n";
                return 0;
            }
        }
        cout << "Yes" << "\n";
    }

}
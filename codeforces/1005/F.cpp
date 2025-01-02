#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    #ifdef ONLINE_JUDGE
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    #endif //fast IO
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adjlist(n);
    vector<vector<int>> edges;
    for (int i=0; i<m; i++) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adjlist[x].push_back({y,i});
        adjlist[y].push_back({x,i});
        edges.push_back({x,y,i});
    }
    int INF = 100000007;
    vector<int> dist(n,INF);
    dist[0] = 0;
    deque<int> visited;
    visited.push_back(0);
    vector<int> proc(n,0);
    while (visited.size()) {
        int f = visited[0];
        visited.pop_front();
        if (proc[f]) {
            continue;
        }
        proc[f] = 1;
        for (auto j:adjlist[f]) {
            if (dist[f]+1 < dist[j.first]) {
                visited.push_back(j.first);
                dist[j.first] = dist[f] + 1;
            }
        }
    }
    
    vector<int> bases(n);
    vector<vector<int>> values(n);
    for (auto edge:edges) {
        int x,y,i;
        x=edge[0];
        y=edge[1];
        i=edge[2];
        if (dist[x] == dist[y]-1) {
            values[y].push_back(i);
        }
        else if (dist[y] == dist[x]-1) {
            values[x].push_back(i);
        }

    }
    for (int i=0; i<n; i++) {
        bases[i] = values[i].size();
        sort(values[i].begin(), values[i].end());
        //cout << i <<" " << values[i].size() << endl;
    }
    vector<vector<int>> answers;
    for (int i=0; i<k; i++) {
        int r = i;
        vector<int> anslist(m,0);
        for (int j=1; j<n; j++) {
            //cout << i <<" " << r << " " <<" " << values[j].size() << endl;
            anslist[values[j][r%bases[j]]] = 1;
            r/=bases[j];
        }
        if (r!=0) {
            break;
        }
        answers.push_back(anslist);
        
    }
    cout << answers.size() << endl;
    for (auto i:answers) {
        for (auto j:i) {
            cout << j;
        }
        cout << endl;
    }

    
    
}


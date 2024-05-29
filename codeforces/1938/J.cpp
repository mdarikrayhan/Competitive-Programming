#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;

void dijkstra(vector<vector<pii> > &gr, int start, vector<int>&dist) {
    priority_queue <pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, start));
    dist.clear();
    dist.resize(gr.size(), 1e9);
    dist[start] = 0;

    while(not pq.empty()) {
        pii tmp = pq.top();
        int node = tmp.se;
        int cost = tmp.fi;
        pq.pop();

        for(pii adj : gr[node]) {
            if(cost + adj.fi < dist[adj.se]) {
                dist[adj.se] = cost + adj.fi;
                pq.push(make_pair(dist[adj.se], adj.se));
            }
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    vector<vector<pii> > gr(n);
    set <pair<int, pii> > edges;
    while(m--) {
        int u,v,t;
        cin>>u>>v>>t;
        --u,--v;

        gr[u].push_back(make_pair(t, v));
        gr[v].push_back(make_pair(t, u));
        edges.insert(make_pair(t, make_pair(u,v)));
        edges.insert(make_pair(t, make_pair(v,u)));
    }

    vector<int> d1, d2;
    dijkstra(gr, 0, d1);
    dijkstra(gr, n-1, d2);

    if(d1.back() == 1e9) {
        cout << "-1\n";
        return 0;
    }

    set <pair<int, pii> > shortest;
    int curr = n-1;
    while(curr) {
        for(pii adj : gr[curr]) {
            if(d1[curr] == d1[adj.se] + adj.fi) {
                shortest.insert(make_pair(adj.fi, make_pair(curr, adj.se)));
                shortest.insert(make_pair(adj.fi, make_pair(adj.se, curr)));
                curr = adj.se;
                break;
            }
        }
    }

    int second = 1e9;
    for(pair<int, pii> edge : edges) {
        //If not in shortest
        if(shortest.find(edge) == shortest.end())
        {
            pii vs = edge.se;
            second = min(second, d1[vs.fi] + edge.fi + d2[vs.se]);
        }
    }

    if(second == 1e9) cout << "-1\n";
    else cout << d1[n-1] + second << endl;
}

	  	      		  		 		 		   	  		
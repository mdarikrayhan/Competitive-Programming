# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> val;
vector<int> ans;
int root, sum;

void build_graph(int n){
    int u,v;
    adj.clear();
    val.clear();
    adj.resize(n+1);
    val.resize(n+1);

    for (int i = 1; i <= n; i++){
        cin >> u >> v;

        if (u == 0){
            root = i;
        }
        else{
            adj[u].push_back(i);
            adj[i].push_back(u);
        }

        sum += v;
        val[i] = v;
    }
}

bool dfs(int v, int p){
    bool flag = false;
    for (auto &u: adj[v]){
        if (u == p) continue;
        if (dfs(u,v)){
            flag = true;
        }
        val[v] += val[u];
    }

    if(p != -1){
        if ((flag && val[v] == 2*sum) || (!flag && val[v] == sum)){
            flag = true;
            ans.push_back(v);
            if((int(ans.size() == 2))){
                cout << ans[0] << " " << ans[1] << endl;
                exit(0);
            }
        }
    }
    return flag;
}


void solve(){
    int n; 
    cin >> n;

    sum = 0;
    build_graph(n);

    if (sum%3 != 0){
        cout << -1 << endl;
        return ;
    }
    
    sum /= 3;
    dfs(root, -1);

    cout << -1 << endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
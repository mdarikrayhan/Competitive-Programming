#include <bits/stdc++.h>

using namespace std;
#define MAX_N 200005
#define ll long long

ll n, x, y;
vector<vector<ll>> span_tree(MAX_N);
ll dp[MAX_N][2];

bool is_star() {
    for(int i = 1; i <= n; ++i) {
        if(span_tree[i].size() != 1 && span_tree[i].size() != n-1) {
            return 0;
        }
    }
    return 1;
}

void dfs(int x1, int fa) {
    vector<int> info(2, 0);
    ll sum = 0;
    for (auto y1 : span_tree[x1]) if (y1 != fa) {
        dfs(y1, x1);
        sum += dp[y1][1];
        info.push_back(dp[y1][0] - dp[y1][1]);
    }
    nth_element(info.begin(), info.begin() + 1, info.end());
    dp[x1][0] = sum+info[0];
    dp[x1][1] = 1+sum+info[0]+info[1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x >> y;
    
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        span_tree[a].push_back(b);
        span_tree[b].push_back(a);
    }
        
    if(x >= y) {
        cout << (is_star() ? (n-2)*y+x : (n-1)*y) << "\n";
        return 0;
    } 
    
    dfs(1, -1);
    cout << x*(n-dp[1][1])+y*(dp[1][1]-1) << "\n";
    
    return 0;
}
		 		 	  			 	 	  			 	  		 	
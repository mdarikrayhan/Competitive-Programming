#include <bits/stdc++.h>
using namespace std;

#define MH 650005
#define N 100005
#define M 10

int base = 28, pw[M], pos[MH], n, m, k, in[N];
string s[N];
vector<int> adj[N];


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     	 
    pw[0] = 1;
    for (int i = 1; i <= 4; i++){
    	pw[i] = pw[i - 1] * base;
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
    	cin >> s[i];
    	int hsh = 0;
    	for (int j = 0; j < (int) s[i].size(); j++){
    		if (s[i][j] == '_') hsh += 27 * pw[j];
    		else hsh += (s[i][j] - 'a' + 1) * pw[j];
    	}
    	pos[hsh] = i;
    }

    for (int i = 1; i <= m; i++){
    	string ss; int ps;
    	cin >> ss >> ps;
    	int ok = 0;
    	for (int msk = 0; msk < 1 << k; msk++){
    		int hsh = 0;
    		for (int j = 0; j < k; j++){
    			if ((msk >> j) & 1){
    				hsh += (ss[j] - 'a' + 1) * pw[j];
    			}
    			else hsh += 27 * pw[j];
    		}	
    		if (pos[hsh] == ps){
    			ok = 1;
    			continue;
    		}
    		if (pos[hsh] == 0) continue;
    		adj[ps].push_back(pos[hsh]);
    		in[pos[hsh]]++;
    	}
    	if (!ok){
    		cout << "NO";
    		return 0;
    	}
    }

    queue<int> q;
    for (int i = 1; i <= n; i++){
    	if (!in[i]) q.push(i);
    }
    vector<int> res;

    while (!q.empty()){
    	int u = q.front();
    	q.pop();
    	res.push_back(u);
    	for (auto x : adj[u]){
    		in[x]--;
    		if (!in[x]) q.push(x);
    	}
    }

    if ((int) res.size() != n){
    	cout << "NO";
    	return 0;
    }

    cout << "YES\n";
    for (auto x : res) cout << x << " ";

    return 0;
}     
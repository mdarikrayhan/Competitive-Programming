#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mp make_pair

string dir[8] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};
int dn[8] = { 0, 0, 1,-1, 1,-1, 1,-1};
int dc[8] = {-1, 1, 0, 0,-1,-1, 1, 1};
map<pair<char, int>, bool> mark;
map<pair<char,int>, int> step;

pair<int, int> get_parent(char c, int n, int i){
    return mp(c-dc[i], n-dn[i]);
}

bool is_valid(char c, int n){
    if(c < 'a' or c > 'h') return false;
    if(n < 1 or n > 8) return false;
    return true;
}

void solve(){
    char li, lf; //letra inicial, letra final
    int ni, nf;// numero inicial, numero final
    cin >> li >> ni;
    cin >> lf >> nf;

    queue<pair<int, int>> q;
    q.push({li, ni});
    step[mp(li, ni)] = -1;
    mark[mp(li, ni)] = true;

    while(not q.empty()){
        auto [c, n] = q.front(); q.pop();

        for(int i=0; i<8; i++){
            char cn = c + dc[i];
            int nn = n + dn[i];
            if(not is_valid(cn, nn)) continue;
            if(mark[mp(cn, nn)]) continue;
            q.push(mp(cn, nn));
            step[mp(cn, nn)] = i;
            mark[mp(cn, nn)] = true;
        }
    }

    vector<string> res;
    char c = lf;
    int n = nf;

    while(c != li or n != ni){
        int si = step[mp(c, n)];
        res.push_back(dir[si]);
        pair<int, int> parent = get_parent(c, n, si);
        c = parent.first;
        n = parent.second;
    }

    reverse(res.begin(), res.end());

    cout << res.size() << '\n';
    for(auto s : res) cout << s << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}

	  	  		 	 		  	   				 	 		  	
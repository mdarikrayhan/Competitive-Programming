#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define pf push_front
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define all(a) a.begin(), a.end()

using namespace std;

const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fLL;

const int N = 20;
vector<int> v[4], vis(4), path_vis(4);
queue<int> q;
void dfs(int s){
    vis[s] = 1;
    path_vis[s] = 1;
    for(int i = 0; i < v[s].size(); i++){
        int ans = v[s][i];
        if(!vis[ans]){
            dfs(ans);
        }
        else if(path_vis[ans]){
            cout << "Impossible\n";
            exit(0);
        }
    }
    q.push(s);
    path_vis[s] = 0;

}

void solve() {

    for(int i = 0; i < 3; i++){
        string s;
        cin >> s;
        int a1 = s[0] - 64;
        int a2 = s[2] - 64;
        if(s[1] == '>'){
            v[a1].pb(a2);
        }
        else {
            v[a2].pb(a1);
        }
    }

    for(int i = 1; i <= 3; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();
//        cout << x << endl;
        if(x == 1) {
            cout << "A";
        }
        else if(x == 2) {
            cout << "B";
        }
        else if(x == 3) {
            cout << "C";
        }

    }

}

int main() {
    fast
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll tt = 1;
//    cin >> tt;
    while(tt--)
        solve();



    return 0;
}
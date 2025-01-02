#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <chrono>
#include <cstring>
#include <stack>

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair

#define vll vector<ll>
#define vvll vector< vector<ll> >
#define pll pair<ll, ll>
#define vpll vector< pair<ll, ll> >

#define INF 10000000000000
#define MOD 1000000007

#define rep(i, n) for(int i = 0; i < n; ++i)
#define dbg(x) cerr << x << endl;

//author: @u_d_ash_

using namespace std;
using namespace std::chrono;

vvll graph;

vll init, goal;

vll flipper;

vector<bool> vis;


void dfs(ll level, ll of, ll ef, ll node){

    vis[node] = 1;

    if(level % 2 == 1){

        if(of % 2 == 1){
            init[node - 1] = 1 - init[node - 1];
        }

    }else{

        if(ef % 2 == 1){
            init[node - 1] = 1 - init[node - 1];
        }

    }

    if(init[node - 1] != goal[node - 1]){

        init[node - 1] = goal[node - 1];
        flipper.pb(node);

        if(level % 2 == 1){
            of++;
        }else{
            ef++;
        }

        for(auto child : graph[node]){
            if(!vis[child]){
                dfs(level + 1, of, ef, child);
            }
        }

    }else{

        for(auto children : graph[node]){
            if(!vis[children]){
                dfs(level + 1, of, ef, children);
            }
        }

    }

}

int main(){
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //code here

    ll n;
    cin >> n;

    graph.resize(n + 1);
    vis.resize(n + 1);
    init.resize(n);
    goal.resize(n);


    rep(i, n - 1){
        ll x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    rep(i, n){
        cin >> init[i];
    }
    rep(i, n){
        cin >> goal[i];
    }


    dfs(0, 0, 0, 1);

    // okay.. this is a complete junk guesswork strategy (you can't even call it strategy, it's that bad)

    cout << flipper.size() << endl;

    rep(i, flipper.size()){
        cout << flipper[i] << endl;
    }



    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<milliseconds>(stop - start);
    cerr << dur.count();
}
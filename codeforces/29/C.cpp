//यह समाधान टेलीग्राम से लिया गया है |

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <complex>
#include <iomanip>
#include <algorithm>
#include <set>
#include <numeric> 
//#include <functional>
//#include <numeric>
//#include <limits>
//#include <sstream>
#include <queue>
#include <deque>
//#include <bits et>
//#include <list>
//#include <stack>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define whatis(x) cout << #x << " is " << x << endl;
#define ll long long

void dfs(int t, map<int,int> &vis, map<int,vector<int>> &graph){
    vis[t] = 1;

    for(auto x: graph[t]){
        if(!vis[x]){
            cout<<x+1<<" ";
            dfs(x,vis,graph);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("../../io/input.txt", "r", stdin);
    freopen("../../io/error.txt", "w", stderr);
    #endif
    // int test; cin>>test;
    int test = 1;
    while(test--){
        int n; cin>>n;
        map<int,vector<int>>graph;
        
        for(int i=0;i<n;i++){
            int x,y; cin>>x>>y; 
            x--,y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int start;
        for(auto x: graph){
            if(x.second.size()==1) start = x.first;
        }
        map<int,int> vis;
        cout<<start+1<<" ";
        dfs(start,vis,graph);
    }
    // cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
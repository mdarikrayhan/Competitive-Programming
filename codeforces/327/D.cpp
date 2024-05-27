#include<iostream>
#include <iomanip>
#include<math.h>
#include <bits/stdc++.h>
#include<set>
#include<map>
#include<queue>
#include <fstream>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// lower_bound,upperbound swapped for multiset
// change less_equal to equal for set
#define float long double
#define PYes cout<<"Yes\n"
#define PNo cout<<"No\n"
#define PYES cout<<"YES\n"
#define PNO cout<<"NO\n"
#define pq priority_queue
#define int long long
#define endl '\n'
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define ff(i,a,b) for(int i=b-1;i>=a;i--)

// pbds
// s.find_by_order()
// s.order_of_key()

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef vector<pair<int,int>> vp;
#define sz(a) int((a).size())
#define pb push_back

#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
const int inf = 1LL<<60;
const int N=1e9;
vector<pair<char,ii>> finalanswer;
void dfs(vector<vector<char>>&a,ii x,vvi &vis,int n,int m,set<ii>&s){

    if(x.first-1>=0){
        // ii check =make_pair(3,6);
        if(a[x.first-1][x.second]=='.'){
            ii i=make_pair(x.first-1,x.second);
            if(!vis[i.first][i.second]){
                vis[i.first][i.second]=1;
                dfs(a,i,vis,n,m,s);
                finalanswer.pb(make_pair('D',make_pair(i.first+1,i.second+1)));
                finalanswer.pb(make_pair('R',make_pair(i.first+1,i.second+1)));
                s.erase(i);
                }
            
        }
    }
    if(x.first+1<n){
        if(a[x.first+1][x.second]=='.'){
            ii i=make_pair(x.first+1,x.second);
            if(!vis[i.first][i.second]){
                vis[i.first][i.second]=1;dfs(a,i,vis,n,m,s);
                finalanswer.pb(make_pair('D',make_pair(i.first+1,i.second+1)));
                finalanswer.pb(make_pair('R',make_pair(i.first+1,i.second+1)));
                s.erase(i);
                }

        }
    }
    if(x.second-1>=0){
        if(a[x.first][x.second-1]=='.')
            {ii i=make_pair(x.first,x.second-1);
            if(!vis[i.first][i.second]){
                vis[i.first][i.second]=1;dfs(a,i,vis,n,m,s);
                finalanswer.pb(make_pair('D',make_pair(i.first+1,i.second+1)));
                finalanswer.pb(make_pair('R',make_pair(i.first+1,i.second+1)));
                s.erase(i);
                }
            
            }
    }
    if(x.second+1<m){
        if(a[x.first][x.second+1]=='.')
            {ii i=make_pair(x.first,x.second+1);
            if(!vis[i.first][i.second]){
                vis[i.first][i.second]=1;dfs(a,i,vis,n,m,s);
                finalanswer.pb(make_pair('D',make_pair(i.first+1,i.second+1)));
                finalanswer.pb(make_pair('R',make_pair(i.first+1,i.second+1)));
                s.erase(i);
                }
            }
    }
    return;
}



void solve() {
    finalanswer.clear();
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char> (m,'?'));
    set<ii>s;
    f(i,0,n){
        f(j,0,m){
            cin>>a[i][j];
            if(a[i][j]=='.'){s.insert(make_pair(i,j));
            finalanswer.pb(make_pair('B',make_pair(i+1,j+1)));}
        }
    }    
    vvi vis(n,vi(m,0));
    while(!s.empty())
    {ii i=*s.begin();
    s.erase(s.begin());
    vis[i.first][i.second]=1;
    dfs(a,i,vis,n,m,s);
    }
    // if(n!=21)
    {cout<<finalanswer.size()<<endl;
    for(auto i:finalanswer)cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
    // cout<<finalanswer[261].first<<" "<<finalanswer[261].second.first<<" "<<finalanswer[261].second.second;
    // else {
    //     f(i,0,m)cout<<a[20][i];
    //     // f(i,0,n){
    //     //     f(j,0,m){
    //     //         if(a[i][j]=='.'||a[i][j]=='#')
    //     //         cout<<a[i][j];
    //     //         else cout<<'?';
    //     //         }
    //     //     cout<<endl;
    //     // }
    }
    return;
}








int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
// 	cin >> t;
t=1;
    while (t--) {
        solve();
    }
    return 0;
}
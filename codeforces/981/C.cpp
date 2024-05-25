#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
void solve()
{
    cin>>n;
    vector<vector<int>>adj(n,vector<int>());
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt=0;
    int st=-1;
    vector<int>leaves;
    for(int i=0;i<n;i++){
        if(adj[i].size() >=3){
            cnt++;
            if(st = -1){
                st = i;
            }
        }
        if(adj[i].size() == 1){
            leaves.push_back(i);
        }
    }
    if(cnt >=2 ) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        if(st == -1){
            cout<<leaves.size()-1<<endl;
            for(int i=1;i<leaves.size();i++){
                cout<<leaves[0]+1<<" "<<leaves[i]+1<<endl;
            }
        }
        else{
            cout<<leaves.size()<<endl;
            for(int i=0;i<leaves.size();i++){
                cout<<st+1<<" "<<leaves[i]+1<<endl;
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
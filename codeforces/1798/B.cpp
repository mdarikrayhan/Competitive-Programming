#include<bits/stdc++.h>
using namespace std;
void solve(){
    int m; cin>>m;
    vector<int> arr(50001,0);
 
    int n;
    vector<vector<int>> adj(m);
    int j = 0;
    while(j < m){
        cin>>n;
        for (int i = 0, x; i < n; i++)
        {
            cin>>x;
            adj[j].push_back(x);
            arr[x]++;
        }
        j++;
    }
 
    vector<int> winners;
    for (int i = 0; i < m; i++)
    {
        int flag = 1;
        for(auto j: adj[i]){
            if(arr[j] == 1 && flag){
                winners.push_back(j);  
                flag = 0;
            }
            arr[j]--;
        }
 
        if(flag){
            cout<<"-1"<<endl;
            return;
        }
 }   
    for(auto it: winners){
        cout<<it<<" ";
    }
    cout<<endl;    
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
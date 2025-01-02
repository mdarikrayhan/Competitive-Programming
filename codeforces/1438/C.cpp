#include<bits/stdc++.h>
using namespace std;
int n,m,t;
void solve(){
    cin >> n >> m;
    vector< vector<int> > res(n + 3,vector<int>(m + 3));
    for(int i = 1;i <= n;i ++ ){
        for(int j = 1;j <= m;j ++){
            cin >> res[i][j];
            if((i + j)%2 == 1&&res[i][j]%2 == 1)
            res[i][j]++;
            if((i + j)%2 == 0&&res[i][j]%2 == 0)
            res[i][j]++;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j ++ )
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
}
int main(){
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
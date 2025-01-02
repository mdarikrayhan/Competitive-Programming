#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
vector<vector<int>> f1(vector<vector<int>> &m1,vector<vector<int>> &m2){
    int rows1 = m1.size();
    int rows2 = m2.size();
    int columns1 = m1[0].size();
    int columns2 = m2[0].size();
    vector<vector<int>> res(rows1,vector<int>(columns2,0));
    for(int i = 0; i<rows1; i++){
        for(int j = 0; j<columns2; j++){
            for(int k = 0; k<columns1; k++){
                res[i][j] += (m1[i][k]*m2[k][j])%mod;
                res[i][j] %= mod;
            } 
        }
    }
    return res;
}
signed main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 int m,n;
 cin>>m>>n;
 vector<int> short_paths(m);
 vector<int> long_paths(m);
 for(int i = 0; i<m; i++) cin>>short_paths[i];
 for(int i = 0; i<m; i++) cin>>long_paths[i];
 vector<vector<int>> f(m,vector<int>(m));
 for(int i = 0; i<m; i++){
    for(int j = 0; j<m; j++){
        f[i][j] = (short_paths[i]*short_paths[j] + long_paths[i]*short_paths[j])%mod + long_paths[j]*short_paths[i];
        f[i][j] %= mod;
    }
 }
 vector<vector<int>> fn(m,vector<int>(m,0));
 for(int i = 0; i<m; i++) fn[i][i] = 1;
 while(n>0){
    if(n%2==1){
        fn = f1(fn,f);
    }
    n /= 2;
    f = f1(f,f);
 }
 vector<vector<int>> ans(1,vector<int>(m,0));
 ans[0][0] = 1;
 ans = f1(ans,fn);
 int ways = 0;
 for(int i = 0; i<m; i++){
    ways += ans[0][i];
    ways %= mod;
 } 
 cout<<ways;
return 0;
}
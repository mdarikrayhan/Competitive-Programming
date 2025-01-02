#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;

void solve(){  
    int n,m;
    cin >> n >> m;
    vector<string> a(n,string(m,'0'));
    int dx[] = {-1,-1,-1,0,0,1,1,1},dy[] = {-1,0,1,-1,1,-1,0,1};
    for(int j = 0;j < m;j++){
        bool flag = true;
        for(int k = 0;k < 8;k++){
            int x = 0 + dx[k],y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '1')flag = false;
        }
        if(flag)a[0][j] = '1';
    }
    for(int i = 0;i < n;i++){
        bool flag = true;
        for(int k = 0;k < 8;k++){
            int x = i + dx[k],y = m - 1 + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '1')flag = false;
        }
        if(flag)a[i][m - 1] = '1';
    }
    for(int j = m - 1;j >= 0;j--){
        bool flag = true;
        for(int k = 0;k < 8;k++){
            int x = n - 1 + dx[k],y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '1')flag = false;
        }
        if(flag)a[n - 1][j] = '1';
    }
    for(int i = n - 1;i >= 0;i--){
        bool flag = true;
        for(int k = 0;k < 8;k++){
            int x = i + dx[k],y = 0 + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '1')flag = false;
        }
        if(flag)a[i][0] = '1';
    }
    for(int i = 0;i < n;i++)cout << a[i] << endl;
    
    
    



} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
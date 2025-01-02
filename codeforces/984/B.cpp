#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<vector<char> > a(n,vector<char>(m));
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            //check if empty
            if(a[i][j] == '.'){
                //check all 8 directions for *
                bool flag = false;
                if(i-1>=0 && j-1>=0 && a[i-1][j-1] == '*')
                    flag = true;
                if(i-1>=0 && a[i-1][j] == '*')
                    flag = true;
                if(i-1>=0 && j+1<m && a[i-1][j+1] == '*')
                    flag = true;
                if(j-1>=0 && a[i][j-1] == '*')
                    flag = true;
                if(j+1<m && a[i][j+1] == '*')
                    flag = true;
                if(i+1<n && j-1>=0 && a[i+1][j-1] == '*')
                    flag = true;
                if(i+1<n && a[i+1][j] == '*')
                    flag = true;
                if(i+1<n && j+1<m && a[i+1][j+1] == '*')
                    flag = true;
                if(flag){
                    cout<<"NO\n";
                    return 0;
                }
                    
            }
            else if ( a[i][j] != '*'){
                //check all 8 directions for *
                int count = 0;
                if(i-1>=0 && j-1>=0 && a[i-1][j-1] == '*'){
                    count++;
                }
                if(i-1>=0 && a[i-1][j] == '*'){
                    count++;
                }
                if(i-1>=0 && j+1<m && a[i-1][j+1] == '*'){
                    count++;
                }
                if(j-1>=0 && a[i][j-1] == '*'){
                    count++;
                }
                if(j+1<m && a[i][j+1] == '*'){
                    count++;
                }
                if(i+1<n && j-1>=0 && a[i+1][j-1] == '*'){
                    count++;
                }
                if(i+1<n && a[i+1][j] == '*'){
                    count++;
                }
                if(i+1<n && j+1<m && a[i+1][j+1] == '*'){
                    count++;
                }
                if(count != a[i][j] - '0' ){
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
    }

    cout<<"YES\n";
    
    return 0;
}
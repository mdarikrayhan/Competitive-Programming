// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s[10];
        for(int i=0;i<8;i++){
            cin>>s[i];
        }
        for(int i=1;i<8;i++){
            for(int j=1;j<8;j++){
    if(s[i-1][j-1]=='#'&&s[i-1][j+1]=='#'&&s[i+1][j-1]=='#'&&s[i+1][j+1]=='#'){
        cout<<i+1<<" "<<j+1<<endl;
    }
            }
        }
        cout<<endl;
    }
    
    return 0;
}
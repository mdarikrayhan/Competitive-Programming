#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int main(){
    int n;
    cin>>n;
   
    char a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    int f = 1; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j || (i+j==n-1)){
                if(a[i][j] != a[0][0]){f=0; break;}
            }
            else{
                if(a[i][j] != a[0][1] || a[i][j] == a[0][0]){f=0; break;}
            }
        }
    }
   if(f) cout<<"YES\n";
   else cout<<"NO\n";
   
}
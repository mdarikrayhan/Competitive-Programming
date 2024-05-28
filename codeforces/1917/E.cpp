#include <bits/stdc++.h>
using namespace std;
const int c=1003;
 
int ans[c][c];
 
void solve(){
    int n,k;
    cin>>n>>k;

    if(k==2 && n==2){
        cout << "Yes\n";
        cout << "1 0\n0 1\n";
        return;
    }
 
    if((k&1) || (k%4!=0 && (n*n-6<k || k<6))){
        cout << "No\n";
        return;
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=0;
        }
    }
 
    bool van=k%4!=0;
    if(van){
        if(k>=10){
            ans[1][3]=ans[1][4]=ans[2][2]=ans[2][4]=ans[3][1]=ans[3][4]=ans[4][1]=ans[4][2]=ans[4][3]=ans[4][4]=1;
            k-=10;
        }
        else{
            ans[1][1]=ans[1][2]=ans[2][1]=ans[2][3]=ans[3][2]=ans[3][3]=1;
            k-=6;
        }
    }
 
    for(int i=1;i<=n && k>0;i+=2){
        for(int j=1;j<=n && k>0;j+=2){
            if(van && i<=4 && j<=4) continue;
            ans[i][j]=ans[i+1][j]=ans[i][j+1]=ans[i+1][j+1]=1;
            k-=4;
        }
    }
 
    cout << "Yes\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int tc; cin>>tc;
    while(tc--) solve();
}
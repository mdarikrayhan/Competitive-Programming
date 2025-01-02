// LUOGU_RID: 157073191
#include <bits/stdc++.h>
using namespace std;
int n=6;
char a[7][7],target[7][7]={
{' ',' ',' ',' ',' ',' ',' '},
{' ','0','1','2','3','4','5'},
{' ','6','7','8','9','A','B'},
{' ','C','D','E','F','G','H'},
{' ','I','J','K','L','M','N'},
{' ','O','P','Q','R','S','T'},
{' ','U','V','W','X','Y','Z'}
};
vector<pair<char,int>>ans;
void R(int &x){
    for(int i=n+1;i>=2;i--) a[x][i]=a[x][i - 1];
    a[x][1]=a[x][n+1],ans.push_back({'R',x});
}
void L(int &x){
    for(int i=0;i<n;i++) a[x][i]=a[x][i + 1];
    a[x][n]=a[x][0],ans.push_back({'L',x});
}
void U(int &x){
    for(int i=0;i<n;i++) a[i][x]=a[i + 1][x];
    a[n][x]=a[0][x],ans.push_back({'U',x});
}
void D(int &x){
    for(int i=n+1;i>=2;i--) a[i][x]=a[i-1][x];
    a[1][x]=a[n+1][x],ans.push_back({'D',x});
}
int main(){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x,y,f=0;
            for(int k=1;k<=n;k++){
                if(f) break;
                for(int t=1;t<=n;t++){
                    if(a[k][t]==target[i][j]){
                        f=1,x=k,y=t;
                        break;
                    }
                }
            }
            while(y<j){
                for(int i=1;i<=5;i++) U(y),L(x),D(y),R(x),U(y);
                y++;
            }
            while(y>j){
                y--;
                for(int i=1;i<=5;i++) U(y),L(x),D(y),R(x),U(y);
            }
            while(x>i) R(x),D(y),L(x),U(y),R(x),x--;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i].first<<ans[i].second<<endl;
}
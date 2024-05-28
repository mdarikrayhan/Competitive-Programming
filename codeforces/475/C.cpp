#include<bits/stdc++.h>
using namespace std;
int A[1111][1111],rr[1111][1111],dd[1111][1111],C,ans=2e6;
void rec(int x,int y,int dx=-1,int dy=-1,int cnt=0){
if(cnt>C)return;
if(cnt+(dx==-1?1:dx)*(dy==-1?1:dy)==C){
if(dx==-1)dx=1;
if(dy==-1)dy=1;
ans=min(ans,dx*dy);
return;
}
if((dy==-1||rr[x][y]==dy)&&rr[x+1][y]>=dy&&A[x+1][y]&&dd[x+1][y]>=dx)rec(x+1,y,dx,rr[x][y],cnt+rr[x][y]);
if((dx==-1||dd[x][y]==dx)&&dd[x][y+1]>=dx&&A[x][y+1]&&rr[x][y+1]>=dy)rec(x,y+1,dd[x][y],dy,cnt+dd[x][y]);
}
int main(){
int n,m,mx=1e6,my=1e6;
cin>>n>>m;
for(int i=0;i<n;i++){
string s;
cin>>s;
for(int j=0;j<m;j++){
A[i][j]=(s[j]=='X');
if(A[i][j])mx=min(mx,i),my=min(my,j);
C+=A[i][j];
}
}
for(int i=0;i<n;i++)for(int j=m-1;j>=0;j--)rr[i][j]=(A[i][j]?rr[i][j+1]+1:0);
for(int j=0;j<m;j++)for(int i=n-1;i>=0;i--)dd[i][j]=(A[i][j]?dd[i+1][j]+1:0);
rec(mx,my);
if(ans>1e6)ans=-1;
cout<<ans<<endl;
return 0;
}
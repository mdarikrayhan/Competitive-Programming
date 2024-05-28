#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x=1,y=1;
bool u[10][10];
int main(){
u[1][1]=1;
u[8][8]=1;
cin>>n;
cout<<"a1 ";
n--;
while(n--){
if(n<=6&&y!=8&&x!=8)y=8;
else{
bool k=0;
for(int i=8;i>=1;i--)if(!u[i][y]){
x=i;
k=1;
break;
}
if(k==0)y++;
}
u[x][y]=1;
cout<<char('a'+x-1)<<y<<" ";
}
cout<<"h8";
}
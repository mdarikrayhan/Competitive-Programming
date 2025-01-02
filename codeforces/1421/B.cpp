#include<bits/stdc++.h>
using namespace std;
int t,n,val;
string s[200];
bool check(char x,char y){
val=(s[0][1]==y)+(s[1][0]==y)+(s[n-1][n-2]==x)+(s[n-2][n-1]==x);
if(val<=2){
cout <<val<<endl;
if(s[0][1]==y)printf("1 2\n");
if(s[1][0]==y)printf("2 1\n");
if(s[n-1][n-2]==x)printf("%d %d\n",n,n-1);
if(s[n-2][n-1]==x)printf("%d %d\n",n-1,n);
return 1;
}
return 0;
}
int main(){
cin>>t;
while(t--){
cin>>n;
for(int i=0;i<n;i++)cin>>s[i];
if(check('0','1'));
else check('1','0');
}
}
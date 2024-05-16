#include<iostream>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
char colors[n*m];
bool flag = 1;
for(int i=0;i<n*m;i++){
    cin>>colors[i];
    if(colors[i]=='C' || colors[i]=='M' || colors[i]=='Y')
    {
        cout<<"#Color";
        flag =0;
        break;
    }
}
if(flag)
    cout<<"#Black&White";
}
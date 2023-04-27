#include <bits/stdc++.h>
#define X ({int t;cin>>t;t;})
using namespace std;
int main(){
    map<int,int>d;int n=X;
    for(int i=0;i<n;i++)d[X]++,d[X]--;
    int M=-1,j,t=0;
    for(auto [x,y]: d)if((t+=y)>M)M=t,j=x;
    cout<<j<<' '<<M<<'\n';
}
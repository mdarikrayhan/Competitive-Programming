#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    double x,y,x1,y1,x2,y2,t;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    t=(x1-x)*(y2-y1)-(y1-y)*(x2-x1);
    if(!t) cout<<"TOWARDS"; 
    else if(t>0) cout<<"LEFT";
    else cout<<"RIGHT"; 
}
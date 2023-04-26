#include<iostream>
using namespace std;
int main(){
int t,W,H,x1,y1,x2,y2,w,h,a;
for(cin>>t;t--;){
a=INT_MAX;
cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
if(x2-x1+w<=W)a=min(a,max(0,min(w-x1,w-W+x2)));
if(y2-y1+h<=H)a=min(a,max(0,min(h-y1,h-H+y2)));
if(a!=INT_MAX)cout<<a<<endl;
else puts("-1");
}}
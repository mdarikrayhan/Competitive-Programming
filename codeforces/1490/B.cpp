#include <bits/stdc++.h>
using namespace std;
int main (){
 int t,n,a;
 for(cin>>t;t--;){cin>>n;
 int c0=0,c1=0,c2=0;
 for(int i=0;i<n;i++){cin>>a;
 a%3==0?c0++:a%3==1?c1++:c2++;}
 cout<<max(c0-c2,max(c2-c1,c1-c0))<<endl;
}}
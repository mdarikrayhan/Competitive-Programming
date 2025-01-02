#include<iostream>
using namespace std;int a,b,c,d;main(){for(cin>>a;cin>>a>>b>>c>>d;cout<<(a?a+2*c+min(a+1,b-c+d):1)<<"\n"){if(b<c)swap(b,c);}}
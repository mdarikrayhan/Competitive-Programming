#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int f,s,t,fo;
    f=a+b*c;
    s=a*(b+c);
    t=a*b*c;
    fo=(a+b)*c;
    int fi=a+b+c;
    
    int r=max(f,s);
    int r2=max(t,fo);
    r2=max(r2,fi);
    cout<<max(r,r2)<<endl;
}
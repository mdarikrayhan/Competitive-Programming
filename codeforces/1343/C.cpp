#include<iostream>
using namespace std;
int main(){
long long a,n,sum,b,c;
cin>>a;
while(a--){cin>>n;sum=0;cin>>b;n--;while(n--){cin>>c;if(b*c>0){if(c>b)b=c;}
    else
    {sum+=b;b=c;}}
cout<<sum+b<<endl;}
}
#include <bits/stdc++.h>
using namespace std;
void f(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long sum=c-a+1;
    long long sum1=0;
    sum1=(d-b)/2;
    long long sum2=0;
    if(sum%2==1){
        sum2=(sum1+1)*(sum/2+1);
    }
    else{
        sum2=(sum1+1)*(sum/2);
    }
    sum1*=sum/2;
 cout<<sum1+sum2<<endl;
   
    
}
int main()
{
    f();
    return 0;
}
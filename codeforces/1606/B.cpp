#include<iostream>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
long long n,k,c=1,a=0;
cin>>n>>k;
while(c<k){
c*=2;
a++;
} 
a+=(n-c+k-1)/k;
cout<<a<<endl;
}
}
#include <iostream>
using namespace std;
int main(){
    int k,n,w,p=0;
    cin>>k>>n>>w;
    for(int i=1;i<=w;i++){
        p=(k*i)+p;
    }
    if(n>=p){
        cout<<0;
    }
    else{
        cout<<p-n;

    }

}
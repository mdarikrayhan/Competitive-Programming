#include<bits/stdc++.h>
using namespace std;
int primecheck(int n){
    for(int i=2;i<(int)pow(n,0.5)+1;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
signed main(){
    int n;
        cin>>n;
        for(int m=1;m<1000;m++){
            if(!primecheck(n*m+1)){
                // not prime then
                cout<<m<<"\n";
                exit(0);
            }
        }
  
}
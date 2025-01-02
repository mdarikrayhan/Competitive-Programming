#include<iostream>

using namespace std ;

bool checkPrime(int n){

    int cnt = 0;
    int a = 1;

    while(a < n){
        if(n % a == 0) cnt++;
        a++;
    }

    if(cnt == 1) return true;

    return false;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    
    while(true){
        n++;
        if(checkPrime(n)) {
            break;
        }
    }

    if(n == m) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
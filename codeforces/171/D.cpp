//ᕦ(ò_ó)ᕤ
#include <bits/stdc++.h>
using namespace std;
int x[1000123];
int phi(int n){
    int res=n;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            res-=res/i;
        }
    }
    if(n>1){
        res-=res/n;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n; 
    cout<<n%5%3+1;
}
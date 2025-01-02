#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int n;
    cin>>n;
    if(n/2>2){
        if(n%2==0){
        while(n>0){
            n-=2;
            s+='1';
        }
        cout<<s;
        }
        else{
            n-=3;
            s+='7';
            while(n>0){
                n-=2;
                s+='1';
            }
            cout<<s;
        }
    }
    else{
        if(n==2){
            cout<<1;
        }
        if(n==3){
            cout<<7;
        }
        if(n==4){
            cout<<11;
        }
        if(n==5){
            cout<<71;
        }
    }

    return 0;
}
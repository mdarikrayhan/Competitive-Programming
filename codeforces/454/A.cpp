#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n/2+1; i++){
        for(int j=0; j<(n-1)/2-i; j++){
            cout<<"*";
        }
        for(int j=0; j<2*i+1; j++){
            cout<<"D";
        }
        for(int j=0; j<(n-1)/2-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n/2-1; i>=0; i--){
        for(int j=0; j<(n-1)/2-i; j++){
            cout<<"*";
        }
        for(int j=0; j<2*i+1; j++){
            cout<<"D";
        }
        for(int j=0; j<(n-1)/2-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}


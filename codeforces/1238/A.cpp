#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll int t;
    cin>>t;
    for(auto i=0;i<t;i++){
        ll int a,b;
        cin>>a>>b;
        if(a-b>1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
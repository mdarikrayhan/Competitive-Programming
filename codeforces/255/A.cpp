#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a=0, b=0, c=0, d;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>d;
        if(i%3==0){
            a+=d;
        }
        if(i%3==1){
            b+=d;
        }
        if(i%3==2){
            c+=d;
        }
    }
    if(a>b && a>c){
        cout <<"chest";
    }
    else if(b>c){
        cout<<"biceps";
    }
    else{
        cout<<"back";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int y=0, x=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='x'){
            x++;
        }
        else y++;
    }
    if(x>y){
        for(int i=0; i<x-y; i++){
            cout<<"x";
        }
    }
    if(y>x){
        for(int i=0; i<y-x; i++){
            cout<<"y";
        }
    }
}


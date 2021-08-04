#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int u=0,l=0;
    for ( int i=0;i<s.length();i++){
        if(s[i]>96){
       l++;
        }
        else{
        u++;
    }
    }

     if(u<=l){
        for ( int i=0;i<s.length();i++){
        if(s[i]<91){
        s[i]=s[i]+32;
        }}    
    }
        else{
        for ( int i=0;i<s.length();i++){
        if(s[i]>96){
        s[i]=s[i]-32;
        }}    
    }
    cout<<s;

}
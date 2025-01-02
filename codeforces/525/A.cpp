#include <bits/stdc++.h>
using namespace std;


int main(){
    
        long long int n;
        cin>>n;
        string s;
        cin>>s;
        long long int x=2*n - 2;
        long long int c=0;
        
        int a[26]={0};
        for(int j=0;j<x;j=j+2){
            
            a[s[j]-'a']++;
            if(a[s[j+1]-'A']>0){
                a[s[j+1]-'A']--;
            }else{
                c++;
            }

        }
        cout<<c;


}
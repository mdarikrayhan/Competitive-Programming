#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       string s;
       cin>>s;
       sort(s.begin(),s.end());
       int l=s.size()-1;
       int d=static_cast<int>(s[l]);
       cout<<d-96<<endl;
    }
}
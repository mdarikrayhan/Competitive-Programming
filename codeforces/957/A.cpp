#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    int f1,f2,f3;
    f1=f2=f3=0;
    int f=1;
    for(int i=1;i<n;i++){
        if(s[i]=='?') {continue;}
        if(s[i]==s[i-1]) f=0;
    }

    if(s[0]=='?' || s[n-1]=='?') f1=1;

    for(int i=0;i<n-1;i++) if(s[i]=='?' && s[i+1]=='?') f2=1;

    for(int i=1;i<n-1;i++) if(s[i]=='?' && s[i-1]==s[i+1]) f3=1;

    if((f1|| f2 ||f3) && f) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;

}
#include<iostream>
using namespace std;
int main(){
    int count=0;
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    for(int i=0,j=n-1;i<n,j>=0;++i,--j){
        if(s1[i]!=s2[j]){
            count++;
            break;
        }
    }
    if(count==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
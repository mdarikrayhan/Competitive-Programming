#include<iostream>
using namespace std;
int main(){
int t;
cin>>t;
string s;
for(int i=0;i<t;i++){
        cin>>s;
        cout<<s[0]<<s[1];
    for(int j=2;j<s.length();j++)
        if(j%2==0)
            continue;
        else
            cout<<s[j];
    cout<<endl;
}


}
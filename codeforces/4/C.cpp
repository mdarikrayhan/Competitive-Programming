#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,n,j;string s;
    cin>>n;
    map<string,int> m;
    for(i=0;i<n;i++){
        cin>>s;
        if(!m[s]){
           cout<<"OK"<<endl;
        }
        else{
            cout<<s<<m[s]<<endl;
        }
        m[s]++;
    }
   
    return 0;
}
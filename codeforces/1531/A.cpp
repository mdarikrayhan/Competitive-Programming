// LUOGU_RID: 158221299
#include<bits/stdc++.h>
using namespace std;
int n; bool f;
string s="blue",cur;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cur;
        if(cur=="lock")f=1;
        else if(cur=="unlock")f=0;
        else{
            if(f==1)continue;
            else s=cur;
        }
    }cout<<s<<endl;
    return 0;
}
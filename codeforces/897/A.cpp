#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,l,r;
    cin>>n>>m;
    string s;
    cin>>s;
    char c1,c2;
    while(m--){
    cin>>l>>r>>c1>>c2;
    for(int i=l-1;i<r;i++){
        if(s[i]==c1){
            s[i]=c2 ;
        }
    }
    }
    cout<<s<<endl;

    
    return 0;
}
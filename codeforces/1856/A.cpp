#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        int res=0, cur=0;
        for(int i = 0; i < n; i++){
            int x; 
            cin>>x;
            if(x < cur){
                res = (res > cur ? res : cur);
            }
            cur = x;
        }
        cout<<res<<endl;
    }
}
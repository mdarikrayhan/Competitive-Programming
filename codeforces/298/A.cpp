#include<bits/stdc++.h>
using namespace std;
#define int long long

void Fast() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool prime(int x){
    if(x==1){
        return 0;
    }
    if(x==2){
        return 1;
    }
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

void solve(){
    /* Omar_zydan */
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mod1=0,mod2=0;
    for(int i=0;i<n;i++){
        if(arr[i]=='R'){
            mod1=1;
        }
        if(arr[i]=='L'){
            mod2=1;
        }
    }
    int mode;
    if(mod1&&mod2){
        mode=3;
    }
    else if(mod1&&!mod2){
        mode=1;
    }
    else if(mod2&&!mod1){
        mode=2;
    }
    int start,end;
    if(mode==1){
        for(int i=0;i<n;i++){
            if(arr[i]=='R'){
                start=i+1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]=='R'){
                end=i+2;
            }
        }
    }
    if(mode==2){
        for(int i=0;i<n;i++){
            if(arr[i]=='L'){
                end=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]=='L'){
                start=i+1;
            }
        }
    }
    if(mode==3){
        for(int i=0;i<n;i++){
            if(arr[i]=='R'){
                start=i+1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]=='L'){
                end=i;
                break;
            }
        }
    }
    cout<<start<<" "<<end;
}
int32_t main(){
    Fast();
    int q;
    // cin>>q;
    q=1;
    while(q--){
        solve();
    }
}
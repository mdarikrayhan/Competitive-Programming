#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
bool st(int a,int b,int x){
    if(b==0)return a==x;
    if(x<=a && x%b==a%b)return 1;
    return st(b,a%b,x);
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,x;
        
        cin>>a>>b>>x;
        if(a<b)swap(a,b);
        if(st(a,b,x))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

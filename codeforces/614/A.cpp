#include<bits/stdc++.h>
#define int __int128
using namespace std;
long long l,r,k;
int check(int x){
    int p=1;
    while (p<x){
        p*=(int)k;
        if (p<0) break;
    }
    if (p<0) return -1;
    return p;
}
string construct(int x){
    string s="";
    while (x){
        s=(char)(x%10+48)+s;
        x/=10;
    }
    return s;
    
}
signed main(){
    cin>>l>>r>>k;
    int st=check(l);
    if (st==-1){
        cout<<-1<<endl;
    }
    else if (st>r) cout<<-1<<endl;
    else{
        while (st<=r){
            cout<<construct(st)<<" ";
            st*=k;
            if (st<0) break;
        }
        cout<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,s;
    for(cin>>t;t--;){
        cin>>n>>k;int a[n],x=n,y=101;
        for(int &i:a) cin>>i;
        for(s=0;y--;x=min(s,x),s=0) for(int i=0;i<n;i++) if(a[i]!=y) s++,i+=k-1;
        cout<<x<<'\n';
    }
}
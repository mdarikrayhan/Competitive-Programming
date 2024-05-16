#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long u,v;
        cin>>n>>u>>v;
        long long a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        string s1="NO";
        long long cost=INT64_MAX;
        long long g=INT64_MAX,g1=INT64_MIN,p,h,j=-1,k;
        for(int i=0;i<n-1;i++){
              if(abs(a[i]-a[i+1])>1){
                   s1="YES";
                   cost=0;
                   break;
              }
              if(a[i]<g){
                p=i;
              }
              if(a[i]>g1){
                h=i;
              }
              g=min(a[i],g);
              g1=max(a[i],g1);
              if(abs(a[i]-a[i+1])==1){
                  j=i;
              }
        }
        // cout<<s1<<" "<<j<<endl;
        if(s1=="YES"){
            cout<<cost<<endl;
        }
        else{
           if(j!=-1){
            cost=min(u,v);
            cout<<cost<<endl;
           }
           else{
              cost=min(u+v,2*v);
              cout<<cost<<endl;
           }
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
signed main(){
  fastio();
#ifndef ONLINE_JUDGE
freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    int t ; cin>>t;
    while(t--){
        int n; cin>>n;
        char c; cin>>c;
        string s; cin>>s;
        int ct=0;
        for(int i=0; i<n ; i++){
          if(s[i]!=c){
           ++ct; 
        }
        }
        if(ct==0){
          cout<<0<<endl;
        }
        else if(s[n-1]==c){
          cout<<1<<endl;
          cout<<n<<endl;
        }
        else{
          int flag=0;
          for(int i=n-1; i>=0; i--){
            if(s[i]==c){flag=i+1; break;}
          }
          if(flag>n/2){
            cout<<1<<endl;
            cout<<flag<<endl;
          }
          else{
            cout<<2<<endl;
            cout<<n-1<<" "<<n<<endl;
          }
        }
        }    
return 0;
}
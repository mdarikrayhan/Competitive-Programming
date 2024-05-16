#include <bits/stdc++.h>
using namespace std;
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
 int t;
 cin>>t;
 while(t--){
    int a;
    cin>>a;
    if(360%(180-a)==0){
        cy;
    }
    else{
        cn;
    }
 }
    return 0;
}
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    long long ans=0;
    bool g=false;
    int f=0;
    while(t--){
        int n;
        cin>>n;
        if(n==0){
            g=true;
        }
        if(n>=0){
            ans=ans+abs(n-1);
        }
        else{
            f++;
            ans=ans+abs(-1-n);
        }
    }
    if(f%2==0){
        cout<<ans;
       return 0;
    }
    else{
        if(g){
            cout<<ans;
            return 0;
        }
        cout<<ans+2;
        return 0;
    }
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ma1=0,ma2=0;
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a>=ma1)ma2=ma1,ma1=a;
            else if(a>=ma2)ma2=a;
        }
        if(ma1-ma2>1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
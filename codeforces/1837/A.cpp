#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
       if(x%k==0){
        cout<<"2"<<endl;
        cout<<x-k+1<<" "<<k-1;
        
       }
       else{
        cout<<"1"<<endl;
        cout<<x;
       }
       cout<<endl;
    }
    return 0;
}
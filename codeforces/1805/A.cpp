#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int b=0;
        if(n%2!=0){
            for(int i=0;i<n;i++){
                b=b^a[i];
            }
            cout<<b<<endl;
        }else if(n%2==0){
            for(int i=0;i<n;i++){
                b=b^a[i];

            }if(b==0){
                cout<<0<<endl;
            }else{
                cout<<-1<<endl;
            }
       
    }
}
}
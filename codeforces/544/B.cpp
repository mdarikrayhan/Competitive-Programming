#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    if(k>ceil((n*n)/2.0)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        bool a=false;
        for(int i=0; i<n ; i++){
            for(int j=0; j<n; j++){
                if(k>0 and j%2==a){
                    cout<<'L';
                    k--;
                }
                else
                    cout<<'S';
            }
            cout<<endl;
            a=!a;
        }
        cout<<endl;
    }
}

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        long long t1=0;
        long long t2=0;
        for(int i=0;i<n;i++){
            t1+=a[i];
        }
        for(int i=0;i<m;i++){
            t2+=b[i];
        }
        if(t1>t2) cout<<"Tsondu"<<endl;
        else if(t2>t1) cout<<"Tenzing"<<endl;
        else cout<<"Draw"<<endl;
    }
    return 0;
}
// LUOGU_RID: 160519764
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    if(k<=n/2){
        for(int i=1;i<k;i++)
            cout<<"LDRU";
        cout<<"L";
    }
    else{
        int kk=(n-2)-k+1;
        for(int i=1;i<kk;i++)
            cout<<"RDLU";
        cout<<"R";
        for(int i=1;i<=n/2+3;i++)
            cout<<"RDRU";
        cout<<"LU";
        k=n/2;
        for(int i=1;i<k;i++)
            cout<<"LDRU";
        cout<<"L";
    }
    return 0;
}
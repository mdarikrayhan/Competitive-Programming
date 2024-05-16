#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int s = 0;
    int i = 1;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    while(1){
        if((s+i) > m)break;
        s+=i;
        
        if((i+1)%n != 0) i = (i+1)%n;
        else i++;
        
        if(s==m)break;
    }
    cout<<(m-s)<<endl;
    return 0;
}
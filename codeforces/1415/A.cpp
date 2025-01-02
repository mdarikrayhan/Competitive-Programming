#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m,r,c,x,y,i,j,mm,mmm;
        cin>>n>>m>>r>>c;
        x=abs(r-1);
        y=abs(n-r);
        mm=max(x,y);
        i=abs(c-1);
        j=abs(m-c);
        mmm=max(i,j);
        cout<<mm+mmm<<endl;

    }
}

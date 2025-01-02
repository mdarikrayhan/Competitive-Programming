#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a==9&&b==1){
        cout<<999<<" "<<1000;
    }
    else if(a==b){
        cout<<(a*100)+2<<" "<<(b*100)+3;
    }
    else if(b-a==1){
        cout<<(a*100)+99<<" "<<(b*100);
    }
    else
    cout<<"-1";

    return 0;
}
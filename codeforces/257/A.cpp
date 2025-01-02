#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int f,d,s,j;
    cin>>f>>d>>s;
    int a[f],c=0,b=0,i=f-1;
    d=d-s;
    
    for(j=0;j<f;j++){
        cin>>a[j];
    }
    if(d<=0){
        cout<<"0";
        return 0;
    }
    d++;
    sort(a,a+f);
    while(i>=0){
        b=b+a[i];
        c++;
        if(b>=d){
            cout<<c;
            return 0;
        }
        b--;
        i--;
    }
    cout<<"-1";
    
    return 0;
}
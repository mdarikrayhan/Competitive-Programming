#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,time=240,sum=0,count=1;
    cin>>n>>t;
    time=time-t;
    while(sum<=time){
        sum=sum+count*5;
        count++;
    }
    if(count-2<n){
    cout<<count-2;}
    else{
        cout<<n;
    }
    
    return 0;
}
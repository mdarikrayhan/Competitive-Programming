#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int t=0;
    for(int i=1;i<n;i++)if(abs(a[i]-a[i-1])>1)t=1;
    if(t)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
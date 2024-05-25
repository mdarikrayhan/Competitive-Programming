// Hydro submission #664e745c5fc569b8da962960@1716417629650
#include <bits/stdc++.h>
using namespace std;
long long n,a[101];
long long f(int i){
    if(i==0){
        return a[0];
    }
    return f(i-1)-i+a[i]*(i+1);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<f(n-1);
}
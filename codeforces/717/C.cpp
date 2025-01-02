#include <bits/stdc++.h>
using namespace std;
int main() {
    long long sum=0;
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0,z=n-1;i<=z;i++,z--){
        if(i!=z){
        sum+=(a[i]*a[z]*2)%10007;
        }
        else{
            sum+=a[i]*a[i];
        }
    }
    cout<<sum%10007;
    

    return 0;
}
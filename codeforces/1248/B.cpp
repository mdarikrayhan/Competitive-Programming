#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long totsum=0;
    for(int i=0;i<n;i++) {
        totsum+=arr[i];
    }
    if(n%2!=0) {
        long long temp=(n/2)+1;
        long long horizontal=0;
        long long vertical=0;
        long long ct1=0;
        for(int i=n-1;i>=0;i--) {
            if(ct1==temp) break;
            horizontal+=arr[i];
            ct1++;
        }
        vertical=totsum-horizontal;
        cout<<((vertical*vertical)+(horizontal*horizontal))<<endl;
    }
    else {
        long long tempo=n/2;
        long long horizontal=0;
        long long vertical=0;
        long long ct2=0;
        for(int i=n-1;i>=0;i--) {
            if(ct2==tempo) break;
            horizontal+=arr[i];
            ct2++;
        }
        vertical=totsum-horizontal;
        cout<<((horizontal*horizontal)+(vertical*vertical))<<endl;
    }
    return 0;
}
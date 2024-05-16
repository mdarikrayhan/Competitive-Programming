#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i=0,j=0;
    long long sum=0,maxi=0,maxim=INT_MIN;
    while(j<n){
        if(sum+a[j]<=t)
        {
            sum+=a[j];
            maxi++;
            j++;
             maxim=max(maxi,maxim);
        }
        else if(j<n&&a[j]>t){
            j++;
            i=j;
            sum=0;
            maxi=0;
             maxim=max(maxi,maxim);
        }
        else if(i<n&&sum+a[j]>t){
            maxim=max(maxi,maxim);
            i++;
            sum-=a[i-1];
            maxi--;
        }
    }
    cout << maxim;
    return 0;}
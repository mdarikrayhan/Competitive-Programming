#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while (t--){
        ll n,k5=0;
        cin>>n;
        ll a[n];
        for (int i=0; i<n; i++) {
            cin>>a[i];
            if (a[i]%5==0){
                k5=1;
                a[i] += (a[i]%10);
            }
        }
        if (k5){
            ll k = *max_element(a,a+n);
            ll l = *min_element(a,a+n);
            if (k==l) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
            continue;
        }
        ll k2=0,k12=0;
        for (int i=0; i<n; i++){
            while (a[i]%10!=2){
                a[i] += a[i]%10; 
            }
            if (a[i]%20==2) k2=1;
            if (a[i]%20==12) k12=1;
        }
        ((k2 && k12) ? cout<<"NO"<<"\n" : cout<<"YES"<<"\n");
    }
}
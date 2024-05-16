#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pyes cout<<"YES"<<endl;
#define pno cout<<"NO"<<endl;



int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> v(n);

        set<ll> s;

        for(ll i=0;i<n;i++){
            cin>>v[i];
            s.insert(v[i]);

        }

        vector<ll> arr;
        arr.push_back(v[0]);
        for(ll i=0;i<n;i++){
            if(v[i]!=v[i-1]){
                arr.push_back(v[i]);
            }
        }

        ll count=2;
        for(ll i=1;i<arr.size()-1;i++){
            if((arr[i]>arr[i-1]&&arr[i]>arr[i+1])||(arr[i]<arr[i-1]&&arr[i]<arr[i+1])){
                count++;
            }

        }

        if(s.size()==1){
            cout<<1<<endl;
        }
        else{
            cout<<count<<endl;
        }

       
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main(){
    IOS
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll>v1(n);
        for(int i=0;i<n;i++)cin>>v1[i];
        sort(v1.begin(),v1.end());
        ll ans1=INT_MIN;
        for(int i=1;i<n-1;i++){
            ans1 = max(ans1,v1[i]-2*v1[i-1]);
        }
        ans1+=v1[n-1];
        ll ans2=INT_MIN;
        for(int i=2;i<n;i++){
            ans2=max(ans2,2*v1[i]-v1[i-1]);
        }
        ans2-=v1[0];
        cout<<max(ans2,ans1)<<endl;
    }
}


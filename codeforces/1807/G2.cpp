#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void func(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    if(v[0]!=1){
        cout<<"No\n";
        return;
    }
    else {
        ll sum = 1;
        for(int i=1;i<n;i++){
            if(v[i]>sum){
                cout<<"No\n";
                return;
            }
            else if(sum<1e6)sum+=v[i];
        }
    }
    cout<<"Yes\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;

    while(t--) func();


    return 0;
}
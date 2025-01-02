#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<pair<string,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j+=2){
            (a[i].first)[j]='Z'-(a[i].first)[j]+1;
        }
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) cout<<a[i].second<<" ";
}
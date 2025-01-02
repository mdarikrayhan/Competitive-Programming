#include <bits/stdc++.h>
using namespace std;
int main() {
    double n,t,ans=2;
    cin>>n>>t;
    vector<pair<double,double> > a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        double x1=a[i].second/2+a[i].first;
        double x2=a[i+1].first-a[i+1].second/2;
        if(x2-x1>t){
            ans+=2;
        }
        else{
            if(x2-x1==t){
                ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
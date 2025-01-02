#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
    if(p1.first==p2.first)
        return p1.second>p2.second;
    return p1.first<p2.first;
}
const double PI=3.1415926535;
int mod=(int)(1e9+7);
int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n*=2;
        double rad = 1/(2*sin(PI/n));
        printf("%.9f\n",2.0*sqrt(rad*rad-double(1.0/4.0)));
    }
}


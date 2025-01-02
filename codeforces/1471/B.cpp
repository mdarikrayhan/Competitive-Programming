#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
    if(p1.first==p2.first)
        return p1.second>p2.second;
    return p1.first<p2.first;
}
int mod=(int)(1e9+7);
int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){

        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector<pair<int,int>>nw;
        bool is=true;
        int res=0;
        for(int i=0;i<n;i++){
            if(arr[i]%x)
            {
                is=false;
            }
            if(is)
                nw.push_back({arr[i]/x,x});
            res+=arr[i];
        }
        int i=0;
        while(is){
            if(i==nw.size())
                break;
            if(nw[i].first%x){
                break;
            }
            res+=(nw[i].first*nw[i].second);
            pair<int,int> cur=nw[i];
            nw.push_back({cur.first/x,cur.second*x});
            i++;
        }
        while(i<nw.size()){
            res+=(nw[i].first*nw[i].second);
            i++;
        }
        cout<<res<<"\n";
    }
}


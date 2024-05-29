#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int q;cin>>q;
    map<pair<int,int>,int> mp;
    while(q--){
        int a,b;cin>>a>>b;
        mp[{a,b}] = 1;
    }   
    vector<pair<int ,int>>Q;
    Q.push_back({1,1});
    int lev = 0;
    while(1){
        lev++;
        vector<pair<int ,int>>Q2,Q3;
        for(auto i:Q){
            int all = i.first+i.second;
            if(mp.find(make_pair(i.first,i.second))!=mp.end())all++;
            Q2.push_back({min(n,all),i.second});
            Q2.push_back({i.first,min(m,all)});
        }
        sort(Q2.begin(),Q2.end());
        reverse(Q2.begin(),Q2.end());
        int mi = -1e9;
        for(int i = 0;i<Q2.size();i++){
            if(Q2[i].first==n&&Q2[i].second==m){
                cout<<lev<<endl;
                return 0;
            }
            if(Q2[i].second>mi){
                Q3.push_back(Q2[i]);
                mi = Q2[i].second;
            }
        }
        Q = Q3;
    }
}
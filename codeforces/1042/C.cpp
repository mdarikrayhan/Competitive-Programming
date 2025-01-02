#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   vector<ll>pos,zero;
   vector<pair<ll,ll>>neg,ans;
      ll x,idx,idx2,idx3;
      cin>>x;
      ll arr[x];
      for(ll i=0;i<x;i++){
          cin>>arr[i];
          if(arr[i]>0)pos.push_back(i+1);
          else if(arr[i]<0)neg.push_back({arr[i],i+1});
          else zero.push_back(i+1);
      }
      if(zero.size()) {
          idx = zero[0];
          for (ll i = 1; i < zero.size(); i++) {
              ans.push_back({zero[i],idx});
          }
      }
          if(neg.size()){
              sort(neg.begin(),neg.end());
              if(neg.size()%2){
                  if(zero.size()){
                      ans.push_back({neg.back().second,idx});
                  }
                  if(neg.size()>1){
                      idx2=neg[neg.size()-2].second;
                      for(ll i=0;i<neg.size()-2;i++)ans.push_back({neg[i].second,idx2});
                  }
              }
              else {
                  idx2=neg[0].second;
                  for(ll i=1;i<neg.size();i++)ans.push_back({neg[i].second,idx2});
              }
          }
          if(pos.size()){
              idx3=pos[0];
              for(ll i=1;i<pos.size();i++)ans.push_back({pos[i],idx3});
              if(neg.size()&&neg.size()>1)ans.push_back({idx2,idx3});
          }
          if(zero.size()){
              if(neg.size()>1||pos.size())ans.push_back({INT64_MIN,idx});
          }
          else if(neg.size()%2&&zero.empty()){
              ans.push_back({INT64_MIN,neg.back().second});
          }
          for(auto it:ans){
              if(it.first==INT64_MIN)cout<<2<<" "<<it.second<<"\n";
              else cout<<1<<" "<<it.first<<" "<<it.second<<'\n';
          }
    }
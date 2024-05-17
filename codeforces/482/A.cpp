#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds1;// find_by_order, order_of_key, less, greater,less_equal
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef vector<ll> vec;
typedef vector<string> vecs;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vp;
typedef set<ll> st;
typedef set<pair<ll, ll>> sp;
typedef multiset<ll> mst;
typedef multiset<pair<ll, ll>> mstp;
typedef map<ll, ll> mp;
typedef map<char, ll> mpc;
const ll mx=1e6+1;
bitset<mx>isprime;
const  long long mod=1000000007;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll vv[mx],vv1[mx];

int main()
{


    ll n,k;
    cin>>n>>k;
    vec vv;
    for(ll i=1; i<=n; i++)
    {
        vv.push_back(i);
    }
    if(k==1)
    {
        for(auto x:vv)
        {
            cout<<x<<" ";
        }
    }
    else
    {
         if(n%2!=0){
              if(n%2!=0 and k%2==0){
                  vec ans;
                  ll l=0;
                  ll r=vv.size()-1;
                  while(ans.size()!=k){
                      ans.push_back(vv[l]);
                      ans.push_back(vv[r]);
                      l++;
                      r--;
                  }
                  ll pp=ans[ans.size()-2];
                  for(ll i=ans[ans.size()-1]-1;i>=pp+1;i--){
                     ans.push_back(i);
                  }
                  for(auto x:ans){
                    cout<<x<<" ";
                  }
                  cout<<endl;
              }

              else if(n%2!=0 and k%2!=0){
                  vec ans;
                  ll l=0;
                  ll r=vv.size()-1;
                  while(ans.size()!=k-1){
                      ans.push_back(vv[l]);
                      ans.push_back(vv[r]);
                      l++;
                      r--;
                      //if(ans.size()==k)break;
                  }
                  //l++;
                  ans.push_back(vv[l]);

                  ll pp=ans[ans.size()-2];
                  for(ll i=ans[ans.size()-1]+1;i<=pp-1;i++){
                     ans.push_back(i);
                  }
                  for(auto x:ans){
                    cout<<x<<" ";
                  }

              }
         }

         else{
             if(n%2==0 and k%2==0){
                   vec ans;
                  ll l=0;
                  ll r=vv.size()-1;
                  while(ans.size()!=k){
                      ans.push_back(vv[l]);
                      ans.push_back(vv[r]);
                      l++;
                      r--;
                  }
                  ll pp=ans[ans.size()-2];
                  for(ll i=ans[ans.size()-1]-1;i>=pp+1;i--){
                     ans.push_back(i);
                  }
                  for(auto x:ans){
                    cout<<x<<" ";
                  }
                  cout<<endl;
             }
             else{

                  vec ans;
                  ll l=0;
                  ll r=vv.size()-1;
                  while(ans.size()!=k-1){
                      ans.push_back(vv[l]);
                      ans.push_back(vv[r]);
                      l++;
                      r--;
                      //if(ans.size()==k)break;
                  }
                  //l++;
                  ans.push_back(vv[l]);

                  ll pp=ans[ans.size()-2];
                  for(ll i=ans[ans.size()-1]+1;i<=pp-1;i++){
                     ans.push_back(i);
                  }
                  for(auto x:ans){
                    cout<<x<<" ";
                  }

             }


         }

    }
}

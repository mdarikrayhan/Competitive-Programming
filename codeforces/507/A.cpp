/*Jai Shree Ram*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define pob pop_back
#define all(v) v.begin(),v.end()
#define pi pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define vpi vector<pair<int,int>>
#define loop for(int i=0;i<n;i++)
#define ip for(auto &i:arr)
#define ipp(arr) for(auto i:arr)
#define FastIO \
ios_base::sync_with_stdio(false);\
cin.tie(NULL);\
cout.tie(NULL);
int N=1e5+3;
int mod=1e9+7;
void helper(vi &nums,int sum){
    int n=nums.size();
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        mp[nums[i]].pb(i);
    }
    sort(all(nums));
    
    vi ans;
    for(int i=0;i<n;i++){
        if(sum>=nums[i]){
            vector<int> temp=mp[nums[i]];
            int kk=temp.back();
            temp.pob();
            mp[nums[i]]=temp;
            ans.push_back(kk+1);
            sum-=nums[i];
        }
    }
    cout<<ans.size()<<endl;
    
    for(auto i:ans) cout<<i<<' ';
    
    return;
}
void solve(){
    int n,k;
    cin>>n>>k;
    
    vi arr(n);
    
    ip cin>>i;
    
    helper(arr,k);
}


int32_t main(){
    FastIO
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
    }
}
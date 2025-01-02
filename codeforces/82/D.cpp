#include <bits/stdc++.h>   
using namespace std;
#define ll long long
#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
ll aa[1000009];
ll bb[1000009];
vector<ll>v;
map<ll,ll>mp;
set<ll>st;
pair<ll,ll>pp[1000009];
int xx[]={1,-1,0,0,1,-1,1,-1};
int yy[]={0,0,1,-1,1,-1,-1,1};
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
bool cmp(pair<ll, ll> A, pair<ll, ll> B)
{
    if (A.first > B.first)
        return 1;
    else if (A.first < B.first)
      return 0;
    else if (A.first > B.second)
        return 1;
    else
        return 0;
}
const int mod=1e9+7;
ll fpow(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=(a*1LL*a)%mod)if(b&1)ans=(ans*1LL*a)%mod;
    return ans;
}
int n; 
int dp[1003][1003]; 
int rec(int i,int last){
  if(i==n-1&&last==n+1){
    return aa[i];
  }
  if(i>=n){
    if(i>n){
        return 1e9;
    }
    if(n%2==0)
    return (last!=n+1?1e9:0);
    else return (last!=n+1?aa[last]:1e9);
  }
  if(dp[i][last]+1)return dp[i][last];
  dp[i][last]=1e9; 
  if(last==n+1){
    int a=rec(i+2,n+1)+max(aa[i],aa[i+1]); 
    int b=rec(i+3,i+1)+max(aa[i],aa[i+2]);
    int c=rec(i+3,i)+max(aa[i+1],aa[i+2]);
    dp[i][last]=min({a,b,c}); 
  }else {
    int a=rec(i+2,last)+max(aa[i],aa[i+1]); 
    int b=rec(i+1,n+1)+max(aa[last],aa[i]);
    int c=rec(i+2,i)+max(aa[last],aa[i+1]);
    dp[i][last]=min({a,b,c});
  }
  return dp[i][last];
}
vector<pair<int,int>>ans; 
void print(int i,int last){
if(i>=n){
  return ;
}
if(last==n+1){
   int a=rec(i+2,n+1)+max(aa[i],aa[i+1]); 
    int b=rec(i+3,i+1)+max(aa[i],aa[i+2]);
    int c=rec(i+3,i)+max(aa[i+1],aa[i+2]);
    int d=dp[i][last]; 
    if(d==a){
     if(i+1<n)ans.push_back({i,i+1});
      print(i+2,n+1);
       return;
    }if(d==b){
     if(i+2<n) ans.push_back({i,i+2});
      print(i+3,i+1); return;
    }
 if(i+2<n) ans.push_back({i+1,i+2});
    print(i+3,i); return ;
}else{
  int a=rec(i+2,last)+max(aa[i],aa[i+1]); 
    int b=rec(i+1,n+1)+max(aa[last],aa[i]);
    int c=rec(i+2,i)+max(aa[last],aa[i+1]);
    int d=dp[i][last]; 
    if(d==a){
     if(i+1<n)ans.push_back({i,i+1});
      print(i+2,last);
       return;
    }if(d==b){
      ans.push_back({last,i});
      print(i+1,n+1); return;
    }
   if(i+1<n)ans.push_back({last,i+1});
    print(i+2,i); return ;
}
return;
}
int main()
{
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
fast
int t=1; //cin>>t; 
while(t--){
cin>>n; 
for(int i=0;i<n;i++){
    cin>>aa[i]; 
}
memset(dp,-1,sizeof dp); 
cout<<rec(0,n+1)<<endl; 
print(0,n+1);
for(auto i:ans){
  cout<<i.first+1<<" "<<i.second+1<<endl; 
  bb[i.first]++; bb[i.second]++;
}
for(int i=0;i<n;i++){
  if(bb[i]==0){
    cout<<++i<<endl; break; 
  }
}
}
}
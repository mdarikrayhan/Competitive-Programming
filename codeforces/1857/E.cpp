#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>

#include <cmath>
#define pii pair<int,int>
#define pb push_back
#define ppii pair<int, pair<int,int>>
#define pld pair<long long,double>
#define pibb pair<int,<bool,bool>>
#define yes "YES"
#define no "NO"
#define ll long long
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template<typename T>
struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void add(T val) { ost.insert(make_pair(val, ++freq[val])); }
    void remove(T val) { ost.erase(make_pair(val, freq[val]--)); }
    int index(T val) { return ost.order_of_key(make_pair(val, -1)); }
    T operator[] (int i) const { return ost.find_by_order(i)->first; }

    int lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }
    int upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() { return ost.size(); }
    bool empty() { return ost.empty(); }
};
vector<int> sieve(int n){
   vector<bool> isPrime(n+1,true);
   isPrime[0]=isPrime[1]=false;
   for (int i = 2; i <= (int)sqrt(n); i++){
      for (int j = 2; j <=n; j++){
         if (i*j>n) break;
         isPrime[i*j]=false;
      }
   }
   vector<int> primes;
   for (int i = 2; i < size(isPrime); i++){
      if (isPrime[i]) primes.emplace_back(i);
   }
   return primes;
}
vector<int> spf(int n){
   vector<int> res (n+1,0);
   vector<int> primes = sieve(n);
   for (int prime: primes){
      for (int i = prime; i < n + 1; i+=prime){
         if (res[i]==0){
            res[i]=prime;
         }
      }
   }
   return res;
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int comb(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    return dp[n][k];
}
struct SparseTable{
   vector<vector<int>> table;
   SparseTable(vector<int> nums){
      table.resize(20,vector<int> (nums.size()));
      for (int i = 0; i < nums.size(); i++){
         table[0][i]=nums[i];
      }
      for (int j = 1; j < table.size(); j++){
         for (int i = 0; i+(1<<j)<=nums.size(); i++){
            table[j][i]=min(table[j-1][i],table[j-1][i+(1<<(j-1))]);
         }
      }
   }
   int query(int left, int right){
      int length = right-left+1;
      int power = length ? __builtin_clzll(1) - __builtin_clzll(length) : -1;
      return min(table[power][left],table[power][right-(1<<power)+1]);
   }
};
struct SegmentTree{
   vector<pii> tree;
   vector<int> nums;
   vector<bool> lazy;
   string s;
   SegmentTree(vector<int> arr, string st){
      s=st;
      nums = arr;
      tree.resize(4*arr.size());
      lazy.resize(4*arr.size());
      build_tree(0,0,arr.size()-1);
   }
   void build_tree(int node, int left, int right){
      if(left == right){
         if (s[left]=='1'){
            tree[node]=pii(0,nums[left]);
            return;
         }
         tree[node]=pii(nums[left],0);
         return;
      }
      int mid = (left+right)>>1;
      build_tree(2*node+1,left, mid);
      build_tree(2*node+2,mid+1,right);
      tree[node]=pii(tree[2*node+1].first^tree[2*node+2].first,tree[2*node+1].second^tree[2*node+2].second);
   }
   void update(int node, int l, int r, int arrLeft, int arrRight){
      if (lazy[node]){
         int temp = tree[node].first;
         tree[node].first=tree[node].second;
         tree[node].second = temp;
         lazy[node]=false;
         if (arrLeft!=arrRight){
            lazy[2*node+1]= !lazy[2*node+1];
            lazy[2*node+2]= !lazy[2*node+2];
         }
      }
      if (arrLeft > r || arrRight < l) return;
      if (arrLeft>=l && arrRight<=r){
         int temp = tree[node].first;
         tree[node].first=tree[node].second;
         tree[node].second = temp;
         if (arrLeft!=arrRight){
            lazy[2*node+1]= !lazy[2*node+1];
            lazy[2*node+2]= !lazy[2*node+2];
         }
         return;
      }
      int mid = (arrLeft+arrRight)>>1;
      update(2*node+1,l,r,arrLeft,mid);
      update(2*node+2,l,r,mid+1,arrRight);
      tree[node]=pii(tree[2*node+1].first^tree[2*node+2].first,tree[2*node+1].second^tree[2*node+2].second);
   }
};
struct UnionFind{
   vector<int> par;
   vector<int> rank;
   UnionFind(int n){
      par.resize(n,-1);
      rank.resize(n,-1);
   }
   int find(int u){
      if (par[u]==-1) return u;
      return par[u]=find(par[u]);
   }
   void unionn(int u, int v){
      int uPar=find(u);
      int vPar=find(v);
      if (uPar==vPar) return;
      if (rank[uPar]==rank[vPar]) rank[uPar]++;
      if (rank[uPar]>rank[vPar]){
         par[vPar]=uPar;
      }
      else{
         par[uPar]=vPar;
      }
   }
};

void solve(){
   int n;
   cin>>n;
   vector<pii> nums(n);
   for (int i = 0; i < n; i++){
       int a;
       cin>>a;
       nums[i]=pii(a,i);
   }
   sort(nums.begin(),nums.end());
   vector<ll> res(n);
   ll ans = 0;
   for (int i = 0; i < n; i++){
      ans+=nums[i].first-nums[0].first+1;
   }
   res[nums[0].second]=ans;
   for (int i = 1; i < n; i++){
      ll diff = nums[i].first-nums[i-1].first;
      ans+=diff*(i-1);
      ans-=diff*(n-1-i);
      res[nums[i].second]=ans;
   }
   for (int i = 0; i < n; i++) cout<<res[i]<<" ";
   cout<<endl;
}
int main(){
   int t=1;
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin>>t;
   while (t--){
      solve();
   }
}
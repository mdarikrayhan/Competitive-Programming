#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
using namespace __gnu_pbds;
#define int long long
#define fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ld long double
#define popcount(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define vec(x) vector<x>
#define vi vector<int>
#define vii vec(vi)

#define pii pair<int,int> 
#define vpii vec(pii)

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// change less to greater for decending order
// less_equal for multiset
//find_by_order  -- pbdsname.find_by_order(x) gives the pointer of xth index ( 0 based indexing)
//order_of_key  --  gives number of elements (strinctly in case of set) less than x
//lowerbound upperbound applicable
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;



void solve() {
  int n,k;
  cin>>n>>k;
  set<int> s;
  vi a;
  int p=pow(3,k-1);
  // cout<<p<<endl;
  int dum;
  int x;
  int in;
  fo(i,0,n){
    dum=p;
    x=0;
    fo(i,0,k){
      cin>>in;
      x+=dum*in;
      dum/=3;
    }
    s.insert(x);
    a.pb(x);
  }
  int num1,num2,x1,x2,num3;
  map<int,int> m;
  // for(auto val : a) cout<<val<<" ";
  cout<<endl;
  fo(i,0,n){
    
    fo(j,i+1,n){
      num1=a[i];
      num2=a[j];
      num3=0;
      dum=p;
      fo(i,0,k){
        x1=0;
        x2=0;
        while(num1>=dum){
          num1-=dum;
          x1++;
        }
        while(num2>=dum){
          num2-=dum;
          x2++;
        }
        if(x1==x2) num3+=x1*dum;
        else{
          num3+=((3-x1-x2))*dum;
        }
        dum/=3;
      }
      if(s.find(num3)!=s.end()){
        m[a[i]]++;
        m[a[j]]++;
        m[num3]++;
        // cout<<a[i]<< " "<<a[j]<<" "<<num3<<endl;
      } 
    }
  }
  int ans=0;
  for(auto pr : m){
    x=pr.sec/3;
    ans+=(x*(x-1))/2;
  }
  cout<<ans<<endl;

}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
  int t = 1;
  // cin >> t;
  // prime(5e3+2);
  while(t--) {
    solve();
  }
 
  return 0;
}
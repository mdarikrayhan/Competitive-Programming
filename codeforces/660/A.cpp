#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using  namespace std;
template<class T>
using  ordered_set =  tree <T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
using  namespace std;
#define ll  long long
#define sz(s) (int) (s.size())
#define all(v) v.begin(), v.end()
inline bool getBit(long long num, int idx) {return ((num >> idx) & 1);}
inline int Ones(long long num){ int cnt=0;while(num)cnt++,num&=(num-1); return cnt;}
inline int add(ll a,ll b,int mod){return (0LL + a%mod + b%mod + mod)%mod;}
inline int mul(ll a,ll b,int mod){return (1LL * a%mod * b%mod)%mod;}
//mt19937_64 rng( std::chrono::system_clock::now( ).time_since_epoch( ).count( ) );
//inline ERand(int l,int r){return uniform_int_distribution<int>(l,r)(rng);  }
const int  dx[]  = {1,-1,0,0,1,1,-1,-1};
const int  dy[]  = {0,0,-1,1,1,-1,1,-1};
const char dir[] = {'D','U','L','R'};
void FastIO(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
#ifndef ONLINE_JUDGE
 freopen("in.txt", "r", stdin);
 freopen("out.txt", "w", stdout);
 #endif
}

template<class T> istream &operator>>(istream &in , vector<T>&v){
    for(auto &i : v)
        in>>i;
    return in;
 }
 
 template<class T> ostream &operator<<(ostream &out , vector<T>&v){
     for(auto &i : v)
         out<<i<<" ";
   return out;
 }

const int  N = 1e6+2, MOD = 1e9+7 , mod = 998244353, LOG = 63;
const ll inf = 1e18;
    
    
       
    
    
   void SolveIt(){
     
      
      int n; cin>>n;
      vector<int>v(n);
      cin>>v;
      vector<int>ans;
      for(int i=0;i<n;++i){
        ans.push_back(v[i]);
        if(i+1<n && __gcd(v[i],v[i+1])>1)
            ans.push_back(1);
      }
      cout<<sz(ans)-n<<"\n"<<ans;

    

   }
  


int32_t  main()
{

    FastIO();

     int Test=1,tc=1;
         //cin>>Test;
       while(Test --> 0){
//         cout<<"Case "<<tc++<<":\n";
         SolveIt();

    }// AC Yarab


}

   				 	   						    		  			
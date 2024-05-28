#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define int uint64_t
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define repi(it, container) for (auto it = (container).begin(); it != (container).end(); ++it)
#define repi_const(it, container) for (auto it = (container).cbegin(); it != (container).cend(); ++it)
#define all(x) (x).begin(), (x).end()


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// unordered_map<long long, int, custom_hash> safe_map;
// gp_hash_table<long long, int, custom_hash> safe_hash_table;


bool isPrime[1000002];


void seive(){
     for(int i=0;i<1000002;i++){
        isPrime[i]=true;
     }

     isPrime[0]=isPrime[1]=false;

     for(int i=2;i*i<=1000002;i++){
        if(isPrime[i]==true){
            for(int j=i*i;j<=1000002;j+=i){
                isPrime[j]=false;
            }
        }
     }
      return;
}




void solve(){
   int n , k ; cin>>n>>k;

   int sum =0; 

   vector<vector<int>> ans(n);

   int left = 1 , right = (k-1)*n + 1; 

   for(int i=1;i<=n;i++){
    
    for(int j=1;j<=n;j++ ){
        if(j<k){
            
            ans[i-1].push_back(left);
            left++;
        }
        else{
            if(j==k)  sum+=right;
           
            ans[i-1].push_back(right);
            right++;
        }
    }

   }


    cout<<sum<<endl;
    for(auto &v : ans ){
        for(auto val: v){
            cout<<val<<' ';
        }
        cout<<endl;
    }

   
  
}


  
int32_t main() {
   int t; 
//    cin>>t; 
      t=1;
    
    while(t--){
        solve();     
    }
}
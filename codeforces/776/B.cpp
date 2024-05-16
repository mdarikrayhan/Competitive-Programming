#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long int
const int N=2e3+7;
const int mod=1e9+7;
const double eps=1e-9;
const double pi=    3.14159265358979323846;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    op_set;
 
//I can't add more days to my life now , let me add some life to my days then
 
int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<int> check((int)1e5+1);
    check[0]=1;
    check[1]=0;
    for(int i=2 ; i<=(int)1e5; i++){
        for(int j=2 ; j*j<=i ; j++){
            if(i%j==0){
                check[i]=1;
                break;
            }
        }
    }

    auto solve=[&]{
          int n;
          cin>>n;
          int cnt=1;
          int k=1;
          vector<int> ans;
          for(int i=1+1 ; i<=n+1 ; i++){
             if(!check[i]){
                ans.push_back(1);
             }else{
                ans.push_back(2);
             }
          }
          
          if(n>=3) cout<<2<<"\n";
          else cout<<1<<"\n";
          for(auto &it:ans) cout<<it<<" ";
          cout<<"\n";
    };
 
    int t=1;
    //std::cin >> t;
    for(int i=0 ; i<t  ; i++){
        solve();
    }
   
    return 0;
}


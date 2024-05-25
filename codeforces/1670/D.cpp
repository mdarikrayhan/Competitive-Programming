#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int low = 1;
        int high = 1e9;
        int ans = 0;
        while(low <= high){
            int mid = low + ((high - low)>>1);
            if(6LL * mid * mid <= n){
                ans = mid;
                low = mid+1;
            }else{
                high =mid-1;
            }
        }
       // cout<<"ans is "<<ans<<endl;
        if(6LL * ans * ans == n){
            cout<<3*ans<<"\n";
        }else{
            int cur= 6 * ans * ans + 4 * ans;
            if(cur >= n){
                cout<<3*ans+1<<"\n";
            }else{
                int cur = 6 * ans * ans + 8 * ans + 2;
                if(cur >= n){
                    cout<<3*ans+2<<"\n";
                }else{
                    cout<<3*(ans+1)<<"\n";
                }
            }
        }
    }
}
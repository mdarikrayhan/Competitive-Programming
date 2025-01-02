#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[1005][1005];
vector<int> cnt(105);
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        while(n--){
            int a,b;
            cin>>a>>b;
            if(a>b){
                ans++;
            }
        }cout<<ans<<endl;
        
    }
    return 0;
}

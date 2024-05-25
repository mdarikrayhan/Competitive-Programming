#include <bits/stdc++.h>
using namespace std;
#define int long long
set <int> st1[1001][2],st;
vector <int> pre[1001];
int ans=0;
int n,k;
int arr[1001][5];
int dp[1001];
void solve(int i){
    if(i==n) return;
    dp[arr[i][0]]=1;
    for(int j:pre[arr[i][0]]){
        dp[arr[i][0]]=max(dp[arr[i][0]],dp[j]+1);    
    }
    solve(i+1);
    ans=max(ans, dp[arr[i][0]]);
    ans=max(ans, dp[arr[i+1][0]]);
    return;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        st1[arr[i][0]][0]=st;
        st.insert(arr[i][0]);
    }
    
    for(int j=1;j<k;j++){
        int u=(j+1)%2;
        st.clear();
        for(int i=0;i<n;i++){
            cin>>arr[i][j];
            int v=arr[i][j];
            
            st1[v][j%2].clear();
            for(auto it:st){
                if(st1[v][u].find(it)!=st1[v][u].end()){
                    st1[v][j%2].insert(it);
                }
            }
            
            st.insert(arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(auto it:st1[arr[i][(k-1)]][(k-1)%2]) pre[arr[i][(k-1)]].push_back(it);
    }
    solve(0);
    cout<<ans<<endl;
    return 0;
}
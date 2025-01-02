#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(string &ans,string &s,int i){
    if(s.size()+i<=ans.size()) return 0;
    for(int j = i;j<ans.size();j++){
        if(s[j-i]!=ans[j]){
            return 0;
        }
    }
    return 1;
}

void solve(){
    int n,k;
    cin>>n>>k;
    k--;
    string s;
    cin>>s;
    string ans = s;
    while(k){
        int f = 1;
        for(int i=1;i<ans.size();i++){
            if(check(ans,s,i)){
                // cout<<i<<endl;
                int cnt = 0;
                for(int j = i;j < ans.size();j++){
                    cnt++;
                }
                for(int j = cnt;j < n;j++){
                    ans.push_back(s[j]);
                }
                f = 0;
                k--;
                break;
            }
        }
        if(f){
            ans+=s;
            k--;
        }
        // cout<<ans<<" "<<k<<endl;
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // int t;cin>>t;while(t--)
        solve();
}
#ifdef ONLINE_JUDGE
#define debug(...);
#else
#include "dbg/template.cpp"
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int dp[1001][11][11];
string s;
vector<int> ans;
int m , f = 0;
int depee(int last , int l , int r , int turn , int sml , int smr){
    if (turn==m){
        f = 1;
        return 0;
    }
    int &ret = dp[turn][l][r];
    if (ret!=-1){
        return ret;
    }
    for (int i = 1 ; i <= 10 ; i++){
        if (i!=last && s[i-1]=='1'){
            if (turn%2==0){
                if (sml+i>smr){
                    ret = depee(i,i,r,turn+1,sml+i,smr);
                    if (f){
                        ans.push_back(i);
                        return ret;
                    }
                }
            }else{
                if (smr+i>sml){
                    ret = depee(i,l,i,turn+1,sml,smr+i);
                    if (f){
                        ans.push_back(i);
                        return ret;
                    }
                }
            }
        }
    }
    return ret;
}
void burn(){
    // يارب يشتغل
    cin >> s;
    cin >> m;
    depee(0,0,0,0,0,0);
    if (f){
        cout << "YES" << endl;
        reverse(ans.begin(),ans.end());
        for (int i = 0 ; i < m ; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp,-1,sizeof dp);
    int t=1;
    // cin >> t;
    while (t--){
        burn();
    }
    return (0-0);
}
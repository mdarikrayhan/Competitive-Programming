#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
#define f(i,a,b) for(int i = (a);i <= (b);++i)
#define all(c) c.begin(),c.end()
const int p = 1e9 + 7;
const int N = 1e5 + 8;
void solve()
{
    int n;cin >> n;
    map<int,vi > mp;
    f(i,1,n){
        int u;cin >> u;
        mp[u].push_back(i);
    }
    int ans = 2e9;
    for(auto & [i,v] : mp){
        int res = v.size() + 1;
        if(v.size() == n){
            ans = min(ans,0);continue;
        }
        if(v.size() == 1){
            if(*v.begin() == 1 || *v.rbegin() == n)ans = min(ans,1);
            else ans = min(ans,2);continue;
        }
        if(v[0] == 1)res --;
        if(v[v.size() - 1] == n)res --;
        for(int j = 0;j < v.size() - 1;j++){
            if(v[j] + 1 == v[j + 1])res--;
        }
        ans = min(ans,res);
    }cout << ans << endl;
}
int main() 
{
    ios::sync_with_stdio,cin.tie(0),cout.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
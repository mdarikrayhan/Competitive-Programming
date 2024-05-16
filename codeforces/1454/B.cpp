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
    map<int,int> mp;
    map<int,int> ind;
    f(i,1,n){
        int u;cin >> u;
        mp[u] ++;
        if(!ind.count(u))ind[u] = i;
    }
    for(auto & [u,v]: mp){
        if(v == 1){
            cout << ind[u] << endl;return;
        }
    }cout << -1 << endl;
}
int main() 
{
    ios::sync_with_stdio,cin.tie(0),cout.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define int long long
#define fast ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);
using namespace std;
// auto makeDequeUnique = [](std::deque<int>& myDeque) {
//     std::sort(myDeque.begin(), myDeque.end());
//     myDeque.erase(std::unique(myDeque.begin(), myDeque.end()), myDeque.end());
// };
// auto insertInAscendingOrder = [](std::deque<int>& deque, int value) {
//     auto it = std::lower_bound(deque.begin(), deque.end(), value);
//     deque.insert(it, value);
// };
void solve(){
    int n,m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for(int i{0}; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> kitne;
    map<int,int> mp;
    for(auto i: a) mp[i] = 1;
    for(int i{1}; i<=m; i++){
        if(mp[i] == 1)
        kitne.push_back(i);
    }
    int ans{0};
    for(int i{1}; i<=(1e6-m+1); i++){
        if(kitne.size() >= k){
            int count = kitne.size() - k + 1;
            while(count){
                kitne.pop_back();
                ans++;
                count--;
            }
        }
        if(kitne.size()){
            if(kitne[0] == i){
                kitne.erase(kitne.begin(), kitne.begin() + 1);
            }
        }
        if(mp[i+m] == 1){
            kitne.push_back(i+m);
        }
    }
    cout << ans << "\n";
    
}
int32_t main(){
    fast;
    solve();
}
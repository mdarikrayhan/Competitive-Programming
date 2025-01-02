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
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i{0}; i<n; i++) cin >> a[i];
    int minn  = n/m;
    int maxx = n/m + n%m;
    map<int,int> mp;
    for(int i{1}; i<=m; i++){
        mp[i] = minn;
    }
    vector<int> cna_be_changed;
    for(int i{0}; i<n; i++){
        if(mp[a[i]] == 0){
            cna_be_changed.push_back(i);
            continue;
        }
        mp[a[i]]--;
    }
    // for(auto i: cna_be_changed) cout << i << " ";
    // cout << "\n";
    int steps{0};
    for(auto i: mp){
        if(i.second > 0){
            int k = i.second;
            while(k > 0 && cna_be_changed.size()){
                a[cna_be_changed.back()] = i.first;
                cna_be_changed.pop_back();
                k--;
                steps++;
            }
        }
    }
    cout << minn << " " << steps << "\n";
    for(auto i: a){
        cout << i << " ";
    }
    cout << "\n";
}
int32_t main(){
    fast;
    solve();
}
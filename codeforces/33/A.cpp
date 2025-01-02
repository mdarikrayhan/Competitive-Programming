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
    int n,m,k; cin >> n >> m >> k;
    map<int,vector<int>> mp;
    for(int i{0}; i<n; i++){
        int r,c; cin >> r >> c;
        mp[r].push_back(c);
    }
    vector<int> mins(m);
    for(auto i: mp){
        int hmm = INT_MAX;
        for(auto j: i.second){
            hmm = min(hmm, j);
        }
        mins[i.first-1] = hmm;
    }
    int possi{0};
    for(auto i: mins){
        possi += i;
    }
    if(possi >= k){
        cout << k << "\n";
    }
    else cout << possi << "\n";
    
}
int32_t main(){
    fast;
    solve();
}
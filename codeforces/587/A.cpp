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
    int n; cin >> n;
    vector<int> a(n);
    for(int i{0}; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> count(1e7, 0);
    for(int i{0}; i<n; i++){
        count[a[i]]++;
    }
    for(int i{0}; i<=1e7-2; i++){
        int k = count[i];
        count[i] = k%2;
        count[i+1] += k/2;
    }
    int ans{0};
    for(int i{0}; i<=1e7; i++){
        if(count[i] == 1) ans++;
    }
    cout << ans << "\n";
}
int32_t main(){
    fast;
    solve();
}
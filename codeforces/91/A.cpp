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
    string s1, s2; cin >> s1 >> s2;
    map<char,int> mp;
    for(int i{0}; i<s1.size(); i++) mp[s1[i]]++;
    int n = s2.size();
    map<char,vector<int>> hmm;
    for(int i{0}; i<s1.size(); i++){
        hmm[s1[i]].push_back(i);
    }

    if(!mp[s2[0]]){
        cout << "-1\n";
        return;
    }

    int index = hmm[s2[0]][0];
    int ans{1};
    // for(auto i: hmm){
    //     cout << i.first << " = ";
    //     for(auto j: i.second){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i{0}; i<n-1; i++){
        if(mp[s2[i]] && mp[s2[i+1]]);
        else{
            cout << "-1\n";
            return;
        }

        int k = upper_bound(hmm[s2[i+1]].begin(), hmm[s2[i+1]].end(), index) - hmm[s2[i+1]].begin();
        if(k>hmm[s2[i+1]].size()-1){
            ans++;
            index = hmm[s2[i+1]][0];
        }
        else{
            index = hmm[s2[i+1]][k];
        }
    }
    cout << ans << "\n";
}
int32_t main(){
    fast;
    solve();
}
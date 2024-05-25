
#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    unordered_map<char,long long> freq;
    string s;
    long long ans = 0;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++){
        freq[s[i]]++; 
    }
    for (auto x : freq){
        ans += ((x.second))*((x.second));
    } 
    cout  << ans;
    return 0;
}
 

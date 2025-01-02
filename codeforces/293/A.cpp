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
    string s1,s2; cin >> s1 >> s2;
    vector<int> occupied(2*n, 0);
    vector<int> y_oo, y_oz, y_zo, y_zz;
    for(int i{0};i<2*n; i++){
        if(s1[i] == '1' && s2[i] == '1'){
            y_oo.push_back(i);
        }
        if(s1[i] == '1' && s2[i] == '0'){
            y_oz.push_back(i);
        }
        if(s1[i] == '0' && s2[i] == '1'){
            y_zo.push_back(i);
        }
        if(s1[i] == '0' && s2[i] == '0'){
            y_zz.push_back(i);
        }
    }
    string y,r;
    for(int i{0}; i<2*n; i++){
        if(i%2 == 0){
            while(y_oo.size() && occupied[y_oo.back()]){
                y_oo.pop_back();
            }
            if(y_oo.size()){
                y += '1';
                occupied[y_oo.back()] = 1;
                y_oo.pop_back();
                continue;
            } 

            while(y_oz.size() && occupied[y_oz.back()]){
                y_oz.pop_back();
            }
            if(y_oz.size()){
                y += '1';
                occupied[y_oz.back()] = 1;
                y_oz.pop_back();
                continue;
            } 

            while(y_zo.size() && occupied[y_zo.back()]){
                y_zo.pop_back();
            }
            if(y_zo.size()){
                y += '0';
                occupied[y_zo.back()] = 1;
                y_zo.pop_back();
                continue;
            }

            while(y_zz.size() && occupied[y_zz.back()]){
                y_zz.pop_back();
            }
            if(y_zz.size()){
                y += '0';
                occupied[y_zz.back()] = 1;
                y_zz.pop_back();
                continue;
            }
        }
        else{
            while(y_oo.size() && occupied[y_oo.back()]){
                y_oo.pop_back();
            }
            if(y_oo.size()){
                r += '1';
                occupied[y_oo.back()] = 1;
                y_oo.pop_back();
                continue;
            }

            while(y_zo.size() && occupied[y_zo.back()]){
                y_zo.pop_back();
            }
            if(y_zo.size()){
                r += '1';
                occupied[y_zo.back()] = 1;
                y_zo.pop_back();
                continue;
            }

            while(y_oz.size() && occupied[y_oz.back()]){
                y_oz.pop_back();
            }
            if(y_oz.size()){
                r += '0';
                occupied[y_oz.back()] = 1;
                y_oz.pop_back();
                continue;
            } 

            while(y_zz.size() && occupied[y_zz.back()]){
                y_zz.pop_back();
            }
            if(y_zz.size()){
                r += '0';
                occupied[y_zz.back()] = 1;
                y_zz.pop_back();
                continue;
            }
        }
    }
    if(y > r){
        cout << "First\n";
    }
    else if(y==r){
        cout << "Draw\n";
    }
    else cout << "Second\n";
}
int32_t main(){
    fast;
    solve();
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
// typedef __int128 lll;
// typedef __float128 lld;
using namespace std;

void weird_sort(string& a) {
    int l = 0;
    bool seen_c = false;
    for(int i = 0; i < a.size(); i++){
        if(!seen_c) {
            if(a[i] == 'C') {
                seen_c = true;
            }
        }
        else {
            if(a[i] == 'A') {
                // cout << "SORT : " << l << " " << i << "\n";
                sort(a.begin() + l, a.begin() + i);
                l = i;
                seen_c = false;
            }
        }
    }
    sort(a.begin() + l, a.end());
}

bool reduce(string& a) {
    bool ans = false;
    string tmp = "";
    for(int i = 0; i < a.size();){
        int r = i;
        while(r != a.size() && a[r] == a[i]) {
            r ++;
        }
        int amt = r - i;
        // cout << "AMT : " << amt << "\n";
        if(amt % 2 == 1){
            if(amt > 1){
                ans = true;
            }
            tmp.push_back(a[i]);
        }
        else {
            ans = true;
        }
        i = r;
    }
    a = tmp;
    return ans;
}

void rm_b(string& a){
    string tmp = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 'B') {
            continue;
        }
        tmp.push_back(a[i]);
    }
    a = tmp;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        int a_bcnt = 0;
        int b_bcnt = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 'B') {
                a_bcnt ++;
            }
        }
        for(int i = 0; i < b.size(); i++){
            if(b[i] == 'B') {
                b_bcnt ++;
            }
        }
        if(a_bcnt % 2 != b_bcnt % 2){
            cout << "NO\n";
            continue;
        }
        rm_b(a);
        rm_b(b);
        while(true) {
            if(!(reduce(a) | reduce(b))) {
                break;
            }
        }
        cout << (a == b? "YES" : "NO") << "\n";
    }
    
    return 0;
}

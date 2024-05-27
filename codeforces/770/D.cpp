#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;



char s[400][400];
int main() { 
    int n;
    cin >> n;
    int depth = 0;
    int mdepth = 0;
    vector<pair<int, bool>> res; // bool, is_closesd
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        // cout << c;
        if (c==']') {
            depth--;
            res.push_back({depth, true});
            mdepth = max(depth, mdepth);
        } else {
            res.push_back({depth, false});
            depth++;
        }
    }
    // cout << mdepth;
    int x = 0;
    for (int i=0; i<n; i++) {
        pair<int, bool> cur = res[i];
        if (i && res[i-1].first == cur.first && cur.second) x+=3;
        int top = cur.first;
        int bot = mdepth*2-cur.first+2;
        s[x][top] = '+';
        s[x][bot] = '+';
        if (cur.second) {
            s[x-1][top] = '-';
            s[x-1][bot] = '-';
        } else {
            s[x+1][top] = '-';
            s[x+1][bot] = '-';
        }
        for (int y=top+1; y<bot; y++) {
            s[x][y] = '|';
        }
        x+=1;
    }
    for (int i=0; i<=mdepth*2+2; i++) {
        for (int j=0; j<x; j++) {
            if (s[j][i]) cout << s[j][i];
            else cout << " ";
        }
        cout << "\n";
    }
    
}
 

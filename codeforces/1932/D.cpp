#include <bits/stdc++.h>
 
#define long long long int
#define DEBUG
using namespace std;
 
// @author: pashka
 
int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
    
        string suites = "CDHS";
    
        string ts;
        cin >> ts;
        int trump = suites.find(ts[0]);
    
        vector<int> bs[4];
        for (int i = 0; i < 2 * n; i++) {
            string s;
            cin >> s;
            bs[suites.find(s[1])].push_back(s[0] - '2');
        }
    
        vector<string> res;
        vector<string> left;
        for (int i = 0; i < 4; i++) {
            sort(bs[i].begin(), bs[i].end());
            if (i == trump) continue;
            if (bs[i].size() % 2 == 1) {
                int x = bs[i].back();
                left.push_back(string() + char('2' + x) + suites[i]);
                bs[i].pop_back();
            }
            for (int j = 0; j < (int) bs[i].size(); j++) {
                int x = bs[i][j];
                res.push_back(string() + char('2' + x) + suites[i]);
            }
        }
        if (left.size() > bs[trump].size()) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (string s : left) {
                res.push_back(s);
                int x = bs[trump].back();
                bs[trump].pop_back();
                res.push_back(string() + char('2' + x) + suites[trump]);
            }
            for (int j = 0; j < (int) bs[trump].size(); j++) {
                int x = bs[trump][j];
                res.push_back(string() + char('2' + x) + suites[trump]);
            }
            for (int i = 0; i < 2 * n; i += 2) {
                cout << res[i] << " " << res[i + 1] << "\n";
            }
        }
    }
}
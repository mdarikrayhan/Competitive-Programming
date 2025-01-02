#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w; cin >> h >> w;
    vector<vector<int>> picture;
    for (int i = 0; i< h; i++) {
        vector<int> line;
        for (int j = 0; j < w; j++) {
            int temp; cin >> temp;
            line.push_back(temp);
        }
        picture.push_back(line);
    }
    int top_bottom_diff = 0;
    int middle_diff = 0;
    for (int i = 0; i < w; i++) {
        top_bottom_diff += abs(picture[0][i] - picture[h-1][i]);
        middle_diff += abs(picture[h/2-1][i] - picture[h/2][i]);
    }
    if (middle_diff > top_bottom_diff) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
   int t; cin >> t;
   while (t--) solve();
}

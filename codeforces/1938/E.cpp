#include<iostream>
#include<cstring>
#include<vector>
#include<array>
using namespace std;
using LL = long long;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vector<int> > a(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                a[i][j]--;
            }
        }
        vector<int> row, col;
        vector<int> row1, col1;
        for(int i = 0; i < n; i++){
            vector<int> cnt(n);
            bool ok = false;
            for(int j = 0; j < n; j++){
                if (++cnt[a[i][j]] == 2){
                    ok = true;
                    break;
                }
            }
            if (!ok) row.push_back(i);
            else row1.push_back(i);
        }
        for(int i = 0; i < n; i++){
            vector<int> cnt(n);
            bool ok = false;
            for(int j = 0; j < n; j++){
                if (++cnt[a[j][i]] == 2){
                    ok = true;
                    break;
                }
            }
            if (!ok) col.push_back(i);
            else col1.push_back(i);
        }
        while(row.size() < col.size()){
            row.push_back(row1.back());
            row1.pop_back();
        }
        while(col.size() < row.size()){
            col.push_back(col1.back());
            col1.pop_back();
        }
        vector<array<int, 3> > ans;
        for(int i = 0; i < row.size(); i++){
            int x = row[i], y = col[i];
            bool good1 = false;
            bool good2 = false;
            vector<int> cnt1(n), cnt2(n);
            for(int j = 0; j < n; j++){
                if (j != y && ++cnt1[a[x][j]] == 2){
                    good1 = true;
                }
                if (j != x && ++cnt2[a[j][y]] == 2){
                    good2 = true;
                }
            }
            if (good1){
                int t = -1;
                for(int j = 0; j < n; j++){
                    if (cnt2[j] > 0){
                        t = j;
                        break;
                    }
                }
                ans.push_back({x, y, t});
            }
            else if (good2){
                int t = -1;
                for(int j = 0; j < n; j++){
                    if (cnt1[j] > 0){
                        t = j;
                        break;
                    }
                }
                ans.push_back({x, y, t});
            }
            else{
                int t = -1;
                for(int j = 0; j < n; j++){
                    if (cnt1[j] > 0 && cnt2[j] > 0){
                        t = j;
                        break;
                    }
                }
                ans.push_back({x, y, t});
            }
        }
        cout << ans.size() << '\n';
        for(auto [x, y, z] : ans){
            cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
        }
    }

}
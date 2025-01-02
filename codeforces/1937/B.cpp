#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxN = 2e5+ 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        vector<string> a(2);
        int n;
        cin >> n;
        cin >> a[0] >> a[1];
        int d = 0, path = 1, h = -1;
        vector<pair<int, int>> otkyde; 
        while(d < n - 1){
            if(a[1][d] != a[0][d + 1]){
                if(a[1][d] < a[0][d + 1]){
                    h = 1;
                    //path = 1;
                }else{
                    path = 0;
                } 
                if(h == 1)break;
            }
            path++;
            otkyde.push_back({0, d + 1});
            d++;
        }
        while(d <= n - 2){
            //cout << 'q';
            otkyde.push_back({1, d});
            d++;
        }
        string ans = "";
        ans += a[1][n-1];
        for(int i = otkyde.size() - 1; i >= 0; i--){
            ans += a[otkyde[i].first][otkyde[i].second];
        }
        ans += a[0][0];
        reverse(ans.begin(), ans.end());
        cout << ans << "\n" << path << "\n";
    }
    return 0;
}
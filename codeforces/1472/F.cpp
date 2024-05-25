#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")
#define ll long long
#define int long long
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;

bool cmp(pii &a, pii &b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

bool getVal(vector<pii> &a, int start, int end){
    if (start > end)
        return true;
    for (int i = start; i <= end; i++){
        if (i + 1 > end){
            return false;
        }
        else{
            if (a[i + 1].first == a[i].first){
                if ((a[i + 1].second - a[i].second) % 2 == 0)
                    return false;
                else{
                    i++ ;
                }
            }
            else{
                if ((a[i + 1].second - a[i].second) % 2)
                    return false;
                else
                    i++ ;
            }
        }
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), cmp);

    bool flag = true;
    int start = 0;
    for (int i = 1; i < m; i++){
        if (a[i].second == a[i - 1].second){
            flag &= getVal(a, start, i - 2);
            start = i + 1;
        }
    }
    flag &= getVal(a, start, m - 1);

    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll numTests = 1;
    cin >> numTests;
    while(numTests-- ){
        solve();
    }
    return 0;
}
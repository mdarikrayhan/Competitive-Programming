#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define rep(i, begin, end) for(int i = begin; i < end; i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define sq(x) (x)*(x)

const int N = 112345;
const int inf = 1e9+7;

void solvetask()
{
    int n;
    cin >> n;

    vector<array<int,2>> a, um;

    rep(i,0,n){
        int x; cin >> x;
        if(x == 1) um.push_back({1, i+1});
        else a.push_back({x, i+1});
    }
    if(sz(a) == 0){
        cout << "NO\n";
        return;
    }

    vector<array<int,2>> res;
    int qnt = sz(a)-1;
    rep(i,1,sz(a)){
        res.push_back({a[i-1][1], a[i][1]});
        a[i][0]--;
        a[i-1][0]--;
    }

    rep(i,0,min(2,sz(um))){
        if(i == 0){
            res.push_back({um[i][1], a.front()[1]});
            a.front()[0]--;
        }else{
            res.push_back({um[i][1], a.back()[1]});
            a.back()[0]--;
        }
        qnt++;
    }

    int j = 0;
    rep(i, min(2, sz(um)), sz(um)){
        while(j < sz(a) && a[j][0] == 0) j++;
        if(j == sz(a)){
            cout << "NO\n";
            return;
        }
        res.push_back({um[i][1], a[j][1]});
        a[j][0]--;
    }

    cout << "YES " << qnt << '\n';
    cout << sz(res) << '\n';
    for(auto [x,y] : res)
        cout << x <<" " << y << '\n';

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solvetask();
        // cout << (solvetask() ? "Yes" : "No") << '\n';
}

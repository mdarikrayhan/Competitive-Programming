#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define rep(i, begin, end) for(int i = begin; i < end; i++)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define sq(x) (x)*(x)

const int N = 112345;
const int inf = 1e9+7;

int solvetask()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<array<int,2>> v;
    int res = 0;
    rep(i,0,n){
        if(s[i] == 'S') continue;
        if(v.empty() || v.back()[1] != i-1){ 
            if(!v.empty()) res = max(res, v.back()[1] - v.back()[0] + 1);
            v.push_back({i, i});
        }
        else v.back()[1] = i;
    }
    if(sz(v) == 0) return res;

    res = max(res, v.back()[1] - v.back()[0] + 1);
    if(sz(v) < 2) return res;

    res++;
    rep(i,1,sz(v)){
        if(v[i][0] - v[i-1][1] == 2)
            res = max(res, v[i][1] - v[i][0] + 1 + v[i-1][1] - v[i-1][0] + 1 + (sz(v) > 2));
    }

    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--)
        // solvetask();
        cout << solvetask() << '\n';
}

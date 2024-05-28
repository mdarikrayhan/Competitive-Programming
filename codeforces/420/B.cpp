#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<char, int>>v(m);

    for(auto &[a, b]: v) cin >> a >> b;

    vector<bool>mark(n + 2, 0);
    int s1 = -1;

    for(int i = 0; i < m; i++){
        auto &[a, b] = v[i];

        if(!mark[b] && a == '-') s1 = b;
        mark[b] = true;
    }
    
    vector<int>ans;
    for(int i = 1; i <= n; i++){
        if(!mark[i]) ans.push_back(i);
    }

    const auto check = [&](int x, bool spec) -> bool {
        // cout << "checking " << x << " " << spec << endl;

        vector<bool>mark(n + 2); 
        int cnt = spec; bool on = spec;
        bool ret = true;
        mark[x] = spec;

        for(int i = 0; i < m; i++){
            if(v[i].first == '+'){
                if(v[i].second == x) on = true;
                cnt++; mark[v[i].second] = true;
            } else{
                if(v[i].second == x) on = false;
                if(mark[v[i].second]) cnt--;
                mark[v[i].second] = false;
            }

            // cout << i << " : " << on << ", " << cnt << endl;
            ret &= (on || (cnt == 0));
        }

        return ret;
    };

    if(s1 == -1){
        if(check(v[0].second, 0)) ans.push_back(v[0].second);
    } else{
        if(check(s1, 1)) ans.push_back(s1);
    }

    sort(ans.begin(), ans.end());

    cout << (int)ans.size() << '\n';
    for(auto &x: ans) cout << x << " ";
    cout << '\n';

    return 0;
}
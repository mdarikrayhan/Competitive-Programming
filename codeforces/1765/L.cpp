#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define ull unsigned long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define s second
#define f first
#define pb push_back
#define oo 1000000000000000000ll
#define all(a) (a).begin(), a.end()
#define rall(a) (a).rbegin(), a.rend()
#define mp make_pair

void solve() {
    const int d = 7;

    int n, m, k; cin >> n >> m >> k;
    vector<set<int>> v(d);
    map<int, vector<int>> working;
    for (int i = 1; i <= n; ++i){
        int t; cin >> t;
        for (int j = 0; j < t; ++j){
            string day; cin >> day;
            if (day == "Sunday") v[0].insert(i), working[i].pb(0);
            else if (day == "Monday") v[1].insert(i), working[i].pb(1);
            else if (day == "Tuesday") v[2].insert(i), working[i].pb(2);
            else if (day == "Wednesday") v[3].insert(i), working[i].pb(3);
            else if (day == "Thursday") v[4].insert(i), working[i].pb(4);
            else if (day == "Friday") v[5].insert(i), working[i].pb(5);
            else if (day == "Saturday") v[6].insert(i), working[i].pb(6);
        }
    }
    set<int> holidays;
    for (int i = 0; i < m; ++i){
        int day; cin >> day;
        holidays.insert(day);
    }

    vector<vector<int>> projects(k);
    vector<set<pair<int, int>>> pending(n+1);
    for (int i = 0; i < k; ++i){
        int p; cin >> p;
        for (int j = 0; j < p; ++j){
            int worker; cin >> worker;
            projects[i].pb(worker);
            if (j == 0){
                pending[worker].insert({i, j});
            }
        }
    }

    for (int i = 0; i < d; ++i){
        for (int j = 1; j <= n; ++j){
            if (v[i].find(j) == v[i].end()) continue;
            if (pending[j].empty())
                v[i].erase(j);
        }
    }

    int completed = 0;
    vector<int> ans(k);
    for (int day = 1; completed < k; ++day){
        if (holidays.count(day)) continue;
        set<int> del;
        vector<pii> next;
        for (auto worker : v[day % d]){
            auto it = pending[worker].begin();
            ans[it->f] = day;
            next.push_back(*it);
            pending[worker].erase(it);
            if (pending[worker].empty()) del.insert(worker);
        }

        for (auto [i, j] : next){
            if (j+1 == projects[i].size()) completed++;
            else {
                del.erase(projects[i][j+1]);
                pending[projects[i][j+1]].insert({i, j+1});
                for (auto ww : working[projects[i][j+1]]){
                    v[ww].insert(projects[i][j+1]);
                }
            }
        }

        for (auto de : del){
            for (auto ww : working[de])
                v[ww].erase(de);
        }
    }

    for (int i = 0; i < k; ++i) cout << ans[i] << " ";
    cout << "\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tst; tst = 1;
    //cin >> tst;
    while (tst--){
        solve();
    }

    return 0;

}
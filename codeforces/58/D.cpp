#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define filein freopen("input.in", "r", stdin);
#define fileout freopen("output.txt", "w", stdout);
#define ld long double
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{fastio
    int n, mx = 0, mn = 11;
    cin >> n;
    char d;
    string s;
    vector<string> arr[11];
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        arr[s.size()].push_back(s);
        mx = max(mx, (int)s.size());
        mn = min(mn, (int)s.size());
    }
    for (int i = 1; i <= 10; i++) sort(arr[i].begin(), arr[i].end(), greater<>());
    cin >> d;
    for (int t = 0; t < n; t += 2)
    {
        vector<string> candidates;
        for (int i = 1; i <= 10; i++)
        {
            if (!arr[i].empty()) candidates.push_back(arr[i].back()+d);
        }
        sort(candidates.begin(), candidates.end());
        int c = candidates[0].size()-1;
        cout << candidates[0];
        arr[c].pop_back();
        cout << arr[mx+mn-c].back() << '\n';
        arr[mx+mn-c].pop_back();
    }
}
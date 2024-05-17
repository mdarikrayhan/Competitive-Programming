#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    int t, a, b, p;
    string path;
    cin >> t;
    for (int z = 0; z < t; ++z) {
        cin >> a >> b >> p >> path;
        int n = path.size(), k = 1, j = 0;
        vector<pair<int, int> > v; /* first = index, second = price */
        for (int i = 1; i < n; ++i) {
            if (path[i] != path[i - 1]) {
                k = 0;
                if (path[i] == 'A') {
                    v.push_back({j, b});
                } else v.push_back({j, a});
                j = i;
            }
            k++;
        }
        if (k > 1) {
            if (path[n - 1] == 'A') {
                v.push_back({n - k, a});
            } else v.push_back({n - k, b});
        }
        v.push_back({n - 1, 0});
        int i = v.size() - 1, pay = 0;
        while (i >= 0 && pay + v[i].second <= p) {
            pay += v[i].second;
            i--;
        }
        cout << v[i + 1].first + 1 << endl;
    }
    return 0;
}

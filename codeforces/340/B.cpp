#include <iostream>
#include<iomanip>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include<queue>
using namespace std;
#define ld double
#define ll long long

struct node {
    ld x, y;
    ld area(node& n2, node& n3) {
        auto d1 = dis(n2);
        auto d2 = dis(n3);
        return crs(d1, d2);
    }

    ld crs(node& d1, node& d2) {
        return abs(d1.x * d2.y - d1.y * d2.x) / 2;
    }

    node dis(node& n2) {
        node ans;
        ans.x = n2.x - x;
        ans.y = n2.y - y;
        return ans;
    }

};

vector<ld> tris[300][300][2];
void slv() {
    int n; cin >> n;
    vector<node>spec(n);
    for (int i = 0; i < n; i++)
        cin >> spec[i].x >> spec[i].y;
    double ans = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            int pos = i * n + j;
            auto d = spec[i].dis(spec[j]);
            ld s,c;
            bool se = d.x != 0;
            if(se)
                s = d.y / d.x;
            if(se)
                c = spec[i].y - spec[i].x * s;
            double mx1 = 0, mx2 = 0, mn1 = 1e6, mn2 = 1e6;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j)
                    continue;
                ld area = spec[i].area(spec[j], spec[k]);
                bool g = 0;
                if (!se)
                    g = spec[k].x < spec[i].x;
                else g = spec[k].y > spec[k].x * s + c;
                if (g)
                    mx1 = max(area, mx1), mn1 = min(area, mn1);
                else
                    mx2 = max(area, mx2), mn2 = min(area, mn2);

            }
            if(mx1>0&&mx2>0)
                ans = max(ans, mx1 + mx2);
            if(mx1>0)
                ans = max(ans, mx1 - mn1);
            if(mx2>0)
                ans = max(ans, mx2 - mn2);
        }
        
    cout << fixed <<ans<< '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--) {
        slv();
    }
    cout.flush();

}
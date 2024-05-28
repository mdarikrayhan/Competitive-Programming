// ⠀⠀⠀⠀⠀⠀⠀⠀⠀ ＿＿
// 　　　　　／＞　　フ
// 　　　　　| 　_　 _ |
// 　 　　　／` ミ＿xノ
// 　　 　 /　　　 　 |
// 　　　 /　 ヽ　　 ﾉ
// 　 　 │　　|　|　|
// 　／￣|　　 |　|　|
// 　| (￣ヽ＿_ヽ_)__)
// 　＼二つ
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int N = (1e5) + 4;
typedef long double ld;
ld w, h, a;
const ld pi = acos(-1);
// LOGIC BEFORE CODE
// CHECK FOR YOUR OWN TESTCASES
void solve()
{
    cin >> w >> h >> a;
    if (h > w) {
        swap(h, w);
    }
    a = min(a, 180.0 - a);
    a /= 180;
    a *= pi;
    ld z = (w - (h * sin(a)) / (1.0 + cos(a))) / (1.0 + cos(a) - sin(a) * sin(a) / (1 + cos(a)));
    ld v = (h - z * sin(a)) / (1.0 + cos(a));
    if (v > 0.0) {
        ld x = z * cos(a);
        ld y = z * sin(a);
        ld ans = w * h;
        ans -= x * y;
        x = v * cos(a);
        y = v * sin(a);
        ans -= x * y;
        cout << fixed << setprecision(7) << ans << endl;
    } else {
        v = h / sin(a);
        ld x = v * cos(a / 2.0);
        ld y = v * sin(a / 2.0);
        ld ans = x * y * 2.0;
        cout << fixed << setprecision(7) << ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}
// LOGIC BEFORE CODE
// CHECK FOR YOUR OWN TESTCASES

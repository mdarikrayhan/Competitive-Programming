// LUOGU_RID: 160153908
#include <bits/stdc++.h>
using namespace std;
namespace Slongod{
const int N = 105;
int n , W , sm , a[N] , b[N] , id[N];
pair <int,int> p[N];
void main()
{
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; sm += a[i];
        p[i].first = a[i]; p[i].second = i;
    } sort(p + 1 , p + 1 + n);
    for (int i = 1; i <= n; i++){a[i] = b[i] = p[i].first; id[i] = p[i].second;}
    if (W <= 0 or W > sm){cout << "No\n"; return;}
    if (W == 1 and a[1] > 1){cout << "No\n"; return;}
    if (W < a[1] and n < 2){cout << "No\n"; return;}
    
    cout << "Yes\n";
    if (W >= a[1]) {
        cout << id[1] << ' ';
        for (int i = 1 , tw = W; tw; i++) {
            while(a[i] and tw) {
                a[i]--; tw--;
            }
        }
        for (int i = 1; i <= n; i++) {
            while(a[i]--) {
                cout << id[i] << ' ' << id[i] << ' ';
            }
        } cout << id[1] << ' '; b[1]--; W--;
        for (int i = 1; W; i++) {
            while(b[i] and W) {
                b[i]--; W--;
                cout << id[i] << ' ' << id[i] << ' ';
            }
        } cout << '\n';
    } else {
        cout << id[1] << ' '; a[1]--; a[2]--;
        for (int i = 2; i <= n; i++) {
            while(a[i]--){cout << id[i] << ' ' << id[i] << ' ';;}
        } cout << id[1] << ' ' << id[2] << ' ';
        while((a[1]--) >= W - 1){cout << id[1] << ' ' << id[1] << ' ';} a[1]++;
        cout << id[2] << ' '; while(a[1]--){cout << id[1] << ' ' << id[1] << ' ';}
    }
}
}int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    return Slongod :: main(),0;
}
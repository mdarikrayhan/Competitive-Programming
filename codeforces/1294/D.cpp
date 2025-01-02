// When the MEX increases then we need from that array to determine if we can get it again
// So how do we determine whether or not we can get then number let's say 5?
// Let's say we get the number 15 and x is 10, 15 mod 10 = 5
// But what about something like we need the number 20 and we have a 25 and x = 5?
// Let's take the number 20 mod x, that would give us 0
// Since 25 mod 5 is also 0, it's possible. It also works if it's not 0, if they have the same mod, then it works
// x = 6, we are at 20
// If we look at the numbers a where a mod 6 = 2
// 2, 8, 14, 20, 26, 32, notice that all of these numbers work. So we have a count mod array

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, x; cin >> q >> x;
    vector<int> cnt(x, 0);
    int MEX = 0;
    for (int i = 0; i < q; i++){
        int y; cin >> y;
        cnt[y % x]++;
        while (cnt[MEX % x] > 0){
            cnt[MEX % x]--;
            MEX++;
        }
        cout << MEX << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template<typename T, typename U>
bool chkmax(T& a, U b) {
    return a < b && (a = forward<U>(b), true);
}
template<typename T, typename U>
bool chkmin(T& a, U b) {
    return a > b && (a = forward<U>(b), true);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string in; cin >> in;

    int move = 0;
    for(int i = 0; i < n/2; i++) {
        if(in[2*i] == in[2*i+1]) {
            in[2*i] = 'a' + 'b' - in[2*i];
            move++;
        }
    }

    cout << move << '\n';
    cout << in << '\n';
    
    return 0;
}

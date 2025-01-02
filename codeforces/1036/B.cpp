#include<bits/stdc++.h>
#define bug(x...)                  \
    do {                           \
        std::cout << #x << " -> "; \
        err(x);                    \
    } while (0)
void err() { std::cout << std::endl;}
template <class T, class... Ts>
void err(T arg, Ts ...args) { std::cout << arg << ' '; err(args...);}
using ll = long long;
using namespace std;

void work(){
    ll x, y, k;
    cin >> x >> y >> k;
    if(x > y) swap(x, y);

    if(k < max(x, y)){
        cout << -1 << '\n';
        return;
    }

    ll res = 0;
    res += x;
    k -= x;
    y -= x;

    ll d = y / 2 * 2;
    res += d;
    k -= d;
    y %= 2;

    if(y == 0){
        if(k & 1) res += k - 2;
        else res += k;
    }else{
        res += k - 1;
    }

    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; cin >> T;
    while(T--) work();

    return 0;
}
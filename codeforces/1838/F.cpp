#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// Ofast, O0, O1, O2, O3, unroll-loops, fast-math, trapv

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define Mp          make_pair
#define sep         ' '
//#define endl        '\n'
#define F	        first
#define S	        second
#define pb          push_back
#define SZ(x)       (int)x.size()
#define all(x)      (x).begin(),(x).end()
#define kill(res)	cout << res << '\n', exit(0);
#define set_dec(x)	cout << fixed << setprecision(x);
#define fast_io     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io     freopen("input.txt", "r", stdin) ; freopen("output.txt", "w", stdout);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll N = 107;
const ll Mod = 1e9 + 7;

int n, x1, Y1, x2, y2;

void outp1(){
    for(int i = 1; i <= n; i++){
        if(i % 2){
            for(int j = 1; j < n; j++) cout << ">";
            cout << "v" << endl;
        }
        else{
            cout << "v";
            for(int j = 1; j < n; j++) cout << "<";
            cout << endl;
        }
    }
}

void outp2(){
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            for(int j = 1; j < n; j++) cout << ">";
            cout << "^" << endl;
        }
        else{
            cout << "^";
            for(int j = 1; j < n; j++) cout << "<";
            cout << endl;
        }
    }
}

void output(int x, int y){
    cout << "? " << x << sep << y << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << "^";
        }
        cout << endl;
    }

    int xp, yp;
    cin >> xp >> yp;

    if(xp == 0 && yp == y){
        cout << "! " << x << sep << y << sep << "^" << endl;
        return;
    }

    cout << "? " << x << sep << y << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << "v";
        }
        cout << endl;
    }

    cin >> xp >> yp;

    if(xp == n+1 && yp == y){
        cout << "! " << x << sep << y << sep << "v" << endl;
        return;
    }

    cout << "? " << x << sep << y << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << "<";
        }
        cout << endl;
    }

    cin >> xp >> yp;

    if(xp == x && yp == 0){
        cout << "! " << x << sep << y << sep << "<" << endl;
        return;
    }

    cout << "? " << x << sep << y << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ">";
        }
        cout << endl;
    }

    cin >> xp >> yp;

    if(xp == x && yp == n+1){
        cout << "! " << x << sep << y << sep << ">" << endl;
        return;
    }
}

int main(){
    fast_io;
    
    cin >> n;

    cout << "? " << 1 << sep << 1 << endl;

    outp1();

    cin >> x1 >> Y1;

    if(x1 == -1){
        int l = 1, r = n * n + 1;
        while(r-l > 1){
            int mid = (l+r)/2;

            int x = (mid + n - 1) / n;
            int y = mid - (x-1) * n;
            if(x % 2 == 0) y = n+1 - y;

            cout << "? " << x << sep << y << endl;
            outp1();

            int xp, yp;
            cin >> xp >> yp;

            if(xp == -1) l = mid;
            else r = mid;
        }

        int x = (l + n - 1) / n;
        int y = l - (x-1) * n;
        if(x % 2 == 0) y = n+1 - y;
        output(x, y);
        return 0;
    }
    else if(x1 == n+1 && ((n % 2 && Y1 == n) || (n % 2 == 0 && Y1 == 1))){
        int nothing = 0;
    }
    else{
        if(x1 == 0) cout << "! " << 1 << sep << Y1 << sep << "^" << endl;
        if(x1 == n+1) cout << "! " << n << sep << Y1 << sep << "v" << endl;
        if(Y1 == 0) cout << "! " << x1 << sep << 1 << sep << "<" << endl;
        if(Y1 == n+1) cout << "! " << x1 << sep << n << sep << ">" << endl;
        return 0;
    }

    if(n % 2) cout << "? " << n << sep << n << endl;
    else cout << "? " << n << sep << 1 << endl;

    outp2();

    cin >> x2 >> y2;

    if(x2 == -1){
        int l = 1, r = n * n + 1;
        while(r-l > 1){
            int mid = (l+r)/2;

            int x = (mid + n - 1) / n;
            int y = mid - (x-1) * n;
            x = n+1 - x;
            if(x % 2) y = n+1 - y;

            cout << "? " << x << sep << y << endl;
            outp2();

            int xp, yp;
            cin >> xp >> yp;

            if(xp == -1) l = mid;
            else r = mid;
        }

        int x = (l + n - 1) / n;
        int y = l - (x-1) * n;
        x = n+1 - x;
        if(x % 2) y = n+1 - y;
        output(x, y);
        return 0;
    }
    else if(x2 == 0 && y2 == 1){
        int nothing = 0;
    }
    else{
        if(x2 == 0) cout << "! " << 1 << sep << y2 << sep << "^" << endl;
        if(x2 == n+1) cout << "! " << n << sep << y2 << sep << "v" << endl;
        if(y2 == 0) cout << "! " << x2 << sep << 1 << sep << "<" << endl;
        if(y2 == n+1) cout << "! " << x2 << sep << n << sep << ">" << endl;
        return 0;
    }

}

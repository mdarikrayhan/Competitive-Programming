#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define rep(i,a,b) for (int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define PB push_back
#define FS first
#define SD second
#define ary(k) array<int, k>
template<class A,class B> void cmx(A &x, B y) {x=max<A>(x, y);}
template<class A,class B> void cmn(A &x, B y) {x=min<A>(x, y);}
typedef pair<int, int> pii;
typedef vector<int> vi;

int res[102][102];
int ans[3][3], q = 0, n;

mt19937 rng(2137);

bool solve() {
    int myans[4][4];
    for (int ii = 0; ii < (1<<16); ii++) {
//            cerr << "try\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                myans[i][j] = 0;
                if (ii & (1<<(3*i+j)))
                    myans[i][j] = 1;
//                    cerr << myans[i][j];
            }
//                cerr << "\n";
        }
        for (int h = 1; h <= 4; h++) {
            for (int w = 1; w <= 4; w++) {
                int ok = 1;
                for (int si = 0; si < 3; si++) {
                    for (int sj = 0; sj < 3; sj++) {
                        int ile = 0;
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 3; j++) {
//                            int reszta = (i+si)/3 + (j+sj)/3;
//                            reszta %= 2;
                                ile += ans[i][j] * myans[(i+si)%h][(j+sj)%w];
                            }
                        }
//                            cerr << si << " " << sj << " " << ile << "\n";
                        if (ile%2==0)
                            ok = 0;
                    }
                }
                if (ok) {
//                        cerr << "hurra\n";
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            cout << myans[i%h][j%w];
                        }
                        cout << "\n";
                    }
                    cout.flush(); q++;
                    string sss;
                    cin >> sss;
                    return true;
                }
            }
        }
    }
    return false;
}

void fun() {
    cin >> n;
    if (n > 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j && i == 2) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << "\n";
        }
        cout.flush(); q++;
        string slo;
        cin >> slo;
        if (slo == "CORRECT")
            return;
        for (int i = 0; i < n-2; i++) {
            cin >> slo;
            for (int j = 0; j < n-2; j++) {
                res[i][j] = slo[j]-'0';
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ans[i][j] = res[2-i][2-j];
//                cerr << ans[i][j];
            }
//            cerr << "\n";
        }
        assert(solve());
    } else {
        while (true) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << rng() % 2;
                }
                cout << "\n";
            }
            cout.flush(); q++;
            string slo;
            cin >> slo;
            if (slo == "CORRECT")
                return;
            cin >> slo;
        }
    }
}

signed main() {
//	cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    int t = 333;
    while (t--) fun();
//    for (int ii = 1; ii < (1<<9); ii++) {
//        for (int i = 0; i < 3; i++) {
//            for (int j = 0; j < 3; j++) {
//                ans[i][j] = 0;
//                if (ii & (1 << (3 * i + j)))
//                    ans[i][j] = 1;
//                cerr << ans[i][j];
//            }
//            cerr << "\n";
//        }
//        cerr << "\n";
//        assert(solve());
//    }
}

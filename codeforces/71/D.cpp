// LUOGU_RID: 160394881
#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const char ra[4] = {'C', 'D', 'H', 'S'};
const char rb[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

int n;
int m;
int g[20][20];
int was[54];

int get (string s) {
    if (s[0] == 'J' && (s[1] == '2' || s[1] == '1')) re s[1] - '0' + 51;
    int tmp = 0;
    for (int i = 0; i < 4; i++)
        if (s[1] == ra[i])
            tmp += 13 * i;
    for (int i = 0; i < 13; i++)
        if (s[0] == rb[i])
            tmp += i;
    re tmp;
}

int cross (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    re int (max (x1, x3) <= min (x2, x4) && max (y1, y3) <= min (y2, y4));
}

int check (int x, int y, int j1, int j2) {
    int ok1 = 1, ok2 = 1;
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            for (int c = 0; c < 3; c++)
                for (int d = 0; d < 3; d++) {
                    if (a == c && b == d) continue;
                    int p = g[x + a][y + b];
                    if (p == 52) p = j1;
                    if (p == 53) p = j2;
                    int q = g[x + c][y + d];
                    if (q == 52) q = j1;
                    if (q == 53) q = j2;
                    if (p / 13 != q / 13) ok1 = 0;
                    if (p % 13 == q % 13) ok2 = 0;
                }
    re ok1 | ok2;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            g[i][j] = get (s);
            was[g[i][j]] = 1;
        }
    for (int j1 = -1; j1 < 52; j1++)
        if (j1 == -1 && !was[52] || j1 != -1 && was[52] && !was[j1])
            for (int j2 = -1; j2 < 52; j2++)
                if ((j2 == -1 && !was[53] || j2 != -1 && was[53] && !was[j2]) && (j1 == -1 || j2 == -1 || j1 != j2))                    
                    for (int p = 0; p + 2 < n; p++)
                        for (int q = 0; q + 2 < m; q++)
                            if (check (p, q, j1, j2))
                                for (int a = 0; a + 2 < n; a++)
                                    for (int b = 0; b + 2 < m; b++)
                                        if (check (a, b, j1, j2) && !cross (p, q, p + 2, q + 2, a, b, a + 2, b + 2)) {
                                            printf ("Solution exists.\n");
                                            if (j1 == -1 && j2 == -1) printf ("There are no jokers.\n");
                                            if (j1 != -1 && j2 == -1) printf ("Replace J1 with %c%c.\n", rb[j1 % 13], ra[j1 / 13]);
                                            if (j1 == -1 && j2 != -1) printf ("Replace J2 with %c%c.\n", rb[j2 % 13], ra[j2 / 13]);
                                            if (j1 != -1 && j2 != -1) printf ("Replace J1 with %c%c and J2 with %c%c.\n", rb[j1 % 13], ra[j1 / 13], rb[j2 % 13], ra[j2 / 13]);
                                            printf ("Put the first square to (%d, %d).\n", p + 1, q + 1);
                                            printf ("Put the second square to (%d, %d).\n", a + 1, b + 1);
                                            re 0;
                                        }
    printf ("No solution.\n");
    return 0;
}

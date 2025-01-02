/*
SkibidiDomDomDomDomDomDo&######&mDomDomDomDomDomDo
YesYesYesYesYesYesYes@#BGGBBBBBB#@@YesYesYesYesYes
@@@@@@@@@@@@@@@@@@@@@#?JJ?7?7?JJG@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@BJ5YJ!!7?JJ5@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@BYYJY??YJJJYB@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@#YJYY??J?7?5&@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@#YJ55JYYYJJG@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@&P5JJJ??JYP&@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@&&BBGPBBBBGG5YYPGB#@@@@@@@@@@@@@@
@@@@@@@@@@@@@&#BGGPPP5P55555YYYYPPPPGB#&@@@@@@@@@@
@@@@@@@@@@@#GPPPPPPPPPGPPPPPP55PPPPPPPPGB&@@@@@@@@
@@@@@@@@@&GPPPPPPPPPPPPPPPPPPPPPPPPPPPGPPGB&@@@@@@
@@@@@@@@#PPPPPPPPPPPPPPPPPPPP5PPPY5PPPPPPPPPG&@@@@
@@@@@@@BPPGGPPPPPPPPPP5PPPPPPPPPPJ?YY5PGPPPP5P&@@@
@@@@@&GPGGGGPPPPPPPPPPP5PPP5PGGGGPJ??JJY5PPPPPPB@@
@@@@#GGGGGBGPPPPPPPPPPP5PGPPGGP5PY?JJJ???JY5PP55G@
@@@#GGGGGBBGGPPPPPPPPPPP5GPGGJJ??JJJJJ?????JYY555G
@@&P55PGGB#BGGGPPPPPPPPGPYGBBPP5JJ??Y555YJJYYYYYP#
@@G5YYJY5B&#BBGGPPPPPPPY7~?PBBBBGPPGB#&BP5YYYYYYP@
@#555YYJY&&BBGGGPPPPPPPY!~^YBGGGGGGBBB#&BP5YY555#@
@BYYYYY5#&BBBGGGPPPPPPPP5Y5PGGGGGPPPGGB##BGPGGB#@@
@GJYYYG&@BGGBBGGPPPPPPPPPPPPPPPPPPPPPPGGGBGP&@@@@@
&PJJYY#@#GGGGBGGGGPGPPPPPPPPPPPPPPPPPPPPPPP5#@@@@@
B5YJ5YB@BGGBGGGGGGGGPPPPPPPPPPPPPPPPPPPPPPP5B@@@@@
#G55G&@@BGGGGGGGGGGGPPPPPPPPPPPPPPPPPPPPPPP5B@@@@@
@&B#@@@@#GGGGGGGGGGGGGPPPPPPPPPPPPPPPPPPPPPPP#@@@@
@@@@@@@#GGGGGGGGGGGGGGGGGGPGGPPPPPPPPPPPGGP5JY&@@@
@@@@@@&GGGBBGGGGGGGGGGGGGGGGGGGGGGGGGGGGP5?!!!G@@@
@@@@@@&YY5PBBBBBGGGGGGGGGGGGGGGGGGGGGPYJ7!!!!!5@@@
@@@@@@#J?7?JY5PGBBBBBBBBBBBBBGGGP5Y?7!!!!!!!!!?&@@
@@@@@@&J??77777?JY55PGPP55YYJ??77!!!!!!!!!!!!!7&@@
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define Endl endl
#define ll long long
#define in insert
#define F first
#define S second
#define ii pair <int, int> 
#define vii vector <ii>
#define loop(i, n) for(int i = 0 ; i < n ; i++)
#define lop(i, x, n) for(int i = x ; i <= n ; i++)
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

const int N = 5e2 + 5;
int n, m;
int a[N][N], pr[N][N];

int ss(int x1, int y1, int x2, int y2) {
    return  pr[x2][y2] - pr[x2][y1-1] - pr[x1-1][y2] + pr[x1-1][y1-1];
}

bool valid (int x1, int y1, int x2, int y2) {
    return x1 > 0 && x2 > 0 && x1 <= n && x2 <= n && y1 > 0 && y2 > 0 && y1 <= m && y2 <= m;
}

int fc (int x1, int y1) {
    int mx = INT_MIN;

    int x2 = x1 + 2, y2 = y1 + 2;

    if (!valid(x1, y1, x2, y2)) return INT_MIN;
    int sm = ss(x1, y1, x2, y2) - a[x1+1][y1] - a[x1+1][y1+1];

    mx = max(mx, sm);

    while (x1 > 0 && y1 > 0) {
        x1 --, y1 --;
        x2 ++, y2 ++;

        if (!valid(x1, y1, x2, y2) || x1 - 1 < 0 || y1 - 1 < 0) break;

        sm = ss(x1, y1, x2, y2) - sm - a[x1+1][y1];

        mx = max(mx, sm);
    }

    return mx;
}

void solve(){
    scanf("%d%d", &n, &m);

    lop (i, 1, n) lop (j, 1, m) scanf("%d", &a[i][j]);

    lop (i, 1, n) {
        lop (j, 1, m) {
            pr[i][j] = pr[i-1][j] + pr[i][j-1] - pr[i-1][j-1] + a[i][j];
        }
    }

    int ans = INT_MIN;

    lop (i, 1, n) {
        lop (j, 1, m) {
            ans = max(ans, fc(i, j));
        }
    }

    printf("%d\n", ans);
}

int main(){

    int tt = 1;

    while(tt--){
        solve();
    }

    return 0;
}
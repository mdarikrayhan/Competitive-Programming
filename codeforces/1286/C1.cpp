// LUOGU_RID: 159781149
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pr pair<int, int>
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    int x = 0, mm = 1;
    char ch = getchar();

    while (!isdigit(ch)) {
        if (ch == '-') mm = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }

    return x * mm;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }

    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 105;

vector<string> a[N], b[N], c[N];

char ans[N], L[N], R[N];
int cnt[N], vis[N];

int n, m;

int calcA(int len, char ch) {
    if (!len) return 0;
    int Ans = 0;
    for (int i = 0; i < a[len].size(); i++) {
        for (int j = 0; j < len; j++) {
            if (a[len][i][j] == ch) Ans++;
        }
    }
    if (len < n) {
        for (int i = 0; i < a[len + 1].size(); i++) {
            for (int j = 0; j < len + 1; j++) {
                if (a[len + 1][i][j] == ch) Ans--;
            }
        }
    }
    return Ans;
}

int calca(int pos, char ch) {
    return calcA(n - pos + 1, ch) - calcA(n - pos, ch);
}

int calcBC(int len, char ch) {
    if (len > m) return 0;

    int Ans = 0;

    for (int i = 0; i < c[len].size(); i++) {
        for (int j = 0; j < len; j++) {
            if (c[len][i][j] == ch) Ans++;
        }
    }

    if (len > 1) {
        for (int i = 0; i < b[len - 1].size(); i++) {
            for (int j = 0; j < len - 1; j++) {
                if (b[len - 1][i][j] == ch) Ans--;
            }
        }
    }

    return Ans;
}

int calcbc(int pos, char ch) {
    return calcBC(m - pos + 1, ch) - calcBC(m - pos + 2, ch);
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;

    if (n == 1) {
        cout << "? 1 " << n << endl;
        string s;
        cin >> s;
        cout << "! " << s << endl;
        return 0;
    }
    if (n == 2) {
        string s = "";
        char ch;
        cout << "? 1 1" << endl;
        cin >> ch;
        s += ch;
        cout << "? 2 2" << endl;
        cin >> ch;
        s += ch;
        cout << "! " << s << endl;
        return 0;
    }
    if (n == 3) {
        string s = "";
        char ch;
        cout << "? 1 1" << endl;
        cin >> ch;
        s += ch;
        cout << "? 2 2" << endl;
        cin >> ch;
        s += ch;
        cout << "? 3 3" << endl;
        cin >> ch;
        s += ch;
        cout << "! " << s << endl;
        return 0;
    }

    cout << "? 1 " << n << endl;

    for (int i = 1; i <= n * (n + 1) / 2; i++) {
        string s;
        cin >> s;
        a[s.size()].pb(s);
    }

    m = n / 2;

    cout << "? 2 " << m << endl;

    for (int i = 1; i <= m * (m - 1) / 2; i++) {
        string s;
        cin >> s;
        b[s.size()].pb(s);
    }

    cout << "? 1 " << m << endl;

    for (int i = 1; i <= m * (m + 1) / 2; i++) {
        string s;
        cin >> s;
        c[s.size()].pb(s);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 26; j++) {
            int now = calcbc(i, j + 97);
            ans[i] += now * (j + 97);
        }
    }

    for (int i = 1; i <= m; i++) {
        int sum = 0;
        for (int j = 0; j < 26; j++) {
            int now = calca(i, j + 97);
            sum += now * (j + 97);
        }
        ans[n - i + 1] = char(sum - ans[i]);
    }

    if (n & 1) {
        int res = 0;
        for (int i = 0; i < n; i++) res += a[n][0][i];
        for (int i = 1; i <= n; i++) {
            if (i == m + 1) continue;
            res -= ans[i];
        }
        ans[m + 1] = res;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << endl;
}
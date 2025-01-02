#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
inline int read() {int x=0,f=1,ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1; ch=getchar();}while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-'0'); ch=getchar();}return f==1?x:-x;}
inline void print(int a[],int n,int offset=0) {for(int i=0; i<n; i++)printf("%d ",a[i+offset]);printf("\n");}

inline void init() {
    int n = read(), m = read(), d = read();
    vector<int> s(m + 2);
    for (int i = 1; i <= m; i++) s[i] = read();
    s[0] = 0;
    s[m + 1] = n + 1;
    vector<int> f(m + 2), g(m + 2);
    f[0] = 0;
    for (int i = 1; i <= m; i++) f[i] = f[i - 1] + (i == 1 ? 1 + (s[i] - 1 + d - 1) / d : (s[i] - s[i - 1] + d - 1) / d);
    g[m + 1] = 0;
    for (int i = m; i >= 1; i--) g[i] = g[i + 1] + (s[i + 1] - s[i] + d - 1) / d;
    // for (int i = 0; i <= m + 1; i++) cout << f[i] << ' '; cout << endl;
    // for (int i = 0; i <= m + 1; i++) cout << g[i] << ' '; cout << endl;
    int mn = 2e9, cnt = 0;
    for (int i = 1; i <= m; i++) {
        int x = f[i - 1] + g[i + 1];
        if (i == 1) {
            x += (s[i + 1] - 1 + d - 1) / d;
        } else {
            x += (s[i + 1] - s[i - 1] - 1) / d;
        }
        if (x < mn) mn = x, cnt = 1;
        else if (x == mn) cnt++;
    }
    cout << mn << ' ' << cnt << '\n';
}
inline void doit() {
}
int main() {
    //freopen("test.in", "r", stdin);
    int t=read();
    while(t--){
        init();
        doit();
    }
    return 0;
}

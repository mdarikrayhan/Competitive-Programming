// LUOGU_RID: 157112781
#include <bits/stdc++.h>
#define LL long long
#define mes(s, x) memset(s, x, sizeof(s))
#define Maxn 505
#define Maxn2 250005
// #define Maxn 5
// #define Maxn2 15
#define mod 998244353
using namespace std;
inline LL read(){char c;c = getchar();while(!(('0' <= c && c <= '9') || c == '-')) c = getchar();bool flag = 0;if(c == '-'){flag = 1;c = getchar();}LL tot = 0;while('0' <= c && c <= '9'){tot = 10 * tot + c - '0';c = getchar();}return flag ? -tot : tot;}
int a[Maxn][Maxn], px[Maxn2], py[Maxn2], dt[2 * Maxn], d[2 * Maxn];
vector<int> g[2 * Maxn];
stack<int> stk;
bool b[Maxn];
void addedge(int i, int j){
    g[i].push_back(j);
    d[j]++;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
        freopen("out","w",stdout);
    #endif
    int T = read(), n, x, y, ans;
    bool flag;
    while(T--){
        ans = 1;
        n = read();
        for(int i = 0; i < 2 * n; i++) dt[i] = -1, g[i].clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = read();
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                x = read();
                px[x] = i;
                py[x] = j;
            }
        }
        flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(px[a[i][j]] == i){
                    if(dt[i] != -1 && dt[i] != (py[a[i][j]] - j + n) % n) flag = 1;
                    dt[i] = (py[a[i][j]] - j + n) % n;
                }
                if(py[a[i][j]] == j){
                    if(dt[n + j] != -1 && dt[n + j] != (px[a[i][j]] - i + n) % n) flag = 1;
                    dt[n + j] = (px[a[i][j]] - i + n) % n;
                }
            }
        }
        if(flag){
            puts("0");
            continue;
        }
        for(int i = 0; i < n; i++) if(dt[i] > 0) flag = 1;
        if(!flag){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(py[a[i][j]] != j) flag = 1;
                }
            }
            if(flag){
                puts("0");
                continue;
            }
            x = 0;
            for(int i = 0; i < n; i++){
                if(dt[n + i] > 0){
                    x++;
                    ans = 1ll * x * ans % mod;
                }
            }
            printf("%d\n", ans);
            continue;
        }
        flag = 0;
        for(int i = 0; i < n; i++) if(dt[n + i] > 0) flag = 1;
        if(!flag){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(px[a[i][j]] != i) flag = 1;
                }
            }
            if(flag){
                puts("0");
                continue;
            }
            x = 0;
            for(int i = 0; i < n; i++){
                if(dt[i] > 0){
                    x++;
                    ans = 1ll * x * ans % mod;
                }
            }
            printf("%d\n", ans);
            continue;
        }
        flag = 0;
        for(int i = 0; i < 2 * n; i++) if(dt[i] == -1) flag = 1;
        if(flag){
            puts("0");
            continue;
        }
        for(int i = 1; i < n; i++) b[i] = 0;
        for(int i = 0; i < n; i++){
            if(dt[i]){
                if(b[dt[i]]) flag = 1;
                b[dt[i]] = 1;
            }
        }
        for(int i = 1; i < n; i++) b[i] = 0;
        for(int i = 0; i < n; i++){
            if(dt[n + i]){
                if(b[dt[n + i]]) flag = 1;
                b[dt[n + i]] = 1;
            }
        }
        if(flag){
            puts("0");
            continue;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dt[i] == (py[a[i][j]] - j + n) % n){
                    if(dt[n + j] && dt[i]) addedge(i, n + j);
                    if(i == px[a[i][j]]){
                        if(dt[i]){
                            if(dt[n + py[a[i][j]]]) addedge(n + py[a[i][j]], i);
                        }else{
                            if(dt[n + py[a[i][j]]]) flag = 1;
                        }
                    }else if(dt[n + py[a[i][j]]] == (px[a[i][j]] - i + n) % n){
                        if(dt[i]) addedge(i, n + py[a[i][j]]);
                    }else flag = 1;
                }else if(dt[n + j] == (px[a[i][j]] - i + n) % n){
                    if(dt[i] && dt[n + j]) addedge(n + j, i);
                    if(j == py[a[i][j]]){
                        if(dt[n + j]){
                            if(dt[px[a[i][j]]]) addedge(px[a[i][j]], n + j);
                        }else{
                            if(dt[px[a[i][j]]]) flag = 1;
                        }
                    }else if(dt[px[a[i][j]]] == (py[a[i][j]] - j + n) % n){
                        if(dt[n + j]) addedge(n + j, px[a[i][j]]);
                    }else flag = 1;
                }else flag = 1;
            }
        }
        // for(int i = 0; i < 2 * n; i++){
        //     for(int j = 0; j < g[i].size(); j++){
        //         cerr<<i<<" "<<g[i][j]<<endl;
        //     }
        // }
        for(int i = 0; i < 2 * n; i++) if(dt[i] && d[i] == 0) stk.push(i);
        while(stk.size()){
            ans = 1ll * stk.size() * ans % mod;
            x = stk.top();
            stk.pop();
            for(int j = 0; j < g[x].size(); j++){
                y = g[x][j];
                d[y]--;
                if(d[y] == 0) stk.push(y);
            }
        }
        for(int i = 0; i < 2 * n; i++){
            if(d[i]) flag = 1;
            d[i] = 0;
            g[i].clear();
        }
        if(flag){
            puts("0");
            continue;
        }
        printf("%d\n", ans);
    }
    return 0;
}
// LUOGU_RID: 159653944
//私は猫です
#include <bits/stdc++.h>
using namespace std;
// #define int long long
int read(){
    int xx = 0, f = 1; char ch = getchar();
    for (;!isdigit(ch); ch = getchar())
        f = (ch == '-' ? -1 : 1);
    for (; isdigit(ch); ch = getchar())
        xx = (xx << 3) + (xx << 1) + ch - '0';
    return xx * f;
}
int n, cnt = 0, tmp, tmpt;
char a[1005], ans[1005], b[1005];
char rev(char x){return x == 'T' ? 'F' : 'T';}
int ask(int l, int r){
    if ((++cnt) > 675){while(1);} int ret = 0;
    if ((r - l + 1) & 1){
        for (int i = 1; i <= n; ++i)printf("%c", (l <= i && i <= r) ? 'F' : 'T');
        printf("\n"); fflush(stdout);
    }
    else {
        for (int i = 1; i <= n; ++i)printf("%c", (l <= i && i <= r) ? rev(a[i]) : a[i]);
        printf("\n"); fflush(stdout);
    }
    ret = read(); 
    if (ret == n)exit(0);
    return ret;
}
signed main(){
    n = read();
    for (int i = 1; i <= n; ++i)
    for (int i = 1; i <= n; ++i)a[i] = (i & 1 ? 'T' : 'F');
    tmp = ask(-1, 0), tmpt = ask(-2, 0);
    for (int i = 1, x, ret; i <= n; i += 3){
        if (i + 3 > n + 1){
            while(i <= n){
                ret = ask(i, i);
                if (ret == tmpt + 1)ans[i] = 'F';
                else ans[i] = 'T';
                ++i;
            }
            break;
        }
        ret = ask(i, i + 2); x = (tmpt - ret + 3) / 2; // x = cnt_true
        // cout<<x<<endl;
        if (x == 0){ans[i] = ans[i + 1] = ans[i + 2] = 'F';}
        else if (x == 3){ans[i] = ans[i + 1] = ans[i + 2] = 'T';}
        else {
            ret = ask(i, i + 1);
            if (ret == tmp + 2){
                ans[i] = rev(a[i]), ans[i + 1] = rev(a[i + 1]);
                ans[i + 2] = (x == 2 ? 'T' : 'F');
            }
            else if (ret + 2 == tmp){
                ans[i] = a[i], ans[i + 1] = a[i + 1];
                ans[i + 2] = (x == 2 ? 'T' : 'F');
            }
            else if (x == 1)ans[i] = ans[i + 1] = 'F', ans[i + 2] = 'T';
            else ans[i] = ans[i + 1] = 'T', ans[i + 2] = 'F';
        }
    }
    for (int i = 1; i <= n; ++i)printf("%c", ans[i]); printf("\n");
    return 0;
}


// LUOGU_RID: 158974639
#include <bits/stdc++.h>
using namespace std;
int a[55][55],b[55][55];
int main() {
    int na,ma; cin >> na >> ma;
    for(int i = 1;i <= na;i++) {
        for(int j = 1;j <= ma;j++) {
            scanf("%01d",&a[i][j]);
        }
    }
    int nb,mb; cin >> nb >> mb;
    for(int i = 1;i <= nb;i++) {
        for(int j = 1;j <= mb;j++) {
            scanf("%01d",&b[i][j]);
        }
    }
    long long maxn = -0x7fffffffffff,maxx = -1,maxy = -1;
    for(int x = min(-nb,-na);x <= max(nb,na);x++) {
        for(int y = min(-mb,-ma);y <= max(mb,ma);y++) {
            bool flag = true;
            long long ans = 0;
            for(int i = 1;i <= na;i++) {
                for(int j = 1;j <= ma;j++) {
                    if((i+x) > nb || (j+y) > mb || (i+x) < 1 || (j+y) < 1) {
                        continue;
                    }
                    else ans += 1ll * a[i][j] * b[i+x][j+y];
                }
            }
            if(flag) {
                if(ans > maxn) {
                    maxn = ans;
                    maxx = x;
                    maxy = y;
                }
            }
        }
    }
    cout << maxx << ' ' << maxy << endl;
    return 0;
}
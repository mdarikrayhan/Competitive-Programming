// LUOGU_RID: 160441506
/**
 *    author: sunkuangzheng
 *    created: 27.05.2024 14:09:03
**/
#include<bits/stdc++.h>
#ifdef DEBUG_LOCAL
#include <mydebug/debug.h>
#endif
using ll = long long;
const int N = 200+5;
using namespace std;
int T,n,k,f[N][N][N],g[N][N][N]; vector<int> a,ans[N];
struct ele{int x,id;}b[N];
void era(int x){
    for(int i = 0;i < a.size();i ++) if(a[i] == x) return a.erase(a.begin() + i),void();
}int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k,a.resize(n);
    for(int i = 0;i < n;i ++) cin >> a[i];
    for(int i = 1;i <= k;i ++) cin >> b[i].x,b[i].id = i;
    sort(b+1,b+k+1,[&](ele a,ele b){return a.x < b.x;});
    for(int i = 1;i < k;i ++){
        int m = 2 * b[i].x - 1,p = b[i].x;
        for(int j = 0;j < m;j ++) for(int k = 0;k <= p;k ++) for(int l = 0;l <= p;l ++)
            f[j][k][l] = g[j][k][l] = 0;
        f[0][0][0] = 1;
        for(int j = 0;j < m;j ++){
            for(int k = 0;k < p;k ++) for(int l = 0;l < p;l ++){
                if(!j && !k && !l) f[j][k+1][(l + a[j]) % p] = 1,g[j][k+1][(l + a[j]) % p] = j;
                if(j && f[j-1][k][l]) f[j][k+1][(l + a[j]) % p] = 1,g[j][k+1][(l + a[j]) % p] = j;
            }for(int k = 0;k <= p;k ++) for(int l = 0;l < p;l ++) if(!f[j+1][k][l]) 
                f[j+1][k][l] = f[j][k][l],g[j+1][k][l] = g[j][k][l];
        }assert(f[m-1][p][0]); int now = m - 1,st = 0;
        for(int j = p;j >= 1;j --)
            ans[b[i].id].push_back(a[g[now][j][st]]),now = g[now][j][st] - 1,st = (st - a[now+1] % p + p) % p;
        for(int j : ans[b[i].id]) era(j);
    }int sum = 0,fk = 0;
    for(int i : a) sum = (sum + i) % b[k].x,ans[b[k].id].push_back(i);
    cout << (fk = (b[k].x - sum)) << "\n",ans[b[k].id].push_back(fk);
    for(int i = 1;i <= k;i ++,cout << "\n") for(int j : ans[i]) cout << j << " "; 
}
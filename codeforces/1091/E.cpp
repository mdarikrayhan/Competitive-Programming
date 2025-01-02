// LUOGU_RID: 158863481
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, q, l, r, zo, rl, rr, v[500010], w[500010], sum[500010];

int check(int x){//0 : too small; 1 : too big
    for(int i = 1, j = 1; i <= n; i++){
        if(j != i || j == i && v[i] >= x)
            w[j] = v[i];
        else
            w[j] = x, w[++j] = v[i];
        j++;
    }
    if(v[n] >= x)
        w[n + 1] = x;
    // cout << x << endl;
    // for(int i = 1; i <= q; i++)
    //     cout << w[i] << ' ';
    // cout << endl;
    for(int i = 1; i <= q; i++)
        sum[i] = sum[i - 1] + w[i];
    int ind = q;//first place that v[ind] >= k
    for(int k = 1; k <= q; k++){
        while(v[ind] < k)
            ind--;
        int a0 = sum[k], a1 = k * (k - 1) + sum[q] - sum[max(ind, k)] + k * (max(ind, k) - k);
        // cout << a0 << ' ' << a1 << endl;
        if(a0 > a1){
            if(x >= w[k])
                return 1;
            else
                return 0;
        }
    }
    return 2;
}

signed main(){
    cin >> n, q = n + 1, l = 1, r = n;
    for(int i = 1; i <= n; i++)
        cin >> v[i], zo = (zo + v[i]) % 2;
    sort(v + 1, v + n + 1), reverse(v + 1, v + n + 1);
    l = zo, r = n - (n % 2 != zo);
    while(l < r){
        int mid = (l + r) / 2 + 1;
        if(mid % 2 != zo)
            mid++;
        if(check(mid) == 1)
            r = mid - 2;
        else
            l = mid;
    }
    rr = l;
    l = zo, r = n - (n % 2 != zo);
    while(l < r){
        int mid = (l + r) / 2;
        if(mid % 2 != zo)
            mid--;
        if(check(mid) == 0)
            l = mid + 2;
        else
            r = mid;
    }
    rl = l;
    for(int i = rl; i <= rr; i += 2)
        cout << i << ' ';
    if(rl > rr)
        cout << -1;
    cout << endl;
    return 0;
}/////
// LUOGU_RID: 160100360
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k, v;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v, k += v;
    if((k * 2 + n - n * n) % (n * 2) == 0){
        int rr = (k * 2 + n - n * n) / (n * 2);
        for(int i = 0; i < n; i++)
            cout << rr + i << ' ';
        cout << endl;
        return 0;
    }
    int rr = (k * 2 + n - n * n + n * 2 - 1) / (2 * n), x = (n * 2 * rr - k * 2 - n + n * n) / 2;
    for(int i = 0; i < n; i++)
        if(i >= (n - x))
            cout << rr + i - 1 << ' ';
        else
            cout << rr + i << ' ';
    cout << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long
int bigmod(int b, int p, int mod) {
    b=b%mod;
    int res = 1;
    for(; p; res=(p&1?(1ll*res*b)%mod:res),b=(1ll*b*b)%mod, p/=2);
    return res;
}
void solve();
void preCompute();
vector<int> vt;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t= 0, tc=1;
    preCompute();
//    cin >> tc;
    while(tc--) {
        solve();
    }


    return 0;
}

int tc = 0;
const int mxn = 1e5+5;
const int N = 1000+2;
int c[N][N], row1[N], row2[N], col1[N], col2[N], row[N], col[N];
void process(int n, int cnt[], int res[]){
     int temp = 0, temp2 = 0;
     for(int i=1; i<=n; i++){
        res[i]+=cnt[i]*4;
        temp2 += 32*temp;
        temp2 += 16*cnt[i-1];
        temp+=cnt[i-1];
        res[i] += res[i-1] + temp2 + 16*temp;
     }
}
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> c[i][j];
            row[i]+=c[i][j];
            col[j]+=c[i][j];
        }
    }
    process(n, row, row1);
    process(m, col, col1);
    reverse(row+1, row+1+n);
    reverse(col+1, col+1+m);
    process(n, row, row2);
    process(m, col, col2);
    reverse(row2, row2+1+n);
    reverse(col2, col2+1+m);
    int mn = LLONG_MAX;
    int x = -1, y = -1;
    for(int i=0, temp; i<=n; i++){
        for(int j=0; j<=m; j++){
            temp = row1[i]+row2[i]+col1[j]+col2[j];
            if(mn > temp) {
                mn = temp;
                x = i, y = j;
            }
        }
    }

    cout << mn << "\n";
    cout <<x << " "<<y;

}

void preCompute() {



}


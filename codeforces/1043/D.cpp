#include <bits/stdc++.h>

#define pb             push_back
#define int            long long
#define fill(x, y)     memset(x, y, sizeof(x))
#define all(x)         (x).begin(), (x).end()
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define IO             { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
#define endl           '\n'

using namespace std;

typedef long long      ll;
typedef pair<int, int> ii;
typedef vector<int>    vi;



void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m, vi(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int pos[m][n];
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            pos[i][a[i][j]-1]=j; // Corrected index
        }
    }

    int ans=0;
    int cnt=1;
    for(int i=1;i<n;i++) {
        int found=1;
        
        for(int j=0;j<m;j++) {
            int x=pos[j][a[0][i]-1]; // Corrected index
            int y=pos[j][a[0][i-1]-1]; // Corrected index
            if(y+1!=x) {found=false; break;}
        }

        if(found) cnt++; 
        else {
            ans+=(cnt*(cnt+1))/2;
            cnt=1;
        }

    }

    ans += (cnt*(cnt+1))/2;

    cout<<ans<<endl;
}

signed main() {
    IO;
    int tc = 1;
    //cin >> tc;
    for (int cs = 1; cs <= tc; cs++) {
        solve();
    }
}

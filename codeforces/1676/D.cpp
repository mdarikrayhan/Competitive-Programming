#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n";
#define no  cout << "NO\n";
#define f first
#define s second
#define pb push_back

void run_case(){
    int n, m, mx = 0;
    cin >> n >> m;
    int a[n + 1][m + 1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int sum = a[i][j];
            int x = i, u = j, z = j;
            while(x >= 0){
                if(u >= 0){
                    sum += a[x][u];
                    u--;
                }
                if(z <= m - 1){
                    sum += a[x][z];
                    z++;
                }
                x--;
            }
            x = i, u = j, z = j;
            while(x <= n - 1){
                if(u >= 0){
                    sum += a[x][u];
                    u--;
                }
                if(z <= m - 1){
                    sum += a[x][z];
                    z++;
                }
                x++;
            }
            sum -= (4 * a[i][j]);
            mx = max(mx, sum);
            sum = 0;
        }
    }
    
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t-- > 0) run_case(); 
}
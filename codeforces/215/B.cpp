#include <bits/stdc++.h>

using namespace std;
#define fast cin.tie(0); cin.sync_with_stdio(0);
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
bool flag=false;
int cnt=0;


int main(){
    fast;
    int n, m, k, a, b, max_r1=0, max_p1=0, min_p2=5005;
    cin >> n; int x[n];
    for(int i=0;i<n;i++) cin >> x[i];
    cin >> m; int y[m];
    for(int i=0;i<m;i++) cin >> y[i];
    cin >> k; int z[k];
    for(int i=0;i<k;i++) cin >> z[i];
    cin >> a >> b;

    for(int i=0;i<n;i++){
        max_r1 = max(max_r1, x[i]);
    }
    
    for(int i=0;i<m;i++){
        max_p1 = max(max_p1, y[i]);
    }
    for(int i=0;i<k;i++){
        min_p2 = min(min_p2, z[i]);
    }

    double r2 = sqrt((max_r1*max_r1)/(1+((a/ (double)b)*(min_p2/ (double) max_p1))));
    printf("%.12f", r2);
    return 0;
}
#include <bits/stdc++.h>
#define GO cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
typedef long long ll;
using namespace std;
const int N = 1e6 + 5;
int a[N];

int main()
{
    GO
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 1; i < N; i++) a[i] += a[i - 1];
    for(int i = N - 1; i >= 1; i--){
        int s = 0;
        for(int j = i; j < N; j += i){
            int ind = min({N - 1, j + i - 1, j + k});
            s += a[ind] - a[j - 1];
        }
        if(s == n){
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}

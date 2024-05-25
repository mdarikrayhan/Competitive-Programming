#include <bits/stdc++.h>
#define GO cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
typedef long long ll;
using namespace std;


int main()
{
    GO
    int n, k;
    cin >> n >> k;
    string s[4];
    for(int i = 0; i < 4; i++) s[i] = string(n, '.');
    cout << "YES\n";
    if(k % 2 == 0){
        int j = 1;
        while(k){
            k -= 2;
            s[1][j] = '#';
            s[2][j] = '#';
            j++;
        }
    }
    else if(k % 2 && k <= n - 2){
        int l = n / 2;
        int r = n / 2;
        k--;
        s[1][l] = '#';
        while(k){
            k -= 2;
            l--, r++;
            s[1][l] = '#';
            s[1][r] = '#';
        }
    }
    else{
        for(int i = 1; i < n - 1; i++) s[1][i] = '#', k--;
        k -= 2;
        assert(k >= 0);
        s[2][1] = '#';
        s[2][n - 2] = '#';
        int j = 2;
        while(k){
            s[2][j] = '#';
            k--;
            j++;
        }
    }
    for(int i = 0; i < 4; i++) cout << s[i] << '\n';
    return 0;
}

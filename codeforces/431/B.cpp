#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> A(5, vector<int>(5));
    vector<int> ord(5);
    iota(ord.begin(), ord.end(), 0);
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            cin >> A[y][x];
        }
    }
    int ans = 0;
    do{
        int sv = 0;
        for(int i = 0; i < 5; i++){
            for(int j = i; j + 1 < 5; j += 2){
                sv += A[ord[j + 1]][ord[j]];
                sv += A[ord[j]][ord[j + 1]];
            }
        }
        ans = max(ans, sv);
    }while(next_permutation(ord.begin(), ord.end()));
    cout << ans << '\n';
}
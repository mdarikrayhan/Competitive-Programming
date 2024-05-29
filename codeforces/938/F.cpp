#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 5e3 + 10;

bool dp[N];

void work(){
    string s;
    cin >> s;

    int n = s.size();
    s = ' ' + s;

    int m = log2(n);
    int len = n - (1 << m) + 1;
    memset(dp, 1, sizeof dp);
    //枚举第i个位置
    for(int i = 1; i <= len; i++){
        char ch = 'z';
        for(int j = 0; j < (1 << m); j++){
            if(dp[j]){
                for(int k = 0; k < m; k++){
                    dp[j | (1 << k)] = 1;
                }
            }
        }

        for(int j = 0; j < (1 << m); j++){
            if(dp[j]) ch = min(ch, s[i + j]);
        }

        for(int j = 0; j < (1 << m); j++){
            dp[j] &= (s[i + j] == ch);
        }

        cout << ch;
    }
    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; //cin >> T;
    while(T--) work();

    return 0;
}
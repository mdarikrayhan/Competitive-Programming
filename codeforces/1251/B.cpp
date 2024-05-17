#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;

void solution() {
    int n; cin >> n;
    vector<int>a(n);
    int ones = 0, zeroes = 0;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = s.length();
        for(char &c: s) {
            if(c == '0') zeroes++;
            else ones++;
        }
        if(s.length() % 2 == 1) {
            ans++;
        }
    }


    sort(a.begin(), a.end()); 
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 1) {
         continue;
        }

        int len = a[i];
        if(zeroes + ones == len && (zeroes % 2 == 1 || ones % 2 == 1)) {
            continue;
        }
        ans++;
        int diff = (abs(ones- zeroes) + 1) / 2;
        if(ones >= zeroes) {
            int x = min(len,diff * 2);
            ones -= x;
            zeroes -= (len - x);
        } else {
            int x = min(len,diff * 2);
            zeroes -= x;
            ones -= (len - x);
        }

    }

    cout << ans << "\n";

}


int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t --){
        solution();
    }
    
    return 0;
}



// LUOGU_RID: 159211696
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_BIT = 30;
int main() {  
    int n;  
    cin >> n;  
    unordered_map<int, int> mp;  
    int a[n];
    for (int i = 0; i < n; i++) {  
        cin >> a[i];  
        mp[a[i]]++;  
    }  
    int ans = 0;  
    for (int i = 0;i < n;i++) {  
        bool found = false;  
        for (int bit = 0;bit <= MAX_BIT;bit++) {  
            int target = (1 << bit) - a[i];
            if (target > 0 && mp.count(target) && (mp[target] > 1 || (mp[target] == 1 && target != a[i]))) {  
                found = true;  
                break;  
            }  
        }  
        if (!found) ans++;  
    }  
    cout << ans ;  
    system("pause");
    return 0;  
}
#include <bits/stdc++.h>
using namespace std;
// #include "debug/debug.h"

int main() {

    // cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;

    while(t--) { 

        int s_h, s_m;
        scanf("%d:%d", &s_h, &s_m);

        int x;
        cin >> x;

        int hh, mm, ans = 0;

        if(s_h%10==s_m/10 && s_h/10==s_m%10) ans++;

        hh = (s_h + (s_m + x)/60) % 24;
        mm = (s_m + x) % 60;

        while(hh!=s_h || mm!=s_m) {

            if(hh%10==mm/10 && hh/10==mm%10) ans++;
            
            hh = (hh + (mm + x)/60) % 24;
            mm = (mm + x) % 60;
        }

        cout << ans << '\n';
    }

    return 0;
}

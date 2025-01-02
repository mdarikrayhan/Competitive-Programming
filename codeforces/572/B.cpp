#include<bits/stdc++.h>
using namespace std;

bool flag1[100000+9] = {false};
bool flag2[100000+9] = {false};

int main() {
    map<int, int> mymapb, mymaps;

    int n, s, k = 0, l = 0, x, a[1000+9], b[1000+9], t, s1, s2;
    char ch;

    cin >> n >> s;
    s1 = s2 = s;

    for(int i = 1; i <= n; i++) {
        cin >> ch;
        if(ch == 'B') {
            cin >> t >> x;
            if(!flag1[t]) {
                a[k] = t;
                k++;
                flag1[t] = true;
            }
            mymapb[t] += x;
        } else {
            cin >> t >> x;
            if(!flag2[t]) {
                b[l] = t;
                l++;
                flag2[t] = true;
            }
            mymaps[t] += x;
        }
    }

    sort(a, a+k);
    sort(b, b+l);

    for(int i = s1-1; i >= 0; i--) {
        if(i < l)
            cout << "S " << b[i] << " " << mymaps[b[i]] << '\n';
    }

    for(int i = k-1; s2 > 0 && i >= 0; s2--, i--) {
        cout << "B " << a[i] << " " << mymapb[a[i]] << '\n';
    }

    return 0;
}

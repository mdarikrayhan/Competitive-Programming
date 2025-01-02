#include <bits/stdc++.h>

using namespace std;

bitset<100001> c[26];
string a;
int n;
bitset<100001> ans;

void query1() {
    int idx; char ch;
    cin >> idx >> ch;
    c[a[idx]-'a'][idx] = 0;
    a[idx] = ch;
    c[a[idx]-'a'][idx] = 1;
}

void query2() {
    int l, r; string x;
    cin >> l >> r >> x;
    if (r - l + 1 < x.size()) {
        cout << "0\n";
        return;
    }
    ans &= 0; ans = ~ans;
    for (int i = 0; i < x.size(); i++) {
        ans &= ((c[x[i]-'a']>>(l))<<(l+100000-r))>>i;
    }
    cout << ans.count() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    n = a.size();
    a = "0" + a;
    for (int i = 1; i <= n; i++) {
        c[a[i]-'a'][i] = 1;
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) query1();
        else query2();
    }
}

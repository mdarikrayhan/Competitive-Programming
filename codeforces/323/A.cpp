#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int ans[N];

void solve()
{
    int k;
    scanf("%d", &k);
    if (k % 2 == 1) {
        printf("-1\n");
        return;
    }
    string s1 = "";
    string s2 = "";
    char c[] = {'b', 'w'};
    for (int i = 0; i < k / 2; i++) s1 = s1 + string(2, c[i % 2]);
    for (int i = 0; i < k / 2; i++) s2 = s2 + string(2, c[(i + 1) % 2]);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j += 2) {
            if (i % 2 == 0) {
                cout << ((j / 2) % 2 == 0 ? s1 : s2) << endl;
                cout << ((j / 2) % 2 == 0 ? s1 : s2) << endl;
            } else {
                cout << ((j / 2) % 2 == 0 ? s2 : s1) << endl;
                cout << ((j / 2) % 2 == 0 ? s2 : s1) << endl;
            }
        }
        printf("\n");
    }
}

int main()
{
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
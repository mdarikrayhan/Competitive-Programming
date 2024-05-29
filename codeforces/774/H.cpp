#include <stdio.h>
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
int a[20000];

int main() {
    int n;
    scanf("%d", &n);

    forn(i, n) scanf("%d", &a[i + 1]);
    char c = 'a';
    for (int k = n; k > 0; k--) {
        int x = a[k];
        forn(j, x) {
            forn(cnt, k) printf("%c", c);
            if (c == 'a') c = 'b'; else c = 'a';
        }
        for (int j = k; j > 0; j--) a[j] -= (k - j + 1) * x;

    }
}
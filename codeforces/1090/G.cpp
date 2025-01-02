#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 250005;
const int Maxb = 60;

int q;
int n;
int ded[Maxn];
int m;
map <int, ll> mask[Maxn];
set <int> inmask[Maxn];
int my[Maxn];
int atk[Maxn], pnt[Maxn];

void getDmg(int ind, int b, int quer)
{
b = pnt[ind] - b;
if (b >= 50000) return;
if (b <= 0) { ded[ind] = quer; inmask[my[ind]].erase(ind); return; }
if (inmask[my[ind]].size() > 1) {
inmask[my[ind]].erase(ind);
m++;
mask[m] = mask[my[ind]];
inmask[m].insert(ind);
my[ind] = m;
}
int mid = my[ind];
map <int, ll>::iterator it = mask[mid].find(b / Maxb);
int lst = b / Maxb;
while (b > 0 && b / Maxb == lst && it != mask[mid].end()) {
while (b > 0 && b / Maxb == lst && (it->second & 1ll << ll(b % Maxb))) {
it->second ^= 1ll << ll(b % Maxb);
b--;
}
if (b <= 0 || b / Maxb == lst) break;
it = mask[mid].find(b / Maxb);
lst = b / Maxb;
}
if (b <= 0) { ded[ind] = quer; mask[mid].clear(); }
else mask[mid][b / Maxb] ^= 1ll << ll(b % Maxb);
}

int main()
{
fill(ded, ded + Maxn, -1);
scanf("%d", &q);
inmask[0].insert(0);
for (int i = 1; i <= q; i++) {
int typ; scanf("%d", &typ);
if (typ == 1) { n++; my[n] = 0; inmask[0].insert(n); }
else if (typ == 2) {
int ind; scanf("%d", &ind);
if (ded[ind] == -1) atk[ind]++;
} else if (typ == 3) {
int ind; scanf("%d", &ind);
if (ded[ind] == -1) pnt[ind]++;
} else if (typ == 4) {
int ind; scanf("%d", &ind);
n++;
if (ded[ind] != -1) ded[n] = i;
else {
pnt[n] = pnt[ind];
atk[n] = atk[ind];
my[n] = my[ind];
inmask[my[n]].insert(n);
}
} else if (typ == 5) {
int a, b; scanf("%d %d", &a, &b);
if (ded[a] == -1 && ded[b] == -1) {
getDmg(a, atk[b], i);
getDmg(b, atk[a], i);
}
}
}
printf("%d\n", n);
for (int i = 1; i <= n; i++)
printf("%d%c", ded[i], i + 1 <= n? ' ': '\n');
return 0;
}

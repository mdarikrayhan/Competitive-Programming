#include <bits/stdc++.h>

using namespace std;

 #define Fi first

#define Se second

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

#define all(x) (x).begin(), (x).end()

#define pb push_back

#define szz(x) (int)(x).size()

#define rep(i, n) for(int i=0;i<(n);i++)

typedef tuple<int, int, int> t3;

 using FL = long double;

typedef pair<FL, FL> pdd;

pdd operator-(pdd a, pdd b) { return {a.Fi - b.Fi, a.Se - b.Se}; }

pdd operator+(pdd a, pdd b) { return {a.Fi + b.Fi, a.Se + b.Se}; }

pdd operator*(pdd a, FL b) { return {a.Fi * b, a.Se * b}; }

pdd operator/(pdd a, FL b) { return {a.Fi / b, a.Se / b}; }

FL operator/(pdd a, pdd b) { return a.Fi * b.Se - a.Se * b.Fi; }

FL operator*(pdd a, pdd b) { return a.Fi * b.Fi + a.Se * b.Se; }

FL length(pdd a) { return sqrt(a * a); }

int LI;

 struct polygon {

 polygon() {}

 polygon(vector <pdd> x, int id = -1) : pt(std::move(x)) {

  if(id == -1) this->id = LI++;

  else this->id = id;

 }

 vector <pdd> pt;

 int id;

 void In() {

  int n; scanf("%d", &n);

  pt.resize(n);

  for(auto &[x, y] : pt) scanf("%Lf%Lf", &x, &y);

  id = LI++;

 }

 vector <polygon> tri() {

  vector <pdd> qt = pt;

  vector <polygon> res;

  while(1) {

   int m = szz(qt);

   if(m == 3) {

    res.emplace_back(qt);

    break;

   }

   rep(i, m) {

    int pi = (i + m - 1) % m;

    int qi = (i + 1) % m;

    if((qt[i] - qt[pi]) / (qt[qi] - qt[i]) < 0) continue;

    int ok = 1;

    rep(j, m) {

     if(j == i || j == pi || j == qi) continue;

     if((qt[i] - qt[pi]) / (qt[j] - qt[pi]) <= 0) continue;

     if((qt[qi] - qt[i]) / (qt[j] - qt[i]) <= 0) continue;

     if((qt[pi] - qt[qi]) / (qt[j] - qt[qi]) <= 0) continue;

     ok = 0;

     break;

    }

    if(ok) {

     vector <pdd> cut = {qt[pi], qt[i], qt[qi]};

     res.emplace_back(cut);

     qt.erase(qt.begin() + i);

     break;

    }

   }

  }

  return res;

 }

 void output() {

  printf("%d ", szz(pt));

  for(auto [x, y] : pt) printf("%.15Lf %.15Lf ", x, y); puts("");

 }

} X[30030];

int L, TL;

 struct str {

 str(vector<int> ids, int dir) : ids(std::move(ids)), dir(dir) {}

 vector <int> ids;

 int dir;

};

 vector <str> ans;

 void make_sq(int FT = 0) {

 X[L++].In();

 int p1 = L;

 auto v = X[p1 - 1].tri();

 for(const auto& e : v) X[L++] = e;

 int p2 = L;

 vector <int> ids;

 auto push_ans = [&](int dir) {

  ans.emplace_back(ids, dir);

  ids.clear();

 };

 for(int i=p1-1;i<p2;i++) ids.pb(i);

 push_ans(0);

 vector <int> rct;

  double sum_area = 0;

 for(int k=p1;k<p2;k++) {

  auto &poly = X[k];

  int f = 0;

  FL dis = length(poly.pt[1] - poly.pt[0]);

  for(int i=1;i<3;i++) {

   int j = (i + 1) % 3;

   FL val = length(poly.pt[i] - poly.pt[j]);

   if(dis < val) dis = val, f = i;

  }

   pdd qt0 = poly.pt[f], qt1 = poly.pt[(f+1)%3], qt2 = poly.pt[(f+2)%3];

  pdd pt1 = (qt0 + qt2) * 0.5;

  pdd pt2 = (qt1 + qt2) * 0.5;

   FL wt = ((qt2 - pt1) * (pt2 - pt1)) / ((pt2 - pt1) * (pt2 - pt1));

  pdd pt3 = pt1 + (pt2 - pt1) * wt;

   vector <pdd> P1 = {qt0, qt1, pt2, pt1};

  vector <pdd> P2 = {pt2, qt2, pt3};

  vector <pdd> P3 = {pt3, qt2, pt1};

   X[L++] = polygon(P1);

  X[L++] = polygon(P2);

  X[L++] = polygon(P3);

   ids = {k, L-3, L-2, L-1};

  push_ans(0);

   pdd pt4 = pt1 * 2 - pt3, pt5 = pt2 * 2 - pt3;

   vector <pdd> P4 = {pt2, qt1, pt5};

  vector <pdd> P5 = {pt4, qt0, pt1};

  vector <pdd> P6 = {qt0, qt1, pt5, pt4};

  sum_area += length(qt1 - qt0) * length(pt5 - qt1);

  X[L] = polygon(P4, X[L-2].id);

  X[L+1] = polygon(P5, X[L-1].id);

  L += 2;

   ids = {L, L-5, L-2, L-1};

  push_ans(1);

   rct.pb(L);

  X[L++] = polygon(P6);

 }

 FL W = sqrt(sum_area) * 1.123;

 FL H = sum_area / W;

  vector <int> rct2;

 for(int e : rct) {

  FL w = length(X[e].pt[1] - X[e].pt[0]);

  FL h = length(X[e].pt[2] - X[e].pt[1]);

  if(w > h) {

   rotate(X[e].pt.begin(), X[e].pt.begin() + 1, X[e].pt.end());

   swap(w, h);

  }

  int p = e;

  while(w < W) {

   pdd qt0 = X[p].pt[0], qt1 = X[p].pt[1], qt2 = X[p].pt[2], qt3 = X[p].pt[3];

   pdd pt1 = (qt0 + qt3) * 0.5, pt2 = (qt1 + qt2) * 0.5;

   vector <pdd> P1 = {qt0, qt1, pt2, pt1};

   vector <pdd> P2 = {pt1, pt2, qt2, qt3};

   X[L++] = polygon(P1);

   X[L++] = polygon(P2);

    ids = {p, L-2, L-1};

   push_ans(0);

    pdd pt3 = qt1 * 2 - qt0, pt4 = pt2 * 2 - pt1;

   vector <pdd> P3 = {qt1, pt3, pt4, pt2};

   vector <pdd> P4 = {qt0, pt3, pt4, pt1};

    X[L] = polygon(P3, X[L-1].id);

   X[L+1] = polygon(P4);

   ids = {L+1, L-2, L};

   push_ans(1);

   L += 2;

    w *= 2;

   h /= 2;

   p = L - 1;

  }

   if(abs(w - W) > 1e-14) {

   FL hp = w * h / W;

   pdd qt0 = X[p].pt[0], qt1 = X[p].pt[1], qt2 = X[p].pt[2], qt3 = X[p].pt[3];

   pdd pt1 = qt0 + (qt1 - qt0) / length(qt1 - qt0) * W;

   pdd pt2 = qt2 + (qt3 - qt2) / length(qt3 - qt2) * W;

   pdd pt3 = qt1 + (pt2 - qt1) * (w - W) / W;

   pdd pt4 = qt0 + (qt3 - qt0) / length(qt3 - qt0) * hp;

   pdd pt5 = pt1 + pt4 - qt0;

    vector <pdd> P1 = {qt0, pt1, pt3, pt2, qt3};

   vector <pdd> P2 = {pt1, qt1, pt3};

   vector <pdd> P3 = {pt2, qt1, qt2};

    vector <pdd> P4 = {qt3, pt2, pt4};

   vector <pdd> P5 = {pt4, pt3, pt5};

   vector <pdd> P6 = {qt0, pt1, pt5, pt4};

    X[L] = polygon(P1);

   X[L+1] = polygon(P2);

   X[L+2] = polygon(P3);

   X[L+3] = polygon(P4, X[L+1].id);

   X[L+4] = polygon(P5, X[L+2].id);

   X[L+5] = polygon(P6);

    ids = {p, L, L+1, L+2};

   push_ans(0);

    ids = {L+5, L, L+3, L+4};

   push_ans(1);

   rct2.pb(L+5);

    L += 6;

  }

  else rct2.pb(p);

 }

 if(FT == 0) {

  FL s = 0;

  for(int e : rct2) {

   FL h = length(X[e].pt[2] - X[e].pt[1]);

   vector <pdd> P = {pdd(0, s), pdd(W, s), pdd(W, s + h), pdd(0, s + h)};

   ids.pb(L);

   X[L++] = polygon(P, X[e].id);

   s += h;

  }

  ids.insert(ids.begin(), L);

  vector <pdd> P = {pdd(0, 0), pdd(W, 0), pdd(W, H), pdd(0, H)};

  X[L++] = polygon(P);

  push_ans(1);

 }

 else {

  vector <str> tans;

  FL s = 0;

  ids.pb(TL);

  int pl = L;

  for(int e : rct2) {

   FL h = length(X[e].pt[2] - X[e].pt[1]);

   vector <pdd> P = {pdd(0, s), pdd(W, s), pdd(W, s + h), pdd(0, s + h)};

   ids.pb(L);

   X[L++] = polygon(P);

   s += h;

  }

  tans.emplace_back(ids, 0); ids.clear();

  for(int e : rct2) {

   ids = {e, L};

   X[L] = X[e]; X[L].id = X[pl++].id;

   ++L;

   tans.emplace_back(ids, 1); ids.clear();

  }

  reverse(all(ans));

  for(auto &e : ans) e.dir ^= 1;

  tans.insert(tans.end(), all(ans));

  ans = tans;

 }

}

 map <int, int> IM;

  int main() {

 make_sq(0);

 int CI = 0;

 auto get_id = [&](int x) {

  int v = X[x].id;

  if(IM.find(v) == IM.end()) IM[v] = CI++;

  return IM[v];

 };

 get_id(0);

 auto output = [&]() {

  for(const auto& e : ans) {

   if(e.dir == 0) {

    puts("scissors");

    printf("%d %d\n", get_id(e.ids[0]), szz(e.ids) - 1);

    for(int i=1;i<szz(e.ids);i++) {

     get_id(e.ids[i]);

     X[e.ids[i]].output();

    }

   }

   else {

    puts("tape");

    printf("%d ", szz(e.ids) - 1);

    for(int i=1;i<szz(e.ids);i++) printf("%d ", get_id(e.ids[i])); puts("");

    for(int i=1;i<szz(e.ids);i++) {

     X[e.ids[i]].output();

    }

    get_id(e.ids[0]);

    X[e.ids[0]].output();

   }

  }

 };

    output();

    TL = L - 1;

    ans.clear();

    make_sq(1);

    output();

    return 0;

}
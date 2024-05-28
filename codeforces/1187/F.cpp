// LUOGU_RID: 159691743
/*
 *  ███████████ ███████████  █████████  ██████████  ████████   ████████
 * ▒█▒▒▒▒▒▒███ ▒▒███▒▒▒▒▒▒█ ███▒▒▒▒▒███▒███▒▒▒▒███ ███▒▒▒▒███ ███▒▒▒▒███
 * ▒     ███▒   ▒███   █ ▒ ▒███    ▒▒▒ ▒▒▒    ███ ▒▒▒    ▒███▒▒▒    ▒███
 *      ███     ▒███████   ▒▒█████████       ███     ██████▒    ███████
 *     ███      ▒███▒▒▒█    ▒▒▒▒▒▒▒▒███     ███     ▒▒▒▒▒▒███  ███▒▒▒▒
 *   ████     █ ▒███  ▒     ███    ▒███    ███     ███   ▒███ ███      █
 *  ███████████ █████      ▒▒█████████    ███     ▒▒████████ ▒██████████
 * ▒▒▒▒▒▒▒▒▒▒▒ ▒▒▒▒▒        ▒▒▒▒▒▒▒▒▒    ▒▒▒       ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒
 */

#include <bits/stdc++.h>

const int pMod = 1e9 + 7;

template<class Tp>
Tp Add(Tp x) { return x; }

template<class Tp, class ...Tps>
int Add(Tp x, Tps ...y) { return (x + Add(y...)) % pMod; }

template<class Tp, class ...Tps>
void AddC(Tp &x, Tps ...y) { x = Add(x, y...); }

template<class Tp>
Tp Mul(Tp x) { return x; }

template<class Tp, class ...Tps>
int Mul(Tp x, Tps ...y) { return int(1LL * x * Mul(y...) % pMod); }

template<class Tp, class ...Tps>
void MulC(Tp &x, Tps ...y) { x = Mul(x, y...); }

int ExGcd(int a, int b, int &x, int &y) {
  if (!b) return x = 1, y = 0, a;
  int d = ExGcd(b, a % b, y, x);
  return y -= a / b * x, d;
}

int Inv(int x) {
  int ret, t, d = ExGcd(x, pMod, ret, t);
  return d * Add(ret, pMod);
}

struct Node { int l, r; };

int main() {
#ifdef LOCAL
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  freopen("task.err", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<Node> a(n + 1);
  for (int i = 1; i <= n; i++) std::cin >> a[i].l;
  for (int i = 1; i <= n; i++) std::cin >> a[i].r;

  int sum1 = 0, sum2 = 0;
  auto Calc = [&](std::vector<Node> s) {
    int l = s[0].l, r = s[0].r;
    for (int i = 1; i < (int) s.size(); i++) {
      l = std::max(l, s[i].l);
      r = std::min(r, s[i].r);
    }
    int its = std::max(0, r - l + 1);
    return its;
  };
  for (int i = 1, lst = 0, res = 0; i <= n; i++) {
    int all = Mul(a[i - 1].r - a[i - 1].l + 1,
                  a[i].r - a[i].l + 1);
    int bad = Calc({a[i - 1], a[i]});
    int pro = Mul(all - bad, Inv(all));
    AddC(sum1, Mul(pro, res));
    AddC(sum2, pro);
    AddC(res, lst), lst = pro;
  }
  for (int i = 1; i < n; i++) {
    int l1 = a[i - 1].r - a[i - 1].l + 1;
    int l2 = a[i + 1].r - a[i + 1].l + 1;
    int all = Mul(l1, l2, a[i].r - a[i].l + 1);
    int bad = Add(Mul(l2, Calc({a[i - 1], a[i]})),
                  Mul(l1, Calc({a[i + 1], a[i]})),
                  -Calc({a[i - 1], a[i + 1], a[i]}));
    int pro = Mul(all - bad, Inv(all));
    AddC(sum1, pro);
  }
  AddC(sum2, Mul(2, sum1));
  std::cout << Add(sum2, pMod) << '\n';

  return 0;
}
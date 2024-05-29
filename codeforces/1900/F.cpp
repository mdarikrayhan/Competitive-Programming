#include <bits/stdc++.h>
// konakarthik12
// cpp20

using namespace std;

template <typename T>
struct NotBool {
  using type = T;
};

template <typename T>
concept HasValueType = requires { typename T::value_type; };

template <typename T>
concept Printable = requires(ostream& os, const T& val) {
  { os << val } -> same_as<ostream&>;
};

template <typename T>
concept Readable = requires(istream& is, T& val) {
  { is >> val } -> same_as<istream&>;
};

template <typename T1>
concept Readable1D = requires(istream& is, const T1&) {
  { Readable<typename remove_reference_t<T1>::value_type> };
};

template <typename T1>
concept Readable2D = requires(istream& is, const T1&) {
  { Readable<typename remove_reference_t<T1>::value_type::value_type> };
};

template <typename C>
struct Con {
  using T = C::value_type;
  using value_type = T;
  C v;

  Con() {
  }
  
  auto begin() {
    return this->v.begin();
  }

  auto end() {
    return this->v.end();
  }

  T& front() {
    return this->v.front();
  }

  T& back() {
    return this->v.back();
  }
  int size() const {
    return this->v.size();
  }

  void reserve(int size) {
    this->v.reserve(size);
  }

  void resize(int size) {
    this->v.resize(size);
  }
  
  void pb(const T& element) {
    this->v.push_back(element);
  }

  template <typename... Args>
  auto& eb(Args&&... args) {
    return this->v.emplace_back(std::forward<Args>(args)...);
  }

  void clear() {
    this->v.clear();
  }

  void iota(int n) {
    this->iota(1, n);
  }
  void iota(T a, T b) {
    this->resize(b - a + 1);
    std::iota(this->v.begin(), this->v.end(), a);
  }

  template <class Compare = std::less<>>
  auto lower_bound(const T& x, Compare comp = {}) {
    return std::lower_bound(v.begin(), v.end(), x, comp);
  }

  template <class Compare = std::less<>>
  auto upper_bound(const T& x, Compare comp = {}) {
    return std::upper_bound(v.begin(), v.end(), x, comp);
  }
};

template <typename T1, typename T2>
struct pr {
  
};

template <typename V>
struct wec : public Con<vector<typename NotBool<V>::type>> {
  using T = NotBool<V>::type;
  using Con<vector<typename NotBool<V>::type>>::Con;

  T& operator[](size_t index) {
    return this->v[index - 1];
  }

};

template <typename T>
using ww = wec<wec<T> >;
using wwi = ww<int>;

using wi = wec<int>;
using wwi = ww<int>;

#define sz(x) (int) size(x)

#define cexp constexpr

#define deb(...) (void) 0;

template <typename T>
  requires Readable<T>
void __read(T& arr) {
  cin >> arr;
}

template <typename T>
void reserve(T& v, size_t s) {
  cexp bool HasReserve = requires {
    { v.reserve(s) };
  };

  if cexp (HasReserve) {
    v.reserve(s);
  }
}

template <typename V>
void append(V& v, const typename V::value_type& x) {
  cexp bool HasPB = requires {
    { v.pb(x) };
  };
  cexp bool HasPushBack = requires {
    { v.push_back(x) };
  };

  if cexp (HasPB) {
    v.pb(x);
  } else if cexp (HasPushBack) {
    v.push_back(x);
  } else {
    v.insert(x);
  }
}
template <typename Container>
  requires HasValueType<Container>
void __read1D(Container& v, const int& n) {
  using T = Container::value_type;
  v.clear();
  reserve(v, n);
  for (int i = 0; i < n; i++) {
    T x;
    __read(x);
    append(v, x);
  }
}

void read() {
}

template <typename T>
void read(T&& arg) {
  __read(std::forward<T>(arg));
}

template <typename T, typename T2, typename... Args>
  requires(Readable1D<T> && !Readable2D<T> && !Readable<T>)
void read(T&& first, T2&& second, Args&&... args) {
  __read1D(std::forward<T>(first), std::forward<T2>(second));
  read(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
  requires(Readable<T> || (!Readable1D<T> && !Readable2D<T>) )
void read(T&& first, Args&&... args) {
  __read(std::forward<T>(first));
  read(std::forward<Args>(args)...);
}

template <typename T>
requires Printable<T>
void __print(T x) {
  cout << x;
}

template <typename Arg, typename... Args>
void print(Arg&& arg, Args&&... args) {
  __print(arg);
  if cexp (sizeof...(args) > 0) {
    __print(' ');
    print(args...);
  }
}

template <typename... Args>
void println(Args&&... args) {
  print(args...);
  print('\n');
}

template <typename Func>
  requires requires(Func func) {
    { invoke_result_t<Func>() } -> same_as<void>;
  }
void call_print(Func func) {
  invoke(func);
}

template <typename Func>
  requires requires(Func func) {
    { invoke_result_t<Func>() };
  }
void handle_solve(Func func) {
  call_print(func);
}

void init_main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
}

// ********************************************** ACTUAL CODE STARTS HERE **********************************************

wi arr;
bool min_stage = true;
bool bad(int i, int j) {
  if (min_stage) return arr[i] > arr[j];
  else return arr[i] < arr[j];
}
template <typename Cont>
wi trim(Cont& cur) {
  wi next;
  int n = sz(cur);
  for (int i = 1; i <= n; i++) {
    if (i > 1 && bad(cur[i], cur[i - 1])) continue;
    if (i < n && bad(cur[i], cur[i + 1])) continue;
    next.pb(cur[i]);
  }
  return next;
}
wwi parts;
using iter = decltype(parts.begin()->begin());
struct Val {
  
};

auto solve() {
  int n, qrs;
  read(n, qrs);
  read(arr, n);
  deb(arr);
  parts.eb().iota(n);
  // for (int i = 1; i <= n; i++) parts.back().eb(i, arr[i]);
  while (sz(parts.back()) > 1) {
    if (min_stage) parts.pb(trim(parts.back()));
    else parts.pb(trim(parts.back()));
    min_stage = !min_stage;
  }
  deb(parts);

  for (int q = 0; q < qrs; q++) {
    int l, r;
    read(l, r);
    deb(l, r);

    wec<pr<Val, Val>> tails;
    min_stage = true;
    int l_val = 0, r_val = 0;
    set<int> rem;
    int special = 0;
    for (wi& part: parts) {
      // iter l_iter, r_iter;
      iter l_iter = part.lower_bound(l);
      while (l_iter != part.end() && rem.contains(*l_iter)) l_iter++;
      // if (l_iter == part.end() || *l_iter > r) break;
      iter r_iter = part.upper_bound(r);
      if (r_iter == part.begin()) break;
      r_iter--;
      while (r_iter != part.begin() && rem.contains(*r_iter)) r_iter--;
      if (l_iter > r_iter) break;
      // assert(r_iter != part.begin());
      deb(*l_iter, *r_iter);
      assert(*l_iter >= l);
      assert(*r_iter <= r);
      if (l_val == *l_iter) l_val = 0;
      if (r_val == *r_iter) r_val = 0;

      deb(part);
      deb(min_stage, l_val, r_val, rem);
      deb(*l_iter, *r_iter);
      if (l_iter == r_iter) {
        if (!rem.contains(*l_iter)) special = *l_iter;
        break;
      }

      assert(l_iter < r_iter);

      if (l_val && bad(l_val, *l_iter)) l_val = 0;
      if (r_val && bad(r_val, *r_iter)) r_val = 0;
      if (bad(*l_iter, *next(l_iter)) || (l_val && bad(*l_iter, l_val))) rem.insert(*l_iter);
      else l_val = *l_iter;
      if (bad(*r_iter, *prev(r_iter)) || (r_val && bad(*r_iter, r_val))) rem.insert(*r_iter);
      else r_val = *r_iter;
      deb();
      min_stage = !min_stage;
    }
    // deb("break");
    // deb(*l_iter, *r_iter);
    wi nums;
    if (l_val) nums.pb(l_val);
    if (special) nums.pb(special);
    if (r_val) nums.pb(r_val);
    deb(nums);
    while (sz(nums) > 1) {
      nums = trim(nums);
      min_stage = !min_stage;
    }
    println(arr[nums.front()]);

    min_stage = !min_stage;
  }
}
// std::function<bool(int, int)> comp;

// min_stage = true;

// for (int j = 1; j <= sz(tails); j++) {
//   deb(min_stage, l_val, r_val);
//   auto [l_tail, r_tail] = tails[j];
//   auto [l_iter, l_edge_replace] = l_tail;
//   auto [r_iter, r_edge_replace] = r_tail;
//   // auto [l_tail_next, r_tail_next] = tails[j + 1];
//   // auto l_iter_next = l_tail_next.it;
//   // auto r_iter_next = r_tail_next.it;
//   if (min_stage) comp = std::less<int>();
//   else comp = std::greater<int>();

//   if (l_val != -1 && bad(l_val, *l_iter)) l_val = -1;
//   if (r_val != -1 && bad(r_val, *r_iter)) r_val = -1;
//   // deb(*l_iter, *l_iter_next, l_edge_replace, l_val);
//   if ((j == sz(tails) || *l_iter != *tails[j + 1].f.it) && l_edge_replace && l_val == -1) l_val = *l_iter;
//   // deb(*r_iter, *r_iter_next, r_edge_replace, r_val);
//   if ((j == sz(tails) || *r_iter != *tails[j + 1].s.it) && r_edge_replace && r_val == -1) r_val = *r_iter;
//   min_stage = !min_stage;
// }
// println()
// deb(min_stage);
// deb(l_val, r_val, tails.back());
// assert(tails.back().f.it == tails.back().s.it);
// wi nums;
// if (l_val != -1) nums.pb(l_val);
// auto [tail_last_l, tail_last_r] = tails.back();
// nums.pb(*tail_last_l.it);
// if (tail_last_l.it != tail_last_r.it) nums.pb(*tail_last_r.it);
// if (r_val != -1 && r_val != l_val) nums.pb(r_val);
// deb(nums);
// while (sz(nums) > 1) {
//   nums = trim(nums);
//   min_stage = !min_stage;
// }
// deb(nums);

// **********************************************  ACTUAL CODE ENDS HERE  **********************************************

int main() {
  init_main();

  handle_solve(solve);

  return 0;
}


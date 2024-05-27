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
  
  T& operator[](size_t index) {
    return this->v[index];
  }

  void reserve(int size) {
    this->v.reserve(size);
  }

  void assign(int size, T x = T()) {
    this->v.assign(size, x);
  }

  void pb(const T& element) {
    this->v.push_back(element);
  }

  void clear() {
    this->v.clear();
  }

  T max() {
    return *std::max_element(v.begin(), v.end());
  }
  
};

template <typename V>
struct vec : public Con<vector<typename NotBool<V>::type>> {
  
  using Con<vector<typename NotBool<V>::type>>::Con;
};

using vi = vec<int>;

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

template <typename T>
int blen(T x) {
  return bit_width(static_cast<make_unsigned_t<decltype(x)>>(x));
}

template <typename T, typename F>
T min_false(T l, T h, F comp) {
  auto iter = ranges::partition_point(views::iota(l, h + 1), comp);
  return *iter;
}

template <typename T, typename F>
T min_true(T l, T h, F comp) {
  return min_false(l, h, not_fn(comp));
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

template <typename Res>
void handle_print(Res& res) {
  println(res);
}

template <typename Func>
  requires requires(Func func) {
    { invoke_result_t<Func>() } -> movable;
  }
void call_print(Func func) {
  auto result = invoke(func);
  handle_print(result);
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

int n;
vi arr;
// vvi mem;
vi has_nonzero;
vi compute(int x) {
  if (x == 0) return arr;
  // vi& cur = mem[x];
  // if (cur) return cur;
  vi cur;
  int half_pow = x == 1 ? 1 : 1 << (blen(x - 1) - 1);
  deb(half_pow);
  int y = x - half_pow;
  deb(x, half_pow, y);
  vi prev = compute(y);
  cur.assign(n);
  for (int i = 0; i < n; i++) {
    cur[i] = prev[i] ^ prev[(i + half_pow) % n];
    has_nonzero[x] |= cur[i];
  }
  // mem[x] = cur;
  return cur;
}

bool check(int x) {
  deb("check", x);
  compute(x);
  return !has_nonzero[x];
}
auto solve() {
  read(n);
  // mem.assign(n + 1);
  has_nonzero.assign(n + 1);
  read(arr, n);

  // mem[0] = arr;
  if (arr.max() == 0) return 0;
  return min_true(1, n, check);
}

// **********************************************  ACTUAL CODE ENDS HERE  **********************************************

int main() {
  init_main();

  handle_solve(solve);

  return 0;
}


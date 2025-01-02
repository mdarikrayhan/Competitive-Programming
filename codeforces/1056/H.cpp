// LUOGU_RID: 158661673
#pragma GCC optimize(3, "unroll-loops", "no-stack-protector")
#define atsum(l, r) accumulate(l, r, 0)
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int inf = 0x3f3f3f3f;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
template <typename T>
inline void chkmin(T &x, T y) {
    x = min(x, y);
}
template <typename T>
inline void chkmax(T &x, T y) {
    x = max(x, y);
}
namespace FastIO {
// ------------------------------
#define IN_HAS_NEG
#define OUT_HAS_NEG
#define CHK_EOF
#define DISABLE_MMAP
// ------------------------------
#if __cplusplus < 201400
#error Please use C++14 or higher.
#endif
#if __cplusplus > 201700
#define INLINE_V inline
#else
#define INLINE_V
#endif
#if (defined(LOCAL) || defined(_WIN32)) && !defined(DISABLE_MMAP)
#define DISABLE_MMAP
#endif
#ifndef DISABLE_MMAP
#include <sys/mman.h>
#endif
#ifdef LOCAL
inline char gc() { return getchar(); }
inline void pc(char c) { putchar(c); }
#else
#ifdef DISABLE_MMAP
INLINE_V constexpr int _READ_SIZE = 1 << 18;
INLINE_V static char _read_buffer[_READ_SIZE], *_read_ptr = nullptr,
                                               *_read_ptr_end = nullptr;
inline char gc() {
    if (__builtin_expect(_read_ptr == _read_ptr_end, false)) {
        _read_ptr = _read_buffer;
        _read_ptr_end =
            _read_buffer + fread(_read_buffer, 1, _READ_SIZE, stdin);
#ifdef CHK_EOF
        if (__builtin_expect(_read_ptr == _read_ptr_end, false)) return EOF;
#endif
    }
    return *_read_ptr++;
}
#else
INLINE_V static const char *_read_ptr =
    (const char *)mmap(nullptr, INT_MAX, 1, 2, 0, 0);
inline char gc() { return *_read_ptr++; }
#endif
INLINE_V constexpr int _WRITE_SIZE = 1 << 18;
INLINE_V static char _write_buffer[_WRITE_SIZE], *_write_ptr = _write_buffer;
inline void pc(char c) {
    *_write_ptr++ = c;
    if (__builtin_expect(_write_buffer + _WRITE_SIZE == _write_ptr, false)) {
        fwrite(_write_buffer, 1, _write_ptr - _write_buffer, stdout);
        _write_ptr = _write_buffer;
    }
}
INLINE_V struct _auto_flush {
    ~_auto_flush() {
        fwrite(_write_buffer, 1, _write_ptr - _write_buffer, stdout);
    }
} _auto_flush;
#endif
#ifdef CHK_EOF
inline bool _isdigit(char c) { return (c & 16) && c != EOF; }
inline bool _isgraph(char c) { return c > 32 && c != EOF; }
#else
inline bool _isdigit(char c) { return c & 16; }
inline bool _isgraph(char c) { return c > 32; }
#endif
template <class T>
INLINE_V constexpr bool _is_integer = numeric_limits<T>::is_integer;
template <class T>
INLINE_V constexpr bool _is_signed = numeric_limits<T>::is_signed;
template <class T>
INLINE_V constexpr bool _is_unsigned = _is_integer<T> && !_is_signed<T>;
template <>
INLINE_V constexpr bool _is_integer<__int128> = true;
template <>
INLINE_V constexpr bool _is_integer<__uint128_t> = true;
template <>
INLINE_V constexpr bool _is_signed<__int128> = true;
template <>
INLINE_V constexpr bool _is_unsigned<__uint128_t> = true;
#undef INLINE_V
inline void read(char &c) {
    do c = gc();
    while (!_isgraph(c));
}
inline void read_cstr(char *s) {
    char c = gc();
    while (!_isgraph(c)) c = gc();
    while (_isgraph(c)) *s++ = c, c = gc();
    *s = 0;
}
inline void read(string &s) {
    char c = gc();
    s.clear();
    while (!_isgraph(c)) c = gc();
    while (_isgraph(c)) s.push_back(c), c = gc();
}
#ifdef IN_HAS_NEG
template <class T, enable_if_t<_is_signed<T>, int> = 0>
inline void read(T &x) {
    char c = gc();
    bool f = true;
    x = 0;
    while (!_isdigit(c)) {
        if (c == 45) f = false;
        c = gc();
    }
    if (f)
        while (_isdigit(c)) x = x * 10 + (c & 15), c = gc();
    else
        while (_isdigit(c)) x = x * 10 - (c & 15), c = gc();
}
template <class T, enable_if_t<_is_unsigned<T>, int> = 0>
#else
template <class T, enable_if_t<_is_integer<T>, int> = 0>
#endif
inline void read(T &x) {
    char c = gc();
    while (!_isdigit(c)) c = gc();
    x = 0;
    while (_isdigit(c)) x = x * 10 + (c & 15), c = gc();
}
inline void write(char c) { pc(c); }
inline void write_cstr(const char *s) {
    while (*s) pc(*s++);
}
inline void write(const string &s) {
    for (char c : s) pc(c);
}
#ifdef OUT_HAS_NEG
template <class T, enable_if_t<_is_signed<T>, int> = 0>
inline void write(T x) {
    char buffer[numeric_limits<T>::digits10 + 1];
    int digits = 0;
    if (x >= 0) do
            buffer[digits++] = (x % 10) | 48, x /= 10;
        while (x);
    else {
        pc(45);
        do buffer[digits++] = -(x % 10) | 48, x /= 10;
        while (x);
    }
    while (digits) pc(buffer[--digits]);
}
template <class T, enable_if_t<_is_unsigned<T>, int> = 0>
#else
template <class T, enable_if_t<_is_integer<T>, int> = 0>
#endif
inline void write(T x) {
    char buffer[numeric_limits<T>::digits10 + 1];
    int digits = 0;
    do buffer[digits++] = (x % 10) | 48, x /= 10;
    while (x);
    while (digits) pc(buffer[--digits]);
}
template <int N>
struct _tuple_io_helper {
    template <class... T>
    static inline void _read(tuple<T...> &x) {
        _tuple_io_helper<N - 1>::_read(x), read(get<N - 1>(x));
    }
    template <class... T>
    static inline void _write(const tuple<T...> &x) {
        _tuple_io_helper<N - 1>::_write(x), pc(32), write(get<N - 1>(x));
    }
};
template <>
struct _tuple_io_helper<1> {
    template <class... T>
    static inline void _read(tuple<T...> &x) {
        read(get<0>(x));
    }
    template <class... T>
    static inline void _write(const tuple<T...> &x) {
        write(get<0>(x));
    }
};
template <class... T>
inline void read(tuple<T...> &x) {
    _tuple_io_helper<sizeof...(T)>::_read(x);
}
template <class... T>
inline void write(const tuple<T...> &x) {
    _tuple_io_helper<sizeof...(T)>::_write(x);
}
template <class T1, class T2>
inline void read(pair<T1, T2> &x) {
    read(x.first), read(x.second);
}
template <class T1, class T2>
inline void write(const pair<T1, T2> &x) {
    write(x.first), pc(32), write(x.second);
}
template <class T1, class... T2>
inline void read(T1 &x, T2 &...y) {
    read(x), read(y...);
}
template <class... T>
inline void read_cstr(char *x, T *...y) {
    read_cstr(x), read_cstr(y...);
}
template <class T1, class... T2>
inline void write(const T1 &x, const T2 &...y) {
    write(x), write(y...);
}
template <class... T>
inline void write_cstr(const char *x, const T *...y) {
    write_cstr(x), write_cstr(y...);
}
template <class T>
inline void print(const T &x) {
    write(x);
}
inline void print_cstr(const char *x) { write_cstr(x); }
template <class T1, class... T2>
inline void print(const T1 &x, const T2 &...y) {
    print(x), pc(32), print(y...);
}
template <class... T>
inline void print_cstr(const char *x, const T *...y) {
    print_cstr(x), pc(32), print_cstr(y...);
}
inline void println() { pc(10); }
inline void println_cstr() { pc(10); }
template <class... T>
inline void println(const T &...x) {
    print(x...), pc(10);
}
template <class... T>
inline void println_cstr(const T *...x) {
    print_cstr(x...), pc(10);
}
}  // namespace FastIO
using namespace FastIO;
template <typename T>
inline void clear(T &x) {
    T y;
    swap(x, y);
}
const int N = 3e5 + 10;
vector<int> vec[N];
int n, m, s;
vector<pair<int, int> > to[N];
int vis[N];
inline void work() {
    read(n, m), s = sqrt(n) / 3;
    for (int i = 1; i <= m; i++) clear(vec[i]);
    for (int i = 1; i <= n; i++) clear(to[i]), vis[i] = 0;
    for (int i = 1; i <= m; i++) {
        int siz;
        read(siz), vec[i].resize(siz);
        for (int &v : vec[i]) read(v);
        if (siz <= s)
            for (int j = 0; j < siz; j++)
                for (int k = 0; k + 1 <= j; k++)
                    to[vec[i][j]].emplace_back(vec[i][k], vec[i][k + 1]);
    }
    for (int i = 1; i <= n; i++) {
        for (auto [u, v] : to[i]) {
            if (vis[u] && vis[u] != v) return println("Human"s);
            vis[u] = v;
        }
        for (auto [u, v] : to[i]) vis[u] = 0;
    }
    memset(vis, -1, sizeof(vis[0]) * (n + 2));
    for (int i = 1; i <= m; i++)
        if (vec[i].size() >= s) {
            for (int j = 0; j < vec[i].size(); j++) vis[vec[i][j]] = j;
            for (int j = 1; j <= m; j++)
                if (j != i && (j < i || vec[j].size() <= s)) {
                    int curr = -1;
                    for (int k = vec[j].size() - 1; ~k; k--)
                        if (~vis[vec[j][k]]) {
                            int posx = vis[vec[j][k]];
                            if (curr < posx)
                                curr = posx;
                            else {
                                if (vec[j][k + 1] != vec[i][posx + 1])
                                return println("Human"s);
                            }
                        }
                }
            for (int j = 0; j < vec[i].size(); j++) vis[vec[i][j]] = -1;
        }
    println("Robot"s);
}
int main() {
    int T;
    read(T);
    while (T--) work();
    return 0;
}
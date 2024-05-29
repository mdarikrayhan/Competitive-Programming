// LUOGU_RID: 159663986
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
inline void chkmin(T &x, T y) { x = min(x, y); }
template <typename T>
inline void chkmax(T &x, T y) { x = max(x, y); }
namespace FastIO
{
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
#if ( defined(LOCAL) || defined (_WIN32) ) && !defined(DISABLE_MMAP)
#define DISABLE_MMAP
#endif
#ifndef DISABLE_MMAP
#include<sys/mman.h>
#endif
#ifdef LOCAL
    inline char gc() { return getchar(); }
    inline void pc(char c) { putchar(c); }
#else
#ifdef DISABLE_MMAP
    INLINE_V constexpr int _READ_SIZE = 1 << 18;
    INLINE_V static char _read_buffer[_READ_SIZE], *_read_ptr = nullptr, *_read_ptr_end = nullptr;
    inline char gc()
    {
        if ( __builtin_expect(_read_ptr == _read_ptr_end, false) )
        {
            _read_ptr = _read_buffer;
            _read_ptr_end = _read_buffer + fread(_read_buffer, 1, _READ_SIZE, stdin);
#ifdef CHK_EOF
            if ( __builtin_expect(_read_ptr == _read_ptr_end, false) ) return EOF;
#endif
        }
        return *_read_ptr++;
    }
#else
    INLINE_V static const char *_read_ptr = (const char *)mmap(nullptr, INT_MAX, 1, 2, 0, 0);
    inline char gc() { return *_read_ptr++; }
#endif
    INLINE_V constexpr int _WRITE_SIZE = 1 << 18;
    INLINE_V static char _write_buffer[_WRITE_SIZE], *_write_ptr = _write_buffer;
    inline void pc(char c)
    {
        *_write_ptr++ = c;
        if ( __builtin_expect(_write_buffer + _WRITE_SIZE == _write_ptr, false) )
        {
            fwrite(_write_buffer, 1, _write_ptr - _write_buffer, stdout);
            _write_ptr = _write_buffer;
        }
    }
    INLINE_V struct _auto_flush
    {
        ~_auto_flush() { fwrite(_write_buffer, 1, _write_ptr - _write_buffer, stdout); }
    }	_auto_flush;
#endif
#ifdef CHK_EOF
    inline bool _isdigit(char c) { return ( c & 16 ) && c != EOF; }
    inline bool _isgraph(char c) { return c > 32 && c != EOF; }
#else
    inline bool _isdigit(char c) { return c & 16; }
    inline bool _isgraph(char c) { return c > 32; }
#endif
    template < class T >
    INLINE_V constexpr bool _is_integer = numeric_limits < T >::is_integer;
    template < class T >
    INLINE_V constexpr bool _is_signed = numeric_limits < T >::is_signed;
    template < class T >
    INLINE_V constexpr bool _is_unsigned = _is_integer < T > && !_is_signed < T >;
    template <> INLINE_V constexpr bool _is_integer < __int128 > = true;
    template <> INLINE_V constexpr bool _is_integer < __uint128_t > = true;
    template <> INLINE_V constexpr bool _is_signed < __int128 > = true;
    template <> INLINE_V constexpr bool _is_unsigned < __uint128_t > = true;
#undef INLINE_V
    inline void read(char &c) { do c = gc(); while ( !_isgraph(c) ); }
    inline void read_cstr(char *s)
    {
        char c = gc(); while ( !_isgraph(c) ) c = gc();
        while ( _isgraph(c) ) *s++ = c, c = gc();
        *s = 0;
    }
    inline void read(string &s)
    {
        char c = gc(); s.clear(); while ( !_isgraph(c) ) c = gc();
        while ( _isgraph(c) ) s.push_back(c), c = gc();
    }
#ifdef IN_HAS_NEG
    template < class T, enable_if_t < _is_signed < T >, int > = 0 >
    inline void read(T &x)
    {
        char c = gc(); bool f = true; x = 0;
        while ( !_isdigit(c) ) { if ( c == 45 ) f = false; c = gc(); }
        if ( f ) while ( _isdigit(c) ) x = x * 10 + ( c & 15 ), c = gc();
        else     while ( _isdigit(c) ) x = x * 10 - ( c & 15 ), c = gc();
    }
    template < class T, enable_if_t < _is_unsigned < T >, int > = 0 >
#else
    template < class T, enable_if_t < _is_integer < T >, int > = 0 >
#endif
    inline void read(T &x)
    {
        char c = gc(); while ( !_isdigit(c) ) c = gc();
        x = 0; while ( _isdigit(c) ) x = x * 10 + ( c & 15 ), c = gc();
    }
    inline void write(char c) { pc(c); }
    inline void write_cstr(const char *s) { while ( *s ) pc(*s++); }
    inline void write(const string &s) { for ( char c : s ) pc(c); }
#ifdef OUT_HAS_NEG
    template < class T, enable_if_t < _is_signed < T >, int > = 0 >
    inline void write(T x)
    {
        char buffer[numeric_limits < T >::digits10 + 1]; int digits = 0;
        if ( x >= 0 )  do buffer[digits++] =  ( x % 10 ) | 48, x /= 10; while ( x );
        else { pc(45); do buffer[digits++] = -( x % 10 ) | 48, x /= 10; while ( x ); }
        while ( digits ) pc(buffer[--digits]);
    }
    template < class T, enable_if_t < _is_unsigned < T >, int > = 0 >
#else
    template < class T, enable_if_t < _is_integer < T >, int > = 0 >
#endif
    inline void write(T x)
    {
        char buffer[numeric_limits < T >::digits10 + 1]; int digits = 0;
        do buffer[digits++] = ( x % 10 ) | 48, x /= 10; while ( x );
        while ( digits ) pc(buffer[--digits]);
    }
    template < int N > struct _tuple_io_helper
    {
        template < class ...T >
        static inline void _read(tuple < T... > &x)
        { _tuple_io_helper < N - 1 >::_read(x), read(get < N - 1 > (x)); }
        template < class ...T >
        static inline void _write(const tuple < T... > &x)
        { _tuple_io_helper < N - 1 >::_write(x), pc(32), write(get < N - 1 > (x)); }
    };
    template <> struct _tuple_io_helper < 1 >
    {
        template < class ...T >
        static inline void _read(tuple < T... > &x) { read(get < 0 > (x)); }
        template < class ...T >
        static inline void _write(const tuple < T... > &x) { write(get < 0 > (x)); }
    };
    template < class ...T >
    inline void read(tuple < T... > &x) { _tuple_io_helper < sizeof...(T) >::_read(x); }
    template < class ...T >
    inline void write(const tuple < T... > &x) { _tuple_io_helper < sizeof...(T) >::_write(x); }
    template < class T1, class T2 >
    inline void read(pair < T1, T2 > &x) { read(x.first), read(x.second); }
    template < class T1, class T2 >
    inline void write(const pair < T1, T2 > &x) { write(x.first), pc(32), write(x.second); }
    template < class T1, class ...T2 >
    inline void read(T1 &x, T2 &...y) { read(x), read(y...); }
    template < class ...T >
    inline void read_cstr(char *x, T *...y) { read_cstr(x), read_cstr(y...); }
    template < class T1, class ...T2 >
    inline void write(const T1 &x, const T2 &...y) { write(x), write(y...); }
    template < class ...T >
    inline void write_cstr(const char *x, const T *...y) { write_cstr(x), write_cstr(y...); }
    template < class T >
    inline void print(const T &x) { write(x); }
    inline void print_cstr(const char *x) { write_cstr(x); }
    template < class T1, class ...T2 >
    inline void print(const T1 &x, const T2 &...y) { print(x), pc(32), print(y...); }
    template < class ...T >
    inline void print_cstr(const char *x, const T *...y) { print_cstr(x), pc(32), print_cstr(y...); }
    inline void println() { pc(10); }
    inline void println_cstr() { pc(10); }
    template < class ...T >
    inline void println(const T &...x) { print(x...), pc(10); }
    template < class ...T >
    inline void println_cstr(const T *...x) { print_cstr(x...), pc(10); }
}
using namespace FastIO;
template <typename T>
inline void clear(T &x) {
    T y;
    swap(x, y);
}
const int N = 3e6 + 10;
int w[N << 2];
void del(int u, int L, int R, int x) {
    --w[u];
    if (L == R) return;
    int M = L + R >> 1;
    if (x <= M) return del(u << 1, L, M, x);
    return del(u << 1 | 1, M + 1, R, x);
}
int kth(int u, int L, int R, int k) {
    if (L == R) return assert(w[u]), L;
    int M = L + R >> 1;
    if (k <= w[u << 1]) return kth(u << 1, L, M, k);
    return kth(u << 1 | 1, M + 1, R, k - w[u << 1]);
}
void build(int u, int L, int R) {
    w[u] = R - L + 1;
    if (L == R) return;
    int M = L + R >> 1;
    build(u << 1, L, M), build(u << 1 | 1, M + 1, R);
}
char str[N], resstr[N];
int n, m;
int l[N], r[N], fa[N];
inline int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
int main() {
    read_cstr(str + 1), read(n, m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) read(l[i], r[i]);
    build(1, 1, n);
    for (int i = m; i; i--) {
        int pl = (l[i] != r[i] ? l[i] + 1 : l[i]);
        for (int j = 1; j <= r[i] - l[i] + 1; j++) {
            if (r[i] >= w[1]) break;
            fa[find(kth(1, 1, n, r[i] + 1))] = find(kth(1, 1, n, pl)), del(1, 1, n, kth(1, 1, n, r[i] + 1));
            pl += 2;
            if (pl > r[i])
                pl = l[i];
        }
    }
    for (int i = 1; i <= n; i++) if (w[1] >= i)resstr[kth(1, 1, n, i)] = str[i];
    for (int i = 1; i <= n; i++)  pc(resstr[find(i)]);
    return 0;
}
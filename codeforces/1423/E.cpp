#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,avx,avx2,fma")

using namespace std;

struct point {
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y) {}
    point operator + (const point &other) const {
        return point(x + other.x, y + other.y);
    }
    point operator - (const point &other) const {
        return point(x - other.x, y - other.y);
    }
    double operator * (const point &other) const {
        return x * other.x + y * other.y;
    }
    double operator ^ (const point &other) const {
        return x * other.y - y * other.x;
    }
    double len2() const {
        return x * x + y * y;
    }
    point norma() const {
        return point(-y, x);
    }
    point mul(double k) const {
        return point(x * k, y * k);
    }
};

struct line {
    point p, v;
    double c, denom;
    line() {}
    line(point aa, point bb): p(aa), v(bb - aa) { 
        denom = v.len2();
        c = p.x * v.y - p.y * v.x;
    }
    double intersection_t(line b) const {
        return ((b.p - p) ^ b.v) / (v ^ b.v);
    }
    double distToSegment2(const point &other) const {
        line l(other, other + v.norma());
        double t0 = intersection_t(l);
        if (t0 >= 0 && t0 <= 1) {
            float d = -other.x * v.y + other.y * v.x + c;
            return d * d / denom;
        }
        return (other - p).len2();
    }
};

bool point_inside(const point &p, const vector<line> &poly) {
    int cnt = 0;
    for (const auto &l : poly) {
        point a = l.p, b = l.p + l.v;
        if (a.y > b.y) {
            swap(a, b);
        }
        if (a.y == b.y) {
            continue;
        }
        if (b.y <= p.y || a.y > p.y) {
            continue;
        }
        cnt += (((b - a) ^ (p - a)) >= 0);
    }
    return cnt % 2;
}

double calcS(const vector<point> &poly) {
    double s = 0;
    for (int i = 0; i < (int) poly.size(); i++) {
        s += poly[i] ^ poly[(i + 1) % poly.size()];
    }
    return 0.5 * s;
}

template <class T = int> inline T readInt();						
inline double readDouble();
inline int readUInt();					 
inline int readChar();					 
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt( T x, int len = -1 );
template <class T> inline void writeUInt( T x, int len = -1 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

/** Read */

static const int buf_size = 4096;

static char buf[buf_size];
static int buf_len = 0, buf_pos = 0;

inline bool isEof() {
	if (buf_pos == buf_len) {
		buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (buf_pos == buf_len)
			return 1;
	}
	return 0;
}

inline int getChar() { 
	return isEof() ? -1 : buf[buf_pos++];
}

inline int peekChar() { 
	return isEof() ? -1 : buf[buf_pos];
}

inline bool seekEof() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		buf_pos++;
	return c == -1;
}

inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}

inline int readUInt() {
	int c = readChar(), x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}

inline void readWord( char *s ) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine( char *s ) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

/** Write */

static int write_buf_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_buf_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
	write_buf[write_buf_pos++] = x;
}

inline void flush() {
	if (write_buf_pos)
		fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
}

template <class T> 
inline void writeInt( T x, int output_len ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
}

template <class T> 
inline void writeUInt( T x, int output_len ) {
	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeUInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}


signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cout.precision(5);
    float width, height;
    int n;
    width = readDouble();
    height = readDouble();
    n = readInt();
    vector<vector<line>> poly(n, vector<line>(40));
    vector<point> poly0(40);
    vector<double> ss(n);
    for (int i = 0; i < n; i++) {
        int v;
        v = readInt();
        poly0.resize(v);
        poly[i].resize(v);
        for (int j = 0; j < v; j++) {
            poly0[j].x = readDouble();
            poly0[j].y = readDouble();
        }
        for (int j = 0; j < v; j++) {
            poly[i][j] = line(poly0[j], poly0[(j + 1) % v]);
        }
        ss[i] = calcS(poly0);
    }
    int q;
    q = readInt();
    vector <int> indices;
    for (int i = 0; i < q; i++) {
        indices.clear();
        double totalS = 0;
        point c;
        double r;
        c.x = readDouble();
        c.y = readDouble();
        r = readDouble();
        double r2 = r * r;
        for (int j = 0; j < n; j++) {
            bool flag = 0;
            if (point_inside(c, poly[j])) {
                indices.push_back(j);
                totalS += ss[j];
//                cout << j << ' ' << "HERE" << ' ' << c.x << ' ' << c.y << endl;
                continue;
            }
            for (const auto &segm : poly[j]) {
                if (segm.distToSegment2(c) <= r2) {
                    indices.push_back(j);
                    totalS += ss[j];
                    break;
                }
            }
        }
        writeDouble(totalS, 7);
        writeChar(' ');
        writeInt(indices.size());
        writeChar(' ');
        for (int elem : indices) {
            writeInt(elem);
            writeChar(' ');
        }
        writeChar('\n');
    }
    flush();
    return 0;
}
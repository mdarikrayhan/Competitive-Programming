#include<bits/stdc++.h>
#define For(i,l,r) for(int i=l,i##_e=r;i<=i##_e;++i)
#define rFor(i,r,l) for(int i=r,i##_e=l;i>=i##_e;--i)
#define y0 y_zero
#define y1 y_one
#define all(a) a.begin(),a.end()
using namespace std;
using u32=unsigned;
using i64=long long;
using ll=long long;
using u64=unsigned long long;
using ull=unsigned long long;
#if __SIZEOF_POINTER__==8
using i128=__int128;
using u128=__uint128_t;
#endif
using pii=array<int,2>;
using pll=array<ll,2>;
#if __cplusplus>=201402L
void cmin(auto &a,auto b){a=min(a,b);}
void cmax(auto &a,auto b){a=max(a,b);}
#endif
#define mtc() int T; cin>>T; while(T--) work();

// #define with_buffer

#if defined(with_buffer) && defined(EOF) && __cplusplus>=201103L

class in_buffer_t {
	static constexpr int len=1<<16;
	char buf[len],*p1=buf; const char *p2=buf;
	FILE *in;
   public:
	in_buffer_t():in(nullptr){}
	in_buffer_t(FILE *in):in(in){}
	char getc() {
		if(p1!=p2 || (p2=buf+fread(p1=buf,1,len,in))!=p1) return *(p1++);
		return EOF;
	}
};
class out_buffer_t {
	static constexpr int len=1<<16;
	char buf[len],*p1=buf; const char *const p2=buf+len;
	FILE *out;
   public:
	out_buffer_t():out(nullptr){}
	out_buffer_t(FILE *out):out(out){}
	void putc(char x) {
		if(p1!=p2) { *(p1++)=x; return; }
		fwrite(p1=buf,len,1,out),*(p1++)=x;
	}
	~out_buffer_t() { fwrite(buf,p1-buf,1,out); }
};
in_buffer_t stdin_buf(stdin);
out_buffer_t stdout_buf(stdout);

#define cin my_cin
#define cout my_cout
class my_istream {
	using istream=my_istream;
	in_buffer_t *const in;
	template<class T> void read_uint(T &x)const{
		char c=0; x=0;
		for(;~c && !isdigit(c);) c=in->getc();
		if(!~c) return;
		for(;isdigit(c);c=in->getc()) x=x*10+(c&15);
	}
	template<class T> void read_sint(T &x)const{
		char m=0,c=0; x=0;
		for(;~c && !isdigit(c);) m|=(c=in->getc())==45;
		if(!~c) return;
		for(;isdigit(c);c=in->getc()) x=x*10+(c&15);
		if(m) x=-x;
	}
   public:
	my_istream():in(nullptr){}
	my_istream(in_buffer_t *const in):in(in){}
#define doit(T,F)\
	friend istream operator>>(const istream in,T &x) {\
		in.F(x); return in;\
	}
	doit(unsigned,read_uint)
	doit(int,read_sint)
	doit(unsigned long,read_uint)
	doit(long,read_sint)
	doit(unsigned long long,read_uint)
	doit(long long,read_sint)
#if __SIZEOF_POINTER__==8
	doit(__uint128_t,read_uint)
	doit(__int128,read_sint)
#endif
#undef doit
	char get()const{return in->getc();}
	friend istream operator>>(const istream in,char &x) {
		for(x=32;isspace(x);x=in.in->getc()); return in;
	}
	friend istream operator>>(const istream in,char *s) {
		char c=32;
		for(;isspace(c);c=in.in->getc());
		for(;~c && !isspace(c);c=in.in->getc()) *(s++)=c; *s=0;
		return in;
	}
	friend istream operator>>(const istream in,string &s) {
		char c=32; s.clear();
		for(;isspace(c);c=in.in->getc());
		for(;~c && !isspace(c);c=in.in->getc()) s.push_back(c);
		return in;
	}
	istream getline(char *s) {
		for(char c=in->getc();~c && c!=10 && c!=13;c=in->getc()) *(s++)=c; *s=0;
		return *this;
	}
	istream getline(string &s) {
		s.clear(); for(char c=in->getc();~c && c!=10 && c!=13;c=in->getc()) s.push_back(c);
		return *this;
	}
};
class my_ostream {
	using ostream=my_ostream;
	out_buffer_t *const out;
	template<class T> void write_uint(const T x)const{
		if(x>9) write_uint(x/10);
		out->putc((x%10)|48);
	}
	template<class T> void write_sint(T x)const{
		if(x<0) out->putc(45),x=-x;
		if(x>9) write_sint(x/10);
		out->putc((x%10)|48);
	}
   public:
	my_ostream():out(nullptr){}
	my_ostream(out_buffer_t *const out):out(out){}
#define doit(T,F)\
	friend ostream operator<<(const ostream out,const T x) {\
		out.F(x); return out;\
	}
	doit(unsigned,write_uint)
	doit(int,write_sint)
	doit(unsigned long,write_uint)
	doit(long,write_sint)
	doit(unsigned long long,write_uint)
	doit(long long,write_sint)
#if __SIZEOF_POINTER__==8
	doit(__uint128_t,write_uint)
	doit(__int128,write_sint)
#endif
#undef doit
	void put(const char c)const{out->putc(c);}
	friend ostream operator<<(const ostream out,const char x) {
		out.out->putc(x); return out;
	}
	friend ostream operator<<(const ostream out,const char *s) {
		for(;*s;) out.out->putc(*(s++)); return out;
	}
	friend ostream operator<<(const ostream out,const string s) {
		for(auto x:s) out.out->putc(x); return out;
	}
};
my_istream cin(&stdin_buf);
my_ostream cout(&stdout_buf);
#define endl '\n'
#endif
#if !defined(LOCAL) && __cplusplus>=201402L
struct empty_cerr_t {
	empty_cerr_t& operator<<(auto x) {
		return *this;
	}
}empty_cerr;
#define cerr empty_cerr
#endif
#define vect basic_string
const int N=1e3+10;
int n,m;
int a[N][N],d[N];
vect<int> b;
vector<array<int,3>> ans;
int c[N],vis[1<<20];
vect<int> vec;
void work() {
	int sum=0;
	For(i,0,m-1) {
		cout<<"? 1 "<<b[i]<<endl; string s; cin>>s;
		if(s=="Lose") {
			cout<<"! "<<b[i]<<endl; return;
		} else {
			sum|=(s=="Win")<<i;
		}
	}
	cout<<"! "<<vis[sum]<<endl;
}
int main() {
// #ifdef LOCAL
// 	freopen(".in","r",stdin);
// 	// freopen(".out","w",stdout);
// 	// freopen(".debug","w",stderr);
// #endif
#ifndef with_buffer
	ios::sync_with_stdio(0); cin.tie(0);
#endif
	int T;
	cin>>n>>m>>T;
	For(i,1,m) {
		int u,v; cin>>u>>v;
		a[u][v]=1; ++d[u];
	}
	m=min(n,20);
	For(i,1,m) {
		int p=min_element(d+1,d+n+1)-d; b+=p; d[p]=1e9;
	}
	for(auto u:b) For(v,1,n) if(a[u][v] && d[v]<n) ans.push_back({-1,u,v});
	For(i,0,m-1) For(j,0,m-1) {
		int dt=(i<j)-a[b[i]][b[j]];
		if(dt) ans.push_back({dt,b[i],b[j]});
	}
	For(i,0,m) {
		For(j,0,(1<<m)-1) if(__builtin_popcount(j)==i) {
			vec+=j; if(vec.size()==n-m+1) break;
		}
		if(vec.size()==n-m+1) break;
	}
	For(i,1,n) if(d[i]<n) {
		int x=0;
		For(j,0,m-1) x|=(a[i][b[j]])<<j;
		ans.push_back({1,i,i});
		for(auto y:vec) if(!vis[x^y]) {
			x^=y; vis[x]=i;
			For(j,0,m-1) {
				int dt=(x>>j&1)-a[i][b[j]];
				if(dt) ans.push_back({dt,i,b[j]});
			}
			break;
		}
	}
	cout<<ans.size()<<"\n";
	for(auto [tmp,u,v]:ans) {
		if(tmp>0) cout<<"+ "<<u<<" "<<v<<"\n";
		else cout<<"- "<<u<<" "<<v<<"\n";
	} cout<<flush;
	while(T--) {
		work();
		string str; cin>>str;
	}
}
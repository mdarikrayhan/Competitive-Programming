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
void cmin(auto &a,auto b){if(a>b)a=b;}
void cmax(auto &a,auto b){if(a<b)a=b;}
#endif
#define mtc() int T; cin>>T; while(T--) work();
#define vect basic_string

#define with_buffer

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
template<class F,class C> struct MCMF_t {
	static constexpr int N=7e4+10;
	static constexpr F FL=numeric_limits<F>::max();
	static constexpr C Z=numeric_limits<C>::max();
	struct edge {
		int v,n; F w; C c;
	}e[N]; int n,hd[N],tot=1,s,t;
	void _add(int u,int v,F w,C c) { e[++tot]={v,hd[u],w,c}; hd[u]=tot; }
	void add(int u,int v,F w,C c) { _add(u,v,w,c); _add(v,u,0,-c); }
	void clear() { For(i,1,n) hd[i]=0; tot=1; }
	void init(int _n) { n=_n; clear(); }
	C h[N],d[N]; int p[N];
	void spfa() {
		static bool vis[N];
		For(i,1,n) h[i]=Z;
		queue<int> q; q.push(s); h[s]=0; vis[s]=1;
		while(q.size()) {
			int u=q.front(),v; q.pop(); vis[u]=0;
			for(int i=hd[u];i;i=e[i].n) if(e[i].w && h[u]+e[i].c<h[v=e[i].v]) {
				h[v]=h[u]+e[i].c;
				if(!vis[v]) q.push(v),vis[v]=1;
			}
		}
	}
	bool dij() {
		For(i,1,n) d[i]=Z;
		priority_queue<pair<C,int>> q; q.emplace(d[s]=0,s);
		while(q.size()) {
			auto [tmp,u]=q.top(); q.pop();
			if(-tmp!=d[u]) continue;
			for(int i=hd[u];i;i=e[i].n) if(e[i].w) {
				int v=e[i].v; auto w=d[u]+h[u]-h[v]+e[i].c;
				if(w<d[v]) d[v]=w,p[v]=i,q.emplace(-w,v);
			}
		}
		For(i,1,n) if(d[i]!=Z) h[i]=d[i]+=h[i];
		return d[t]!=Z;
	}
	pair<F,C> solve(int _s,int _t,int _n=-1) {
		s=_s; t=_t; if(_n) n=~_n?_n:t;
		int fl=0; For(i,2,tot) fl|=e[i].w && e[i].c<0;
		if(fl) spfa(); else For(i,1,n) h[i]=0;
		F a1=0; C a2=0; while(dij()) {
			F m=FL; for(int u=t;u!=s;u=e[p[u]^1].v) cmin(m,e[p[u]].w);
			a1+=m; a2+=m*d[t];
			for(int u=t;u!=s;u=e[p[u]^1].v) e[p[u]].w-=m,e[p[u]^1].w+=m;
		}
		return {a1,a2};
	}
};
const int N=4.4e3+10,Z=1e9;
struct nd {
	int id; ll a,b;
	ll calc(ll x){return a*x+b;}
};
int n;
nd a[N];
bool chk(ll t) {
	vector<pair<ll,int>> b;
	ll m=0;
	For(i,1,n) {
		cmax(m,a[i].calc(t));
		if(a[i].id<=n/2) b.emplace_back(m,1);
		else b.emplace_back(a[i].calc(t),-1);
	}
	sort(all(b),greater<>());
	int s=0,fl=1;
	for(auto [x,y]:b) {
		s+=y; fl&=s>=0;
	}
	return fl;
}
MCMF_t<int,int> f;
int main() {
#ifdef LOCAL
	freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// freopen(".debug","w",stderr);
#endif
#ifndef with_buffer
	ios::sync_with_stdio(0); cin.tie(0);
#endif
	cin>>n; n<<=1;
	For(i,1,n) {
		a[i].id=i; cin>>a[i].a>>a[i].b;
	}
	sort(a+1,a+n+1,[](nd x,nd y){return x.b<y.b || (x.b==y.b && x.a>y.a);});
	int l=-1,r=1e9+1;
	while(l+1<r) {
		int m=l+r>>1;
		if(chk(m)) r=m;
		else l=m;
	}
	if(r>1e9) return cout<<-1<<endl,0;
	cout<<r<<" ";
	For(i,1,n/2) f.add(2*n+1,i,1,0);
	For(i,n/2+1,n) f.add(i+n,2*n+2,1,0);
	For(i,2,n) {
		f.add(a[i].id,a[i-1].id,Z,0);
		if(a[i].b==a[i-1].b) f.add(a[i-1].id,a[i].id,Z,0);
	}
	sort(a+1,a+n+1,[&](nd x,nd y){return x.calc(r)<y.calc(r);});
	For(i,1,n) {
		f.add(i,i+n,1,-1); f.add(i,i+n,Z,0);
	}
	For(i,2,n) {
		f.add(a[i].id+n,a[i-1].id+n,Z,0);
		if(a[i].calc(r)==a[i-1].calc(r)) f.add(a[i-1].id+n,a[i].id+n,Z,0);
	}
	cout<<n+f.solve(2*n+1,2*n+2).second;
}
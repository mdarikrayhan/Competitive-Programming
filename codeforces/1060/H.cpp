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
#define vect basic_string
const int p0=21,p1=22,_ac=23,_mc=24,_sp=25;
int d,p;
ll ksm(ll a,int b=p-2,ll s=1) {
	for(;b;b>>=1,a=a*a%p) if(b&1) s=s*a%p; return s;
}
vector<tuple<char,int,int,int>> _ans;
// z=x+y
void add1(int x,int y,int z) {
	// assert(x>=1 && x<=5000 && y>=1 && y<=5000 && z>=1 && z<=5000);
	_ans.emplace_back('+',x,y,z);
}
// y=x^d
void powd(int x,int y) {
	// assert(x>=1 && x<=5000 && y>=1 && y<=5000);
	_ans.emplace_back('^',x,y,0);
}
#ifdef LOCAL
mt19937_64 rng(114514);
#define rand _rnd
inline ull _rnd(){return rng();}
inline ll _rnd(const ll l,const ll r){return rand()%(r-l+1)+l;}
#endif
void pr(int res) {
#ifdef LOCAL
	For(T,1,1000) {
		static ll f[5010];
		ll x=rand(0,p-1),y=rand(0,p-1);
		// ll x=2,y=0;
		For(i,1,100) f[i]=1; f[1]=x; f[2]=y;
		for(auto [a,b,c,d]:_ans) {
			if(a=='+') f[d]=(f[b]+f[c])%p;
			else f[c]=ksm(f[b],::d);
			// cerr<<a<<" "<<b<<" "<<c<<" "; if(d) cerr<<d; cerr<<endl<<endl;
			// For(i,1,25) cerr<<f[i]<<" ",(i%10==0 && (cerr<<" ",0)); cerr<<endl<<endl;
		}
		if(x*y%p!=f[res]) {
			// cerr<<x<<" "<<y<<"\nFailed :("<<endl;
			// For(i,1,100) if(f[i]!=1) {
			// 	cerr<<i<<" "<<f[i]<<endl;
			// }
			exit(0);
		}
	}
#endif
	for(auto [a,b,c,d]:_ans) {
		cout<<a<<" "<<b<<" "<<c; if(d) cout<<" "<<d;
		cout<<endl;
	}
	cout<<"f "<<res<<endl;
#ifdef LOCAL
	cout<<_ans.size()<<endl;
#endif
}
// y+=x
void addp(int x,int y) {
	add1(x,y,y);
}
// y+=m
void addc(ll m,int y) {
	m%=p; if(!m) return;
	powd(p1,_ac);
	for(;m;m>>=1,addp(_ac,_ac)) if(m&1) addp(_ac,y);
}
// x=y
void ass(int x,int y) {
	add1(y,p0,x);
}
// y+=x*m
void mulc(int x,ll m,int y) {
	m%=p; if(!m) return;
	ass(_mc,x);
	for(;m;m>>=1,addp(_mc,_mc)) if(m&1) addp(_mc,y);
}
ll C[30][30],a[30][30],b[30][30];
void gause(int n) {
	// For(i,0,n) For(j,0,n) cerr<<a[i][j]<<" \n"[j==j_e]; cerr<<endl;
	// For(i,0,n) For(j,0,n) cerr<<b[i][j]<<" \n"[j==j_e]; cerr<<endl;
	For(i,0,n) {
		int k=-1;
		For(j,i,n) if(a[j][i]) { k=j; break; }
		For(j,i,n) swap(a[i][j],a[k][j]);
		For(j,0,n) swap(b[i][j],b[k][j]);
		ll w=ksm(a[i][i]);
		For(j,i,n) a[i][j]=a[i][j]*w%p;
		For(j,0,n) b[i][j]=b[i][j]*w%p;
		For(j,0,n) if(i!=j && a[j][i]) {
			w=a[j][i];
			For(k,i,n) a[j][k]=(a[j][k]-a[i][k]*w%p+p)%p;
			For(k,0,n) b[j][k]=(b[j][k]-b[i][k]*w%p+p)%p;
		}
	}
	// For(i,0,n) For(j,0,n) cerr<<a[i][j]<<" \n"[j==j_e]; cerr<<endl;
	// For(i,0,n) For(j,0,n) cerr<<b[i][j]<<" \n"[j==j_e]; cerr<<endl;
}
void solve(int x,int tar) {
	For(i,0,d) For(j,C[i][0]=1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	For(i,0,d) For(j,0,d) a[i][j]=b[i][j]=0;
	For(i,0,d) b[i][i]=1;
	For(i,0,d) {
		ass(_sp,x); addc(i,_sp);
		powd(_sp,10+i);
		For(j,0,d) {
			a[i][j]=C[d][j]*ksm(i,d-j)%p;
		}
	}
	gause(d); ass(tar,p0);
	For(i,0,d) mulc(10+i,b[2][i],tar);
}
int main() {
#ifdef LOCAL
	freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// freopen(".debug","w",stderr);
#endif
#ifndef with_buffer
	ios::sync_with_stdio(0); cin.tie(0);
#endif
	cin>>d>>p;
	addc(p-1,p0);
	ass(3,p0); ass(4,p0);
	add1(1,2,3); mulc(3,p-ksm(2),3);
	addp(3,4); mulc(2,p-1,4);
	solve(3,5); solve(4,6);
	ass(7,p0);
	addp(5,7); mulc(6,p-1,7);
	pr(7);
}
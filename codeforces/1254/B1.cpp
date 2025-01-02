// Problem: B1. Send Boxes to Alice (Easy Version)
// Contest: Codeforces - Codeforces Round 601 (Div. 1)
// URL: https://codeforces.com/contest/1254/problem/B1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,inline,unroll-loops")
#ifdef GTRAKIOI
#define _GLIBCXX_DEBUG //交题前记得注释掉不然容易T。
#endif
#include<bits/stdc++.h>
// #include<stdio.h>
#define File(s) freopen(#s".in","r",stdin),freopen(#s".out","w",stdout)
#ifdef GTRAKIOI
#define defrog(...) fprintf(stderr,__VA_ARGS__)
#define deb(x) (std::cerr<<#x<<"@"<<__LINE__<<"="<<(x)<<'\n')
#else
#define defrog(...) 1
#define deb(x) 1
#endif
#define defrogf(...) defrog(__VA_ARGS__)
#define Tp template<typename T>
#define Tl template<typename T
#define Tr >
#define IS(cond) ,std::enable_if_t<(cond), int> = 0
#if __cplusplus>=201703L
#define register
#endif
#define rg register

#ifdef _MSC_VER
#if __has_include(<__msvc_int128.hpp>)
#include <__msvc_int128.hpp> // https://stackoverflow.com/a/76440171
#define __int128 std::_Signed128
#define __int128_t std::_Signed128
#define __uint128_t std::_Unsigned128
#define __SIZEOF_INT128__ 16
#endif
#endif
using ll=long long;
using ull=unsigned long long;
#ifdef __SIZEOF_INT128__
using lll=__int128;
// using ulll=unsigned __int128;
#endif
using db=double;
using ld=long double;
#define INT_ALIAS(w) using i##w=std::int##w##_t;using u##w=std::uint##w##_t;
INT_ALIAS(8) INT_ALIAS(16) INT_ALIAS(32) INT_ALIAS(64)
#ifdef __SIZEOF_INT128__
using i128=__int128_t;
using u128=__uint128_t;
using i7=__int128_t;
using u7=__uint128_t;
template <class T>
using to_unsigned = typename std::conditional<
    std::is_same<T, __int128_t>::value ||
        std::is_same<T, __int128>::value,
    std::common_type<__uint128_t>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;
#else
template <class T>
using to_unsigned = std::make_unsigned<T>;
#endif
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

using pii=std::pair<int,int>;
using vi=std::vector<int>;
using vll=std::vector<ll>;
using vpii=std::vector<pii>;
using vvi=std::vector<vi>;
template<typename T>using pq=std::priority_queue<T>;
template<typename T>using pqg=std::priority_queue<T,std::vector<T>,std::greater<>>;
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define all(cont) std::begin(cont),std::end(cont)

char ibuf[1<<15],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<15,stdin),p1==p2)?EOF:*p1++)
struct FastIO{
	Tl IS(!std::numeric_limits<T>::is_signed) Tr inline void oint(T x){
		T y=1;
		while(y<=x/10)y*=10;
		do putchar(int(x/y)|48),x%=y,y/=10;while(y);
	}
	Tl IS(std::numeric_limits<T>::is_signed) Tr inline void oint(const T&x){
		if(x<0){
			putchar('-');
			oint<to_unsigned_t<T>>(-x);
		}else oint<to_unsigned_t<T>>(x);
	}
	Tl=int IS(std::numeric_limits<T>::is_integer) Tr inline T rint(){rg char c,f=0;while((c=getchar())<48||c>57)f|=c=='-';to_unsigned_t<T> a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
	// inline ll rll(){rg char c,f=0;while((c=getchar())<48||c>57)f|=c=='-';rg ull a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
//	inline operator int(){return rint();}
	// inline operator ll(){return rll();}
	Tl IS(std::numeric_limits<T>::is_integer) Tr inline operator T(){return rint<T>();}
	inline char rchar(){rg char c;while(!isgraph(c=getchar()));return c;}
	inline int rstr(char*s){rg char c;while(!isgraph(c=getchar()));int cnt=-1;do s[++cnt]=c;while(isgraph(c=getchar()));s[++cnt]=0;return cnt;}
	inline std::string rs(){rg char c;while(!isgraph(c=getchar()));std::string s;do s+=c;while(isgraph(c=getchar()));return s;}
	Tl IS(std::numeric_limits<T>::is_integer) Tr inline void print(const T&x){oint(x);}
	inline void print(const char&x){putchar(x);}
	inline void print(const char*const&x){for(int i=0;x[i];++i)putchar(x[i]);}
	#if __cplusplus >= 202002L
	Tp requires std::ranges::range<T> inline void print(const T&c){
		bool first=true;
		for(const auto&x:c){
			if(!first)putchar(' ');
			first=false;
			print(x);
		}
	}
	#endif
	inline void print(const std::string&x){for(int i=0;x[i];++i)putchar(x[i]);}

	// print with separators
	// inline void prints(){putchar('\n');}
	// inline void prints(const auto&x,const auto&...rst){print(x),putchar(' '),prints(rst...);}
	inline void prints(const auto&...x){((print(x),putchar(' ')),...);putchar('\n');}
}g90;
inline void YON(const bool&x){puts(x?"YES":"NO");}
inline void Yon(const bool&x){puts(x?"Yes":"No");}
inline void yon(const bool&x){puts(x?"yes":"no");}

template<typename T=int>std::vector<T>rvec(std::size_t n,std::size_t start=0) {
	std::vector<T>res(start+n);
	for(std::size_t i=start;i<start+n;++i)res[i]=g90;
	return res;
}

std::mt19937 rng(u32(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
Tl IS(std::is_floating_point<T>::value) Tr inline T rnd(const T&a,const T&b){
	return std::uniform_real_distribution<T>(a,b)(rng);
}
Tl IS(std::numeric_limits<T>::is_integer) Tr inline T rnd(const T&a,const T&b){
	return std::uniform_int_distribution<T>(a,b)(rng);
}
namespace MY_STD{
	Tp inline T abs(const T&a){return a<0?-a:a;}
}
#if __cplusplus >= 202002L
namespace all{
	using namespace std::ranges;
	using namespace std::views;
	
	//ambiguous ones
	using std::views::iota;
	using std::views::empty;
	using std::views::reverse;
	inline constexpr auto&R=std::views::reverse;
}
#endif
struct DSU{//unweighted
	using key_type=int;

	std::vector<key_type>fa,size;
	inline DSU(key_type n):fa(n),size(n,1){std::iota(fa.begin(),fa.end(),0);}
	inline key_type& getFa(key_type x){
		while(x^fa[x])x=fa[x]=fa[fa[x]];
		return fa[x];
	}
	inline key_type& operator[](const key_type&x){return getFa(x);}
	inline auto canMerge(const key_type&u,const key_type&v){return getFa(u)!=getFa(v);}
	inline bool merge(key_type u,key_type v){
		u=getFa(u),v=getFa(v);
		return (u)!=(v)&&(size[u]<size[v]&&(std::swap(u,v),1),fa[v]=u,size[u]+=size[v],size[v]=0,true);
	}

};

template<typename Compare=std::less<>>inline bool ckmax(auto& a,const auto& b,const Compare&comp={}){return comp(a,b)?(a=b,true):false;}
template<typename Compare=std::less<>>inline bool ckmin(auto& a,const auto& b,const Compare&comp={}){return comp(b,a)?(a=b,true):false;}

inline auto divf(const auto&a,const auto&b){//assume b>0
	return a<0?(a+1)/b-1:a/b;
}
inline auto divc(const auto&a,const auto&b){//assume b>0
	return a>0?(a-1)/b+1:a/b;
}


constexpr int N=-2024,M=1000000007;
inline int qpow(ll a,auto b){int res=1;for(;b;a=a*a%M,b>>=1)if(b&1)res=res*a%M;return res;}
// #define pow qpow

signed main(){
	//std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
	int n=g90;
	vi pos;
	for(int i=0;i<n;++i){
		int x=g90;
		if(x)pos.eb(i);
	}
	if(pos.size()==1){
		puts("-1");
		return 0;
	}
	ll ans=1e18;
	for(int d=2;d<=n;++d)if(!(pos.size()%d)){
		ll sum=0;
		for(int i=0;i<pos.size();++i){
			int c=(i/d*d)+d/2;
			// deb(c);
			sum+=std::abs(pos[c]-pos[i]);
		}
		ckmin(ans,sum);
	}
	printf("%lld\n",ans);
}//main()
// LUOGU_RID: 154965944
/**************************************************
 * Fast Algorithm Template by Richard1211.
 * Please submit with C++14 or higher version.
 * Blog on Luogu: https://www.luogu.com.cn/blog/522539/
 * Blog on Byethost: http://Richard1211.byethost5.com/
 * Blog on RBTree's: https://Richard1211.rbtr.ee/
***************************************************/
//#pragma GCC optimize(3,"Ofast","inline")
//#pragma GCC target("avx2")
//open Ofast sometimes
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
//#include <bits/extc++.h>
#else
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#endif
//#ifdef __linux__
//#include<sys/mman.h>
//#include<sys/types.h>
//#include<fcntl.h>
//#include<unistd.h>
//#else
//#endif
using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
#define Alice printf("Alice\n")
#define Bob printf("Bob\n")
#define PFir printf("First\n")
#define Pfir printf("first\n")
#define PSec printf("Second\n")
#define Psec printf("second\n")
#define RYES return YES,0
#define RYes return Yes,0
#define Ryes return yes,0
#define RNO return NO,0
#define RNo return No,0
#define Rno return no,0
#define RAlice return Alice,0
#define RBob return Bob,0
#define RFir return PFir,0
#define Rfir return Pfir,0
#define RSec return PSec,0
#define Rsec return Psec,0
#define Inline __inline__ __attribute__ ((always_inline))
#define Test() \
long long TestCount=read();\
for(register int TestCase=1;TestCase<=TestCount;++TestCase)
#define Tesf() for(register int TestCase=1;TestCase<=t;++TestCase)
#ifdef ONLINE_JUDGE
//when on OJ,close the debug version
//hope code with no bugs.
//think twice,code once.
//timer won't print anything
//don't be TLE or MLE,only AC.
#undef Debug
#undef Setmemory
#define Debug(...) 42
#define Setmemory(tmp) 0
#else
//open debug version.
//hope code with no bugs.
//because of using c++17, we need to undefine register.
//Debug will print out the things we need.
//Setmemory will set the end memory we need.
#define register
#define Debug(...) cerr << "Debug " << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define Setmemory(Tmp) (Timebot::timer.End=&Tmp,0)
template<typename A,typename B>string to_string(pair<A,B>p);
template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p);
template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p);
string to_string(const string&s){return'"'+s+'"';}
string to_string(const char*s){return to_string((string)s);}
string to_string(bool b){return(b?"true":"false");}
string to_string(vector<bool>v){bool first=true;string res="{";for(int i=0;i<static_cast<int>(v.size());i++){if(!first){res+=", ";}first=false;res+=to_string(v[i]);}res+="}";return res;}
template<size_t N>string to_string(bitset<N>v){string res="";for(size_t i=0;i<N;i++){res+=static_cast<char>('0'+v[i]);}return res;}
template<typename A>string to_string(A v){bool first=true;string res="{";for(const auto&x:v){if(!first){res+=", ";}first=false;res+=to_string(x);}res+="}";return res;}
template<typename A,typename B>string to_string(pair<A,B>p){return"("+to_string(p.first)+", "+to_string(p.second)+")";}
template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+")";}
template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+", "+to_string(get<3>(p))+")";}
inline void debug_out(){cerr<<endl;}
template<typename Head,typename...Tail>void debug_out(Head H,Tail...T){cerr<<" "<<to_string(H);debug_out(T...);}
namespace Timebot{
	//timer will print the time and the memory of the code for you.
	//don't be TLE or MLE,only AC.
	struct Timer{
		bool f,*Beg,*End;
	    clock_t Begin;
	     Timer():Begin(clock()),Beg(&f){}
	    ~Timer(){double t=(clock()-Begin)*1000./CLOCKS_PER_SEC;t>=60000?fprintf(stderr,"Time: %.2lf min\n",t/60000.):t>=1000?fprintf(stderr,"Time: %.2lf s\n",t/1000.):fprintf(stderr,"Time: %.0lf ms\n",t);fprintf(stderr,"Memory: %.3lf MB\n",(End-Beg)/1048576.0);}
	}timer;
}
#endif
constexpr double pi=3.1415926535897932384626433832795;
constexpr double ei=2.7182818284590452353602874713527;
template<class T>Inline T Min(register T a,register T b){return a<b?a:b;}
template<class T>Inline T Max(register T a,register T b){return a>b?a:b;}
template<class T>inline T Min(initializer_list<T>a){register T x=numeric_limits<T>::max();for(auto &it:a){x=Min(x,it);}return x;}
template<class T>inline T Max(initializer_list<T>a){register T x=numeric_limits<T>::min();for(auto &it:a){x=Max(x,it);}return x;}
template<class T>Inline bool Cmin(register T&a,register T b){return a>b?(a=b,true):false;}
template<class T>Inline bool Cmax(register T&a,register T b){return a<b?(a=b,true):false;}
template<class T>inline bool Cmin(register T&a,initializer_list<T>b){register long long x=a;for(auto &it:b){a=Min(a,it);}return x==a?false:true;}
template<class T>inline bool Cmax(register T&a,initializer_list<T>b){register long long x=a;for(auto &it:b){a=Max(a,it);}return x==a?false:true;}
template<class T>Inline T Abs(register T a){return a>0?a:-a;}
template<class T>Inline T Lowbit(register T x){return(x)&(-x);}
template<class T>Inline void Swap(register T&a,register T&b){b^=a^=b^=a;}
template<class T>inline T Gcd(T a,T b){return b?Gcd(b,a%b):a;}
template<class T>inline T Lcm(T a,T b){return a*b/Gcd(a,b);}
template<class T>inline T Exgcd(T a,T b,T&x,T&y){if(b==0){x=1;y=0;return a;}T d=Exgcd(b,a%b,x,y);T t=x;x=y;y=t-a/b*y;return d;}
template<class T>inline T ExExgcd(T a,T b,T&x,T&y,T c){if(b==0){x=c;y=0;return a;}T d=ExExgcd(b,a%b,x,y,c);T t=x;x=y;y=t-a/b*y;return d;}
template<class T>inline T Ksc(T a,T b){if(a==0||b==0){return 0;}T ans=0;while(b){if(b&1){ans=a+ans;}a=a+a;b>>=1;}return ans;}
template<class T>inline T Ksc(T a,T b,T p){if(a==0||b==0){return 0;}T ans=0;while(b){if(b&1){ans=(a+ans)%p;}a=(a+a)%p;b>>=1;}return ans;}
template<class T>inline T Ksm(T a,T b,bool f=false){if(a==0){return 0;}if(b==0){return 1;}T ans=1;while(b){if(b&1){ans=!f?a*ans:Ksc(a,ans);}a=!f?a*a:Ksc(a,a);b>>=1;}return ans;}
template<class T>inline T Ksm(T a,T b,T p,bool f=false){if(a==0){return 0;}if(b==0){return 1%p;}T ans=1;while(b){if(b&1){ans=!f?a*ans%p:Ksc(a,ans,p);}a=!f?a*a%p:Ksc(a,a,p);b>>=1;}return ans;}
template<class T>inline T Inv(T x,T p){return Ksm(x,p-2,p);}
template<class T>inline T Fac(T n){if(n==0){return 1;}int ans=1;for(register int i=1;i<=n;++i){ans*=i;}return ans;}
template<class T>inline T Fac(T n,T p){if(n==0){return 1;}register long long ans=1;for(register int i=1;i<=n;++i){ans=ans*i%p;}return ans;}
template<class T>Inline int Popcount(T x,bool f=true){return f?__builtin_popcountll(x):__builtin_popcount(x);}
template<class T>Inline int Prebit(T x,bool f=true){return f?__builtin_clzll(x):__builtin_clz(x);}
template<class T>Inline int Sufbit(T x,bool f=true){return f?__builtin_ctzll(x):__builtin_ctz(x);}
template<class T>Inline int Lowone(T x,bool f=true){return f?__builtin_ffsll(x):__builtin_ffs(x);}
template<class T>Inline int Parity(T x,bool f=true){return f?__builtin_parityll(x):__builtin_parity(x);}
template<class T>Inline bool Isdigit(T ch){return ch>='0'&&ch<='9';}
template<class T>Inline bool Isletter(T ch){return ch>='A'&&ch<='Z'||ch>='a'&&ch<='z';}
template<class T>Inline bool Isupper(T ch){return ch>='A'&&ch<='Z';}
template<class T>Inline bool Islower(T ch){return ch>='a'&&ch<='z';}
template<class T>Inline char Tolower(T ch){return ch-'A'+'a';}
template<class T>Inline char Toupper(T ch){return ch-'a'+'A';}
template<class T>inline void Memset(T*d,long long n,long long s){for(register int i=0;i<=s-1;++i){d[i]=n;}}
template<class T>inline void Bug(T x,string name){cerr<<name<<": "<<x<<endl;}
template<class T>inline void Bug(T x){cerr<<x<<endl;}
template<class T>inline T Sin(register T degree){return sin(degree*(pi/180));}
template<class T>inline T Cos(register T degree){return cos(degree*(pi/180));}
template<class T>inline T Tan(register T degree){return tan(degree*(pi/180));}
template<class T>inline T Asin(register T degree){return asin(degree)*180.0/pi;}
template<class T>inline T Acos(register T degree){return acos(degree)*180.0/pi;}
template<class T>inline T Atan(register T degree){return atan(degree)*180.0/pi;}
template<class T>inline long long Rand(T l,T r){static mt19937_64 Rd(chrono::steady_clock::now().time_since_epoch().count());return uniform_int_distribution<long long>(l,r)(Rd);}
template<class T,class F>inline T Binarysearch(T l,T r,T f,const F &check){T mid,ans;for(mid=(l+r)>>1,ans=f;l<=r;mid=(l+r)>>1){check(mid)?ans=mid,r=mid-1:l=mid+1;}return ans;}
template<class T,class F>inline T Binarysearch(T l,T r,T f,double eps,const F &check){T mid,ans;for(mid=(l+r)/2;r-l>eps;mid=(l+r)/2){check(mid)?ans=mid,l=mid:r=mid;}return ans;}
template<class T>inline void Radixsort(register const int n,T*a,T*b){int r1[0x100],r2[0x100],r3[0x100],r4[0x100];memset(r1,0,sizeof(r1));memset(r2,0,sizeof(r2));memset(r3,0,sizeof(r3));memset(r4,0,sizeof(r4));register int i,tmp_int;register T*j,*tar;for(j=a+1,tar=a+n+1;j!=tar;++j){tmp_int=*(int*)j;++r1[tmp_int&0xff];++r2[(tmp_int>>8)&0xff];++r3[(tmp_int>>16)&0xff];++r4[tmp_int>>24];}for(i=1;i<=0xff;++i){r1[i]+=r1[i-1];r2[i]+=r2[i-1];r3[i]+=r3[i-1];r4[i]+=r4[i-1];}for(j=a+n;j!=a;--j){tmp_int=*(int*)j;b[r1[tmp_int&0xff]--]=*j;}for(j=b+n;j!=b;--j){tmp_int=*(int*)j;a[r2[(tmp_int>>8)&0xff]--]=*j;}for(j=a+n;j!=a;--j){tmp_int=*(int*)j;b[r3[(tmp_int>>16)&0xff]--]=*j;}for(j=b+n;j!=b;--j){tmp_int=*(int*)j;a[r4[tmp_int>>24]--]=*j;}}
template<class T>inline void Radixsort(register const int n,T*a,T*b,bool op){size_t size_of_type=sizeof(T);size_t num_of_buc=size_of_type>>1;unsigned**r=new unsigned*[num_of_buc];register int i,k;for(i=0;i<num_of_buc;++i){r[i]=new unsigned[0x10000];memset(r[i],0,0x10000*sizeof(unsigned));}register unsigned short tmp_us;register T*j,*tar;for(k=0;k<num_of_buc;++k){for(j=a+1,tar=a+n+1;j!=tar;++j){tmp_us=*(((unsigned short*)j)+k);++r[k][tmp_us];}}for(k=0;k<num_of_buc;++k){for(i=1;i<=0xffff;++i){r[k][i]+=r[k][i-1];}}for(k=0;k<num_of_buc;k+=0x2){i=k;for(j=a+n;j!=a;--j){tmp_us=*(((unsigned short*)j)+i);b[r[i][tmp_us]--]=*j;}i|=1;if(i==num_of_buc){break;}for(j=b+n;j!=b;--j){tmp_us=*(((unsigned short*)j)+i);a[r[i][tmp_us]--]=*j;}}for(int i=0;i<num_of_buc;i++){delete[]r[i];}delete[]r;}
template<class T>inline void Radixsort(register const int n,T*a,T*b,bool op1,bool op2){Radixsort(n,a,b,true);reverse(a+1,a+n+1);reverse(upper_bound(a+1,a+n+1,(T)(-0.0)),a+n+1);}
inline int rd(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}return x*f;}
inline long long read(){long long x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}return x*f;}
inline unsigned long long Read(){unsigned long long x=0;long long f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}return x*f;}
inline bool wrt(int x,char ch='\n'){static char buf[64];static int len=-1;if(x<0){putchar('-');x=-x;}do{buf[++len]=x%10;x/=10;}while(x);while(len>=0){putchar(buf[len--]+'0');}putchar(ch);return true;}
inline bool write(long long x,char ch='\n'){static char buf[64];static long long len=-1;if(x<0){putchar('-');x=-x;}do{buf[++len]=x%10;x/=10;}while(x);while(len>=0){putchar(buf[len--]+'0');}putchar(ch);return true;}
//inline bool Write(unsigned long long x,char ch='\n'){static char buf[64];static long long len=-1;if(x<0){putchar('-');x=-x;}do{buf[++len]=x%10;x/=10;}while(x);while(len>=0){putchar(buf[len--]+'0');}putchar(ch);return true;}
inline void OF(string s){string IN=s+".in";string OUT=s+".out";freopen(IN.c_str(),"r",stdin);freopen(OUT.c_str(),"w",stdout);}
inline void CF(string s){fclose(stdin);fclose(stdout);}
/*
Good Luck!
Have Fun!
CSPJ RP++
CSPS RP++
  OI RP++
 NOI RP++
 CTT RP++
 CTS RP++
 IOI RP++
Goal:
CF IM
AT 2DAN
LG Lv9
To be continued...
*/
//.................................................................................................................
//.................................................................................................................
//.................................................................................................................
//.................................................................................................................
//.................................................................................................................
//.......RRRRRRRRRRRRRRRRRRRR...................PPPPPPPPPPPPPPPPPPPP...............................................
//.......RRRRRRRRRRRRRRRRRRRRRR.................PPPPPPPPPPPPPPPPPPPPPP.............................................
//.......RRRRRRRRRRRRRRRRRRRRRRR................PPPPPPPPPPPPPPPPPPPPPPPP...........................................
//.......RRRR.................RRRRR.............PPPP...............PPPPP...........................................
//.......RRRR.................RRRRR.............PPPP................PPPPP..........................................
//.......RRRR.................RRRRR.............PPPP................PPPPP..........................................
//.......RRRR...............RRRRR...............PPPP...............PPPPP...........................................
//.......RRRR............RRRRRR.................PPPP.............PPPPPP............................................
//.......RRRR............RRRRRR.................PPPP............PPPPPP.............................................
//.......RRRR........RRRRRR.....................PPPP........PPPPPPP................................................
//.......RRRRRRRRRRRRRRRRRR.....................PPPPPPPPPPPPPPPPPP.................................................
//.......RRRRRRRRRRRRRRRRRR.....................PPPPPPPPPPPPPPPP...................................................
//.......RRRR..........RRRR.....................PPPPP.................................+++................+++.......
//.......RRRR...........RRRR....................PPPPP.................................+++................+++.......
//.......RRRR.............RRRR..................PPPPP.................................+++................+++.......
//.......RRRR..............RRRR.................PPPPP...........................+++++++++++++++....+++++++++++++++.
//.......RRRR...............RRRR................PPPPP...........................+++++++++++++++....+++++++++++++++.
//.......RRRR................RRRR...............PPPPP.................................+++................+++.......
//.......RRRR.................RRRR..............PPPPP.................................+++................+++.......
//.......RRRR...................RRRR............PPPPP.................................+++................+++.......
//.................................................................................................................
//.................................................................................................................
//.................................................................................................................
//.................................................................................................................
//.................................................................................................................
[[maybe_unused]]constexpr long long N=1000100;
long long n,m,x;
int main(){
    n=read();
    m=read();
    x=read();
    n-=(x<<1)-1;
    m-=(x<<1)-1;
    return !write(Min(n,m)<0?0:Max(1LL,n+m));
}
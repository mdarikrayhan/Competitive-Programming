// LUOGU_RID: 159703460
#include<bits/stdc++.h>
#define int long long
#define said(...)//请在这里输入你想要说的_________
#define pb push_back
#define em emplace_back
#define F(i,x,y) for(int i=x;i<=y;++i)
#define G(i,x,y) for(int i=x;i>=y;--i)
#define W(G,i,x) for(auto&i:G[x])
#define W_(G,i,j,x) for(auto&[i,j]:G[x])
#define PreSolve F($,520,1314)said("666") ;/*fk*/
#define add(x,y) z[x].em(y)
#define add_(x,y) add(x,y),add(y,x)
#define Add(x,y,d) z[x].em(y,d)
#define Add_(x,y,z) Add(x,y,z),Add(y,x,z);
#define fk ios_base::sync_with_stdio(0),cin.tie(0);
#define inf (7611257611378358090ll/2)
using namespace std;
auto gcd(int p, int b)[[]]->int{
    int _a=__builtin_ctzll(p),_b=__builtin_ctzll(b),c=min(_a, _b);b>>=_b;
    while(p){
        p>>=p;int diff=p-b;
        _a=__builtin_ctzll(diff);
        b=min(p,b),p=abs(diff);
    }return b<<c;
}
namespace FastIO{
    class FastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?(file_end=true),EOF:*p1++;}void put(char x){p3-obuf<1000007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}FastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}FastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());
    for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}FastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,FastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=(t<<3)+(t<<1)+(c^48);if(y==1)t=-t;return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;
    bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=(t<<3)+(t<<1)+(c^48);if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value||std::is_same<any,__uint128_t>::value),FastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=(t<<3)+(t<<1)+(c^48);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=(t<<3)+(t<<1)+(c^48);return t;}template<typename any1,typename any2>FastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.x>>t.y;}FastIO&operator<<(const char t){put(t);return*this;}FastIO&operator<<(const char*t)
    {for(;*t;t++)put(*t);return*this;}FastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,FastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value||std::is_same<any,__uint128_t>::value),FastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>FastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.x<<' '<<t.y;}~FastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
}using namespace FastIO;
#ifndef y78 // sjhy78 唯一原神
// 36号 渊深

// #define cin fio
// #define cout fio
#endif

const int N = 300100;
const int mod = 1e9 + 7;

namespace yhb { // TaoTaoTaoTao

// 多测 预处理
void flower() {
    
}

// 主程序
int dfs(int x, int v) {
    int t = x, bin = 1;
    while (t / 2) {
        bin *= 2;
        t /= 2;
    }
    if (v < bin) {
        return dfs(x / 2, v);
    } else if (v > bin) {
        return dfs(x / 2, v - bin);
    } else if (x % 2) {
        return 1;
    } else {
        return 0;
    }
}
int a[N];
void qunqun() {
    int n, l, r, s = 0;
    cin >> n >> l >> r;
    F(i, l, r) {
        s += dfs(n, i);
    }
    cout << s << '\n';
}
} // using namespace yhb::qunqun;
auto main() [[O3]] -> signed {
    PreSolve
    int T;
    // cin >> T;
    T = 1;
    yhb::flower();
    while (T--) {
        yhb::qunqun();
    }
    said("保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!")
    said("202 && 101, 90=2, F(3023)=1919810, 739085 011000130014001600180030002300")
    said("1500579580691697718744745746748750783809813814817818819830821823825826829830833835836837838841842853856859862871873874875877883889892893894895896897898899")
}
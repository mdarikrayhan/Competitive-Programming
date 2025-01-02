// LUOGU_RID: 160377848
%:include<bits/stdc++.h>
%:define int long long
%:define said(...)//请在这里输入你想要说的_________
%:define pb push_back
%:define em emplace_back
%:define F(i,x,y) for(int i=x;i<=y;i++)
%:define G(i,x,y) for(int i=x;i>=y;i--)
%:define W(G,i,x) for(auto&i:G[x])
%:define W_(G,i,j,x) for(auto&[i,j]:G[x])
%:define PRESOLVE F($,520,1314)said("666") ;/*fk*/
%:define add(x,y) z[x].em(y)
%:define add_(x,y) add(x,y),add(y,x)
%:define Add(x,y,d) z[x].em({y,d})
%:define Add_(x,y,z) Add(x,y,z),Add(y,z,x);
%:define fk ios_base::sync_with_stdio(0),cin.tie(0);
%:define inf (7611257611378358090ll/2)
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
    class fastIO{private:char ibuf[1000007],*p1=ibuf,*p2=ibuf,obuf[1000007],*p3=obuf,sta[50];bool file_end=false;char get(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?(file_end=true),EOF:*p1++;}void put(char x){p3-obuf<1000007?*p3++=x:(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x);}public:explicit operator bool(){return!file_end;}size_t flush(){size_t f=fwrite(obuf,p3-obuf,1,stdout);p3=obuf;*p3=0;return f;}fastIO&operator>>(char&t){for(t=get();!isgraph(t);t=get());return*this;}template<typename any>typename std::enable_if<std::is_same<any,char>::value,any>::type tpval(){char t;for(t=get();!isgraph(t);t=get());return t;}
    fastIO&operator>>(char*t){char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())*t=c,t++;*t=0;return*this;}fastIO&operator>>(std::string&t){t.clear();char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return*this;}template<typename any>typename std::enable_if<std::is_same<any,std::string>::value,any>::type tpval(){std::string t;char c;for(c=get();!isgraph(c);c=get());for(;isgraph(c);c=get())t+=c;return t;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator>>(any&t){t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=(t<<3)+(t<<1)+(c^48);if(y==1)t=-t;return*this;}
    template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,any>::type tpval(){any t=0;bool y=0;char c=get();for(;!isdigit(c);c=get())if(c==45)y=true;for(;isdigit(c);c=get())t=(t<<3)+(t<<1)+(c^48);if(y==1)t=-t;return t;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value||std::is_same<any,__uint128_t>::value),fastIO>::type&operator>>(any&t){t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=(t<<3)+(t<<1)+(c^48);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__uint128_t>::value,any>::type tpval(){any t=0;char c=get();for(;!isdigit(c);c=get());for(;isdigit(c);c=get())t=(t<<3)+(t<<1)+(c^48);return t;}
    template<typename any1,typename any2>fastIO&operator>>(std::pair<any1,any2>&t){return*this>>t.first>>t.second;}fastIO&operator<<(const char t){put(t);return*this;}fastIO&operator<<(const char*t){for(;*t;t++)put(*t);return*this;}fastIO&operator<<(const std::string&t){for(const char it:t)put(it);return*this;}template<typename any>typename std::enable_if<(std::is_signed<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value)||std::is_same<any,__int128_t>::value,fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;if(t<0)t=-t,put(45);while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any>typename std::enable_if<(std::is_unsigned<any>::value&&std::is_integral<any>::value&&!std::is_same<any,char>::value||std::is_same<any,__uint128_t>::value),fastIO>::type&operator<<(any t){if(!t){put(48);return*this;}int len=0;while(t)sta[len++]=t%10+48,t/=10;while(len--)put(sta[len]);return*this;}template<typename any1,typename any2>fastIO&operator<<(const std::pair<any1,any2>&t){return*this<<t.first<<' '<<t.second;}~fastIO(){fwrite(obuf,p3-obuf,1,stdout);}}fio;
}using namespace FastIO;
%:ifndef y78
%:define cin fio
%:define cout fio
%:endif
const int N=1000100;
map<pair<int,int>,int>mp;
int fun(int n,int m,int p){
    if(p==1)return m-fun(n,m,p^1);
    if(m<=1)return m*(!!__builtin_parityll(n));
    if(mp.count({n,m}))return mp[{n,m}];
    return mp[{n,m}]=fun(n/2,(m+1)/2,n%2)+fun((n+1)/2,m/2,n%2);
}
auto main()[[O3]]->signed{
    PRESOLVE 
    int q;cin>>q;while(q--){int x,y;cin>>x>>y;cout<<fun(x,y,0)<<'\n';}
    said("RP++! CSP 2024 RP++! NOIP 2024 RP++!")
    said("保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!保佑我AC!")
}
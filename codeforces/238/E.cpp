// LUOGU_RID: 159638723
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

#define cin fio
#define cout fio
#endif

const int N = 210;

namespace yhb { // TaoTaoTaoTao

// 多测 预处理
void flower() {
    
}
// 主程序
int n, m, s, t, k;
int mp[N][N], deg[N][N], box[N][N], dis[N][N];
bool can[N];
struct Flower {
    int x, y;
} z[N];
void qunqun() {
    cin >> n >> m >> s >> t;
    F(i, 1, n) {
        F(j, 1, n) {
            mp[i][j] = inf;
        }
    }
    F(i, 1, n) {
        mp[i][i] = 0;
    }
    F(i, 1, m) {
        int u, v;
        cin >> u >> v;
        mp[u][v] = 1;
    }
    F(k, 1, n) {
        F(i, 1, n) {
            F(j, 1, n) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    cin >> k;
    F(i, 1, k) {
        cin >> z[i].x >> z[i].y;
        if (mp[z[i].x][z[i].y] < inf) {
            can[i] = true;
        } else {
            can[i] = false;
        }
    }
    F(i, 1, n) {
        F(j, 1, k) {
            if (can[j] && mp[z[j].x][i] + mp[i][z[j].y] == mp[z[j].x][z[j].y]) {
                box[j][mp[z[j].x][i]]++;
                F(_, 1, n) {
                    if (mp[i][_] == 1 && mp[z[j].x][i] + mp[i][_] + mp[_][z[j].y] == mp[z[j].x][z[j].y]) {
                        deg[i][j]++;
                    }
                }
            }
        }
    }
    memset(dis, 0x3f, sizeof dis);
    F(i, 1, k) {
        // cout << i << ": " << dis[z[i].x][z[i].y] << ' ' << dis[t][z[i].y] << ' ' << dis[z[i].x][z[i].y] << '\n';
        if (can[i] && mp[z[i].x][t] + mp[t][z[i].y] == mp[z[i].x][z[i].y]) {
            dis[t][i] = 0;
        }
    }
    // cout << '\n';
    F(_, 0, n - 1) {
        queue<pair<int, int>> q;
        F(i, 1, n) {
            F(j, 1, k) {
                if (dis[i][j] == _) {
                    q.push({i, j});
                }
            }
        }
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (box[y][mp[z[y].x][x]] == 1) {
                if (s == x) {
                    cout << 1 + dis[x][y] << '\n';
                    return;
                }
                F(j, 1, k) {
                    if (can[j] && mp[z[j].x][x] + mp[x][z[j].y] == mp[z[j].x][z[j].y]) {
                        dis[x][j] = min(dis[x][j], dis[x][y] + 1);
                    }
                }
            }
            F(j, 1, n) {
                if (mp[j][x] == 1 && mp[z[y].x][j] + mp[j][x] + mp[x][z[y].y] == mp[z[y].x][z[y].y]) {
                    if (!--deg[j][y]) {
                        if (dis[x][y] < dis[j][y]) {
                            dis[j][y] = dis[x][y];
                            q.push({j, y});
                        }
                    }
                }
            }
        }
    }
    cout << "-1\n";
}
}
auto main() [[O3]] -> signed {
    int T;
    T = 1;
    yhb::flower();
    while (T--) {
        yhb::qunqun();
    }
}
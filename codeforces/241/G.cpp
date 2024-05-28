// LUOGU_RID: 160322926
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define em emplace_back
#define F(i,x,y) for(int i=x;i<=y;i++)
#define G(i,x,y) for(int i=x;i>=y;i--)
#define W(G,i,x) for(auto&i:G[x])
#define W_(G,i,j,x) for(auto&[i,j]:G[x])
#define add(x,y) z[x].em(y)
#define add_(x,y) add(x,y),add(y,x)
#define Add(x,y,d) z[x].em(y,d)
#define Add_(x,y,z) Add(x,y,z),Add(y,x,z);
#ifdef int
#define inf (7611257611378358090ll/2)
#else
#define inf 0x3f3f3f3f
#endif
using namespace std;
auto main() [[O3]] -> signed {
    cout << "302\n1 1000000\n"; int t = 300000;
    F(i, 1, 300) cout << t << ' ' << 300 - i + 1 << '\n', t += 600;
    cout << "1000000 1000000\n";
}
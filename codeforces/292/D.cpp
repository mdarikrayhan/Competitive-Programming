// LUOGU_RID: 160004470
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#define maxm 500005
#define maxn 505
#define inf 0x3f3f3f3f3f3f
using namespace std;
namespace fastIO{
#ifdef ONLINE_JUDGE
	const int SIZE = 1 << 20;
	char in[SIZE], out[SIZE], *p1 = in, *p2 = in, *p3 = out;
#define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, SIZE, stdin), p1 == p2) ? EOF : *p1 ++ )
#define flush() (fwrite(out, 1, p3 - out, stdout))
#define putchar(x) (p3 == out + SIZE && (flush(), p3 = out), *p3 ++ = (x))
	class Flush {public: ~Flush() {flush();}} _;
#endif
	template<typename Type>
	inline Type read(Type &x){
		x = 0; bool flag(0); char c = getchar();
		while (!isdigit(c)) flag ^= (c == '-'), c = getchar();
		while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
		return flag ? x = -x : x;
	}
	template<typename Type>
	inline void write(Type x){
		x < 0 ? x = -x, putchar('-') : 0;
		static short Stack[35], top(0);
		do Stack[ ++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(Stack[top -- ] | 48);
	}
	inline char read(char &x) {do x = getchar(); while (isspace(x)); return x;}
	inline int read(char *x) {static char *c = x; while (!isspace(*c = getchar()) && *c != EOF) c ++ ; *c = '\0'; return c - x;}
	inline char write(const char &x) {return putchar(x);}
	template<typename Type> inline void write(Type *x) {while (*x) putchar(*x ++ );}
	template<typename Type, typename ...Args> inline void read(Type &x, Args &...y) {read(x), read(y...);}
	template<typename Type, typename ...Args> inline void write(const Type &x, const Args &...y) {write(x), putchar(' '), write(y...), sizeof...(y) ^ 1 ? 0 : putchar('\n');}
	template<typename Type>	inline void write(const Type &x, char c) {write(x), putchar(c);}
#ifdef ONLINE_JUDGE
	#undef getchar
	#undef flush
	#undef putchar
#endif
}
using namespace fastIO;
int T,n,m,l,r,ans;
int a[maxn],vis[maxn];
vector<pair<int,int> >e[maxn]; 
void Dfs(int x,int op){
	vis[x]=op;
	for(register int i=0;i<e[x].size();i++){
		int y=e[x][i].first,id=e[x][i].second;
		if(id>=l&&id<=r)continue;
		if(vis[y]==op)continue;
		Dfs(y,op);
	}
}
#define mp make_pair
signed main(){
	read(n);read(m);
	for(register int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		e[x].push_back(mp(y,i));
		e[y].push_back(mp(x,i));
	} 
	read(T);
	for(register int ii=1;ii<=T;ii++){
		read(l);read(r);
		ans=0;
		for(register int i=1;i<=n;i++){
			if(vis[i]!=ii){
				Dfs(i,ii);
				ans++;
			}
		}
		write(ans);
		write('\n');
	}
    return 0;
}
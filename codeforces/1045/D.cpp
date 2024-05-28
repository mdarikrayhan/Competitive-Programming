// LUOGU_RID: 157255291
#include <bits/stdc++.h>
using namespace std;
int n, q, x, y, f[1000005];
double pp, p[100005], dp[100005];
vector<int> s[100005];
namespace Fast_IO
{
    static char buf[1000000],*paa=buf,*pd=buf,out[10000000];int length=0;
    // #define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
    inline int read()
    {
        int x(0),t(1);char fc(getchar());
        while(!isdigit(fc)){if(fc=='-') t=-1;fc=getchar();}
        while(isdigit(fc)) x=(x<<1)+(x<<3)+(fc^48),fc=getchar();
        return x*t;
    }
    inline void flush(){fwrite(out,1,length,stdout);length=0;}
    inline void put(char c){if(length==9999999) flush();out[length++]=c;}
    inline void put(string s){for(char c:s) put(c);}
    inline void print(int x)
    {
        if(x<0) put('-'),x=-x;
        if(x>9) print(x/10);
        put(x%10+'0');
    }
    inline bool chk(char c) { return !(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'); }
    inline bool ck(char c) { return c!='\n'&&c!='\r'&&c!=-1&&c!=' '; }
    inline void rd(char s[],int&n)
    {
        s[++n]=getchar();
        while(chk(s[n])) s[n]=getchar();
        while(ck(s[n])) s[++n]=getchar();
        n--;
    }
}
using namespace Fast_IO;
void dfs(int x, int fa) {
	f[x] = fa;
	for (int i = 0; i < s[x].size(); i++) {
		if (s[x][i] != fa) {
			dfs(s[x][i], x);
			dp[x] += 1.0 - p[s[x][i]];
		}
	}
}
signed main() {
	n = read();
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &p[i]);
	}
	for (int i = 1; i < n; i++) {
		x = read() + 1, y = read() + 1;
		s[x].emplace_back(y);
		s[y].emplace_back(x);
	}
	dfs(1, 0);
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += p[f[i]] * (1.0 - p[i]);
	}
	q = read();
	while (q--) {
		x = read() + 1;
		scanf("%lf", &pp);
		double nk = dp[f[x]] - (1.0 - p[x]) + (1.0 - pp);
		ans -= dp[f[x]] * p[f[x]] - nk * p[f[x]];
		ans += pp * dp[x] - p[x] * dp[x];
		dp[f[x]] = nk, p[x] = pp;
		printf("%.5lf\n", ans);
	}
	flush();
}
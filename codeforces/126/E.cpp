#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define gc() getchar()
inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;}
struct D{char g[17][17]; int w;}Ans, F; char __[] = "YWRB"; bool book[10][10]; vector<int> C, N; set<vector<int> > H;
int A[10][10], L[10], R[10], _[4][4], e[25][25], u[25][25], ma[25], S = 20, T = 21, z; typedef pair<int,int> pii; vector<pii> g;
bool DFS(int p){if(p>=10&&e[p][T]) return --e[p][T],++e[T][p],true; ma[p] = z; for(rint i = 0; i < 20; i++) if(ma[i]<z&&u[p][i]&&e[p][i]&&DFS(e[p][i])) return --e[p][i],++e[i][p],true; return false;}
void Fill(int a, int b, int c, int d, int t){(A[a][b]==L[t])+(A[c][d]==R[t])<(A[c][d]==L[t])+(A[a][b]==R[t])?a^=c^=a^=c,b^=d^=b^=d:0, F.g[a<<1][b<<1] = __[L[t]], F.g[c<<1][d<<1] = __[R[t]];}
void Work()
{
 if(H.count(C)) return; H.insert(C); g.clear(), F.w = 0, memset(e,0,sizeof e); static vector<int> c, n; c = C, n = N;
 for(rint i = 0; i < 10; i++) for(; c[i]&&n[i]; --c[i], --n[i], F.w += 2, g.push_back(pii(i,i))); if(Ans.w>(F.w>>1)+28) return;
 for(rint i = 0, j, w; i < 10; i++) for(j = 0; j < 10; u[i][j+10] ? F.w+=w=min(c[i],n[j]),c[i]-=w,e[i][S]+=w,n[j]-=w,e[T][j+10]+=w,e[j+10][i]=w,e[i][j+10]=28-w : 0, j++);
 for(rint i = 0; i < 10; e[S][i] = c[i], e[i+10][T] = n[i], i++); for(; ++z, DFS(S); ++F.w); if(Ans.w>=F.w) return;
 for(rint i = 0, j; i < 10; i++) for(j = 0; j < 10; j++) for(; e[j+10][i]--; g.push_back(pii(i,j)));
 for(rint i = 0, j; i < 10; i++) for(j = 0; c[i] && j < 10; j++) for(; c[i]&&n[j]; --c[i], --n[j], g.push_back(pii(i,j)));
 for(rint i = 0, j, x, y, k; i < 7; i++) for(j = 0; j < 8; j++) if(F.g[i<<1][j<<1]=='.'&&((j<7&&(x=i,y=j+1,F.g[i<<1][j<<1|1]=='-'))||(i<6&&(x=i+1,y=j,F.g[i<<1|1][j<<1]=='|'))))
  {k = _[A[i][j]][A[x][y]]; for(auto &t:g) if(t.first==k){Fill(i,j,x,y,t.second), swap(t,g.back()), g.pop_back(); break;}}
 Ans = F; for(rint i = 0, j; i < 7; i++) for(j = 0; j < 8; F.g[i<<1][j<<1] = '.', j++);
}
void DFS(int x, int y)
{
 y>=8?++x,y=0:0; if(x>=7) return Work(); if(book[x][y]) return DFS(x,y+1);
 if(y<7&&!book[x][y+1]) ++C[_[A[x][y]][A[x][y+1]]], F.g[x<<1][y<<1|1] = '-', book[x][y+1] = true, DFS(x,y+1), book[x][y+1] = false, F.g[x<<1][y<<1|1] = '.', --C[_[A[x][y]][A[x][y+1]]];
 if(x<6) ++C[_[A[x][y]][A[x+1][y]]], F.g[x<<1|1][y<<1] = '|', book[x+1][y] = true, DFS(x,y+1), book[x+1][y] = false, F.g[x<<1|1][y<<1] = '.', --C[_[A[x][y]][A[x+1][y]]];
}
int main()
{
 static char s[10]; static int mp[256]; mp['Y'] = 0, mp['W'] = 1, mp['R'] = 2, mp['B'] = 3;
 for(rint i = 0, j; i < 7; i++) for(scanf("%s",s), j = 0; j < 8; A[i][j] = mp[s[j]], j++); C.resize(10), N.resize(10);
 for(rint i = 3, j, t = 0; ~i; i--) for(j = 0; j <= i; N[_[i][j]=_[j][i]=t] = read(), L[t] = i, R[t] = j, t++, j++);
 for(rint i = 0, j, k; i < 4; i++) for(j = 0; j < 4; j++) for(k = 0; k < j; u[_[i][j]][_[i][k]+10] = u[_[i][k]][_[i][j]+10] = 1, k++);
 for(rint i = 0, j; i < 13; i++) for(j = 0; j < 15; F.g[i][j] = '.', j++); Ans.w = -1, DFS(0,0); printf("%d\n",Ans.w);
 for(rint i = 0; i < 13; Ans.g[i][15] = '\n', Ans.g[i][16] = 0, printf("%s",Ans.g[i]), i++); return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<ld, ld> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 100 * 1000 + 15;
int w, h;
int n;
pair<pt, pt> a[N];

inline void readPt (pt& p)
{
	int x, y;
	assert(scanf ("%d%d", &x, &y) == 2);
	
	p = mp(ld(x), ld(y));
}

inline bool read()
{
	if (scanf ("%d%d%d", &w, &h, &n) != 3)
		return false;
		
	forn (i, n)
	{
		readPt(a[i].ft);
		readPt(a[i].sc);
	}

	return true;
}

inline bool operator < (const pt& a, const pt& b)
{
	if (abs(a.x - b.x) < EPS)
		return a.y < b.y;
		
	return a.x < b.x;
}

inline bool in (const ld& a, const ld& b, const ld& p)
{
	return min(a, b) <= p + EPS && p <= max(a, b) + EPS;
}

inline bool in (const pt& a, const pt& b, const pt& p)
{
	return in(a.x, b.x, p.x) && in(a.y, b.y, p.y); 
}

inline ld det (const ld& a, const ld& b, const ld& c, const ld& d)
{
	return a * d - b * c;
}

inline bool intersect (const pt& a, const pt& b, const pt& c, const pt& d, pt& p)
{
	ld A1 = a.y - b.y, B1 = b.x - a.x;
	ld C1 = -(A1 * a.x + B1 * a.y);
	
	ld A2 = c.y - d.y, B2 = d.x - c.x;
	ld C2 = -(A2 * c.x + B2 * c.y);
	
	ld D = det(A1, B1, A2, B2);
	
	if (abs(D) < EPS)
		return false;
		
	p.x = -det(C1, B1, C2, B2) / D;
	p.y = -det(A1, C1, A2, C2) / D;
	
	return in(a, b, p) && in(c, d, p);
}

inline bool merge (pt& a, pt& b, pt c, pt d)
{
	ld A = a.y - b.y, B = b.x - a.x;
	ld C = -(A * a.x + B * a.y);
	
	if (abs(A * c.x + B * c.y + C) > EPS)
		return false;
	if (abs(A * d.x + B * d.y + C) > EPS)
		return false;
		
	if (!in(a, b, c) && !in(a, b, d) && !in(c, d, a) && !in(c, d, b))
		return false;
		
	if (a > b)
		swap(a, b);
	if (c > d)
		swap(c, d);
		
	a = min(a, c), b = max(b, d);
	
	return true;
}

inline bool cmpEq (const pt& a, const pt& b)
{
	return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}

int sze;
pt e[N];
vector<pt> p[N];
vector<int> g[N], used[N];

int cntG;
vector<int> gran[N];
ld area[N];
int id[N];

pt pole;

inline bool cmpAng (const int& a, const int& b)
{
	return atan2(e[a].y - pole.y, e[a].x - pole.x) < atan2(e[b].y - pole.y, e[b].x - pole.x);
}

inline ld getArea (const vector<int>& a)
{
	ld ans = 0;
	forn (i, sz(a))
	{
		int ni = (i + 1) % sz(a);
		
		ans += (e[ a[ni] ].x - e[ a[i] ].x) * (e[ a[ni] ].y + e[ a[i] ].y);
	}
	
	return ans / ld(2);
}

int col[N];
int cntCol = 0;

void dfs (int v)
{
	if (col[v] != -1)
		return;
		
	col[v] = cntCol;
	
	forn (i, sz(g[v]))
	{
		int to = g[v][i];
		
		dfs(to);
	}
}

inline bool onSeg (const pt& a, const pt& b, const pt& p)
{
	ld A = a.y - b.y, B = b.x - a.x;
	ld C = -(A * a.x + B * a.y);
	
	if (abs(A * p.x + B * p.y + C) > EPS)
		return false;
		
	return in(a, b, p);
}

inline bool onPoly (const vector<int>& a, const pt& p)
{
	pt p2 = mp(p.x + 28657, p.y + 33461);
	
	int cnt = 0;
	forn (i, sz(a))
	{
		int ni = (i + 1) % sz(a);
		
		if (onSeg(e[ a[i] ], e[ a[ni] ], p))
			return true;
		
		pt pp;
		cnt += intersect(e[ a[i] ], e[ a[ni] ], p, p2, pp);
	}
	
	return cnt & 1;
}

string colOut[N];
string colIn[N];

void colorBorder (int cid, const string& s);

set<int> gused, cused;

vector<int> par;
vector< vector<int> > gg;

void colorGran (int gid, const string& s)
{
	if (gused.count(gid))
		return;
		
	gused.insert(gid);
	
	//cerr << "G " << gid << ' ' << s << endl;
	
	/*int inner = -1;
	forn (i, cntG)
	{
		if (!onPoly(gran[gid], e[ gran[i][0] ]))
			continue;
			
		if (id[i] == id[gid] || colOut[ id[i] ] != colIn[gid])
			continue;
			
		if (inner == -1 || area[inner] < area[i])
			inner = i;
	}
	
	if (inner != -1)
		colorBorder(id[inner], s);*/
		
	forn (i, sz(gg[gid]))
	{
		int to = gg[gid][i];
		
		if (colOut[to] != colIn[gid])
			continue;
			
		colorBorder(to, s);
	}
	
	if (colIn[gid] == colOut[ id[gid] ])
	{
		colIn[gid] = s;
		colorBorder(id[gid], s);
	}
	else
		colIn[gid] = s;	
}

void colorBorder (int cid, const string& s)
{
	if (cused.count(cid))
		return;
		
	//cerr << "C " << cid << ' ' << s << endl;
		
	cused.insert(cid);

	forn (i, cntG)
		if (id[i] == cid && colIn[i] == colOut[cid])
			colorGran(i, s);
			
	int outer = par[cid];
			
	if (outer != -1 && colIn[outer] == colOut[cid])
		colorGran(outer, s);
			
	colOut[cid] = s;
}

map<string, ld> res;

inline void solve()
{
	a[n++] = mp(mp(0, 0), mp(0, h));
	a[n++] = mp(mp(0, h), mp(w, h));
	a[n++] = mp(mp(w, h), mp(w, 0));
	a[n++] = mp(mp(w, 0), mp(0, 0));

	forn (i, n)
		fore (j, i + 1, n - 1)
			if (merge(a[i].ft, a[i].sc, a[j].ft, a[j].sc))
			{
				swap(a[j], a[n - 1]);
				n--;
				j++;
			}
			
	sze = 0;
	
	forn (i, n)
	{
		e[sze++] = a[i].ft;
		e[sze++] = a[i].sc;
		
		p[i].pb(a[i].ft);
		p[i].pb(a[i].sc);
		
		fore(j, i + 1, n - 1)
		{
			pt pp;
			if (intersect(a[i].ft, a[i].sc, a[j].ft, a[j].sc, pp))
			{
				e[sze++] = pp;
				p[i].pb(pp);
				p[j].pb(pp);
			}
		}
	}
	
	sort(e, e + sze);
	sze = int(unique(e, e + sze, cmpEq) - e);
	
	forn (i, n)
	{
		sort(all(p[i]));
		p[i].erase(unique(all(p[i])), p[i].end());
		
		forn (j, sz(p[i]) - 1)
		{
			int cur = int(lower_bound(e, e + sze, p[i][j]) - e);
			int nxt = int(lower_bound(e, e + sze, p[i][j + 1]) - e);
			
			g[nxt].pb(cur);
			g[cur].pb(nxt);
		}	
	}
	
	forn (i, sze)
	{
		used[i].resize(sz(g[i]));
		forn (j, sz(used[i]))
			used[i][j] = 0;
			
		pole = e[i];
		sort(all(g[i]), cmpAng);
	}
	
	cntG = 0;
	
	forn (i, sze)
		forn (j, sz(g[i]))
			if (!used[i][j])
			{
				int v = i, id = j;
				while (!used[v][id])
				{
					used[v][id] = 1;
					gran[cntG].pb(v);
					
					int to = g[v][id];
					
					int nid = -1;
					forn (k, sz(g[to]))
						if (g[to][k] == v)
						{
							nid = k;
							break;
						}

					assert(nid != -1);

					nid = (nid + 1) % sz(g[to]);
					
					v = to, id = nid;
				}
				
				area[cntG] = getArea(gran[cntG]);
				
				if (area[cntG] > -EPS)
					cntG++;
				else
					gran[cntG].clear();
			}
			
	cntCol = 0;
	forn (i, sze)
		col[i] = -1;
		
	forn (i, sze)
		if (col[i] == -1)
		{
			dfs(i);
			cntCol++;
		}
		
	forn(i, cntG)
	{
		id[i] = col[ gran[i][0] ];

		colOut[ id[i] ] = "black";
		colIn[i] = "white";		
	}		
		
	gg.resize(cntG);
	par.resize(cntCol);
	
	forn (cid, cntCol)
	{
		pt p;
    	forn (i, cntG)
    		if (id[i] == cid)
    		{
    			p = e[ gran[i][0] ];
    			break;
    		}
    	
		int outer = -1;
		forn (i, cntG)
			if (onPoly(gran[i], p) && id[i] != cid && (outer == -1 || area[outer] > area[i]))
				outer = i;
				
		par[cid] = outer;
		if (outer != -1)
			gg[outer].pb(cid);
	}
		
	int m;
	assert(scanf ("%d", &m) == 1);
	forn (i, m)
	{
		//cerr << "-----" << endl;

		int x, y;
		char buf[30];
		
		assert(scanf ("%d%d%s", &x, &y, buf) == 3);
		
		string curColor = string(buf);
		
		int cid = -1;
		forn (j, n)
			if (onSeg(a[j].ft, a[j].sc, mp(x, y)))
			{
				int it = int(lower_bound(e, e + sze, a[j].ft) - e);
				cid = col[it];
				break;
			}
			
		//cerr << cid << endl;
			
		if (cid != -1)
		{
			cused.clear();
			gused.clear();
			colorBorder(cid, curColor);
			continue;
		}
		
		int gid = -1;
		forn (j, cntG)
			if (onPoly(gran[j], mp(x, y)))
				if (gid == -1 || area[j] < area[gid])
					gid = j;
					
		assert(gid != -1);

		gused.clear();
		cused.clear();
		colorGran(gid, curColor);	
	}
	
	/*cerr << "----------" << endl;
	
	forn (i, cntG)
	{
		cerr << id[i] << endl;
		cerr << colIn[i] << ' ' << colOut[ id[i] ] << endl;
		
		forn (j, sz(gran[i]))
		{
			int to = gran[i][j];
			
			cerr << e[to].x << ' ' << e[to].y << endl;
		}
	}*/
	
	fore (i, 1, cntCol - 1)
		res[ colOut[i] ] = 0;
	
	forn (i, cntG)
	{
		if (area[i] < EPS)
			continue;
		
		res[ colIn[i] ] += area[i];
		
		int outer = par[ id[i] ];
		
		if (outer != -1)
			res[ colIn[outer] ] -= area[i];
	}
	
	for(map<string, ld>::iterator it = res.begin(); it != res.end(); it++)
		printf ("%s %.15f\n", it->ft.c_str(), double(it->sc));
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}
//hellobig_tq
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define loop(x, i) for (int i = 0; i < (x); i++)
#define pb push_back
#define var const auto&

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef set<int> si;

#define impos { cout << 0 << endl; exit(0);}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	vector<string> graph, graph2;
	vector<string> res;
	cin >> n >> m;
	graph.resize(n);
	graph2.resize(m, string(n, '0'));
	loop(n, i)
	{
		cin >> graph[i];
		loop(m, j) graph2[j][i] = graph[i][j];
	}
	vii neighbours = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0},{1, 1} };
	loop(n, i) loop(m, j)
	{
		for (var[di, dj] : neighbours)
		{
			if (i + di < 0 || j + dj < 0) continue;
			if (i + di >= n || j + dj >= m) continue;
			if ('0' == graph[i][j]) continue;
			if (graph[i + di][j + dj] != graph[i][j]) continue;
			impos;
		}
	}
	bool rotated = 0;
vert:
	for (char a = '1'; a <= '4'; a++)
	{
		for (char b = '1'; b <= '4'; b++)
		{
			if (b == a) continue;
			for (char c = '1'; c <= '4'; c++)
			{
				if (c == a) continue;
				if (c == b) continue;
				si all = { a, b, c };
				char d;
				if (!all.count('1')) d = '1';
				else if (!all.count('2')) d = '2';
				else if (!all.count('3')) d = '3';
				else if (!all.count('4')) d = '4';
				res = graph;
				bool pos = 1;
				loop(2, startI)
				{
					if (!pos) break;
					for (int i = startI; i < n; i += 2)
					{
						vi colors = { a, b, c, d };
						bool switched = 0;
					switchOffset:
						if (!pos) break;
						loop(2, startJ)
						{
							if (!pos) break;
							for (int j = startJ; j < m; j += 2)
							{
								if (graph[i][j] == '0')
								{
									res[i][j] = colors[2 * startI + startJ];
								}
								else if (res[i][j] != colors[2 * startI + startJ])
								{
									if (!switched && graph[i][j] == colors[2 * startI + !startJ])
									{
										switched = 1;
										swap(colors[2 * startI + startJ], colors[2 * startI + !startJ]);
										//res[i] = graph[i];
										goto switchOffset;
									}
									else
									{
										pos = 0;
										break;
									}
								}
							}
						}
					}
				}
				if (!pos) continue;
				if (rotated)
				{
					loop(m, i)
					{
						loop(n, j) cout << res[j][i];
						cout << endl;
					}
				}
				else
				{
					loop(n, i)
					{
						cout << res[i] << endl;
					}
				}
				exit(0);
			}
		}
	}
	if (rotated) impos
		rotated = 1;
	swap(graph, graph2);
	swap(n, m);
	goto vert;
}
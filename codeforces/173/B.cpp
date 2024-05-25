#include <bits/stdc++.h>
typedef long long ll;
#define FAST_IO (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define all(x)	(x).begin(),(x).end()
#define endl '\n'
#define pb push_back
#define ins insert
#define pii pair<int, int>
#define mkp make_pair
#define ff first
#define ss second
#define bg begin
#define sz size()
#define ms(x,y) memset(x,y,sizeof x)
#define clr clear()
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define vci vector<int>
#define sti set<int>
#define nl cout<<endl
#define vll vector<long long>
#define maxel *max_element
#define minel *min_element
#define stk stack<int>
#define szof sizeof
#define qui queue<int>
using namespace std;
int e[2010];
char a[1010][1010];
int main()
{
	int i,j,n,m,t;
	cin >> n >> m;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			cin >> a[i][j];
	memset(e,-1,szof(e));
	e[1]=0;
	queue <int> q;
	q.push(1);
	while(!q.empty()&&(e[n]==-1))
	{
		t=q.front();
		q.pop();
		if (t>=n)
		{
			t-=n;
			for (int i=1;i<=n;i++)
				if ((a[i][t]=='#')&&(e[i]==-1))
				{
					e[i]=e[t+n]+1;
					q.push(i);
				}
		}
		else
		{
			for (int i=1;i<=m;i++)
				if ((a[t][i]=='#')&&(e[n+i]==-1))
				{
					e[n+i]=e[t]+1;
					q.push(n+i);
				}
		}
	}
	cout << e[n];
	return 0;
}


#include <bits/stdc++.h>
#define vinh ios::sync_with_stdio(false);cin.tie(nullptr);
#define myfor(i,a,b) for(int i=a;i<b;i++)
#define myFor(i,a,b) for(int i=a;i>=b;i--)
#define foreach(x,a) for(auto x:a)
#define forEach(x,a) for(auto &x:a)
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pair<int,int>>
#define vil vector<pair<int,ll>>
#define vll vector<pair<ll,ll>>
#define vi vector<int>
#define vl vector<ll>
#define maxn 100001
using namespace std;
struct play
{
	int l, r, k, id, type;
};
play a[2*maxn];
bool cmp(play a, play b)
{
	if(a.l != b.l) return a.l < b.l;
	else
	{
		if(a.r != b.r) return a.r > b.r;
		else return a.type < b.type;
	}
}
int main()
{
	vinh
	int n; cin>>n;
	int tmp = n;
	myfor(i,0,n)
	{
		cin>>a[i].l>>a[i].r;
		a[i].id = i, a[i].type = 1;
	}
	int m; cin>>m;
	myfor(i,0,m)
	{
		cin>>a[n].l>>a[n].r>>a[n].k;
		a[n].id = i, a[n].type = 0;
		n++;
	}
	sort(a,a+n,cmp);
	set<pii> s;
	int p[tmp] = {0};
	myfor(i,0,n)
	{
		play x = a[i];
		if(x.type)
		{
			auto it = s.lower_bound({x.r,0});
			if(it == s.end()) 
			{
				cout<<"NO";
				return 0;
			}
			int y = it -> second;
			p[x.id] = a[y].id;
			a[y].k --;
			if(a[y].k ==  0) s.erase(it);
		}
		else
		{
			s.insert({x.r,i});
		}
	}
	cout<<"YES"<<endl;
	myfor(i,0,tmp) cout<<p[i]+1<<" ";
}

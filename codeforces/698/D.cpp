// LUOGU_RID: 159817918
// LUOGU_RID: 159816203
#include<bits/stdc++.h>
using namespace std;

const long long K=11;
const long long N=1007;
long long n,k,X,Y,ans=0;
vector<long long> lst[K][N];
bool fl[K],sht[N];
vector<long long> v;
struct ZB{long long x,y,id;}p[N],m[N];
long long _abs(long long x){return (x>=0)?x:-x;}
bool operator < (ZB x,ZB y)
{
	if(X-x.x==X-y.x) return _abs(Y-x.y)<_abs(Y-y.y);
	else return _abs(X-x.x)<_abs(X-y.x);
}
bool tc(long long x,long long y)
{
	if(m[x].x!=m[y].x) return (X-m[x].x)*(X-m[y].x)>0;
	else return (Y-m[x].y)*(Y-m[y].y)>0;
}

bool cmq(ZB x,ZB y){return x.id<y.id;}
bool dfs(vector<long long> v,long long pn)
{
//	for(long long i=0;i<v.size();i++) cout<<(char)(v[i]+'C')<<" ";
//	cout<<endl;
//	cout<<fl[1]<<" "<<fl[2]<<" "<<fl[3]<<" "<<pn<<endl;
	if(v.empty()) return true;
	if(v.size()>pn) return false;
	for(long long i=1;i<=k;i++)
	{
		if(fl[i]) continue;
		long long x=v.back(),y;
		y=x; v.pop_back();
	//	cout<<i<<" "<<fl[i]<<"!"<<x<<" "<<y<<" "<<lst[i][y]<<endl;
		queue<int> q;
		for(long long j=0;j<lst[i][y].size();j++)
			if(!sht[lst[i][y][j]])
			{
				v.push_back(lst[i][y][j]);
				sht[lst[i][y][j]]=true;
				q.push(lst[i][y][j]);
			}
	//	sht[v.back()]=1;
		fl[i]=true;
		if(dfs(v,pn-1)) return true;
		fl[i]=false;
	//	sht[v.back()]=0;
		y=x;
		while(!q.empty())
		{
			v.pop_back();
			sht[q.front()]=false;
			q.pop();
		}
		v.push_back(x);
	}
	return false;
}

int main()
{
//	freopen("data.in","r",stdin);
//	freopen("mine.out","w",stdout);
	scanf("%lld%lld",&k,&n);
	for(long long i=1;i<=k;i++)
		scanf("%lld%lld",&p[i].x,&p[i].y);
	for(long long i=1;i<=n;i++)
		scanf("%lld%lld",&m[i].x,&m[i].y),m[i].id=i;
	for(long long i=1;i<=k;i++)
	{
		X=p[i].x,Y=p[i].y;
	//	sort(m+1,m+1+n,cmp);
	//	for(long long j=1;j<=n;j++) cout<<m[j].x<<" "<<m[j].y<<endl;
	//	cout<<endl;
		for(long long j=1;j<=n;j++)
		{
			for(long long o=1;o<=n;o++)
			{
				if(j==o) continue;			
				if((Y-m[j].y)*(X-m[o].x)==(Y-m[o].y)*(X-m[j].x)&&tc(o,j)&&m[o]<m[j])
					lst[i][m[j].id].push_back(m[o].id)/*,cout<<i<<" "<<m[j].id<<" "<<m[j-1].id<<endl*/;
			}
		}
	}
//	sort(m+1,m+1+n,cmq);
	for(long long i=1;i<=n;i++)
	{
//		cout<<(char)(i+'C')<<endl,;
	//	int i=4;
		v.clear(); v.push_back(i);
		if(dfs(v,k)) ans++;
		for(long long j=1;j<=k;j++) fl[j]=false;
		for(long long j=1;j<=n;j++) sht[j]=false;
	///	cout<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
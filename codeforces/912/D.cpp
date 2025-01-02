// LUOGU_RID: 160484510
#include<iostream>
#include<set>
#include<iomanip>
#include<queue>
using namespace std;

typedef long long ll;

ll n,m,r,k;
struct node {ll x,y,gx;bool operator<(node b) const{return gx<b.gx;}};
set<pair<ll,ll>> s;
int dx[4]={1,-1,0,0};int dy[4]={0,0,1,-1};
priority_queue<node> q;
ll f(ll x,ll y) {return (min(n,x+r-1)-max(x,r)+1)*(min(m,y+r-1)-max(r,y)+1);}

int main()
{
    ll X,Y,ans=0;
	cin>>n>>m>>r>>k;
	X=(n+1)/2;Y=(m+1)/2;
	q.push({X,Y,f(X,Y)});
	s.insert({X,Y});
	while(k--)
    {
		ll x=q.top().x,y=q.top().y;
		ans+=q.top().gx;
		q.pop();
		for(int i=0;i<4;i++)
        {
			ll nx=x+dx[i],ny=y+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s.count({nx,ny})==0)
            {
				s.insert({nx,ny});
				q.push({nx,ny,f(nx,ny)});
			}
		}
	}
	double hh=(n-r+1)*(m-r+1);
	cout<<setprecision(16)<<ans*1.0/(n-r+1)*1.0/(m-r+1)<<endl;
	return 0;
}

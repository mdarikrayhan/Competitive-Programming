#include<bits/stdc++.h>
using namespace std;using ll=long long;using ld=long double;using pii=pair<int,int>;
const int M=998244353;const ll inf=1e17;const double eps=1e-10;
struct S
{
	int n,m,q,S,T,N;ll A,B,C;
	vector<vector<int>>mat;
	void ini()
	{
		cin>>n>>m;mat.resize(n+1,vector<int>(m+1,0));
		for(int i=0;i<n;i++)
		{
			string s;cin>>s;
			for(int j=0;j<m;j++)if(s[j]=='B')mat[i][j]=1;
		}
	}
	void solve()
	{
		int bas=0,mi=0;
		//for(int i=0;i<n;i++,cout<<'\n')for(int j=0;j<m;j++)cout<<mat[i][j];
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)
			mat[i][j]^=mat[i][j+1]^mat[i+1][j]^mat[i+1][j+1],bas+=mat[i][j];
		//for(int i=0;i<n;i++,cout<<'\n')for(int j=0;j<m;j++)cout<<mat[i][j];
		for(int i=0;i<n-1;i++)for(int j=0;j<m-1;j++)
		{
			int cc=mat[i][j]+mat[i][m-1]+mat[n-1][j]+mat[n-1][m-1];
			mi=min(mi,7-cc*2);
		}
		cout<<bas+mi<<'\n';
	}
};
void precal() {}
int main()
{
	//freopen("1.in","r",stdin);
	//cout<<fixed<<setprecision(12);
	ios::sync_with_stdio(0);cin.tie(0);precal();
	int t=1;//cin>>t;
	//clock_t a=clock();
	while(t--){S SS;SS.ini();SS.solve();}
	//cout<<"Time:"<<double(clock()-a)<<'\n';
}
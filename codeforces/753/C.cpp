// LUOGU_RID: 159136447
#include<bits/stdc++.h>
using namespace std;

#define N 10000
#define St 15
vector<int>ans;
string str[N];
int conv[401];
void dfs(int i,int v,string s,int used)
{
	if(i==4)
	{
		str[v]=s;
		if(__builtin_popcount(used)==4)ans.push_back(v);
		return;
	}
	for(int j=0;j<10;j++)dfs(i+1,v*10+j,s+char(j+48),used|(1<<j));
}
void init(){dfs(0,0,"",0),sort(ans.begin(),ans.end()),conv[0]=0,conv[1]=1,conv[2]=2,conv[3]=3,conv[4]=4,conv[10]=5,conv[11]=6,conv[12]=7,conv[13]=8,conv[20]=9,conv[21]=10,conv[22]=11,conv[30]=12,conv[31]=13,conv[40]=14;}

int state(string Q,string A)
{
	int a=0,b=0;
	for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(Q[i]==A[j])
	{
		if(i!=j)b++;
		else a++;
	}
	return conv[a*10+b];
}

double mxE;
int cnt[St],mxv;
double entropy(string q)
{
	double E=0;
	for(int i:ans)cnt[state(q,str[i])]++;
	for(int j=0;j<St;j++)if(cnt[j])
		E-=cnt[j]*1./ans.size()*log2(cnt[j]*1./ans.size()),cnt[j]=0;
	return E;
}

void table()
{
	for(int i=0;i<1e4;i++)
	{
		double E=entropy(str[i]);
		if(E>mxE)mxE=E,mxv=i;
	}
}

string lst;
int A,B;
void sieve(int res)
{
	vector<int>v=ans;
	ans.clear();
	for(int i:v)if(state(lst,str[i])==res)ans.push_back(i);
}

void query(string s)
{
	cout<<(lst=s)<<endl,cout.flush();
	cin>>A>>B;
	if(A==4)exit(0);
	sieve(conv[A*10+B]),mxE=-1e9;
	if(ans.size()==1)mxv=ans.front();
	else for(int i:ans)
	{
		double E=entropy(str[i]);
		if(E>mxE)mxE=E,mxv=i;
	}
}

int main()
{
	init(),query(str[932]);
	while(1)query(str[mxv]);
}
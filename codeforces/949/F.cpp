#include<bits/stdc++.h>
#define N 5250
#define MAC 2000000
#define fo(i,a,b) for(int i=a,E=b;i<=E;i++)
#define ll long long
 
using namespace std;
 
int n,a[N],b[N],top,s[N];
vector<pair<int,int>>pnt;
struct MAP{
	vector<ll> no;
	int n,m;
	void init(int nn){
		n=nn;no.resize(nn);
		m=0;
	}
	void insert(ll x){
		no[m++]=x;if(m==n)sort(no.begin(),no.end());
	}
	int count(ll x){
		return upper_bound(no.begin(),no.end(),x)-lower_bound(no.begin(),no.end(),x);
	}
}M[N];
ll tn(int x,int y){
	if(x==0)return 1ll*MAC*MAC*MAC+13;
	return (1.0*y/x)*MAC*MAC;
}
bool check(int mx,int my){
	int T=lower_bound(pnt.begin(),pnt.end(),make_pair(mx,my))-pnt.begin();
	if(T!=pnt.size()&&pnt[T]==make_pair(mx,my))return 0;
	fo(i,1,n+n){
		int x=s[i];
		ll no=tn(mx-a[x],my-b[x]);
		if(M[x].count(no)!=1)return 0;
	}return 1;
}
 
bool can(int u1,int v1,int u2,int v2){
	ll A1=b[u1]-b[v1],B1=a[v1]-a[u1],C1=1ll*a[v1]*b[u1]-1ll*a[u1]*b[v1];
	ll A2=b[u2]-b[v2],B2=a[v2]-a[u2],C2=1ll*a[v2]*b[u2]-1ll*a[u2]*b[v2];
	if(A1*B2==A2*B1)return 0;
	ll y=(C1*A2-C2*A1)/(B1*A2-B2*A1),x=(C1*B2-C2*B1)/(A1*B2-A2*B1);
	if(abs(x)>1e6 || abs(y)>1e6)return 0;
	if(A1*x+B1*y!=C1 || A2*x+B2*y!=C2)return 0;
	if(check(x,y)){
		printf("Yes\n%I64d %I64d",x,y);return 1;
	}
	return 0;
}
 
int main(){
	srand((int)time(0));rand();
	scanf("%d",&n);
	fo(i,1,n+n)scanf("%d %d",&a[i],&b[i]),s[i]=i,pnt.push_back(make_pair(a[i],b[i]));
	sort(pnt.begin(),pnt.end());
	random_shuffle(s+1,s+n+1);
	for(int i=1;i<=n+n;++i)M[i].init(n+n-1);
	fo(i,1,n+n){
		int t=0;
		fo(j,1,n+n)if(i!=j)M[i].insert(tn(a[i]-a[j],b[i]-b[j]));
	}
	fo(i,3,n+n)fo(j,3,n+n)if(i!=j && can(s[1],s[i],s[2],s[j]))return 0;
	fo(i,4,n+n)if(can(s[1],s[2],s[3],s[i]))return 0;
	printf("No");
}
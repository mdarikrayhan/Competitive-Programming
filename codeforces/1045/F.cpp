// LUOGU_RID: 160013308
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+5;
struct pt{int x,y;}p[maxn],P[maxn];
pt operator -(pt a,pt b){return {a.x-b.x,a.y-b.y};}
int operator ^(pt a,pt b){return a.x*b.y-a.y*b.x;}
bool operator <(pt a,pt b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int n,tp=0,ex[maxn],s[maxn],S[maxn];
void calc(){
	int m=0;tp=0;
	for(int i=1;i<=n;i++)if(!ex[i])P[++m]=p[i];
	for(int i=1;i<=m;i++){
		while(tp>1&&((P[s[tp]]-P[s[tp-1]])^(P[i]-P[s[tp-1]]))<=0)--tp;
		s[++tp]=i;
	}
	int cur=tp;
	for(int i=m-1;i>=1;i--){
		while(tp>cur&&((P[s[tp]]-P[s[tp-1]])^(P[i]-P[s[tp-1]]))<=0)--tp;
		s[++tp]=i;
	}
	for(int i=1;i<=tp;i++)if(P[s[i]].x%2||P[s[i]].y%2){
		cout<<"Ani"<<endl;
		exit(0);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
	p[++n]={0,0};
	sort(p+1,p+n+1);
	calc();
	int t=tp;
	for(int i=1;i<=t;i++)S[i]=s[i];
	for(int i=2;i<t;i+=2)ex[S[i]]=1;
	calc();
	for(int i=2;i<t;i+=2)ex[S[i]]=0;
	for(int i=3;i<t;i+=2)ex[S[i]]=1;
	calc();
	cout<<"Borna"<<endl;
	return 0;
}

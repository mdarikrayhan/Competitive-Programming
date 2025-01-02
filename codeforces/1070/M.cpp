#include<bits/stdc++.h> 
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define max(a,b) (a>b?a:b) 
#define min(a,b) (a<b?a:b)
typedef long long ll;
using namespace std;
inline int read(){
	int n=0,f=1;char c;
	for(c=getchar();c!='-'&&(c<'0'||c>'9');c=getchar());
	if (c=='-') c=getchar(),f=-1;
	for(;c>='0'&&c<='9';c=getchar()) n=n*10+c-48;
	return n*f;
}
struct ar{int x,y,id,d;}now;
bool operator <(ar a,ar b){return a.x==b.x?a.y<b.y:a.x<b.x;}
typedef vector<ar> vt;
int i,a,b,d[3005];
vt p,an;
bool cmp(ar a,ar b){return a.x*b.y>a.y*b.x;}
void solve(vt p){
	int i,j,k,D,n=p.size()-1;
	if (!n) return;
	fo(i,1,n) if (p[i]<p[0]) swap(p[i],p[0]);
	fo(i,1,n) p[i].x-=p[0].x,p[i].y-=p[0].y;
	sort(p.begin()+1,p.end(),cmp);
	fo(i,1,n) p[i].x+=p[0].x,p[i].y+=p[0].y;
	if (p[0].d<0){
		fo(i,1,n){
			j=i,D=0;
			for(;;i++){
				D+=p[i].d;
				if (D>=0) break;
			}
			p[i].d--,an.push_back((ar){p[i].id,p[0].id});
			p[i].d-=D;
			solve(vt(p.begin()+j,p.begin()+i+1));
			p[j=i].d=D-1;
			for(;D;) D+=p[++i].d;
			solve(vt(p.begin()+j,p.begin()+i+1));
		}return;
	}
	for(i=1;p[0].d>=0;){
		for(j=i,D=1;D;i++) D+=p[i].d;
		p[0].d--,an.push_back((ar){p[0].id,p[i-1].id});
		solve(vt(p.begin()+j,p.begin()+i));
	}
	solve(vt(p.begin()+i-1,p.end()));
}
void work(){
	a=read(),b=read();
	fo(i,1,b) d[i]=read();
	p.clear(),an.clear();
	fo(i,1,a+b){
		now.x=read(),now.y=read();
		if (i<=a) now.id=i,now.d=-1;
		else now.d=d[now.id=i-a]-1;
		p.push_back(now);
	}
	solve(p);
	puts("YES");
	fo(i,0,a+b-2) printf("%d %d\n",an[i].x,an[i].y);
}
int main(){
	for(int t=read();t--;) work();
}
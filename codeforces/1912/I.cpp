//Δ_I
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
const DB PI = acos(-1.0);
struct node{
	int x,y;
	node(int X=0,int Y=0){
		x=X,y=Y;
	}
}a[N];
node operator-(node a,node b){
	return node(a.x-b.x,a.y-b.y);
}
LL G(node a,node b){
	return (LL)a.x*b.y-(LL)a.y*b.x;
}
LL S(int i,int j,int k){
	return abs(G(a[j]-a[i],a[k]-a[i]));
}
int n,m;
LL s;
DB f[N],g[N],h[N];
pair<DB,int> e[N*3];
int main(){
	int T,i,j,k,o;
	LL t,w,x,y,z;
	DB p,q,r;
	node c,d;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&s);
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		s*=2;
		i=0,j=1,t=0;
		while(1){
			while(1){
				w=S(i,j,(j+1)%n);
				if(t+w<=s)
					t+=w,j=(j+1)%n;
				else
					break;
			}
			w=S(i,j,(j+1)%n);
			r=(DB)(s-t)/w;
			c=a[j]-a[i];
			d=a[(j+1)%n]-a[j];
			p=c.x+r*d.x;
			q=c.y+r*d.y;
			f[i]=atan2(q,p);
			if(i==n-1)
				break;
			t-=S(i,i+1,j);
			i++;
		}
		i=n-1,j=n-2,t=0;
		while(1){
			while(1){
				w=S(i,j,(j+n-1)%n);
				if(t+w<=s)
					t+=w,j=(j+n-1)%n;
				else
					break;
			}
			w=S(i,j,(j+n-1)%n);
			r=(DB)(s-t)/w;
			c=a[j]-a[i];
			d=a[(j+n-1)%n]-a[j];
			p=c.x+r*d.x;
			q=c.y+r*d.y;
			g[i]=atan2(-q,-p);
			if(i==0)
				break;
			t-=S(i,i-1,j);
			i--;
		}
		for(i=0;i<n;i++){
			c=a[i]-a[(i+n-1)%n];
			h[i]=atan2(c.y,c.x);
		}
		m=0;
		for(i=0;i<n;i++){
			//cout<<i<<' '<<f[i]<<' '<<g[i]<<' '<<h[i]<<endl;
			e[++m]=make_pair(f[i],1);
			e[++m]=make_pair(g[i],2);
			e[++m]=make_pair(h[i],3);
		}
		sort(e+1,e+m+1);
		e[0]=make_pair(-PI,0);
		e[m+1]=make_pair(PI,0);
		for(i=0;i<n;i++)
			if(h[i]>h[(i+1)%n])
				k=i;
		for(i=k;f[i]<g[i];i=(i+n-1)%n);
		i=(i+1)%n;
		for(j=k;f[j]<g[j];j=(j+1)%n);
		j=(j+n-1)%n;
		z=0,x=0,y=0;
		for(o=i;o!=(j+1)%n;o=(o+1)%n)
			z++,x+=a[o].x,y+=a[o].y;
		r=0;
		for(o=1;o<=m+1;o++){
			p=e[o-1].first;
			q=e[o].first;
			r+=(x-z*a[k].x)*(cos(q)-cos(p))/z;
			r+=(y-z*a[k].y)*(sin(q)-sin(p))/z;
			//cout<<e[o-1].first<<' '<<i<<' '<<k<<' '<<j<<endl;
			if(e[o].second==1){
				z--,x-=a[i].x,y-=a[i].y;
				i=(i+1)%n;
			}
			if(e[o].second==2){
				j=(j+1)%n;
				z++,x+=a[j].x,y+=a[j].y;
			}
			if(e[o].second==3){
				k=(k+1)%n;
			}
		}
		printf("%.12lf\n",r/PI/2);
	}
	return 0;
}
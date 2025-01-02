#include<bits/stdc++.h>
using namespace std;
struct apple{
	int l,d,wz;
	bool operator<(const apple &other)const{
		return d<other.d;
	}
}e[100005];
long long f[100005][2][2];
pair<int,int>p[100005][2][2];
int q[100005][2][2];
map<int,pair<int,int>>mp;
int cunz(int x){
	return mp.find(x)!=mp.end();
}
void gx(int i,int jj,int ll,int j,int l,int z,int zz){
	if(f[i+1][jj][ll]<f[i][j][l]+z){
		f[i+1][jj][ll]=f[i][j][l]+z;
		p[i+1][jj][ll]=make_pair(j,l);
		q[i+1][jj][ll]=zz;
	}
}
vector<pair<int,int>>an;
void jia(int x,int y){
	if(y==1){
		an.emplace_back(e[x].wz,mp[e[x].d-1].second);
	}else{
		an.emplace_back(e[x].wz,mp[e[x].d].second);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int M=1000000001;
	for(int i=1;i<=n;++i){
		int c,s;
		scanf("%d%d",&c,&s);
		s=M-s;
		mp[s]=make_pair(c,i);
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&e[i].l,&e[i].d);
		e[i].d=M-e[i].d;
		e[i].wz=i;
	}
	sort(e+1,e+m+1);
	memset(f,-63,sizeof(f));
	f[1][cunz(e[1].d-1)][cunz(e[1].d)]=0;
	e[m+1].d=1e9+9;
	for(int i=1;i<=m;++i){
		for(int j=0;j<2;++j)for(int l=0;l<2;++l){
			if(f[i][j][l]<-1e18)continue;
			int jj=(e[i+1].d==e[i].d?j:e[i+1].d==e[i].d+1?l:cunz(e[i+1].d-1));
			int ll=(e[i+1].d==e[i].d?l:cunz(e[i+1].d));
			gx(i,jj,ll,j,l,0,0);
			if(j&&e[i].l>=mp[e[i].d-1].first){
				int dj=mp[e[i].d-1].first;
				int jj=(e[i+1].d==e[i].d?0:e[i+1].d==e[i].d+1?l:cunz(e[i+1].d-1));
				int ll=(e[i+1].d==e[i].d?l:cunz(e[i+1].d));
				gx(i,jj,ll,j,l,dj,1);
			}
			if(l&&e[i].l>=mp[e[i].d].first){
				int dj=mp[e[i].d].first;
				int jj=(e[i+1].d==e[i].d?j:e[i+1].d==e[i].d+1?0:cunz(e[i+1].d-1));
				int ll=(e[i+1].d==e[i].d?0:cunz(e[i+1].d));
				gx(i,jj,ll,j,l,dj,2);
			}
		}
	}
	printf("%lld\n",f[m+1][0][0]);
	int I=m+1,J=0,L=0;
	while(I>1){
		if(q[I][J][L])jia(I-1,q[I][J][L]);
		auto au=p[I][J][L];
		--I;J=au.first,L=au.second;
	}
	printf("%d\n",(signed)an.size());
	for(auto pi:an)printf("%d %d\n",pi.first,pi.second);
	return 0;
}
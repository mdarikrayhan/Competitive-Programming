#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
long long H[609];
int pa[609],qry,hd[609],to[1209],nxt[1209],k,co[609],vv[609][609];
void l(int u,int v) {
	to[++k]=v;nxt[k]=hd[u];hd[u]=k;
}
std::unordered_map<long long,int> v;
std::set<int> mg(std::set<int> x,std::set<int> y) {
	for(auto it=y.begin();it!=y.end();it++) x.insert(*it);
	return x;
}
int qr(std::set<int> x) {
	if(x.size()<=1) return 0; 
	long long qq=0;
	for(auto it=x.begin();it!=x.end();it++) {
		qq^=H[*it];
	}
	if(v.find(qq)!=v.end()) return v[qq];
/*	int as=0;
	for(auto it=x.begin();it!=x.end();it++) {
		for(auto it2=x.find(*it);it2!=x.end();it2++) {
			as+=vv[*it][*it2];
		}
	}
	qry++;
	return v[qq]=as;*/
	printf("? %d\n",(signed)x.size());
	for(auto it=x.begin();it!=x.end();it++) {
		printf("%d ",*it);
	}
	printf("\n");fflush(stdout);int tp;
	scanf("%d",&tp);
	if(tp==-1) exit(0);
	return v[qq]=tp;
}
int yb(std::set<int> x,std::set<int> y) {
	if(x.empty()||y.empty()) return 0;
	return (qr(mg(x,y))-qr(x)-qr(y));
}
std::set<int> fd(std::set<int> x,std::set<int> y,int tp) {
	if(tp==-1) tp=yb(x,y);
	std::set<int> ans;
	if(tp==0) return ans;
	if(x.size()==1) {
		ans.insert(*x.begin());
		return ans;
	}
	std::set<int> aq1,aq2;
	tp=x.size()/2;int ct=0;
	for(auto it=x.begin();it!=x.end();it++) {
		ct++;
		if(ct<=tp) aq1.insert(*it);
		else aq2.insert(*it);
	}
	std::set<int> a1=fd(aq1,y,-1);
	std::set<int> a2=fd(aq2,y,yb(x,y)-yb(aq1,y));
	return mg(a1,a2);
}
int gt(std::set<int> x,std::set<int> y,int tp) {
	if(tp==-1) tp=yb(x,y);
	if(tp==0) return 0;
	if(y.size()==1) {
		return (*y.begin());
	}
	std::set<int> aq1,aq2;
	tp=y.size()/2;int ct=0;
	for(auto it=y.begin();it!=y.end();it++) {
		ct++;
		if(ct<=tp) aq1.insert(*it);
		else aq2.insert(*it);
	}
	int tq=gt(x,aq1,-1);
	if(tq) return tq;
	return gt(x,aq2,yb(x,y)-yb(x,aq1));
}
void dfs(int n,int f) {
	pa[n]=f;
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		dfs(to[i],n);
	}
}
int N;
signed main(void) {
	srand(time(NULL));
	//N=599;int p[609];
	scanf("%d",&N);
	/*for(int i=1;i<=N;i++) {
		p[i]=i;
	}
	std::random_shuffle(p+1,p+N+1);
	for(int i=1;i<N;i++) {
		vv[p[i]][p[i+1]]=1;
		vv[p[i+1]][p[i]]=1;
	}
	vv[p[1]][p[N]]=1;
	vv[p[N]][p[1]]=1;*/
	for(int i=1;i<=N;i++) {
		for(int j=0;j<60;j++) {
			if(rand()&1) H[i]^=(1ll<<j);
		}
	}
	std::set<int> s0,s1,s2,nw0,nw1;
	nw0.insert(1);
	s0.insert(1);
	for(int i=2;i<=N;i++) s2.insert(i);
	while(!s2.empty()) {
		std::set<int> s3=fd(s2,mg(nw0,nw1),-1),ss0,ss1;
		for(auto it=s3.begin();it!=s3.end();it++) {
			std::set<int> tp;tp.insert(*it);
			int f1=gt(tp,mg(nw0,ss0),-1);
			int f2=gt(tp,mg(nw1,ss1),yb(tp,mg(mg(nw0,ss0),mg(nw1,ss1)))-yb(tp,mg(nw0,ss0)));
			if(f1&&f2) {
				std::vector<int> vc;
				dfs(f1,0);
				int tp=f2;
				while(tp!=f1) {
					vc.push_back(tp);tp=pa[tp];
				} 
				vc.push_back(f1);
				vc.push_back(*it);
				printf("N %d\n",(signed)vc.size());
				for(int i=0;i<vc.size();i++) printf("%d ",vc[i]);
				fflush(stdout);
			//	printf("\n%d",qry);
				return 0;
			}
			if(f1) ss1.insert(*it),s1.insert(*it),l(f1,*it),l(*it,f1);
			else ss0.insert(*it),s0.insert(*it),l(f2,*it),l(*it,f2);
			s2.erase(*it);
		}
		nw0=ss0,nw1=ss1;
	}
	printf("Y %d\n",(signed)s0.size());
	for(auto it=s0.begin();it!=s0.end();it++) printf("%d ",(*it));
	fflush(stdout);
	//printf("\n%d",qry);
}
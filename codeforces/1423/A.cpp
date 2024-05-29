#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define SZ(x) ((int)(x).size())
using namespace std;
const int N=1005;
int n,who[N],a[N][N];
bool ban[N][N];
deque<int>pref[N];
void GG(){puts("-1"),exit(0);}
void clip(int k1){
	while(SZ(pref[k1])&&ban[k1][pref[k1].front()])pref[k1].pop_front();
	while(SZ(pref[k1])&&ban[k1][pref[k1].back()])pref[k1].pop_back();
	if(!SZ(pref[k1]))GG();
}
void del(int k1,int k2){
	ban[k1][k2]=ban[k2][k1]=1;
}
void add(int k1,int k2){
	who[k2]=k1;
	while(1){
		D("add\n");
		clip(k2);
		if(pref[k2].back()!=k1)del(pref[k2].back(),k2);
		else break;
	}
}
void work1(){ // find a stable table
	queue<int>q;
	rep(i,1,n)q.push(i);
	while(SZ(q)){
		int k1=q.front();
		D("work1 %d\n",k1);
		q.pop();
		while(1){
			D("doing\n");
			clip(k1);
			int k2=pref[k1].front(),k3=who[k2];
			if(k3&&a[k2][k3]<a[k2][k1]){del(k1,k2);continue;}
			if(k3){who[k2]=0,q.push(k3);}
			add(k1,k2);
			break;
		}
	}
}
int nex(int k1){
	clip(k1);
	int k2=pref[k1].front();pref[k1].pop_front();
	clip(k1);
	pref[k1].push_front(k2);
	return who[pref[k1][1]];
}
void work2(){
	int cur=1;
	while(1){
		D("work2\n");
		for(;cur<=n;++cur){
			clip(cur);
			if(SZ(pref[cur])>1)break;
		}
		if(cur>n){
			rep(i,1,n)printf("%d\n",pref[i].front());
			puts("");
			//puts("OK");
			exit(0);
		}
		vector<int>cyc,CYC;
		{
			int k1=cur,k2=cur;
			do k1=nex(k1),k2=nex(nex(k2));while(k1!=k2);
			do cyc.PB(k2),k2=nex(k2);while(k1!=k2);
		}
		for(auto k1:cyc){
			int k2=pref[k1][0];
			CYC.PB(k2);
			who[k2]=0;
			del(k1,k2);
		}
		rep(i,0,SZ(cyc)-1){
			add(cyc[i],CYC[(i+1)%SZ(CYC)]);
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	if(n&1)GG();
	rep(i,1,n){
		rep(j,1,n)if(i!=j)scanf("%d",&a[i][j]),pref[i].PB(j);
		sort(pref[i].begin(),pref[i].end(),[&](int k1,int k2){return a[i][k1]<a[i][k2];});
	}
	work1();
	work2();
	return 0;
}
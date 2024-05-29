// LUOGU_RID: 160513715
#include <bits/stdc++.h>
using namespace std;
const int N=60;
typedef long long ll;

ll T;
int n,m;
vector<int> a;
vector<pair<pair<int,int>,pair<int,int> > > ans;

void ins(int x,int y,bool tp) {
	if(x<0 || y<0 || x>n || y>m) return ;
	if(tp) {
		if(x+1>n) return ;
		ans.push_back({{x,y},{x+1,y}});
	}
	else {
		if(y+1>m) return ;
		ans.push_back({{x,y},{x,y+1}});
	}
}

void inss(int x,int y,int tp) {
	ins(x,y,tp),ins(y,x,!tp);
}

int main() {
	scanf("%lld",&T);
	while(T) a.push_back(T%6),T/=6;
	reverse(a.begin(),a.end());
	n=m=a.size()+1<<1;
	inss(1,2,1);
	for(int i=0;i<a.size();i++) {
		inss(2+i*2,4+i*2,0),inss(3+i*2,4+i*2,0),inss(1+i*2,5+i*2,0),inss(2+i*2,5+i*2,0);
		a[i]=8-a[i];
		if(a[i]>=6) a[i]-=6,inss(1+i*2,3+i*2,1);
		else if(a[i]>=3) a[i]-=3,ins(1+i*2,3+i*2,1);
		if(a[i]==2) inss(1+i*2,4+i*2,1);
		else if(a[i]==1) ins(1+i*2,4+i*2,1);
	}
	printf("%d %d\n",n,m);
	printf("%d\n",ans.size());
	for(auto i:ans) printf("%d %d %d %d\n",i.first.first,i.first.second,i.second.first,i.second.second);
	return 0;
}

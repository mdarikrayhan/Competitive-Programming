#include<bits/stdc++.h>
using namespace std;
const int maxn=75005,B=200;
int n,s,t,st,T=120;
int cnt[maxn<<1],pos[maxn<<1];
mt19937 rnd(time(0));
map< int,vector<int> >mp;
int query(int x,int y){
	int res;
	printf("? %d %d\n",x,y),fflush(stdout),scanf("%d",&res);
	return res;
}
int main(){
	scanf("%d",&n),s=rnd()%n+1,t=rnd()%n+1;
	while(T--){
		mp.clear();
		for(int i=1;i<=B;i++){
			int x=rnd()%n+1;
			mp[query(s,x)-query(t,x)].push_back(x);
		}
		int sum=0,flg=0;
		for(map< int,vector<int> >::iterator it=mp.begin();it!=mp.end();it++){
			if((it->second.size())>B/2){
				((sum*2>(B-it->second.size()))? t:s)=it->second[0];
				break;
			}
			sum+=it->second.size();
		}
	}
	st=query(s,t);
	for(int i=1;i<=n;i++){
		int a=query(s,i),b=query(t,i);
		if(a+b==st)
			pos[a-b+n]=i;
		cnt[a-b+n]++;
	}
	int sum=0;
	for(int i=0;i<=n+n;i++){
		sum+=cnt[i];
		if(sum>n/2){
			printf("! %d\n",pos[i]),fflush(stdout);
			return 0;
		}
	}
	return 0;
}
// LUOGU_RID: 158899656
#include<bits/stdc++.h>
using namespace std;
int cnt,t[8];
map<string,int> mp;
struct pl{
	int sc,win,in;
	string s;
}p[10];
bool cmp(pl a,pl b){
	if(a.sc!=b.sc)return a.sc>b.sc;
	if(a.in!=b.in)return a.in>b.in;
	if(a.win!=b.win)return a.win>b.win;
	return a.s<b.s;
}
signed main(){
	for(int i=1;i<=5;i++){
		string a,b;
		cin >> a >> b;
		if(!mp[a]) mp[a]=++cnt;
		if(!mp[b]) mp[b]=++cnt;
		t[mp[a]]++;
		t[mp[b]]++;
		int t1,t2;
		scanf("%d:%d",&t1,&t2);
		if(t1>t2) p[mp[a]].sc+=3;
		else if(t1<t2) p[mp[b]].sc+=3;
		else{
			p[mp[a]].sc++;
			p[mp[b]].sc++;
		}
		p[mp[a]].in+=t1-t2;p[mp[b]].in+=t2-t1;
		p[mp[a]].win+=t1;p[mp[b]].win+=t2;
		p[mp[a]].s=a;p[mp[b]].s=b;
	}
	string a,b;
	a="BERLAND";
	for(int i=1;i<=cnt;i++){
		if(t[i]==2&&p[i].s!="BERLAND") b=p[i].s;
	}
	p[mp[a]].sc+=3;
	for(int q=1;q<=99;q++){
		for(int i=q;i<=99;i++){
			int j=i-q;
			for(int k=1;k<=cnt;k++){
				if(p[k].s==a){
					p[k].in+=i-j;
					p[k].win+=i;
				}if(p[k].s==b){
					p[k].in+=j-i;
					p[k].win+=j;
				}
			}
			sort(p+1,p+cnt+1,cmp);
//			if(i==7&&j==0){
//				for(int k=1;k<=cnt;k++){
//					cout<<p[k].sc<<" "<<p[k].in<<" "<<p[k].win<<" "<<p[k].s<<"\n";
//				}
//			}
			if(p[2].s==a||p[1].s==a){
				cout<<i<<":"<<j;
				return 0;
			}
			for(int k=1;k<=cnt;k++){
				if(p[k].s==a){
					p[k].in-=i-j;
					p[k].win-=i;
				}if(p[k].s==b){
					p[k].in-=j-i;
					p[k].win-=j;
				}
			}
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}
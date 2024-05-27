#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+100;

int n;
int s[maxn],t[maxn];

struct P{
	int id,s,t,d;
}p[maxn];

vector<pair<pair<int,int>,int> > ans;

bool cmp1(P x,P y){return x.s<y.s;}
bool cmp2(P x,P y){return x.d==y.d?x.s<y.s:x.d<y.d;}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].s;
		p[i].id=i;
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	sort(t+1,t+1+n);
	sort(p+1,p+1+n,cmp1);
	long long ok=0;
	for(int i=1;i<=n;i++){
		ok+=p[i].s-t[i];
		p[i].t=t[i];
		p[i].d=p[i].s-t[i];
	}
	if(ok) return cout<<"NO"<<endl,0;
//	else cout<<"YES"<<endl;
//	sort(p+1,p+1+n,cmp2);
	int l=1;while(p[l].d<=0&&l<=n) l++;
	for(int i=1;i<=n;i++){
		int d=-p[i].d;
		if(!d) continue;
		while(p[l].d<=0&&l<=n) l++;
		if(d<0||l>n) return cout<<"NO"<<endl,0;
		while(d){
			while(p[l].d<=0&&l<=n) l++;
			if(l>n) return cout<<"NO"<<endl,0;
			int del=min(d,p[l].d);
			p[l].d-=del;d-=del;
			ans.push_back({{p[i].id,p[l].id},del});
		}
	}
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	for(auto tmp:ans){
		cout<<tmp.first.first<<" "<<tmp.first.second<<" "<<tmp.second<<endl;
	}
	
	
	return 0;
}
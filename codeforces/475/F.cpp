// LUOGU_RID: 158971110
#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;

struct c1{bool operator()(pii x,pii y)const{return x.fi==y.fi?x.se<y.se:x.fi<y.fi;}};
struct c2{bool operator()(pii x,pii y)const{return x.se==y.se?x.fi<y.fi:x.se<y.se;}};
struct Set{
	set<pii,c1> s1;
	set<pii,c2> s2;
	void erase(const pii& x){s1.erase(x),s2.erase(x);}
	void insert(const pii& x){s1.insert(x),s2.insert(x);}
};
int solve(Set& s){
	auto i1=s.s1.begin();
	auto i2=s.s1.rbegin();
	auto i3=s.s2.begin();
	auto i4=s.s2.rbegin();
	auto E=--s.s1.end();
	for(;i1!=E;++i1,++i2,++i3,++i4){
		if(i1->fi<=next(i1)->fi-2){
			Set t;
			for(auto it=s.s1.begin(),E=next(i1);it!=E;) t.insert(*it),s.erase(*it++);
			return solve(t)+solve(s);
		}
		if(i2->fi>=next(i2)->fi+2){
			Set t;
			vector<pii> er;
			for(auto it=s.s1.rbegin(),E=next(i2);it!=E;) t.insert(*it),er.pb(*it++);
			for(auto p:er) s.erase(p);
			vector<pii>().swap(er);
			return solve(t)+solve(s);
		}
		if(i3->se<=next(i3)->se-2){
			Set t;
			for(auto it=s.s2.begin(),E=next(i3);it!=E;) t.insert(*it),s.erase(*it++);
			return solve(t)+solve(s);
		}
		if(i4->se>=next(i4)->se+2){
			Set t;
			vector<pii> er;
			for(auto it=s.s2.rbegin(),E=next(i4);it!=E;) t.insert(*it),er.pb(*it++);
			for(auto p:er) s.erase(p);
			vector<pii>().swap(er);
			return solve(t)+solve(s);
		}
	}
	return 1;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	Set s;
	int n,x,y;cin>>n;
	for(int i=1;i<=n;i++) cin>>x>>y,s.insert({x,y});
	cout<<solve(s)<<'\n';
	return 0;
}
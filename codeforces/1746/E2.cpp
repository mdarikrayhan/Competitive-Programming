#include<bits/stdc++.h>
using namespace std;
vector<int>sbstr(vector<int>v,int s,int sz){
	vector<int>ret;
	for(int i=s;i<s+sz;i++) ret.push_back(v[i]);
	return ret;
}
void findans(int x){
	cout<<"! "<<x<<'\n';
	fflush(stdout);
	string s;
	cin>>s;
	if(s==":)") exit(0);
}
bool Q(vector<int>v){
	cout<<"? "<<v.size()<<' ';
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
	fflush(stdout);
	string s;
	cin>>s;
	if(s=="YES") return 1;
	else return 0;
}
vector<int>merge(vector<int>v,vector<int>g) {
	while(g.size()) v.push_back(g.back()),g.pop_back();
	return v;
}
void dfs(vector<int>v,vector<int>g) {
	if(v.size()+g.size()<3){
		while(v.size()) findans(v.back()),v.pop_back();
		while(g.size()) findans(g.back()),g.pop_back();
		return;
	}int i=v.size(),j=g.size(),k,l;
	if(i%2==0&&j%2==0) k=i/2,l=j/2;
	if(i%2==0&&j%2) k=i/2+1,l=j/2;
	if(i%2&&j%2==0) k=i/2,l=j/2;
	if(i%2&&j%2) k=i/2,l=(j+1)/2;
	if(Q(merge(sbstr(v,0,k),sbstr(g,0,l)))) dfs(merge(sbstr(v,0,k),sbstr(g,0,l)),sbstr(v,k,v.size()-k));
	else dfs(merge(sbstr(v,k,v.size()-k),sbstr(g,l,g.size()-l)),sbstr(v,0,k));
}
main() {
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++)
		v.push_back(i+1);
	dfs(v,{});
	return 0;
}
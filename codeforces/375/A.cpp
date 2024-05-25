#include <bits/stdc++.h>
using namespace std;

int calc(string&s){
	int mod=0;
	for(char c:s){
		mod=(mod*10+c-'0')%7;
	}
	return mod;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s,cur,pt="1689";
	bool vis[4]={};
	cin>>s;
	for(char c:s){
		int x=pt.find(c);
		if(x!=-1&&!vis[x]){
			vis[x]=true;
			continue;
		}
		cur.push_back(c);
	}
	int mod=1,val=calc(cur);
	for(int i=0;i+4<s.size();i++){
		mod=(mod*10)%7;
	}
	do{
		int x=stoi(pt);
		if((x*mod+val)%7==0){
			cout<<pt<<cur;
			return 0;
		}
	}while(next_permutation(pt.begin(),pt.end()));

}
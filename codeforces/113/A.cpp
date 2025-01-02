#include<bits/stdc++.h>
using namespace std;
bool f[100005];//1 男 0 女 
int xmd[100005];//1 形容 2 名 3 动 
string ww[6]={"lios","etr","initis","liala","etra","inites"};
int cnt;
int main(){
	string s; 
	while(cin>>s){
		cnt++;
		bool flag=0;
		for(int i=0;i<6;i++){
			bool flag1=0;
			for(int j=0;j<ww[i].size();j++){
				if(s[s.size()-ww[i].size()+j]!=ww[i][j])flag1=1;
			}
			if(!flag1){
				if(i>2) f[cnt]=1;
				else f[cnt]=0;
				xmd[cnt]=i%3+1;
				flag=1;
			}
		}
		if(!flag){
			cout<<"NO";
			return 0;
		}
	}
	if(cnt==1) cout<<"YES";
	else{
		for(int i=2;i<=cnt;i++){
			if(f[i]!=f[1]){
				cout<<"NO";
				return 0;
			}
		}
		int i;
		for(i=1;i<=cnt;i++){
			if(xmd[i]!=1) break;
		}
		if(xmd[i]!=2){
			cout<<"NO";
			return 0;
		}
		for(i=i+1;i<=cnt;i++){
			if(xmd[i]!=3){
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
	}
	return 0;
} 
  	 	    				   		   		  			  	
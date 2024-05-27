// LUOGU_RID: 159737343
#include<bits/stdc++.h>
using namespace std;
bool isdight(char ch){
	return (ch>='0'&&ch<='9');
}
int main(){
	string s,T,st;
	getline(cin,T);
	for(int i=0;i<T.size();i++){
		if(T[i]!=' '){
			st+=T[i];
		}else if(isdight(T[i-1])&&i>0){
			int r=i,f=0;
			while(r<T.size()){
				if(isdight(T[r])){
					f=1;
					break;
				}
				if(T[r]!=' '){
					break;
				}
				r++;
			}
			if(f==1){
				st+=T[i];
			}
		}
	}
	s=st;
	int add=0;
	for(int i=0;i<st.size();i++){
		if(st[i]==','&&st[i+1]!=' '&&i<st.size()-1){
			add++;
			s.insert(i+add," ");
		}
		if(st[i]=='.'&&st[i+1]=='.'&&st[i+2]=='.'){
			if(i>0&&st[i-1]!=' '&&s[i+add-1]!=' '){
				s.insert(i+add," ");
				add++;
			}
			i+=2;
		}
	}
	cout<<s;
}
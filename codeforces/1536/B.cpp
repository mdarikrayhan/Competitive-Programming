#include<bits/stdc++.h>
using namespace std;
string rev(int i){
	if(i==0)return "";
	else return rev((i-1)/26)+(char)((i-1)%26+'a');
}
int main(){
	int n,t;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>s;
		for(int i=1;;i++){
			if(s.find(rev(i))==s.npos){
				cout<<rev(i)<<endl;
				break;
			}
		}
	}
}
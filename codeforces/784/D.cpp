// LUOGU_RID: 160585323
#include<iostream>
#include<cstring>
using namespace std;
char fz[13]={'8','x','x','3','6','9','4','7','0','5'};
int main(){
	string n;
	cin>>n;
	int l=n.length();
	for(int i=0;i<l/2+1;i++){
		if(n[l-i-1]!=fz[n[i]-'0']){
			cout<<"No";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}

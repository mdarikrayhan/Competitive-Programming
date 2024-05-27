#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	int ans=0,j,len=str.size();
	for(int i=0;i<len;i=j){
		for(j=i+1;j<len;j++)
			if(str[j]!='0')
				break;
		if(j-i>i||(j-i==i&&str[i]>str[0]))
			ans=1;
		else
			ans++;
	}
	cout<<ans;
}

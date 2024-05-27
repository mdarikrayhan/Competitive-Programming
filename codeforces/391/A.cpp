// LUOGU_RID: 157293875
#include <bits/stdc++.h>
using namespace std;
char st[101];
int main(){
	gets(st);
	int sum=1,ans=0;
	for(int i=0;i<strlen(st);i++){
		if(st[i]==st[i+1]) {
			sum++;
		}
		else{
			if(sum%2==0){
				ans++;
				sum=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
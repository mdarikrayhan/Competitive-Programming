// LUOGU_RID: 158674871
#include <bits/stdc++.h>
using namespace std;
int n,cntd,cntr,d,r;
char c[200005],cc;
queue<char> q;
int main(){
	scanf("%d",&n);
	scanf(" %s",c+1);
	for(int i=1;i<=n;i++){
		if(c[i]=='D') d++;
		else r++;
		q.push(c[i]);
	}
	while(d&&r){
		cc=q.front();
		q.pop();
		if(cc=='D'&&cntd){
			cntd--;
			continue;
		} 
		if(cc=='R'&&cntr){
			cntr--;
			continue;
		}
		if(cc=='R'){
			d--;
			cntd++;
		}
		if(cc=='D'){
			r--;
			cntr++;
		}
		q.push(cc);
	}
	//djdahfdshjfhs
	printf("%c",r?'R':'D');
	return 0;
}
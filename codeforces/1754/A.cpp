#include<bits/stdc++.h>
using namespace std;
int main(){

	int t,n,q;
	char c;
	cin>>t;
	while(t--){
		cin>>n;
		q=0;
		while(n--){
			cin>>c;
			if(c=='Q')q++;
			else if(q>0)q--;
		}
		cout<<(q?"No\n":"Yes\n");
	}
}
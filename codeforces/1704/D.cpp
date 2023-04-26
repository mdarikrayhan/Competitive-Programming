#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	for(cin >> n;cin >> n >> m;)
		for(long long i=0,tmp=0,la,stp=0;i<n;++i,tmp=0){
			for(int j=0;j<m;++j){
				cin >> x;
				tmp+=x*j;
			}
			if(!i||stp)
				la=tmp;
			else if(la!=tmp){
				cout << (la<tmp?i+1:1) << " " << abs(la-tmp) << "\n";
				stp=1;
			}
		}
}
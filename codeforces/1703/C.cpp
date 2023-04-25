#include <iostream>
using namespace std;

char ss[51];
int aa[101];

int main() {
	int Tcs,nn;
	cin>>Tcs;
	while(Tcs--) {
		cin>>nn;
		for(int i=0; i<nn; ++i)
			cin>>aa[i];
		for(int i=0,b; i<nn; ++i) {
			cin>>b>>ss;
			int up=0;
			for(int j=0; ss[j]; ++j)
				up+=ss[j]=='U'?1:-1;
			cout<<(aa[i]+100000-up)%10<<' ';
		}
		cout<<endl;
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 int main(){
	int n,m;
	cin>>n>>m;
	vector<int> x(n);
	for(int &xi:x) cin>>xi;
	sort(x.rbegin(),x.rend());
	int i=0;
	while(i<n&&x[i]*(i+1)<=m) ++i;
	vector<bool> used(m+1,false);
	if(i<n){
		cout<<"Bernardo"<<endl;
		while(n--){
			int y,a;
			cin>>y>>a;
			int b=a;
			for(int j=x[i];j<= m;j+=x[i])
				if(j>=a&&j<a+y&&(used[j]||(b%x[i])!=0))
					b=j;
			used[b]=true;
			cout<<b<<endl;
		}
	}
	else {
		cout<<"Alessia"<<endl;
		for(i=0;i<n;++i){
			int y=x[i];
			int a=1;
			while(true){
				int b=a+y-1;
				while(!used[b]&&b>a) --b;
				if(used[b]) a=b+1;
				else break;
			}
			cout<<y<<' '<<a<<endl;
			int b;
			cin>>b;
			used[b]=true;
		}
	}
	return 0;
}
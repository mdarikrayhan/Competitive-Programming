#include <bits/stdc++.h>
using namespace std;
int main (){
	int t,i,j;string a;
	for(cin>>t;t--;){cin>>a;
	i=a.find("11");j=a.rfind("00");
		cout<<((i!=-1&&j!=-1&&i<j)?"no\n":"yes\n");
	}
}
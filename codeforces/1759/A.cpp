#include<iostream>
using namespace std;
string str;
int T;
int main()
{
	cin>>T;
	for(int i=50;i>=1;i--)str+="Yes";
	while(T--)
	{
		string p;
		cin>>p;
		if(str.find(p,0)!=-1)puts("YES");
		else puts("NO");
	}
	return 0;
}
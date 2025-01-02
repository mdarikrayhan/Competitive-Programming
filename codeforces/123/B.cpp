// LUOGU_RID: 158682952
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,x1,x2,y1,y2;
	cin>>a>>b>>x1>>y1>>x2>>y2;
	int x=x1;
	int y=y1;
	x1=x+y;
	y1=y-x;
	x=x2;
	y=y2;
	x2=x+y;
	y2=y-x;
	a*=2;
	b*=2;
	x1=x1/a+(x1>0);//(0,0)
	x2=x2/a+(x2>0);
	y1=y1/b+(y1>0);
	y2=y2/b+(y2>0);
	cout<<max(abs(y2-y1),abs(x2-x1))<<endl;
}
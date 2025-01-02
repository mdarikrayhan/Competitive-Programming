#include<iostream>
using namespace std;
int main ()
{
	string s;
	bool t=true;
	int i1=-1,i2=-1,i3=-1,i4=-1,m=0;
	cin>>s;
	int n=s.length();
	for (int i=0,j=n-1;i<n&&j>=0;i++,j--)
	{
		if (s[i]=='[' && i1==-1)
		i1=i;
		if (s[j]==']' && i2==-1)
		i2=j;
	}
	if (i1==-1 || i2==-1)
	t=false;
	for (int i=0,j=n-1;i<n&&j>=0;i++,j--)
	{
		if (s[i]==':' && i3==-1 && i>i1)
		i3=i;
		if (s[j]==':' && i4==-1 && j<i2)
		i4=j;
	}
	if (i3==-1 || i4==-1)
	t=false;
	for (int i=i3;i<i4;i++)
	{
		if (s[i]=='|')
		m++;
	}
	if (t && i1<i3&&i3<i4&&i4<i2)
	cout<<4+m<<endl;
	else
	cout<<-1<<endl;
}
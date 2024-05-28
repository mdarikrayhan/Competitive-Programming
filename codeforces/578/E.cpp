// LUOGU_RID: 160428593
#include<bits/stdc++.h>
using namespace std;
string s;
set <int>s1,s2;
int ans[100050],aid;
const int inf=1e6;
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='L')
		s1.insert(i);
		else s2.insert(i);
	}
	s1.insert(inf);
	s2.insert(inf);
	if(s1.size()<s2.size()||(s1.size()==s2.size()&&*s1.begin()>*s2.begin()))
	swap(s1,s2);
	int cnt=0,pos=-1,next=*s1.begin();
	bool flag=false;
	for(int i=0;i<s.length();i++)
	{
		flag=!flag;
		if(flag)
		{
			if(next==inf||(*s2.lower_bound(next)==inf&&*s1.begin()!=next&&*s1.begin()<*s2.begin()))
			{
			cnt++;
			next=*s1.begin();
			}
			pos=next;
			s1.erase(pos);
			next=*s2.lower_bound(pos);
			ans[++aid]=pos+1;
		}
		else{
			if(next==inf||(*s1.lower_bound(next)==inf&&*s2.begin()!=next&&*s1.begin()>*s2.begin()))
			{
				cnt++;
				next=*s2.begin();
			}
			pos=next;
			s2.erase(pos);
			next=*s1.lower_bound(pos);
			ans[++aid]=pos+1;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=aid;i++)
	cout<<ans[i]<<" ";
	return 0;
}
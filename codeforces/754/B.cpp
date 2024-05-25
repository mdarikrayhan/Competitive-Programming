#include <bits/stdc++.h>
using namespace std;

int main(){
	string s[4];
	for (int i = 0; i < 4; ++i)
	{
		cin>>s[i];
	}
	for (int i = 0; i < 4; ++i)
	{
		int x=0,d=0;
		for (int j = 0; j < 3; ++j)
		{
			if (s[i][j] == 'x')
			{
				x++;
			}
			else if (s[i][j] == '.')
			{
				d++;
			}
		}
		if (x==2 and d==1)
		{
			cout<<"YES"<<endl;
			return 0;
		} 
		x=0,d=0;
		for (int j = 1; j < 4; ++j)
		{
			if (s[i][j] == 'x')
			{
				x++;
			}
			else if (s[i][j] == '.')
			{
				d++;
			}
		}
		if (x==2 and d==1)
		{
			cout<<"YES"<<endl;
			return 0;
		} 
	}
	for(int j =0;j<4;j++){
		int x=0,d=0;
		for (int i = 0; i < 3; ++i)
		{
			if (s[i][j] == 'x')
			{
				x++;
			}
			else if (s[i][j] == '.')
			{
				d++;
			}
		}
		if (x==2 and d==1)
		{
			cout<<"YES"<<endl;
			return 0;
		} 
		x=0,d=0;
		for (int i = 1; i < 4; ++i)
		{
			if (s[i][j] == 'x')
			{
				x++;
			}
			else if (s[i][j] == '.')
			{
				d++;
			}
		}
		if (x==2 and d==1)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	int x=0,d=0;
		for (int i = 0; i < 3; ++i)
		{
			if (s[i][i] == 'x')
			{
				x++;
			}
			else if (s[i][i] == '.')
			{
				d++;
			}
		}
		if (x==2 and d==1)
		{
			cout<<"YES"<<endl;
			return 0;
		} 
		x=0,d=0;
		for (int i = 1; i < 4; ++i)
		{
			if (s[i][i] == 'x')
			{
				x++;
			}
			else if (s[i][i] == '.')
			{
				d++;
			}
		}
		if (x==2 and d==1)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	x=0,d=0;
		for (int i = 0; i < 3; ++i)
		{
			if (s[i][3-i] == 'x')
			{
				x++;
			}
			else if (s[i][3-i] == '.')
			{
				d++;
			}
		}
		if (x==2 and d==1)
		{
			cout<<"YES"<<endl;
			return 0;
		} 
		x=0,d=0;
		for (int i = 1; i < 4; ++i)
		{
			if (s[i][3-i] == 'x')
			{
				x++;
			}
			else if (s[i][3-i] == '.')
			{
				d++;
			}
		}
		if (x==2 and d==1)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	int c=0;
	for (int i = 0; i < 3; ++i)
	{	
		if (s[i][i+1] == 'o')
		{c=0;
			break;
		}
		else if(s[i][i+1] == '.') c++;
	}
	if (c==1)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	c=0;
	for (int i = 0; i < 3; ++i)
	{	
		if (s[i+1][i] == 'o')
		{c=0;
			break;
		}
		else if(s[i+1][i] == '.') c++;
	}
	if (c==1)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	c=0;
	for (int i = 0; i < 3; ++i)
	{	
		if (s[i][2-i] == 'o')
		{	c=0;
			break;
		}
		else if(s[i][2-i] == '.') c++;
	}
	if (c==1)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	c=0;
	for (int i = 0; i < 3; ++i)
	{	
		if (s[i+1][3-i] == 'o')
		{	c=0;
			break;
		}
		else if(s[i+1][3-i] == '.') c++;
	}
	if (c==1)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	else cout<<"NO"<<endl;
}
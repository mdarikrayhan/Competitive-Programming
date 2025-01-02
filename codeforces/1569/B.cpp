#include<bits/stdc++.h>
using namespace std;
int T,N;
string S;
string ans[50];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		vector<int>id;
		for(int i=0;i<N;i++)
		{
			ans[i]=string(N,'=');
			ans[i][i]='X';
			if(S[i]=='2')id.push_back(i);
		}
		if(id.size()==1||id.size()==2)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=0;i<id.size();i++)
		{
			int u=id[i],v=id[(i+1)%id.size()];
			ans[u][v]='+';
			ans[v][u]='-';
		}
		for(int i=0;i<N;i++)cout<<ans[i]<<"\n";
	}
}
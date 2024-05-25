// LUOGU_RID: 160172709
#include<iostream>
#include<map>
using namespace std;
int n,L[500],C[500];
map<int,int> mp;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>L[i];
	for(int i=1;i<=n;i++) cin>>C[i];
	for(int i=1;i<=n;i++){
		for(pair<int,int> x:mp)	{
			int nxt=gcd(L[i],x.first);
			if(!mp[nxt]) mp[nxt]=C[i]+x.second;
			else mp[nxt]=min(mp[nxt],C[i]+x.second);
		}
		if(!mp[L[i]]) mp[L[i]]=C[i];
		else mp[L[i]]=min(mp[L[i]],C[i]);
	}
	if(!mp[1]) mp[1]=-1;
	cout<<mp[1];
	return 0;
}
/*
g++ -g -o myprogram -std=c++11 test.cpp -Wal
./myprogram
*/
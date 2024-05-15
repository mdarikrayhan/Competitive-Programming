// LUOGU_RID: 159104323
#include<bits/stdc++.h>
using namespace std;
int a[102];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		for(int j=k;j<=n;j++)
		{
			if(!a[j]){
				a[j]=k;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
} 
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> e[200010],ans;
int dp[200010];
void dfs(int x,int pre,int op){
	dp[x]=dp[pre]+1;
	int fafa=1145141919;
	for(int y:e[x]){
		if(y==pre||e[y].size()==1||op==0)
			continue;
		dfs(y,x,0);
		fafa=y;
		ans.push_back(y);
		break;
	}
	for(int y:e[x])
		if(y!=pre&&e[y].size()==1)
			ans.push_back(y);
	for(int y:e[x])
		if(y!=pre&&e[y].size()>1&&y!=fafa){
			ans.push_back(y);
			dfs(y,x,1);
		}
}
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int x:e[i])
			if(e[x].size()>1)
				sum++;
		if(sum>=3){
			cout<<"No\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(e[i].size()>1||n==2){
			ans.push_back(i);
			dfs(i,0,1);
			break;
		}
	cout<<"Yes\n";;
	for(int x:ans)
		cout<<x<<' ';
	cout<<'\n';
}

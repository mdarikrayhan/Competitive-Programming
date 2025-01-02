// LUOGU_RID: 160149663
#include<bits/stdc++.h>
using namespace std;
int d[19],ans[19];
queue<pair<int,int> > ab[19];
int cs[1009][1009],tx[4]={0,0,-1,1},ty[4]={1,-1,0,0},a,b,c;
void xg(int x){
	int y=ab[x].size();
	for(int i=1;i<=y;i++){
		int xx=ab[x].front().first,yy=ab[x].front().second;
		ab[x].pop();
		for(int k=0;k<4;k++){
			int n=xx+tx[k],m=yy+ty[k];
			if(n>=1&&n<=a&&m>=1&&m<=b&&cs[n][m]<0){
				ab[x].push({n,m});
				cs[n][m]=x;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>a>>b>>c;
	for(int i=1;i<=c;i++) cin>>d[i];
	for(int i=1;i<=a;i++){
		for(int k=1;k<=b;k++){
			char x;
			cin>>x;
			int y=x-'0';
			if(x=='.')cs[i][k]=-1;
			else if(x=='#')cs[i][k]=0;
			else cs[i][k]=y,ab[y].push({i,k});
		}
	}
	int i=0;
	while(1){
		int flag=0;
		for(int k=1;k<=d[i%c+1];k++){
			if(ab[i%c+1].size())xg(i%c+1);
			else break;
		} 
		for(int k=1;k<=c;k++) if(ab[k].size()) flag=1;
		if(flag==0) break;
		i++;
	}
	for(int i=1;i<=a;i++){
		for(int k=1;k<=b;k++){
			ans[cs[i][k]]++;
		}
	}
	for(int i=1;i<=c;i++) cout<<ans[i]<<" ";
	return 0;
}
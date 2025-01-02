#include<bits/stdc++.h>

using namespace std;

const int N=305005;

int a[N],ok[N],vis[N],n;
int inq[N],mat[N],clk;
vector<int> e[N];
map<int,int> loc[605];
mt19937 rnd(time(0));
void add(int x,int y){
	if (!ok[x]&&!ok[y]){
		e[x].push_back(y);
		e[y].push_back(x);
	}
}
bool dfs(int x){
	shuffle(e[x].begin(),e[x].end(),rnd);
	inq[x]=clk;
	for (auto y:e[x])
		if (inq[mat[y]]!=clk){
			int z=mat[y];
			mat[x]=y; mat[y]=x; mat[z]=0;
			if (!z||dfs(z)) return 1;
			mat[x]=0; mat[y]=z; mat[z]=y;
		}
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int nd=600;
	for (int i=1;i<=n;i++)
		if (a[i]==a[i+1]) ok[a[i]]=1;
	ok[0]=1;
	for (int i=1,j=0;i<=n;i++)
		if (a[i]){
			vis[a[i]]=1;
			if (j+1==i);
			else if ((i-j)%2==1){
				++nd;
				add(a[j],nd); loc[a[j]][nd]=j+1;
				add(a[i],nd+1); loc[a[i]][nd+1]=i-1;
				add(nd,nd+1);
				++nd;
			}
			else{
				++nd;
				add(a[j],nd); loc[a[j]][nd]=j+1;
				add(a[i],nd); loc[a[i]][nd]=i-1;
			}
			j=i;
		}
	for (int T=1;T<=3;T++)
		for (int i=1;i<=nd;i++)
			if (!mat[i]) ++clk,dfs(i);
	for (int i=1;i<=600;i++)
		if (mat[i]&&loc[i][mat[i]])
			a[loc[i][mat[i]]]=i;
	int p=1;
	for (int i=1;i<=n;i++)
		if (!a[i]){
			for (;vis[p];++p);
			if (!a[i+1]) a[i+1]=p;
			a[i]=p++;
		}
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
}
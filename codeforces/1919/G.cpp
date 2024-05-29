#include<bits/stdc++.h>
using namespace std;

const int N=5010;
char s[N][N];bool pd=true;bool bk[N];

vector<int> G[N];int bz[N],b[N];
void ins(int x,int y){
	G[x].push_back(y);
	G[y].push_back(x);
}

void dfs(vector<int> A){
	if(A.size()==1) return ;
	if(A.size()==2){
		ins(A[0],A[1]);
		return ;
	}
	bool pd2=false;
	for(auto x:A)
		if(bz[x]==0&&s[x][x]=='1'){
			vector<int> C;
			for(auto y:A)
				if(s[y][x]=='0'){
					pd2=true;
					C.push_back(y);
				}
			if(pd2){
				vector<int> D;
				for(auto y:A)
					if(s[y][x]=='1')
						D.push_back(y);
//				C.push_back(x);
				for(auto y:C)
					for(auto z:D){
						if(s[y][z]=='1') b[z]--;
						if(s[z][y]=='1') b[y]--;
					}
				int pd3=-1;
				for(auto y:C){
					bool pd1=true;
					if(b[y]==C.size()&&s[x][y]=='0')
						{ins(x,y);pd3=y;break;}
				}
				if(pd3==-1) {pd=false;return ;}
				bz[pd3]=1;
				dfs(C);
//				D.push_back(G[x][0]);
				bz[x]=1;
				dfs(D);
				return ;
			}
			else bz[x]=2;
		}
	if(!pd2){
		vector<int> C,D;
		for(auto x:A){
			if(bz[x]!=1){
				if(s[x][x]=='0') C.push_back(x);
				else D.push_back(x);
			}
		}
		if((C.size()<D.size()+1&&D.size()>0)||(D.size()==0&&C.size()>0)) {pd=false;return ;}
		else{
			if(D.size()>0){
				for(int i=0;i<D.size();i++)
					ins(D[i],C[i]);
				for(int i=1;i<D.size();i++)
					ins(C[i],D[i-1]);
				for(int i=D.size();i<C.size();i++)
					ins(D.back(),C[i]);
				for(auto x:A)
					if(bz[x]==1) ins(D[0],x);
			}
			else{
				for(auto x:A)
					if(x!=A[0]) ins(A[0],x);
			}
		}
	}
}

void dfs2(int x){
	bk[x]=false;bz[x]=0;
	for(auto y:G[x])
		if(bk[y]){
			dfs2(y);
			if(bz[y]==0) bz[x]=1;
		}
}

int main()
{
	
	int n;scanf("%d",&n);
//	for(int i=1;i<n;i++){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		G[x].push_back(y);
//		G[y].push_back(x);
//	}
//	for(int i=1;i<=n;i++){
//		memset(bk,true,sizeof(bk));
//		dfs2(i);
//		for(int j=1;j<=n;j++) s[i][j]=bz[j]+'0';
//	}
//	for(int i=1;i<=n;i++) G[i].clear();
	
//	for(int i=1;i<=n;i++){
//		printf("%s\n",s[i]+1);
//	}
	memset(bz,0,sizeof(bz));
	
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1); 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(s[i][j]=='1') b[j]++;
	
	for(int i=1;i<=n;i++){
		if(s[i][i]=='0'){
			for(int j=1;j<=n;j++)
				if(s[j][i]!='0')
					{pd=false;break;}
		}
		if(!pd) break;
	}
	
	if(!pd){
		printf("NO\n");
		return 0;
	}
	
	vector<int> B;
	for(int i=1;i<=n;i++) B.push_back(i);
	
	memset(bk,true,sizeof(bk));
	dfs(B);
	
	for(int i=1;i<=n;i++){
		memset(bk,true,sizeof(bk));
		dfs2(i);
		for(int j=1;j<=n;j++)
			if(bz[j]+'0'!=s[i][j])
				{pd=false;break;}
		if(!pd) break;
	}
	
	if(pd){
		printf("YES\n");
		for(int i=1;i<=n;i++)
			for(auto y:G[i])
				if(i<y) printf("%d %d\n",i,y);
	}
	else printf("NO\n");
	
	return 0;
}
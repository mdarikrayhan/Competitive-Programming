#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define ul unsigned long long
#define ui unsigned int
#define ri register int
#define pb push_back
string p[15]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
inline int rd(){
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') flag=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*flag;
}
#define N 2010
int n,k,f[N][N];
char ch[N];
typedef pair<int,int>pp;
vector<pp>a[N];
int main()
{
	ios::sync_with_stdio(false);
	n=rd(),k=rd();
	for(ri i=1;i<=n;++i){
		scanf("%s",ch);
		for(ri j=9;j>=0;--j){
			int cnt=0,flg=0;
			for(ri k=0;k<7;++k){
				if(ch[k]==p[j][k]) continue;
				if(ch[k]=='1'){
					flg=1;
					break;
				}
				cnt++;
			}
			if(flg) continue;
			a[i].pb(make_pair(cnt,j));
		}
	}//预处理
	f[n+1][0]=1;
	for(ri i=n;i>=1;--i){
		for(ri l=0;l<a[i].size();++l){
		    for(int j=a[i][l].first;j<=k;j++){
				int w=a[i][l].first;
				f[i][j]|=f[i+1][j-w];
			}
		}
	}//合法性判断
	if(!f[1][k]){
		cout<<-1;
		return 0;
	}
	string ans="";
	int cnt=k;
	for(ri i=1;i<=n;++i){
		for(ri j=0;j<a[i].size();++j){
			int w=a[i][j].first;
			if(cnt<w) continue;
			if(f[i+1][cnt-w]){
				char ch=a[i][j].second+'0';
				ans=ans+ch;
				cnt-=w;
				break;
			}
		}
	}//答案计算
	cout<<ans;
    return 0;
}
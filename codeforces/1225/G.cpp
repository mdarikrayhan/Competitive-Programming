// LUOGU_RID: 160428355
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pr;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
int n,m,a[16],s,b[16];bitset<2005>f[1<<16];priority_queue<pr>q;
int main(){
	n=rd();m=rd();f[0][0]=1;
	for(int i=0;i<n;++i)a[i]=rd(),s+=a[i];
	for(int i=1;i<(1<<n);++i){
		for(int j=0;j<n;++j)if(i>>j&1)f[i]|=f[i^(1<<j)]<<a[j];
		for(int j=s/m;j;--j)if(f[i][j*m])f[i][j]=1;
	}
	if(!f[(1<<n)-1][1])puts("NO");
	else{
		puts("YES");int nw=(1<<n)-1,o=1;
		for(int I=0;I<n;++I){
			for(;o*m<=s&&f[nw][o*m];o*=m)for(int j=0;j<n;++j)if(nw>>j&1)++b[j];
			for(int j=0;j<n;++j)if((nw>>j&1)&&o>=a[j]&&f[nw^(1<<j)][o-a[j]]){nw^=1<<j;o-=a[j];break;}
		}
		for(int i=0;i<n;++i)q.push({b[i],a[i]});
		while(q.size()>1){
			pr u=q.top();q.pop();pr v=q.top();q.pop();
			printf("%d %d\n",u.S,v.S);
			u.S+=v.S;while(u.S%m==0)u.S/=m,u.F--;
			q.push(u);
		}
	}
	return 0;
}
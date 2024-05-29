#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque> 
#include <map>
#include <bitset>
#include <cassert>
#define int long long
using namespace std; 

void read(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!('0'<=c && c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	x*=f;
}
int C[300010][5];
int t,n,c,q,a[300010],siz[300010][5];
pair<int,pair<int,pair<int,int> > > crc[300010];
pair<int,pair<int,int> > val[5][300010];
int l[5][300010],r[5][300010];
signed main(){
	for(int i=0;i<=300000;i++){
		C[i][0]=1;
		for(int j=1;j<=min(i,(int)4);j++){
			C[i][j]=C[i][j-1]*(i-j+1)/j;
		}
	}
	for(int i=0;i<=300000;i++){
		siz[i][0]=1;
		for(int j=1;j<=4;j++){
			siz[i][j]=(siz[i][j-1]+(i-1>=j?C[i-1][j]:0));
		}
	}
	read(t);
	while(t--){
		read(n);
		read(c);
		read(q);
		for(int i=1;i<=n;i++){
			read(a[i]);
		}
		for(int k=1;k<=c;k++){
			deque<pair<int,pair<int,int> > > dq;
			dq.push_back(make_pair(1,make_pair(-1,-1)));
			int lv=0,rv=0;
			for(int i=n;i;i--){
				for(int j=1;j<=min(k,n-i);j++){
					crc[j]=make_pair(a[i+j],make_pair(siz[n-i-j][k-j],make_pair(i,i+j)));
				}
				sort(crc+1,crc+min(k,n-i)+1);
				for(int j=min(k,n-i);j;j--){
//					if(k==4 && i==1){
//						printf("[%lld %lld %lld %lld %lld]",min(k,n-i),crc[j].first,crc[j].second.first,crc[j].second.second.first,crc[j].second.second.second);
//					}
					if(crc[j].first<a[i]){
						++lv;
						dq.push_front(crc[j].second);
					}
				}
				for(int j=1;j<=min(k,n-i);j++){
//					if(k==4 && i==1){
//						printf("[%lld %lld %lld %lld %lld]",min(k,n-i),crc[j].first,crc[j].second.first,crc[j].second.second.first,crc[j].second.second.second);
//					}
					if(crc[j].first>a[i]){
						++rv;
						dq.push_back(crc[j].second);
					}
				}
				l[k][i]=lv;
				r[k][i]=rv;
			}
			for(int i=1;dq.size();i++,dq.pop_front()){
				val[k][i]=dq.front();
				val[k][i].first+=val[k][i-1].first;
				//printf("[%lld %lld]:[%lld %lld %lld]\n",k,i,val[k][i].first,val[k][i].second.first,val[k][i].second.second);
			}
			assert(val[k][lv+1+rv].first==siz[n][k]);
			for(int i=1;i<=n;i++){
				l[k][i]=lv+1-l[k][i];
				r[k][i]=lv+1+r[k][i];
				//printf("[%lld %lld]:[%lld %lld]\n",k,i,l[k][i],r[k][i]);
			}
		}
		int k,v;
		for(int i=1;i<=q;i++){
			read(v);
			read(k);
//			v=(i-1)%n+1;
//			k=(i-1)/n+1;
//			if(v==1){
//				putchar('\n');
//			}
			if(k>siz[n][c]){
				printf("-1\n");
				continue;
			}
			int cur=c,pos=1;
			vector<pair<int,int> > res;
			while(pos<=n && cur){
				int ql=l[cur][pos]-1,qr=r[cur][pos];
				while(ql<qr-1){
					int mid=(ql+qr)>>1;
					if(val[cur][mid].first-val[cur][l[cur][pos]-1].first>=k){
						qr=mid;
					}else{
						ql=mid;
					}
				}
				if(val[cur][qr].second.first==-1){
					break;
				}
				res.push_back(val[cur][qr].second);
				k-=val[cur][qr-1].first-val[cur][l[cur][pos]-1].first;
				pos=val[cur][qr].second.second+1;
				cur-=val[cur][qr].second.second-val[cur][qr].second.first;
			}
			for(auto p:res){
				for(int j=p.first;j<=p.second;j++){
					if(j<p.first+p.second-j){
						swap(a[j],a[p.first+p.second-j]);
					}
				}
			}
			printf("%lld\n",(long long)a[v]);
			for(auto p:res){
				for(int j=p.first;j<=p.second;j++){
					if(j<p.first+p.second-j){
						swap(a[j],a[p.first+p.second-j]);
					}
				}
			}
		}
	}
	return 0;
}
  		 		 	   					 			 	 	 	 		
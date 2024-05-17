#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct Node{
	int xh;
	int li;
	int ri;
}h[N];
bool cmp(Node x,Node y){
	if(x.li==y.li){
		return x.xh<y.xh;
	}else{
		return x.li<y.li;
	}
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int hc[N];
		for(int i=1;i<=n;i++){
			cin>>h[i].li>>h[i].ri;
			h[i].xh=i;
		}
		sort(h+1,h+n+1,cmp);
		int sj=0;
		for(int i=1;i<=n;i++){
			if(i==1){
				hc[h[i].xh]=h[i].li;
				sj=h[i].li+1;
			}else{
				if(h[i].li<=sj){
					if(h[i].ri>=sj){
						hc[h[i].xh]=sj;
						sj+=1;
					}else{
						hc[h[i].xh]=0;
					}
				}else{
					hc[h[i].xh]=h[i].li;
					sj=h[i].li+1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<hc[i]<<" ";
		}
		cout<<"\n";
	}
}
	  	   	   				  					  	     	
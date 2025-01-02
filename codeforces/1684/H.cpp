#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ans[N][2], t;
string st;
int main(){
	cin>>t;
	while(t--){
		cin>>st;
		int len=st.length(), sum=0, d=1, tot;
		for(int i=0;i<len;i++){
			sum+=st[i]-'0';
		}
		if(sum==0){
			printf("-1\n");
			continue;
		}
		while(d<sum) d=d*2;
		while (true){
			int now=0, L=1, tmp=sum;
			tot=0;
			for(int i=1;i<=len;i++){
				int t=now;
				if(sum+t<=d) sum=sum+t;
				else{
					ans[++tot][0]=L;ans[tot][1]=i-1;
					L=i;now=0;
				}	
				now=now*2+st[i-1]-'0';
			}
			ans[++tot][0]=L;ans[tot][1]=len;	
			if (sum==d) break;
			sum=tmp;
			d*=2;
		}
		printf("%d\n", tot);
		for(int i=1;i<=tot;i++)  printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	
	return 0;
}
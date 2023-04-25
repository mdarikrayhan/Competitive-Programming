#include<bits/stdc++.h>
using namespace std;
int w[5],l,t[3],x[30003],p[30003],q[30003],n;
int main(){
	cin>>w[2]>>w[3]>>w[4]>>l;
	for(int i=1;i<=l;i++)
		for(int k=4;k>1;k--)
			if(w[k]){
				int j=-1;
				for(int o=0;o<3;o++)
					if(t[o]+k<=i&&(j==-1||t[o]>t[j]))
						j=o;
				if(~j){
					x[n]=j+1;
					p[n]=i-k;
					q[n++]=i;
					w[k]--;
					t[j]=i;
					break;
				}
			}
	cout<<n<<'\n';
	for(int i=0;i<n;i++)
		cout<<x[i]<<' '<<p[i]<<' '<<q[i]<<'\n';
}
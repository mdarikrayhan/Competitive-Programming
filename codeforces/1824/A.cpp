#include<bits/stdc++.h>
using namespace std;
int cnt,c1,c2,t,n,n2,m,a[114514],top,x;
bool b[114514];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("qwq.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=top;i++){
			b[a[i]]=0;
			a[i]=0;
		}
		top=c1=c2=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x==-1)c1++;
			if(x==-2)c2++;
		//	if(x>0)cout<<x<<endl;
			if(x>0&&b[x]==0){
			a[++top]=x;
			//cout<<a[top]<<" ";
			b[x]=1;	
			}
			
		}
	//	puts("");
		sort(a+1,a+1+top);
		int ans=0;
		ans=min(m,c1+top);
		ans=max(ans,min(m,c2+top));
		for(int i=1;i<=top;i++){
			int m1=min(a[i]-1,c1+i-1)+1+min(m-a[i],c2+top-i);
		//	cout<<a[i]<<" "<<m1<<endl;
			ans=max(ans,m1);
		}
		
	cout<<ans<<endl;
	}
}
 	  	 	 					  	 		     	 	
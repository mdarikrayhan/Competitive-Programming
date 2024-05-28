#include<bits/stdc++.h>
using namespace std;
char a[200001];
int b[200001];
bool vis[200001];
struct node{
	int x;
	int y;
	int z;
	bool operator < (const node &a) const{
		if(a.z==z){
			return a.x<x;
		}else
		return a.z<z;
	}
}; 
int n;
int ans1[200001],ans2[200001];
int l=0;
priority_queue<node> q;
int la[200001],nx[200001];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		la[i]=i-1;
		nx[i]=i+1;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]=='B'&&a[i+1]=='G'){
			q.push(node{i,i+1,abs(b[i]-b[i+1])});
		}
		if(a[i]=='G'&&a[i+1]=='B'){
			q.push(node{i,i+1,abs(b[i]-b[i+1])});
		}
	}
	int ans=0;
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int x=t.x;
		int y=t.y;
		//cout<<x<<" "<<y<<endl;
		if(vis[x]==0&&vis[y]==0){
			ans++;
			vis[x]=1,vis[y]=1;
			ans1[++l]=x,ans2[l]=y;
		}else continue;
		int l=la[x],r=nx[y];	
		if(l<1||r>n)continue;
		nx[l]=r,la[r]=l;
		//cout<<"l:"<<l<<" "<<r<<endl;
		if(((a[l]=='B'&&a[r]=='G')||(a[l]=='G'&&a[r]=='B'))&&vis[l]==0&&vis[r]==0){
			q.push(node{l,r,abs(b[l]-b[r])});
		}
	}
	cout<<l<<endl;
	for(int i=1;i<=l;i++){
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}

 		    		  		  			  				 	 	
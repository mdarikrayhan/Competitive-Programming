#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int n,k,r,S,p[200005];
vector<vector<int>>a,b;

void F(int t,int k){
	if(k%2==0){
		int n=t*k;
		For(i,0,n/2-1)b[i*2/k+1][i*2%k+1]=i+1,b[(i*2+1)/k+1][(i*2+1)%k+1]=n-i;
		return;
	}
	S=3*t;
	For(i,4,k){
		if(i&1){Rep(j,t,1)b[j][i]=++S;}
		else{For(j,1,t)b[j][i]=++S;}
	}
	int x=1,y=(3*t+1)/2,z=3*t;
	For(i,1,(t+1)/2) b[i][1]=x,b[i][2]=y--,b[i][3]=z--,x+=2;
	x=(3*t+3)/2,y=2*t+1,z=t-t%2;
	For(i,(t+3)/2,t) b[i][1]=x++,b[i][2]=y++,b[i][3]=z,z-=2;
}

void work(){
	cin>>n>>k,r=n%k;
	a=b=vector<vector<int>>(n/k+2,vector<int>(k+1,0));
	if(!r)F(n/k,k),a=b;
	else if(r>1&&r<k-1){
		F(n/k+1,r),a=b;
		F(n/k,k-r);
		For(i,1,n/k)For(j,1,k-r)a[i][j+r]=b[i][j]+r*(n/k+1);
	}
	else if(r==1){
		F(n/k,k-2);
		For(i,1,n/k)For(j,1,k-2)a[i][j+2]=b[i][j]+n-(k-2)*(n/k);
		S=0;
		For(i,1,n/k+1)a[i][1]=++S;
		Rep(i,n/k,1)a[i][2]=++S;
	}
	else{
		F(n/k+1,k-2),a=b;
		S=(k-2)*(n/k+1); 
		Rep(i,n/k+1,1)a[i][k-1]=++S;
		For(i,1,n/k)a[i][k]=++S;
	}
}

int main(){
	int T;cin>>T;
	while(T--){
		work();
		long long res,sum=0;
		For(i,1,n)p[i]=a[(i-1)/k+1][(i-1)%k+1];
		For(i,1,k)sum+=p[i];res=sum;
		For(i,k+1,n)sum+=p[i]-p[i-k],res=min(res,sum);
		cout<<res<<"\n";
		For(i,1,n)cout<<p[i]<<" \n"[i==n];
	}
	return 0;
}
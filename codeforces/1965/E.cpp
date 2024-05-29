

    #include<bits/stdc++.h>
    using namespace std;
     
    int i,j,k,n,m,t,cl,c;
    set<tuple<int,int,int,int> > op;
    #define pb(a,b,c,d) op.insert({a,b,c,d})
     
    int main(){
    	cin>>n>>m>>cl;
    	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
    		cin>>c;
    		for(k=2;k<=n+1-i;k++)pb(i,j,k,c);
    		for(k=1;k<i;k++)pb(i+k,j,n+1-i,c);
    		for(k=n+2-i;k<=50+c;k++)pb(i+i-1,j,k,c);
    		for(k=1;k<=m+1;k++)pb(i+i,k,50+c,c);
    	}
    	for(i=1;i<=cl;i++)for(j=1;j<=n+n;j++)pb(j,m+1,50+i,i);
    	cout<<op.size()<<'\n';
    	for(auto [i,j,k,w]:op)printf("%d %d %d %d\n",i,j,k,w);
    }
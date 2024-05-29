#include<bits/stdc++.h>
using namespace std;
int n,m,op[100005],v[100005],r[100005],o,k;
string s[100005];
pair<string,int>res[100005];
queue<int>p[2],q;
int tos(string x){
	int v=0;
	for(char i:x){
		if(i>'9'||i<'0') return 0;
		v=v*10+i-'0';
		if(!v) return 0;
	}
	return v<=n?v:0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i]>>op[i],m+=op[i];
	for(int i=1;i<=n;i++){
		v[i]=tos(s[i]);
		if(v[i]) r[v[i]]=i;
		else o=i;
	}
	if(!o){
		for(int i=1;i<=n;i++) if(v[i]&&(v[i]<=m)!=op[i]) o=i;
		res[++k]={s[o],999999},s[o]="ll45l4",r[v[o]]=0,v[o]=0,o=0;
	}
	for(int i=1;i<=n;i++) if(v[i]) if((v[i]<=m)!=op[i]) p[op[i]].push(i);
	for(int i=1;i<=n;i++) if(!v[i]) p[op[i]].push(i);
	for(int i=1;i<=n;i++) if(!r[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int tp=x<=m,y=p[tp].front();
		p[tp].pop();
		res[++k]={s[y],x};
		if(v[y]) q.push(v[y]);
	}
	if(k==1&&!o) k=0;
	cout<<k<<endl;
	for(int i=1;i<=k;i++){
		if(res[i].second==999999) cout<<"move "<<res[i].first<<" "<<"ll45l4"<<endl;
		else cout<<"move "<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}
   	 		  		        	 	   			 	
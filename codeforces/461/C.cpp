// LUOGU_RID: 144200182
#include<bits/stdc++.h>
using namespace std;
int n,q,t[100005],m,op,x,y,st=1,f=1;
void update(int x,int y){
	for(;x<=n;x+=x&-x)
		t[x]+=y;
}
int query(int x){
	int ret=0;
	for(;x;x-=x&-x)
		ret+=t[x];
	return ret;
}
int id(int x){
	return st+f*(x-1);
}
int query(int x,int y){
	if(f==1)
		return query(id(y))-query(id(x-1));
	else
		return query(id(x))-query(id(y+1));
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cin>>n>>q,m=n;
	for(int i=1;i<=n;i++)
		update(i,1);
	while(q--){
		cin>>op>>x;
		if(op==1){
			if(x<=m-x){
				for(int i=1;i<=x;i++)
					update(id(x+i),query(x-i+1,x-i+1));
				m-=x,st=id(x+1);
			}
			else{
				for(int i=1;i<=m-x;i++)
					update(id(x-i+1),query(x+i,x+i));
				m=x,st=id(x),f=-f;
			}
		}
		else
			cin>>y,cout<<query(x+1,y)<<'\n';
	}
	return 0;
}
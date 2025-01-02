#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>X,Y,ans;int no;
int ask(int x,int y){
	printf("0 %d %d\n",x,y);
	fflush(stdout);int res;
	scanf("%d",&res);return res;
}
void solve(int l,int r){
	if(l>r)return;
	int mid=(l+r)>>1,res;
	res=ask(mid,mid);
	if(res==0)ans.pb(mid),res=1;else no=mid;
	solve(l,mid-res);solve(mid+res,r);
}
int main(){
	solve(-1e8,1e8);
	for(auto w:ans){
		if(ask(w,no)==0)X.push_back(w);
		if(ask(no,w)==0)Y.push_back(w);
	}
	printf("1 %d %d\n",X.size(),Y.size());
	for(auto w:X)printf("%d ",w);puts("");
	for(auto w:Y)printf("%d ",w);
}
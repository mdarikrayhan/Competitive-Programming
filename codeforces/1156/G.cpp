#include<bits/stdc++.h>
using namespace std;

struct node{
	int a,b,op;
	node(int a=0,int b=0,int op=0):a(a),b(b),op(op){}
	bool operator <(const node &B)const{ return a==B.a?b==B.b?op<B.op:b<B.b:a<B.a; }
}P[100000];
int n;
bool isp[100000];
map<node,int>mp;
map<string,int>name;
map<int,string>orinname;
map<int,string>call;

void newnode(string &a){
	++n;
	P[name[a]=n]=node(n);
	orinname[n]=a;
	mp[P[n]]=n;
}

string newname(){
	static int cnt=0;
	string ret;
	int tmp = ++cnt;
	do{
		tmp = ++cnt;
		ret.clear();
		for(int i=0;i<4;i++,tmp/=26)
			ret+=tmp%26+'a';
	}while(name.count(ret));
	return ret;
}

vector<string>ans;

string dfs(int now){
	if(call.count(now)) return call[now];
	if(P[now].b==0) return orinname[P[now].a];
	string a=dfs(P[now].a),b=dfs(P[now].b);
	call[now]=(now==name["res"]?"res":newname());
	ans.push_back(call[now]+'='+a+char(P[now].op)+b);
	return call[now];
}

int main(){
	int T;
	for(scanf("%d",&T);T--;){
		string a,b,c,d;
		cin>>a;
		int L = a.length() , i1 = 0 , i2;
		for(;a[i1] != '=';i1++);
		b=a.substr(0,i1),c=a.substr(i1+1,L-i1-1);
		for(i2=0;string("&$#^").find(c[i2])==-1 && i2<c.length();i2++);
		if(!name.count(b)) newnode(b);
		if(i2==c.length()){
			if(!name.count(c)) newnode(c);
			name[b]=name[c];
		}
		else{
			int op = c[i2];
			d=c.substr(i2+1,c.length()-i2-1),c=c.substr(0,i2);
			if(!name.count(d)) newnode(d);
			if(!name.count(c)) newnode(c);
			node tmp = node(name[c],name[d],op);
			if(!mp.count(tmp)) mp[tmp]=++n,P[n]=tmp;
			name[b]=mp[tmp];
		}
	}
	if(!name.count(string("res"))) puts("0");
	else{
		string a = dfs(name["res"]);
		if(!ans.size() && a!="res") ans.push_back("res="+a);
		printf("%d\n",ans.size());
		for(int i=0,sz=ans.size();i<sz;i++)
			cout<<ans[i]<<endl;
	}
}
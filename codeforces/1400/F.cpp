#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define ll long double
#define int long long 
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

struct vertex {
	map<char,int> next,go;
	int p,link;
	char pch;
	int leaf; // esto se puede cambiar por int
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1),leaf(0){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf++;
}
int go(int v, char c);
int get_link(int v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int go(int v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}
int X;
string s;
int cantidad=0;
void init(int suma){
	if(suma>X)return;
	if(suma==X){
		// buscar un subtring de s, que sea divisor de X
		for(int i=0;i<s.size();i++){
			int sumita=0;
			for(int j=i;j<s.size();j++){
				sumita+=s[j]-'0';
				if(i==0 and j==s.size()-1)continue;
				if(X%sumita==0)return;
			}
		}
		add_string(s);
		return;
	}
	for(int i=1;i<=9;i++){
		s.pb(i+'0');
		init(suma+i);
		s.pop_back();
	}
}
string ESE;
int dp[1005][20005];
int atras[20005];
int hay(int nodo){
	if(atras[nodo]!=-1)return atras[nodo];
	atras[nodo]=0;
	if(t[nodo].leaf)return atras[nodo]=1;
	return atras[nodo]=hay(get_link(nodo));
}

int f(int pos, int v){
	if(pos==ESE.size())return 0;
	if(dp[pos][v]!=-1)return dp[pos][v];
	dp[pos][v] = 1 + f(pos+1,v);
	int nxt = go(v,ESE[pos]);
	if(!hay(nxt))dp[pos][v] = min(dp[pos][v],f(pos+1,nxt));
	return dp[pos][v];
}
signed main(){
    FIFO; 
	aho_init();
	cin>>ESE;
	cin>>X;
	init(0);
	memset(dp,-1,sizeof(dp));
	memset(atras,-1,sizeof(atras));
	cout<<f(0,0)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define forn(i, n) for(int i=0; i<n; i++)
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll, ll> vll;
const int Inf=1e9;
int main(){
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(0);
	int x1, x2, a, b; cin>>x1>>x2>>a>>b;
	if(a>=0&&b>=0){
	    int u=b+a, v=x2-x1-1;
	    if(x2>=x1+a&&x2<=x1+b)
	        cout<<"FIRST"<<'\n'<<x2;
	    else if(x2<x1||a==0||b==0)
	        cout<<"DRAW";
	    else if(v%u==u-1)
	        cout<<"SECOND";
	    else if(v%u>=(a-1)&&v%u<=(b-1))
	        cout<<"FIRST"<<'\n'<<x1+(v%u)+1;
	    else 
	        cout<<"DRAW";
	}else if(a<=0&&b<=0){
	    int u=abs(b+a), v=abs(x1-x2-1);
	    if(x2>=x1+a&&x2<=x1+b)
	        cout<<"FIRST"<<'\n'<<x2;   
	    else if(x2>x1||a==0||b==0)
	        cout<<"DRAW";
	    else if(v%u==u-1)
	        cout<<"SECOND";
	    else if(v%u<=(abs(a)-1)&&v%u>=(abs(b)-1))
	        cout<<"FIRST"<<'\n'<<x1-(v%u)-1;
	    else 
	        cout<<"DRAW";
	}else if(a<0&&b>0){
	    int u=abs(x2-x1);
	    if(u<=b||u<=abs(a))
	        cout<<"FIRST"<<'\n'<<x2;
	    else
	        cout<<"DRAW";   }   }
	   
	  	 	 			 	 		  		           	
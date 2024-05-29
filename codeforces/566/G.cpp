#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
const int N=1000050;
using namespace std;
using vi=basic_string<int>;

struct node{
int x,y,ty;
bool operator < (node b){
return make_pair(x,b.y)<make_pair(b.x,y);
}
bool operator == (node b){
return make_pair(x,y)==make_pair(b.x,b.y);
}
};vector<node> A;
int chk(node a,node b,node c){
return (a.x-b.x)*(b.y-c.y)<(b.x-c.x)*(a.y-b.y);
}
int n,m,x,y;
node s[N];int t;
void solve(){
cin>>n>>m>>x>>y;
for(int i=1;i<=n;i++){int x,y;cin>>x>>y;A.push_back({x,y,1});}
for(int i=1;i<=m;i++){int x,y;cin>>x>>y;A.push_back({x,y,0});}
sort(all(A));
unique(all(A));
for(auto X:A){
while(t&&s[t].y<X.y)t--;
while(t>1&&chk(s[t],s[t-1],X))
t--;
s[++t]=X;
}
for(int i=1;i<=t;i++)
if(s[i].ty){
cout<<"Max"<<endl;
return ;
}
cout<<"Min"<<endl;
}

main(){
ios::sync_with_stdio(false);
int _T=1;//cin>>_T;
while(_T--)solve();

}

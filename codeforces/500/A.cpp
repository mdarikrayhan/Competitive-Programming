#include <bits/stdc++.h>
using namespace std;
// void solve(){
  
// }
int main() {
	// your code goes here
	long n,t;
	cin>>n>>t;
	vector<long>a(n);
for(int i=0;i<n-1;i++){
    cin>>a[i+1];
}
vector<int>visited(n+1,0);
vector<long>adj[n+1];
for(int i=1;i<=n-1;i++){
    adj[i].push_back(a[i]+i);
}
queue<long>q;
q.push(1);
bool flag =0;
while(!q.empty()){
    int v = q.front();
    q.pop();
    if(v==t){
        flag =1;
        cout<<"YES"<<endl;
        break;
    }
    
    for(auto i = adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            visited[*i]=1;
            q.push(*i);
        }
    }
}
if (flag==0){
cout<<"NO"<<endl;}

}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector 
#define IO {cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);}
#define pb push_back
#define LOOP(i,j) for(int i=0;i<j;i++)
#define w(x) while(x--)

void add(int b,set<int> &pq,int x){
    pq.insert(b);
    if(pq.size()>x){
        //cout<<*pq.begin()<<" ";
        pq.erase(pq.begin());
    }
}

bool check(set<int> pq,int x){
    return pq.find(x)!=pq.end();
}

void solve(){
    int t,x,y,z;
    cin>>t>>x>>y;v<int> n;
    LOOP(i,t){
        cin>>z;n.pb(z);
    }
    set<int> pq;
    w(y){
        int a,b;
        cin>>a>>b;
        if(a==1){
            add(n[b-1],pq,x);
            //cout<<n[b-1]<<" ";
        }else{
            (check(pq,n[b-1]))?cout<<"YES\n":cout<<"NO\n";
        }
    }
}

int main(){
    IO 
    solve();
    return 0;
}
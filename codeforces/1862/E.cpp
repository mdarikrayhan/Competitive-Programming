#include<bits/stdc++.h>
#define ll long long
#define vint vector<int>
#define df double
#define pb push_back
#define fs first
#define sc second
#define pii pair<int,int>
#define vll vector<long long>
#define fr(k,i,n) for(int i=k;i<n;i++)
#define f0(i,n) for(int i=0;i<n;i++)
#define M 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n,m,d;
        cin>>n>>m>>d;
        vll v(n);
        f0(i,n)cin>>v[i];
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        ll s=0,ma=0;
        f0(i,n){
            ma=max(s+v[i]-d*(i+1),ma);
            if(v[i]>0){
                pq.push(v[i]);
                s+=v[i];
                if(pq.size()>=m){s-=pq.top();pq.pop();}
            }
        }
        cout<<ma<<'\n';
    }
    return 0;
}
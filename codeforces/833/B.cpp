#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define inf 2e18
#define endl '\n'
const int N=5e5+2,MAXN=1e6+2;
int n,q,a[N],offset=1;
int seg[N*2+3],lazy[N*2];
void prop(int node,int l,int r){
    if(lazy[node]!=0){
        int mid=(l+r)/2;
        seg[node*2]+=lazy[node];
        seg[node*2+1]+=lazy[node];
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
}
void update(int node,int qlo,int qhi,int lo,int hi,int val){
    if(lo>=qlo && hi<=qhi){
        lazy[node]+=val;
        seg[node]+=val;
        return;
    }
    if(lo>qhi || hi<qlo)return;
    prop(node,lo,hi);
    int mid=(lo+hi)/2;
    update(node*2,qlo,qhi,lo,mid,val);
    update(node*2+1,qlo,qhi,mid+1,hi,val);
    seg[node]=max(seg[node*2],seg[node*2+1]);
}
int query(int node,int qlo,int qhi,int lo,int hi){
    if(lo>=qlo && hi<=qhi){
        return seg[node];
    }
    if(lo>qhi || hi<qlo)return 0;
    prop(node,lo,hi);
    int mid=(lo+hi)/2;
    int x=query(node*2,qlo,qhi,lo,mid),y=query(node*2+1,qlo,qhi,mid+1,hi);
    seg[node]=max(x,y);
    return seg[node];
}
signed main(){
    //srand(time(NULL))
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k; cin>>n>>k;
    while(offset<n)offset*=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    map<int,int> last;
    for(int i=1;i<=k;i++){
        vector<int> v;
        v.pb(query(1,0,0,0,offset-1));
        for(int j=1;j<=n;j++){
            if(last[a[j]]==0){
                update(1,0,j-1,0,offset-1,1);
            }
            else{
                update(1,last[a[j]],j-1,0,offset-1,1);
            }
            last[a[j]]=j;
            int whattheflip=query(1,0,j-1,0,offset-1);
            v.pb(whattheflip);
        }
        for(int j=0;j<=N*2;j++){
            seg[j]=0;
            lazy[j]=0;
        }
        for(int j=0;j<v.size();j++){
            update(1,j,j,0,offset-1,v[j]);
            if(j==v.size()-1 && i==k)cout<<v[j];
        }
        last.clear();
    }
}
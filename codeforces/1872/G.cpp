#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 200010;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=0,r=n-1;
    while(l<r&&a[l]==1) l++;
    while(l<r&&a[r]==1) r--;
    ll res=1;
    for(int i=l;i<=r;i++){
        res*=a[i];
        if(res>1e9){
            cout<<l+1<<' '<<r+1<<'\n';
            return;
        }
    }
    vector<int>p;
    for(int i=0;i<n;i++){
        if(a[i]>1) p.push_back(i);
    }
    int sum=accumulate(a.begin(),a.end(),0);
    int L=1,R=1,ans=sum;
    for(int i=0;i<p.size();i++){
        int l=p[i];
        int res=1;
        int s=0;
        for(int j=i;j<p.size();j++){
            int r=p[j];
            res*=a[r];
            s+=a[r]-1;
            int v=sum-(r-l+1)-s+res;
            if(v>ans){
                ans=v;
                L=l+1,R=r+1;
            }
        }
    }
    cout<<L<<' '<<R<<'\n';
}


int main() 
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
 	int T;
 	cin >> T;

 	while(T --)
 	{
 		solve();
 	}

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
#define tc int t;cin>>t;while(t--)
#define vl vector<long long>
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define ll long long int
#define ul unsigned long long int
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define endl '\n'
#define nl cout<<endl;
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define srt(v) sort(v.begin(),v.end())
#define rvs(v) reverse(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define nai cout<<-1<<endl
#define pb push_back

ll Pow(int n){

    ll x=1;
    for(int i=0;i<n;i++){
        x*=2;
    }
    return x;
}

void solve(){

	int n,x,y,m;
    cin>>n;
    int a[n+1]={0};
    int b[n+1]={0};

    m=n*n;
    vi v;

    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(a[x]==0 and b[y]==0){
            v.push_back(i+1);
            a[x]=1;
            b[y]=1;
        }

    }

    srt(v);
    coutv(v);

}


int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	fastio;

    // int t; cin>>t;

    // for(int zz=0;zz<t;zz++){
    //     cout<<"Case "<<zz+1<<':'<<endl;
    //     solve();
    // }
    
    //tc
    solve();
    
	
}
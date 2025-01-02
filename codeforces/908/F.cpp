#include <bits/stdc++.h>
 
#define suiii ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define co cout<<
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #pragma GCC target("avx2,sse3,sse4,avx")
using namespace std;
//stuff
ll n;
ll cpred,lastgre,cpblu,mxdiffr,mxdiffb;
ll ans=0;
void solve(){
    mxdiffr=mxdiffb=0;
    cpred=lastgre=cpblu=-1;
    cin>>n;
    // save the checkpoints for each red and blue and if there is checkpoint behind u just go to it 
    for(int i=0;i<n;i++){
        char c;
        ll idx;
        cin>>idx>>c;
        if(c=='G'||c=='R'){
			if(cpred!=-1){
			    ans+=idx-cpred;
			    mxdiffr=max(mxdiffr,idx-cpred);
			}
			cpred=idx;
		}
		if(c=='G'||c=='B'){
			if(cpblu!=-1){
			    ans+=idx-cpblu;
			    mxdiffb=max(mxdiffb,idx-cpblu);
			}
			cpblu=idx;
		}
		if(c=='G'){
			if(lastgre!=-1){
			    // remove the extra lines
			    ans-=max(0ll,lastgre+mxdiffr+mxdiffb-idx);
	        }
			lastgre=idx;
			mxdiffr=mxdiffb=0;
			cpred=cpblu=idx;
		}
    }
    co ans;
}
 
int main()
{
    suiii
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
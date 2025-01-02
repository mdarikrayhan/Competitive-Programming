#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;


int main()
{
    fastio;
    int t=1;
    // cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        
        lli x;
        priority_queue<lli,vector<lli>,greater<lli>> pq;
        lli curH=0;
        for(int i=0;i<n;i++) {
            cin>>x;
            curH+=x;
            pq.push(x);
            
            while(curH<0) {
                curH-=pq.top();
                pq.pop();
            }
        }
        
        
        cout<<pq.size()<<endl;
    }
	    
	return 0;
}

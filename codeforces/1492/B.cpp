#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const int OO = 0x3f3f3f3f;
void SS(){
    int n;
    cin>>n;
    vector<int>card(n);
    for(int &c:card) cin>>c;
    vector<bool>vis(n+1, false);
    int curMax=n;
    for(int i=n-1;i>=0;i--){
        deque<int>dq;
        while(i>=0 && card[i]!=curMax){
            vis[card[i]]=true;
            dq.push_front(card[i]);
            i--;
        }
        dq.push_front(curMax);
        vis[curMax]=true;
        while(curMax>=1 && vis[curMax]==true) curMax--;
        for(auto x:dq) cout<<x<<" ";
    }
    cout<<'\n';
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    FIO
    int test = 1;
    cin >> test;
    while (test--) SS();
    return 0;
}

  	 		     		 	 		 		 	   	 	 	
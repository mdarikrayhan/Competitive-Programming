#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void TT(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s.push_back('A');
    int mx=0, prevAngry=-1;
    for(int i=0;i<=n;i++){
        if(s[i]=='A'){
            if(prevAngry==-1) prevAngry=i;
            else mx=max(mx, i-prevAngry-1);
            prevAngry=i;
        }
    }
    cout<<mx<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    FAST
    int testCases = 1;
    cin >> testCases;
    while (testCases--) TT();
    return 0;
}

	 	   	 	 			     	  	  				
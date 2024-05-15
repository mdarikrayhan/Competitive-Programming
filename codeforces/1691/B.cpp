#include <bits/stdc++.h>
using namespace std;
#define cyes cout<<"YES"<<endl;
#define cno cout<<"NO"<<endl;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1), ans;
    for(int i=0; i<n; i++)
        cin>>a[i];
    a[n]=-1;
    if(n==1){
        cout<<-1<<endl;
        return ;
    }
    
    int prev=0, cnt=1, val=1;    
    for(int i=1; i<n+1; i++){
        if(a[i]==a[prev])
            cnt++;
        else{
            if(cnt<2){
                cout<<-1<<endl;
                return ;
            }
            cnt = 1;
            prev = i;
            ans.push_back(prev);
        }
    }
    
    for(int it:ans){
        cout<<it<<" ";
        for(int i=val; i<it; i++)
            cout<<i<<" ";
        val=it+1;
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
}
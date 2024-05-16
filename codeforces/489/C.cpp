#include <bits/stdc++.h>
using namespace std;
#define int long long

string getMin(int m,int s){
    int d = max(1LL, s-(m-1)*9);
    char ch = '0'+d;
    string val = "";
    val = val + ch;
    for(int i=1; i<m; i++)
        val = val+"0";
    s=s-d;
    int t=1;
    for(int i=m-1; i>0; i--){
        ch = val[i]+min(s,1LL*9);
        val[i] = ch;
        s=s-min(s,1LL*9);
    }
    return val;
}

string getMax(int m,int s){
    string ans="";
    for(int i=0; i<m; i++){
        char ch = '0'+min(s,1LL*9);
        s=s-min(s,1LL*9);
        ans = ans + ch;
    }
    return ans;
}

void solve(){
    int m,s;    cin>>m>>s;
    if(m==1 && s==0){
        cout<<0<<" "<<0<<endl;
        return;
    }
    if(s<=0 || s>(m*9)){
        cout<<-1<<" "<<-1<<endl;
        return;
    }
    
    cout<<getMin(m,s)<<" "<<getMax(m,s)<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    
    return 0;
}
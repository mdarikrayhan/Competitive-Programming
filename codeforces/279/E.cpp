#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(i,a,b) for (int i=a; i <=b; i++)
#define INF 1<<30
#define md 1000000007
#define FOR(i,n) for(int i=0; i<n; i++)
#define FORR(i,n) for(int i=n-1; i>=0; i--)
#define pb push_back
#define vi vector<int>



int main(){
    string s; cin >> s;
    int n=s.size();
    FOR(i,10) s+='0';
    int cnt=0,e=0;
    FOR(i,n){
        if (e){
            if (s[i]=='0' && s[i+1]=='0') e=0;
            else if (s[i]=='0'){ //think
                cnt++;
            }
        }
        else {
            if (s[i]=='1' && s[i+1]=='1'){
                e=1; cnt+=2;
            }
            else if (s[i]=='1'){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
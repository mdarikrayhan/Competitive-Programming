#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define loop(g,t) for(int g {} ; g<t ; g++)
#define loop1(g,t) for(int g {1} ; g<=t ; g++)
#define cyes cout << "YES"<< endl
#define cno  cout << "NO" << endl
#define F first
#define S second
const long long ll_zero = 0;
const ll N = 1000000007;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
while(t--){
ll n; cin>>n;
vector <ll> q(n); loop(i,n) cin>>q[i];
bool check[n] = {0}, pos = 1;
ll p[n],m{};
p[0] = q[0];
check[p[0]-1] = 1;
while(check[m] == 1) m++;
loop1(i,n-1){
    if(q[i] != q[i-1]){
        p[i] = q[i];
        check[q[i]-1] = 1;
        while(check[m] == 1) m++;
    }
    else{
        if(m+1 >= q[i-1]) pos = 0;
        p[i] = m+1;
        check[m] = 1;
        while(check[m] == 1) m++;
    }
}
if(pos) loop(i,n) cout<<p[i]<<" "; 
else cout<<-1;
cout<<endl;
}
}
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

ll b,cnt{}; cin>>b;

for(ll a=1; a*a <= b; a++){
    if(b%a == 0){
        (b/a != a)?(cnt+=2):(cnt++);
    }
}

cout<<cnt<<endl;
}
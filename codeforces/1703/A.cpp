/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define multicase int NoOfTestCase = 1;cin >> NoOfTestCase;for(int testcaseno=1;testcaseno<=NoOfTestCase;testcaseno++)
bool isPrime(int n){if (n == 2 || n == 3){return true;}if (n <= 1 || n % 2 == 0 || n % 3 == 0){return false;}for (int i = 5; i * i <= n; i += 6){if (n % i == 0 || n % (i + 2) == 0){return false;}}return true;}
bool isPalindrome(string S){string P = S;reverse(P.begin(), P.end());if (S == P) {return true;}else {return false;}}

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int main() {
fastio
multicase
{
string s;
cin>>s;

if(s=="yes"||s=="Yes"||s=="yEs"||s=="yeS"||s=="YEs"||s=="yES"||s=="YeS"||s=="YES"){
    cout<<"YES"<<nl;
}
else{
    cout<<"NO"<<nl;
}
}

return 0;
}
/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define multicase int NoOfTestCase = 1;cin >> NoOfTestCase;for(int testcaseno=1;testcaseno<=NoOfTestCase;testcaseno++)
int main() {
fastio
multicase
{
int n,sum=0;
string s;
cin>>n>>s;
set<char>sc;
for(int i=0;i<n;i++){
    sc.insert(s[i]);
}
int uniqe=sc.size();
cout<<uniqe+n<<nl;
}
return 0;
}
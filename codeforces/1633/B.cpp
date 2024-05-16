#include<iostream>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>     // To include sort functions
#include <cctype>       // To include islower() and isUpper()
using namespace std;
typedef long long l1;
#define ios ios::sync_with_stdio(false);cin.tie(0);
int gcd (int a, int b)
{
    return b ? gcd (b , a % b) : a;
}
int solve(){

    string s;
    cin >> s;
    
    int n = (int)s.size();
    int one = count(s.begin(), s.end(), '1');
    if(one == n || one == 0)return 0;
    int zero = n - one;

    if(one > zero)return zero;
    if(zero > one)return one;
    return one - 1;
}
int main(){
    ios
    int t = 1;
    cin >> t;
    while(t--)cout<<solve()<<"\n";
}

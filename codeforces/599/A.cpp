/*
|4|623720|660130|
*/
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define ll long long
#define pb push_back

using namespace std;

#pragma GCC optimize("O3")

const int N=1e4;
const int mod=1e9+7;
const int INF=1e18;

int a,b,c;

void prob(){
    cin>>a>>b>>c;
    cout<<min(a+b+c,min(a*2+b*2,min(a*2+c*2,b*2+c*2)));
}

//s.erase(remove(s.begin(),s.end(),' '),s.end());   удаление элемента в стринге
//gcd нод
//lcm нок
//v.erase(v.begin()+4); удаление елемента в векторе
//v.erase(v.begin()+2,v.begin()+5); удаление отрезка в векторе

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t2=1;
    // cin>>t2; 
    while(t2--){
        prob();	
    }
}
/*
|4|623720|660130|
*/
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define ll long long
#define pb push_back

using namespace std;

const int N=2000;
const int mod=1e9+7;
const int INF=1e18;

#pragma GCC optimize("O3")

//быстрое возведение в степень
// long long power(long long x,long long y,long long m) {
//    long long res=1;
//    x=x%m;
//    while (y>0) {
//        if (y&1)
//            res=(res*x)%m;
//        y=y>>1;
//        x=(x*x)%m;
//    }
//    return res;
// }
//x = coeficent
//y = power
//m = mod

double n,m;

void prob(){
    cin>>n>>m;
    double x=pow(1.000000011,m)*1.0;
    n=n*x*1.0;
    cout<<fixed;
    cout<<setprecision(30);
    cout<<n;
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
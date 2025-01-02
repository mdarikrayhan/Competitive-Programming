/**

   &&          &&          &&          &&          &&          &&          &&          &&          &&
&&    &&    &&    &&    &&    &&    &&    &&    &&    &&    &&    &&    &&    &&    &&    &&    &&    &&
&&       &&          &&          &&          &&          &&          &&          &&          &&          && &&
&&                                                                                                          &&
&&                                                                                                          &&
&&      D D D D D D            a a a a        G G G G G       H       H      E E E E E       R R R R        &&
&&      D           D         a       a      G                H       H      E              R       R       &&
&&      D             D       a       a      G                H       H      E              R R R R         &&
&&      D              D      a a a a a      G                H H H H H      E E E E E      R R             &&
&&      D             D       a       a      G     G G G      H       H      E              R   R           &&
&&      D           D         a       a      G         G      H       H      E              R     R         &&
&&      D D D D D D           a       a       G G G G G       H       H      E E E E E      R       R       &&
&&                                                                                                          &&
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

**/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool Vowel(char c ) {
    if (c == 'a' || c == 'e') return 1 ;
    return 0 ;
}
bool Constant(char c ) {
    if (c != 'a' && c != 'e') return 1 ;
    return 0 ;
}
string clean (string s ) {
    int n = s.length() ;
    string  c = "" ;
    for (int i = 0 ; i <n ; i++) {
        if ( !((s[i]>='a' && s[i]<='e') || s[i]=='.') ) break;
        c+=s[i] ;
    }
    return c;
}
void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}
void IO()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}
void read()
{
#ifndef ONLINE_JUDGE
    freopen("F:/CodeBlocks/ComeBack/input.txt","r",stdin);
#endif // ONLINE_JUDGE
}
bool k ;
void check (int x , int n )
{
    if (x>=n) {
        if (x==n) k= 1 ;
        return  ;
    }
    check(x+2020 , n) ;
    check(x+2021 , n) ;

}

int toggle (int &a ) {
    if (a==0)  a= 1 ;
    else a = 0 ;
}
int luccy (int n ) {
    int mn = INT_MAX ;
    int mx = 0 ;
    while (n>0) {
        int x = n%10 ;
        mn = min (mn , x) ;
        mx = max (mx , x) ;
        n/=10 ;
    }
    return mx-mn ;
}

const int mx = 29 ;
int freq[mx] ;
int main()
{
    IO() ;
    read() ;
    int n , t  ; cin >>  n >> t ;
    if (n==1 && t ==10) return cout << -1 , 0  ;
    string s = ""  ;
    if (t<10) s+=  char(t+'0')  , n-- ;
    else  s+= "10"  , n-=2 ;
    for (int i = 0 ; i < n ; i++) {
        s+='0' ;
    }
    cout << s ;












}

















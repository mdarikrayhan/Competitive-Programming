#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;
#define __bin(num) std::bitset<sizeof(num) * 8>(num).to_string()
#define zero substr(binary.find_first_not_of('0'))
#define fr(i,a,b) for(int i=a;i<b;i++)
#define fl(i,a,b) for(int i=b-1;i>=a;i--)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,false,sizeof(x))
#define tr(it,a) for(auto it = a.begin(); it!=a.end(); it++)
#define tl(it,a) for(auto it = a.rbegin(); it!=a.rend(); it++)
#define go(a,x) for(auto &a:x)
#define ter(a,b,c) ((a)?(b):(c))
#define yn(a) cout<<((a)?"YES\n":"NO\n")
#define mxe(v) *max_element(v.begin(),v.end())
using ll = long long;
using vi = vector<int>;
using vii = vector<pair<int,int>>;
using pi = pair<int,int>;
 
const int lim = 1e9 + 10; 
    
 
bool isprime(int n){
    if (n==0 or n==1){
        return false;
    }
    for (int i=2;i*i<=n;i++){
        if (n%i==0) return false;
    }return true;
}
 
bool ispalindrome(string &s){
    int st = 0, end = s.size()-1;
    while(st<end){
        if(s[st++]!=s[end--]) return false;
    }return true;
}

bool isnumpalindrome(int n){
    string s = to_string(n);
    int st = 0, end = s.size()-1;
    while(st<end){
        if(s[st++]!=s[end--]) return false;
    }return true;
}

long long int takeInt(string &s){
    long long int n = 0;
    for(int i=0;i<s.size();i++){
        n =n*10 +(s[i]-'0');
    }return n;
}

void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int &i:a){
        cin>>i;
    }for(int &i:b){
        cin>>i;
    }for(int i=0;i<n;i++){
        if(a[i]<b[i] ) swap(a[i],b[i]);
    }
    cout<<(mxe(a))*(mxe(b))<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
ios::sync_with_stdio(0);
cin.tie(0);
    long long t; cin>>t;
    while(t--){
        solve();
    }
}
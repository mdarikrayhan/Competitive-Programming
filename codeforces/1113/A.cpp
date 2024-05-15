#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <chrono>
#include <random>
#include <thread>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>

#define pb push_back
#define Batyrzhan_zhirabas ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define uns unsigned
#define sin signed
#define f first
#define S second
#define YES "YES\n"
#define NO "NO\n"
#define ppb pop_back
#define nl endl
#define koe " ";  
#define Yerke_bul_() using namespace std;

Yerke_bul_()

const int inf = 2000000000;
const int mx = 1e6 + 111;
const int mn = -1e6 - 111;
const int k = 400;

char c[1010][1010];
int a[101010];
int b[100100];

void Batyrzhan_mobilograph(){

    int n,v;
    cin >>n>>v;
    int asd = 0;
    if(n - 1 <= v){
        cout <<n-1;
        return;
    }
    asd = v - 1;
    for(int i =1;i<=n-v;i++){
        asd+=i;
    }
    cout <<asd;
    return ;
    
}
int main() {
    Batyrzhan_zhirabas
    ll T=1;
    //cin >>T;
    for(int i = 1;i<=T;i++){
        //cout <<"Case "<<i<<": \n";
        Batyrzhan_mobilograph();
    }
}

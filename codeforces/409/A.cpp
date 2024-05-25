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
#define ll long long
#define uns unsigned
#define sin signed
#define f first
#define s second
#define pop pop_back
using namespace std;
//2147483648;
const ll maxn = 1e6 + 111;

const int minx = -1e6 - 111;
const int mx = 1e6 + 111;
const int mn = -1e6 - 111;
ll a[1010][1010];
ll b[100100];
char c[101000];
vector<int>g[1100];
vector<int>p[1010];
void Batyrzhan_mobilograph() {

    string n,m;
    cin >>n>>m;
    int asd=0,cnt=0;
    for(int i =0 ;i< n.size();i++){
        if(n[i]=='[' && n[i+1]==']' && m[i]=='8' && m[i+1] == '<'){
            cnt++;
        }if(n[i]=='[' && n[i+1]==']' && m[i]=='(' && m[i+1] == ')'){
            asd++;
        }if(n[i]=='(' && n[i+1]==')' && m[i]=='[' && m[i+1] == ']'){
            cnt++;
        }if(n[i]=='(' && n[i+1]==')' && m[i]=='8' && m[i+1] == '<'){
            asd++;
        }if(n[i]=='8' && n[i+1]=='<' && m[i]=='[' && m[i+1] == ']'){
            asd++;
        }if(n[i]=='8' && n[i+1]=='<' && m[i]=='(' && m[i+1] == ')'){
            cnt++;
        }
    }
    if(asd > cnt){
        cout <<"TEAM 1 WINS";
    }else if (asd ==cnt ){
        cout <<"TIE";
    }else{
        cout <<"TEAM 2 WINS";
    }
    
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   Batyrzhan_mobilograph();}

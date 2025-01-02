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



void Batyrzhan_mobilograph(){

    int n;
		string x;
		cin >> n >> x;
		string a(n, '0'), b(n, '0');
		for (int i = 0; i < n; ++i) {
			if (x[i] == '1') {
				a[i] = '1';
				b[i] = '0';
				for (int j = i + 1; j < n; ++j) {
					b[j] = x[j];
				}
				break;
			} else {
				a[i] = b[i] = '0' + (x[i] - '0') / 2;
			}
		}
		cout << a << endl << b << endl;
	}
int main() {
    Batyrzhan_zhirabas
    ll T=1;
    cin >>T;
    for(int i = 1;i<=T;i++){
        //cout <<"Case "<<i<<": \n";
        Batyrzhan_mobilograph();
    }
}

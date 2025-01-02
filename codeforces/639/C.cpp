#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <random>
//#include <math.h>
#include <cmath>
#include <fstream>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <bitset>
#include <stdio.h>
#include <array>

#pragma comment(linker, "/STACK:36777216")
using namespace std;

#define flu fflush(stdout)
#define gg return 0
#define mp make_pair

typedef long double ptype;

long long mod = /*27449*//*998244353 */ 1e9 + 7 /* 998244353 /*998244353*/ /*1e9 + 9*/;

long long inf = 1e9;
long double eps = 1e-6;
double pi = acosl(-1);
mt19937 rng(100);// chrono::steady_clock::now().time_since_epoch().count()); // 100
ifstream in("input.txt");
ofstream out("output.txt");

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uc = unsigned char;
using us = unsigned short;

int n;

ll p[200120];

void solve() 
{
	int n;
	cin >> n;
	ll k;
	cin >> k;
	for (int i = 0; i <= n; i++)
	{
		cin >> p[i];
	}

	ll acc = 0;
	vector<ll> kek;
	for (int i = 0; i <= n; i++)
	{
		acc += p[i];
		kek.push_back(acc % 2);
		acc /= 2;
	}

	while (acc)
	{
		kek.push_back(acc % 2);
		acc /= 2;
	}

	while (kek.size() && kek.back() == 0)
	{
		kek.pop_back();
	}

	int add = 0;

	if (kek.back() == -1)
	{
		add = 1;
		for (int i = 0; i < kek.size(); i++)
		{
			kek[i] = -kek[i];
		}
	}

	for (int i = 0; i + 1 < kek.size(); i++)
	{
		if (kek[i] < 0)
		{
			kek[i] += 2;
			kek[i + 1] --;
		}
	}
	while (kek.size() && kek.back() == 0)
	{
		kek.pop_back();
	}

	assert(kek.size());

	int l = 0;
	while (kek[l] == 0) l++;

	ll cur = 0;
	for (int i = (int)kek.size() - 1; i > l; i--)
	{
		cur *= 2;
		cur += kek[i];
		if (cur > k * 2)
		{
			cout << "0\n";
			return;
		}
	}
	int ans = 0;
	
	for (int i = l; i >= 0; i--)
	{
		cur *= 2;
		cur += kek[i];
		if (cur > k * 2) break;
		if (i == n)
		{
			if (add)
			{
				if (p[i] + cur <= k && p[i] != -cur)
					ans++;
			}
			else
			{
				if (p[i] - cur >= -k && p[i] != cur)
					ans++;
			}
		}
		if (i < n)
		{
			if (add)
			{
				if (p[i] + cur <= k) 
					ans++;
			}
			else
			{
				if (p[i] - cur >= -k) 
					ans++;
			}
		}
	}
	
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(20) << fixed;
	//	cout.tie();
	clock_t t1 = clock();
	//freopen("input.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 1;
	//cin >> t;
	while (t--) {
		//cout << "Case #" << c++ << ": ";
		solve();
	}
 	gg;
}
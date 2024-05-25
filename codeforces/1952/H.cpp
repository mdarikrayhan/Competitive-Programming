#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

//#define MULTI

#ifdef DEBUG
const long long N = 101;
#endif
#ifndef DEBUG
const long long N = 101;
#endif
string a[N];
bool isPalindrome(string &x)
{
	int t = x.size();
	for(int i=0, j=t-1; i<j; i++, j--)
		if(x[i] != x[j]) return false;
	return true;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		
    }
    #endif
	#ifndef MULTI
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		int m = s.size();
		for(int i=0; i<min(n, m); i++)
			a[i].push_back(s[i]);
		
	}
	for(int i=0; i<n; i++)
			cout << (isPalindrome(a[i])? "YES\n": "NO\n");
	#endif
 	return 0;
}

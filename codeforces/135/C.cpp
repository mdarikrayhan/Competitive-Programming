// LUOGU_RID: 160040789
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, c0[N], c1[N];
char s[N], sp[N];

void mymain() {
	scanf("%s", sp+1);
	n = strlen(sp+1);
	{ // ans = 00
		vector <int> v0, v1;
		for (int i = 1; i <= n; i++) {
			s[i] = sp[i];
			if (s[i] == '?') s[i] = '0';
			if (s[i] == '0') v0.push_back(i);
			else v1.push_back(i);
		}
		if ((int)v0.size() >= (int)v1.size()+1) puts("00");
	}
	{ // ans = 01
		int c0 = 0, c1 = 0, c = 0;
		for (int i = 1; i <= n; i++) {
			s[i] = sp[i];
			if (s[i] == '0') c0++;
			else if (s[i] == '1') c1++;
			else c++;
		}
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i <= n; i++) {
			if (s[i] == '?') cnt++;
			if (c1+c-cnt >= c0+cnt && c1+c-cnt <= c0+cnt+1) {
				for (int j = 1; j <= n; j++) {
					if (s[j] == '?') {
						if (j <= i) s[j] = '0';
						else s[j] = '1';
					}
				}
				flag = true;
				break;
			}
		}
		if (flag) {
			vector <int> v0, v1;
			for (int i = 1; i <= n; i++) {
				if (s[i] == '0') v0.push_back(i);
				else v1.push_back(i);
			}
			if (v0.back() < v1.back()) puts("01");
		}
	}
	{ // ans = 10
		int c0 = 0, c1 = 0, c = 0;
		for (int i = 1; i <= n; i++) {
			s[i] = sp[i];
			if (s[i] == '0') c0++;
			else if (s[i] == '1') c1++;
			else c++;
		}
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i <= n; i++) {
			if (s[i] == '?') cnt++;
			if (c1+cnt >= c0+c-cnt && c1+cnt <= c0+c-cnt+1) {
				for (int j = 1; j <= n; j++) {
					if (s[j] == '?') {
						if (j <= i) s[j] = '1';
						else s[j] = '0';
					}
				}
				flag = true;
				break;
			}
		}
		if (flag) {
			vector <int> v0, v1;
			for (int i = 1; i <= n; i++) {
				if (s[i] == '0') v0.push_back(i);
				else v1.push_back(i);
			}
			if (v1.back() < v0.back()) puts("10");
		}
	}
	{ // ans = 11
		vector <int> v0, v1;
		for (int i = 1; i <= n; i++) {
			s[i] = sp[i];
			if (s[i] == '?') s[i] = '1';
			if (s[i] == '0') v0.push_back(i);
			else v1.push_back(i);
		}
		if ((int)v1.size() >= (int)v0.size()+2) puts("11");
	}
}

void myclear() {
}

int main() {
	int _ = 1;
//	int _; scanf("%d", &_);
	while (_--) mymain(), myclear();
	
	return 0;
}
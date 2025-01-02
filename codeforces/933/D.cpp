// LUOGU_RID: 156824638
#include<bits/stdc++.h>
using namespace std;

#define int __int128
#define M 1000000007

int n, sqn, fore, res, inv[500];

void readin(int &x){
    char c;
	bool f = 0;
    while(((c = getchar()) < '0' || c > '9') && c != '-');
    if(c == '-')
		f = 1, c = getchar();
    x = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
		x = x * 10 + c - '0';
    if(f)
		x = -x;
}

void print(int x){
	if(x < 0)
		putchar('-'), x = -x;
    if(x > 9)
		print(x / 10);
    putchar(x % 10 + '0');
}

int p(int x, int y){
	int ret = 1;
	while(y){
		if(y & 1)
			ret = ret * x % M;
		x = x * x % M, y /= 2;
	}
	return ret;
}

int sm2(int x){
	return inv[3] * x % M * (x + 1) % M * (1 + x * 2 % M) % M;
}

int sm4(int x){
	return sm2(x) * inv[5] % M * (3 * x % M * x % M + 3 * x % M - 1 + M) % M;
}

int sm6(int x){
	return sm2(x) * inv[7] % M * ((3 * p(x, 4) + 6 * p(x, 3) - x * 3 % M + 1 + M) % M) % M;
}

signed main(){
	for(int i = 0; i < 500; i++)
		inv[i] = p(i, M - 2);
	readin(n), sqn = sqrt((long long)n), fore = (p(n, 3) + 3 * p(n, 2) + 2 * n) % M;
	for(int i = -sqn; i <= sqn; i++){
		int cnt = sqrt((long long)(n - i * i));
		res += ((fore + 3 * p(i, 2) % M * n % M - 3 * p(i, 4) % M * n % M + 2 * p(i, 6) % M - 6 * p(i, 4) % M + 4 * p(i, 2) % M) % M + M) % M * ((cnt * 2 + 1) % M) % M;
		res += sm6(cnt) * 2 % M;
		res += sm4(cnt) * (6 * p(i, 2) % M - 6 - n * 3 % M + M * 2) % M;
		res += sm2(cnt) * (n * 3 - p(i, 2) * n % M * 6 % M + 6 * p(i, 4) % M - 12 * p(i, 2) % M + 4 + M * 2) % M;
		res %= M;
	}
	print(res * inv[6] % M), cout << endl;
	return 0;
}////
// LUOGU_RID: 160448104
#include <bits/stdc++.h>
#define Maxn 50050
using namespace std;
char str[Maxn], s[Maxn];
int main (){
	cin >> str;
	int len = strlen(str);
	for(int i = 1; i <= len; i++){
		s[i] = str[i - 1];
	}
	int n = len;
	for(register int i = 1; i <= n / 2; i++){//i是枚举长度
		int tot = 0;
		for(register int j = 1; j <= n - i; j++){
			if(s[j] == s[j + i]){
				tot++;
			}	
			else{
				tot = 0;
			}
			if(tot == i){
				for(register int k = j + 1; k <= n - i; k++){
					s[k] = s[k + i];
				}
				n -= i;
				i = 0;
				break;
			}
		}
	}	
	s[n + 1] = 0;
	cout << s + 1 << endl;
} 

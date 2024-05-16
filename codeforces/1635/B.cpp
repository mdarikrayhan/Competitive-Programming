#include<iostream>
using namespace std;
long long a[1000000];
int main() {
	int t, m;
	cin >> t;
	while (t--) {
		cin >> m;
		int sum = 0, num = 0x3f3f3f3f;//sum为需要改的数字的个数，num用于记录极大值的位置
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		int aa, again = 0;
		for (int i = 1; i < m - 1; i++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {//寻找极大值
				int reduction = 0;
				sum++;//需要改的数字加一
 
				if (i - num == 2) {//判断两个极大值中间是否只差一个数
					sum--;//两个极大值中间只差一个数，只改这两个极大值中间打那个数即可，减去多改的那一个
					reduction = 1;
				}
 
				num = i;//记录极大值的位置
 
				if (reduction == 1) {//两个极大值中间只差一个数，即只改这个数跟更大的那个一样的即可
					num = 0x3f3f3f3f;//清空num值，准备记录下一个极大值的位置（三个相间隔为1个数字的极大值，必定要改两个数，所以此时，第三个极大值无需与前两个数相比较）
					a[i - 3] = aa;//还原前一个极大值前面改变的数字
					if (a[i] >= a[i - 2]) {//比较两极大值大小，使中间位置等于更大一方
						a[i - 1] = a[i];
					}
					else {
						a[i - 1] = a[i - 2];
					}
				}
				else {
					aa = a[i - 1];//发现一个极大值时，记录它前面一个数的值
					a[i - 1] = a[i];//并把其改为与极大值相等的数字
				}
			}
		}
		printf("%d\n", sum);
		for (int i = 0; i < m; i++) {
			printf("%d", a[i]);
			if (i != m - 1) {
				printf(" ");
			}
		}
		if (t != 0) {
			printf("\n");
		}
	}
	return 0;
}
		    	  		      			 			      	
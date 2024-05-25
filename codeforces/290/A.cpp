// LUOGU_RID: 159994884
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
using namespace std; //头文件和命名空间
int main(){
	ios::sync_with_stdio(false); //一定意义上的加速
	string arrNames[40] = { "Washington", "Adams", "Jefferson", "Madison", "Monroe", "Adams", "Jackson", "Van Buren", "Harrison", "Tyler", "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan", "Lincoln", "Johnson", "Grant", "Hayes", "Garfield", "Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley", "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge", "Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy", "Johnson", "Nixon", "Ford", "Carter", "Reagan" }; //历任美国总统的名字
	int nPos; //届数
	cin >> nPos; //输入届数
	cout << arrNames[nPos - 1]; //输出他的名字
	return 0; //结束，emmmmm
}
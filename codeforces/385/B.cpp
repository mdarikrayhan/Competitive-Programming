#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cmath>

int main() {

	std::string s;
	unsigned int ans{ 0 };
	int lastInd{ -1 };
	std::cin >> s;
	for (int i{ 0 }; i < int(s.size()) - 3; i++)
		if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r') {
			if (lastInd == -1)
				ans += (s.size() - i - 3) * (i + 1);
			else
				ans += (s.size() - i - 3) * (i - lastInd);
			lastInd = i;
		}
	std::cout << ans;
	return 0;
}
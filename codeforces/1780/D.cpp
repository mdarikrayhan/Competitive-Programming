#include<iostream>
int main() {
	int t, c, d, r, s;
	std::cin >> t;
	while (t--) {
		std::cin >> c;
		s = d = 0;
		for (int b = 0; c > d; b++)
			std::cout << "- " << (1 << b) << std::endl, std::cin >> r, d += (r >= c), s += ((r >= c) + 1) * (1 << b), c = r;
		std::cout << "! " << s << std::endl;
	}
}
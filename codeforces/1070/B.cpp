// bad

#include <bits/stdc++.h>

struct IP {
	bool valid = true;
	unsigned int mask = 0;
	unsigned int sub = 0;
	void read() {
		char list; std::cin >> list;
		valid = list == '+';
		std::string s;
		for (int shft = 24; shft > 0; shft -= 8) {
			std::getline(std::cin, s, '.');
			mask |= std::stoi(s) << shft;
		}
		std::getline(std::cin, s);
		// std::cerr << "rest: " << s << std::endl;
		if (s.find('/') == std::string::npos) mask |= std::stoi(s), sub = mask;
		else {
			mask |= std::stoi(s.substr(0, s.find('/')));
			sub = std::stoi(s.substr(s.find('/') + 1));
			sub = mask + (1 << (32 - sub)) - 1;
		}
	}
	friend std::ostream& operator << (std::ostream& out, const IP& ip) {
		out << (ip.mask >> 24) << '.' << ((ip.mask >> 16) & 255) << '.' << ((ip.mask >> 8) & 255) << '.' << (ip.mask & 255);
		unsigned int range = ip.sub - ip.mask;
		int cnt = 32;
		while (range) range >>= 1, --cnt;
		out << '/' << cnt;
		return out;
	}
};

#define BAD { std::cout << "-1\n"; exit(0); }

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::vector <IP> ips(n);
	for (IP& ip : ips) ip.read();
	std::vector <IP> ans;
	auto f = [&] (auto&& self, unsigned int l, unsigned int r, std::vector <IP> range) -> void {
		unsigned int mid = ((long long) l + r) / 2;
		bool al = false, nal = false, some = false, nsome = false;
		std::vector <IP> lrn, rrn;
		for (IP ip : range) {
			if (ip.mask == l && ip.sub == r && ip.valid) al = true, some = true;
			else if (ip.mask == l && ip.sub == r) nal = true, nsome = true;
			else {
				(ip.valid ? some : nsome) = true;
				(ip.sub <= mid ? lrn : rrn).push_back(ip);
			}
			if (al && nsome) BAD;
			if (nal && some) BAD;
		}
		if (!nsome) return;
		if (!some) ans.push_back({ true, l, r });
		if (!some) return;
		self(self, l, mid, lrn);
		self(self, mid + 1, r, rrn);
	};
	f(f, 0, ~0, ips);
	std::cout << ans.size() << "\n";
	for (IP ip : ans) std::cout << ip << "\n";
}

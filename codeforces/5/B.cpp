#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
// #include <set>
#include <sstream>  
#include <algorithm>
//#include <cmath>

//#include "mat.h"
//#include "polynomial.h"

int main()
{
    //checkMat();
    //checkPolynomial();

    int n = 0;
    int v = 0;
    std::string str;
    std::vector<std::string> buffer;

    while (!std::cin.eof()) {
        // std::cin >> str;
        std::getline(std::cin, str);
        buffer.push_back(str);
        n++;
        v = std::max(v, int(str.size()));
    }

    auto dline = [&](int length) {
        for (int i = 0; i < length; i++) {
            std::cout << '*';
        }
        std::cout << "\n";
    };

    auto textline = [&](std::string& str, int space1, int space2) {
        std::cout << '*';
        for (int i = 0; i < space1; i++) {
            std::cout << ' ';
        }
        std::cout << str;
        for (int i = 0; i < space2; i++) {
            std::cout << ' ';
        }
        std::cout << '*';
        std::cout << "\n";
    };

    dline(v + 2);
    int half = v / 2;
    bool left = true;
    if (v % 2 == 0) {
        for (int i = 0; i < buffer.size() - 1; i++) {
            auto& cur_str = buffer[i];
            int str_l = cur_str.size();
            int space_ = str_l / 2;
            if (str_l % 2 == 0) {
                textline(cur_str, half - space_, half - space_);
            } else {
                if (left) {
                    textline(cur_str, half - space_ - 1, half - space_);
                }
                else {
                    textline(cur_str, half - space_, half - space_ - 1);
                }
                left = !left;
            }
        }
    } else {
        for (int i = 0; i < buffer.size() - 1; i++) {
            auto& cur_str = buffer[i];
            if (cur_str.empty()) {
                cur_str = " ";
            }
            int str_l = cur_str.size() - 1;
            int space_ = str_l / 2;
             if (str_l % 2 == 0) {
                textline(cur_str, half - space_, half - space_);
            }
            else {
                if (left) {
                    textline(cur_str, half - space_ - 1, half - space_);
                }
                else {
                    textline(cur_str, half - space_, half - space_ - 1);
                }
                left = !left;
            }
        }
    }

    dline(v + 2);
    return 0;
}





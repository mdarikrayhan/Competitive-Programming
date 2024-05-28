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
#include <cmath>

//#include "mat.h"
//#include "polynomial.h"

struct state {
    std::vector<int> hit;
    int total_hit;
    // collect before hit i-th, s.t., hit.back() is (i-1)-th's hit
    // last_hp;
    // cur_hp;
    // no need A when total_hitA >= total_hitB && last_hpA >= last_hpB && cur_hpA >= cur_hpB
    // or last_hp > cur_hp
    // cur_state[cur_hit] = states
};

int main()
{
    //checkMat();
    //checkPolynomial();

    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<int> hp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> hp[i];
        hp[i]++;
    }

    int cur_id = 0;
    std::unordered_map<int, std::unordered_map<int, state>> last_remain, cur_remain;
    cur_remain[hp[cur_id]][0] = {{0}, 0};
    cur_id++;
    std::swap(last_remain, cur_remain);

    while (cur_id < n - 2) {
        for (auto it = last_remain.begin(); it != last_remain.end(); it++) {
            int last_hp = it->first;
            int min_cur_hit = last_hp / b;
            if (last_hp > min_cur_hit * b) {
                min_cur_hit++;
            }

            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
                int last_hit = it2->first;
                int cur_hit = min_cur_hit;
                int cur_hp = std::max(hp[cur_id] - a * min_cur_hit - b * last_hit, 0);

                while (true) {
                    if (cur_remain.find(cur_hp) == cur_remain.end()) {
                        cur_remain[cur_hp] = {};
                        // cur_remain[cur_hp] = { { cur_hit, it2->second } };
                        cur_remain[cur_hp][cur_hit] = it2->second;
                        cur_remain[cur_hp][cur_hit].hit.push_back(cur_hit);
                        cur_remain[cur_hp][cur_hit].total_hit += cur_hit;
                    }
                    else {
                        if (cur_remain[cur_hp].find(cur_hit) != cur_remain[cur_hp].end()) {
                            if (cur_remain[cur_hp][cur_hit].total_hit <= (it2->second.total_hit + cur_hit)) {
                                break; // if exist a cur_hp_key <= cur_hp with total_hit <= nw total_hit
                            }
                        }
                        cur_remain[cur_hp][cur_hit] = it2->second;
                        cur_remain[cur_hp][cur_hit].hit.push_back(cur_hit);
                        cur_remain[cur_hp][cur_hit].total_hit += cur_hit;
                    }

                    if (cur_hp == 0) {
                        break;
                    }
                    else {
                        cur_hp = std::max(cur_hp - a, 0);
                        cur_hit++;
                    }
                }
            }
        }
        cur_id++;
        last_remain.clear();
        std::swap(last_remain, cur_remain);
    }

    state ans = { {}, INT_MAX };
    for (auto it1 = last_remain.begin(); it1 != last_remain.end(); it1++) {
        for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
            int last_hp = std::max(it1->first, hp[n - 1]);
            int cur_hp = hp[cur_id] - b * it2->second.hit.back();

            int cur_hit = std::max(cur_hp / a, last_hp / b);
            if (last_hp > cur_hit * b || cur_hp > cur_hit * a) {
                cur_hit++;
            }

            if (ans.total_hit > cur_hit + it2->second.total_hit) {
                ans = it2->second;
                ans.hit.push_back(cur_hit);
                ans.total_hit += cur_hit;
            }
        }
    }

    std::cout << ans.total_hit << "\n";
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < ans.hit[i]; j++) {
            std::cout << i + 1 << ' ';
        }
    }

    return 0;

}





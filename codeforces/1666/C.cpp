// #define DEBUG
#include <bits/stdc++.h>
#include <iostream>
#include <random>
using namespace std;

#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif

int main() {

    #ifdef DEBUG
    freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout); 
    #endif


    pair<int, int> pnts[3];
    for (int i = 0; i < 3; i++){
        cin >> pnts[i].first >> pnts[i].second;
    }

    sort(pnts, pnts + 3, [](pair<int, int> a, pair<int, int> b) -> bool {
        if (a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    queue<pair<pair<int, int>, pair<int, int>>> lines;
    auto a = pnts[0];
    auto b = pnts[1];
    auto c = pnts[2];

    lines.push({a, {b.first, a.second}});
    lines.push({{b.first, a.second}, b});

    if (c.second > b.second && c.second > a.second){
        if (b.second > a.second){
            lines.push({b, {c.first, b.second}});
            lines.push({{c.first, b.second}, c});
        }
        else {
            lines.push({{b.first, a.second}, {c.first, a.second}});
            lines.push({{c.first, a.second}, c});
        }
    }

    else if (c.second < b.second && c.second < a.second){
        
        if (b.second < a.second){
            lines.push({b, {c.first, b.second}});
            lines.push({{c.first, b.second}, c});
        }
        else {
            lines.push({{b.first, a.second}, {c.first, a.second}});
            lines.push({{c.first, a.second}, c});
        }
    }

    else {
        lines.push({{b.first, c.second}, {c}});
    }

    int cnt = lines.size();
    for (int i = 0; i < cnt; i++){
        auto cc = lines.front();
        lines.pop();
        if (cc.first == cc.second){
            cnt --;
            continue;
        }
        lines.push(cc);
    }

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++){
        auto cc = lines.front();
        lines.pop();
        cout << cc.first.first << " " << cc.first.second << " " << cc.second.first << " " << cc.second.second << "\n";
    }

	#ifdef DEBUG
		cerr << "\nRuntime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}
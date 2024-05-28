#include<bits/stdc++.h>
using namespace std;

long long fn(long long side, long long r, double minr, double maxr) 
{
    long long mins = ceil(side * minr);
    long long maxs = floor(side * maxr);
    
    if (mins > r) return 0;
    return min(r, maxs);
}

int main() {
    long long h, w;
    cin >> h >> w;

    vector<long long> p2;

    for (long long i = 1; i <= max(h, w); i *= 2) {
        p2.push_back(i);
    }

    long long maxArea = 0;
    long long ansh = 0, answ = 0;

    for (long long ht : p2) {
        if (ht > h) break; 

        long long maxW = fn(ht, w, 0.8, 1.25);
        if (maxW == 0) continue;

        long long area = ht * maxW;
        if (area > maxArea || (area == maxArea && ht > ansh)) {
            maxArea = area;
            ansh = ht;
            answ = maxW;
        }
    }

    for (long long candidateW : p2) {
        if (candidateW > w) break; 

        long long maxH = fn(candidateW, h, 0.8, 1.25);
        if (maxH == 0) continue;

        long long area = candidateW * maxH;
        if (area > maxArea || (area == maxArea && maxH > ansh))
        {
            maxArea = area;
            ansh = maxH;
            answ = candidateW;
        }
    }

    cout << ansh << " " << answ << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using std::vector;

struct Lighthouse {
    double x, y, a;
};

const double PI = acos(-1);

double findRightPoint(Lighthouse& lighthouse, double currX, double lastX) {
    double angle = lighthouse.a * PI / 180;

    double dx = currX - lighthouse.x;
    double dy = 0.0 - lighthouse.y;

    double turnDX = dx * std::cos(angle) - dy * std::sin(angle);
    double turnDY = dx * std::sin(angle) + dy * std::cos(angle);

    double k = 1 / turnDY;
    turnDX *= k;

    if (turnDY > 0) {
        return lastX;
    }
//    std::cout << turnDX << " " << turnDY << "\n";

    return std::min(lastX, lighthouse.x - lighthouse.y * turnDX);
}

int main() {
    int n = 0, l = 0, r = 0;
    std::cin >> n >> l >> r;

    vector<Lighthouse> lighthouses(n);
    for (int i = 0; i < n; ++i) {
        double x = 0, y = 0, a = 0;
        std::cin >> x >> y >> a;

        lighthouses[i] = {x, y, a};
    }

    vector<double> maxDistancesDp(1 << n, INT_MIN);
    maxDistancesDp[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                continue;
            }

            auto nextRightX = findRightPoint(lighthouses[j], maxDistancesDp[i] + l, r);
//            std::cout << nextRightX - l << "\n";
            maxDistancesDp[i | (1 << j)] = std::max(maxDistancesDp[i | (1 << j)], nextRightX - l);
        }
    }

    double maxDistance = 0.0;
    for (int i = 0; i < (1 << n); ++i) {
        if (maxDistancesDp[i] > maxDistance) {
            maxDistance = maxDistancesDp[i];
        }
    }

    printf("%.10f", maxDistance);

    return 0;
}
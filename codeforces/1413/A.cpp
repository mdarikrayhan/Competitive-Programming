#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef struct {
    int seals;
    vector<int> energies;
} door;



int main()
{
    int doors;
    vector<door> seals;
    vector<int> energies;

    cin >> doors;

    for (int x = 0; x < doors; ++x) {
	int input = 0;
	cin >> input;

	for (int y = 0; y < input; ++y) {
	    int energy = 0;
	    cin >> energy;
	    energies.push_back(energy);
	}

	seals.push_back({input, energies});
	energies.clear();
    }

    for (auto x: seals) {
	for (auto y = x.energies.begin(); y != x.energies.end(); y += 2) {
	    cout << -*(y+1) << ' ' << *y << ' ';
	}

	cout << '\n';
    }
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // List of days in each month in a normal year
    vector<int> normal_year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // List of days in each month in a leap year
    vector<int> leap_year = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Concatenate both lists to allow wrapping around the calendar
    vector<int> year_sequence;
    year_sequence.reserve(normal_year.size() * 6); // Reserving space for 6 years

    // Adding 3 normal years
    for (int i = 0; i < 3; ++i) {
        year_sequence.insert(year_sequence.end(), normal_year.begin(), normal_year.end());
    }
    
    // Adding 1 leap year
    year_sequence.insert(year_sequence.end(), leap_year.begin(), leap_year.end());
    
    // Adding 2 more normal years
    for (int i = 0; i < 2; ++i) {
        year_sequence.insert(year_sequence.end(), normal_year.begin(), normal_year.end());
    }

    // Reading input
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    // Check if the given sequence matches any part of the combined year sequence
    bool found = false;
    for (size_t start = 0; start <= year_sequence.size() - n; ++start) {
        bool match = true;
        for (int i = 0; i < n; ++i) {
            if (year_sequence[start + i] != sequence[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            found = true;
            break;
        }
    }

    // Output result
    cout << (found ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    int rowStrokes = 0, colStrokes = 0;
    
    // Check rows
    for (int i = 0; i < 8; ++i) {
        bool allBlack = true;
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 'W') {
                allBlack = false;
                break;
            }
        }
        if (allBlack) rowStrokes++;
    }

    // Check columns
    for (int j = 0; j < 8; ++j) {
        bool allBlack = true;
        for (int i = 0; i < 8; ++i) {
            if (board[i][j] == 'W') {
                allBlack = false;
                break;
            }
        }
        if (allBlack) colStrokes++;
    }

    // If all rows are black, we don't need to paint any columns
    if (rowStrokes == 8) {
        cout << 8 << endl;
    } else {
        cout << rowStrokes + colStrokes << endl;
    }

    return 0;
}
